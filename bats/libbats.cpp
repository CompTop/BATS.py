#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

// interface of common functions between F2 and other modP
#define BasicModPInterface(F, name) py::class_<F>(m, name)\
.def(py::init<>())\
.def(py::init<int>())\
.def("__add__", &F::operator+)\
.def("__mul__", &F::operator*)\
.def("__sub__", py::overload_cast<const F&>(&F::operator-, py::const_))\
.def("__truediv__", &F::operator/)\
.def("__str__", &F::str)

// interface for everything other than F2
#define ModPInterface(F, name) BasicModPInterface(F, name)\
.def("__neg__", py::overload_cast<>(&F::operator-, py::const_));

#define SparseVectorInterface(F, name) py::class_<SparseVector<F, size_t>>(m, name)\
.def(py::init<>())\
.def(py::init<const std::vector<size_t>&, const std::vector<F>&>())\
.def("nzinds", &SparseVector<F, size_t>::nzinds)\
.def("__getitem__", py::overload_cast<size_t>(&SparseVector<F, size_t>::getval, py::const_))\
.def("print", &SparseVector<F, size_t>::print);
// .def("__getitem__", (F (SparseVector<F, size_t>::*)(size_t))(&SparseVector<F, size_t>::operator[]))

#define ColumnMatrixInterface(VT, name) py::class_<ColumnMatrix<VT>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t>())\
.def("print", &ColumnMatrix<VT>::print);

#define ChainComplexInterface(MT, name) py::class_<ChainComplex<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const SimplicialComplex&>())\
.def("__getitem__", &ChainComplex<MT>::operator[]);

#define ChainMapInterface(MT, name) py::class_<ChainMap<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const CellularMap&>())\
.def("__getitem__", py::overload_cast<size_t>(&ChainMap<MT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<size_t>(&ChainMap<MT>::operator[]));

#define ReducedChainComplexInterface(MT, name) py::class_<ReducedChainComplex<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const ChainComplex<MT>&>())\
.def("hdim", &ReducedChainComplex<MT>::hdim)\
.def("get_preferred_representative", &ReducedChainComplex<MT>::get_preferred_representative)\
.def("find_preferred_representative", &ReducedChainComplex<MT>::find_preferred_representative)\
.def("maxdim", &ReducedChainComplex<MT>::maxdim);

#define FilteredSimplicialComplexInterface(T, name) py::class_<Filtration<T, SimplicialComplex>>(m, name)\
.def(py::init<>())\
.def("add", (cell_ind (Filtration<T, SimplicialComplex>::*)(T, std::vector<size_t>&))(&Filtration<T, SimplicialComplex>::add))\
.def("complex", &Filtration<T, SimplicialComplex>::complex)\
.def("maxdim", &Filtration<T, SimplicialComplex>::maxdim)\
.def("ncells", &Filtration<T, SimplicialComplex>::ncells)\
.def("vals", py::overload_cast<size_t>(&Filtration<T, SimplicialComplex>::vals, py::const_))\
.def("all_vals", py::overload_cast<>(&Filtration<T, SimplicialComplex>::vals, py::const_));

#define FilteredChainComplexInterface(T, MT, name) py::class_<FilteredChainComplex<T, MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const Filtration<T, SimplicialComplex>&>());

#define ReducedFilteredChainComplexInterface(T, MT, name) py::class_<ReducedFilteredChainComplex<T, MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const FilteredChainComplex<T, MT>&>())\
.def("dim", &ReducedFilteredChainComplex<T, MT>::dim)\
.def("maxdim", &ReducedFilteredChainComplex<T, MT>::maxdim)\
.def("representative", &ReducedFilteredChainComplex<T, MT>::representative )\
.def("persistence_pairs", &ReducedFilteredChainComplex<T, MT>::persistence_pairs);

#define PersistencePairInterface(T, name) py::class_<PersistencePair<T>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t, size_t, T, T>())\
.def("dim", &PersistencePair<T>::get_dim)\
.def("birth_ind", &PersistencePair<T>::get_birth_ind)\
.def("death_ind", &PersistencePair<T>::get_death_ind)\
.def("birth", &PersistencePair<T>::get_birth)\
.def("death", &PersistencePair<T>::get_death)\
.def("__str__", &PersistencePair<T>::str);

PYBIND11_MODULE(libbats, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

    BasicModPInterface(F2, "F2")
        .def("__neg__", py::overload_cast<>(&F2::operator-));

    ModPInterface(F3, "F3")
    ModPInterface(F5, "F5")

    SparseVectorInterface(int, "IntVector")
    SparseVectorInterface(F2, "F2Vector")
    SparseVectorInterface(F3, "F3Vector")

    ColumnMatrixInterface(VInt, "IntMat")
    ColumnMatrixInterface(V2, "F2Mat")
    ColumnMatrixInterface(V3, "F3Mat")


    py::class_<CSCMatrix<int, size_t>>(m, "CSCMatrix")
        .def(py::init<>())
        .def(py::init<size_t, size_t, const std::vector<size_t> &, const std::vector<size_t> &, const std::vector<int> &>())
        .def("__call__", &CSCMatrix<int, size_t>::getval)
        .def("print", py::overload_cast<>(&CSCMatrix<int, size_t>::print, py::const_));

    py::class_<cell_ind>(m, "cell_ind")
        .def(py::init<>())
        .def(py::init<size_t, size_t>())
        .def("__str__", &cell_ind::str);

    py::class_<SimplicialComplex>(m, "SimplicialComplex")
        .def(py::init<>())
        .def("maxdim", &SimplicialComplex::maxdim, "maximum dimension simplex")
        .def("ncells", py::overload_cast<>(&SimplicialComplex::ncells, py::const_), "number of cells")
        .def("ncells", py::overload_cast<const size_t>(&SimplicialComplex::ncells, py::const_), "number of cells in given dimension")
        .def("add", (cell_ind (SimplicialComplex::*)(std::vector<size_t>&))( &SimplicialComplex::add ), "add simplex")
        .def("find_idx", py::overload_cast<const std::vector<size_t> &>(&SimplicialComplex::find_idx))
        .def("boundary", &SimplicialComplex::boundary_csc)
        .def("get_simplex", &SimplicialComplex::get_simplex)
        .def("get_simplices", &SimplicialComplex::get_simplices)
        .def("print_summary", &SimplicialComplex::print_summary);

    FilteredSimplicialComplexInterface(double, "FilteredSimplicialComplex")

    py::class_<CellularMap>(m, "CellularMap")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def("__getitem__", py::overload_cast<size_t>(&CellularMap::operator[], py::const_))\
        .def("__setitem__", py::overload_cast<size_t>(&CellularMap::operator[]));

    m.def("SimplicialMap", &SimplicialMap);

    ChainComplexInterface(M2, "F2ChainComplex")
    ChainComplexInterface(M3, "F3ChainComplex")

    ChainMapInterface(M2, "F2ChainMap")
    ChainMapInterface(M3, "F3ChainMap")

    ReducedChainComplexInterface(M2, "ReducedF2ChainComplex")
    ReducedChainComplexInterface(M3, "ReducedF3ChainComplex")

    FilteredChainComplexInterface(double, M2, "FilteredF2ChainComplex")
    FilteredChainComplexInterface(double, M3, "FilteredF3ChainComplex")

    ReducedFilteredChainComplexInterface(double, M2, "ReducedFilteredF2ChainComplex")
    ReducedFilteredChainComplexInterface(double, M3, "ReducedFilteredF3ChainComplex")

    PersistencePairInterface(double, "PersistencePair")

}
