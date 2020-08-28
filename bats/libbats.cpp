#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

// interface of common functions between F2 and other modP
#define BasicFieldInterface(F, name) py::class_<F>(m, name)\
.def(py::init<>())\
.def(py::init<int>())\
.def("to_int", &F::to_int, "convert to integer.")\
.def("__add__", &F::operator+)\
.def("__mul__", &F::operator*)\
.def("__sub__", py::overload_cast<const F&>(&F::operator-, py::const_))\
.def("__truediv__", &F::operator/)\
.def("__repr__", &F::str)\
.def("__str__", &F::str)

// interface for everything other than F2
#define FieldInterface(F, name) BasicFieldInterface(F, name)\
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
.def(py::init<const CSCMatrix<int, size_t> &>())\
.def("nrow", &ColumnMatrix<VT>::nrow, "number of rows.")\
.def("ncol", &ColumnMatrix<VT>::ncol, "number of columns.")\
.def("tolist", &ColumnMatrix<VT>::to_row_array, "return as C-style array")\
.def("__str__", &ColumnMatrix<VT>::str)\
.def("__mul__", py::overload_cast<const VT &>(&ColumnMatrix<VT>::operator*, py::const_))\
.def("__mul__", py::overload_cast<const ColumnMatrix<VT> &>(&ColumnMatrix<VT>::operator*, py::const_))\
.def("__getitem__", py::overload_cast<size_t>(&ColumnMatrix<VT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<size_t>(&ColumnMatrix<VT>::operator[]))\
.def("__call__", &ColumnMatrix<VT>::operator());\
m.def("Mat", [](const CSCMatrix<int, size_t> &A, VT::val_type) { return ColumnMatrix<VT>(A); });

#define ChainComplexInterface(MT, name) py::class_<ChainComplex<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const SimplicialComplex&>())\
.def(py::init<const CubicalComplex&>())\
.def("__getitem__", &ChainComplex<MT>::operator[]);

#define ChainMapInterface(m, MT, name) py::class_<ChainMap<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const CellularMap&>())\
.def("__getitem__", py::overload_cast<size_t>(&ChainMap<MT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<size_t>(&ChainMap<MT>::operator[]));

#define ReducedChainComplexInterface(MT, name) py::class_<ReducedChainComplex<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const ChainComplex<MT>&>())\
.def("hdim", &ReducedChainComplex<MT>::hdim)\
.def("get_preferred_representative", &ReducedChainComplex<MT>::get_preferred_representative, "get the preferred representative for homology class")\
.def("chain_preferred_representative", &ReducedChainComplex<MT>::chain_preferred_representative, "return the preferred representative of a chain")\
.def("find_preferred_representative", &ReducedChainComplex<MT>::find_preferred_representative)\
.def("to_hom_basis", [](const ReducedChainComplex<MT> &R, const MT &A, size_t k) {return R.to_hom_basis(A, k);})\
.def("to_hom_basis", [](const ReducedChainComplex<MT> &R, const MT::col_type &A, size_t k) {return R.to_hom_basis(A, k);})\
.def("from_hom_basis", [](const ReducedChainComplex<MT> &R, const MT &A, size_t k) {return R.from_hom_basis(A, k);})\
.def("from_hom_basis", [](const ReducedChainComplex<MT> &R, const MT::col_type &A, size_t k) {return R.from_hom_basis(A, k);})\
.def("maxdim", &ReducedChainComplex<MT>::maxdim);

#define InducedMapInterface(m, MT) \
m.def("InducedMap",\
	(MT (*)(const ChainMap<MT> &, const ReducedChainComplex<MT> &, const ReducedChainComplex<MT>&, size_t))(&induced_map), \
	"Induced map on homology." \
);

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

// ReducedFilteredChainComplex for field type T
#define AutoReducedChainComplexInterface(T) \
m.def("ReducedChainComplex", (ReducedChainComplex<ColumnMatrix<SparseVector<T, size_t>>> (*)(const SimplicialComplex&, T))(&__ReducedChainComplex));\
m.def("reduce", (ReducedChainComplex<ColumnMatrix<SparseVector<T, size_t>>> (*)(const SimplicialComplex&, T))(&__ReducedChainComplex));

#define ReducedFilteredChainComplexInterface(T, MT, name) py::class_<ReducedFilteredChainComplex<T, MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const FilteredChainComplex<T, MT>&>())\
.def("dim", &ReducedFilteredChainComplex<T, MT>::dim)\
.def("maxdim", &ReducedFilteredChainComplex<T, MT>::maxdim)\
.def("representative", &ReducedFilteredChainComplex<T, MT>::representative )\
.def("persistence_pairs", &ReducedFilteredChainComplex<T, MT>::persistence_pairs);

// ReducedFilteredChainComplex for field type T
#define AutoReducedFilteredChainComplexInterface(T) \
m.def("ReducedFilteredChainComplex", (ReducedFilteredChainComplex<double, ColumnMatrix<SparseVector<T, size_t>>> (*)(const Filtration<double, SimplicialComplex>&, T))(&__ReducedFilteredChainComplex));\
m.def("reduce", (ReducedFilteredChainComplex<double, ColumnMatrix<SparseVector<T, size_t>>> (*)(const Filtration<double, SimplicialComplex>&, T))(&__ReducedFilteredChainComplex));


#define PersistencePairInterface(T, name) py::class_<PersistencePair<T>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t, size_t, T, T>(), "initialize with hdim, birth_ind, death_ind, birth, death.")\
.def("dim", &PersistencePair<T>::get_dim)\
.def("birth_ind", &PersistencePair<T>::get_birth_ind)\
.def("death_ind", &PersistencePair<T>::get_death_ind)\
.def("birth", &PersistencePair<T>::get_birth)\
.def("death", &PersistencePair<T>::get_death)\
.def("length", &PersistencePair<T>::length)\
.def("mid", &PersistencePair<T>::mid)\
.def("__str__", &PersistencePair<T>::str);

PYBIND11_MODULE(libbats, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

    BasicFieldInterface(F2, "F2")
        .def("__neg__", py::overload_cast<>(&F2::operator-));

    FieldInterface(F3, "F3")
    FieldInterface(F5, "F5")
    FieldInterface(FQ, "Rational")

    SparseVectorInterface(int, "IntVector")
    SparseVectorInterface(F2, "F2Vector")
    SparseVectorInterface(F3, "F3Vector")
    SparseVectorInterface(FQ, "RationalVector")

    ColumnMatrixInterface(VInt, "IntMat")
	m.def("Mat", [](const CSCMatrix<int, size_t> &A) { return ColumnMatrix<VInt>(A); });
    ColumnMatrixInterface(V2, "F2Mat")
    ColumnMatrixInterface(V3, "F3Mat")
    ColumnMatrixInterface(VQ, "RationalMat")


    py::class_<CSCMatrix<int, size_t>>(m, "CSCMatrix")
        .def(py::init<>())
        .def(py::init<size_t, size_t, const std::vector<size_t> &, const std::vector<size_t> &, const std::vector<int> &>())
        .def("__call__", &CSCMatrix<int, size_t>::getval)
		.def("nrow", &CSCMatrix<int, size_t>::nrow, "number of rows.")\
		.def("ncol", &CSCMatrix<int, size_t>::ncol, "number of columns.")\
        .def("print", py::overload_cast<>(&CSCMatrix<int, size_t>::print, py::const_));

    py::class_<cell_ind>(m, "cell_ind")
        .def(py::init<>())
        .def(py::init<size_t, size_t>())
        .def("__str__", &cell_ind::str);

    py::class_<CellComplex>(m, "CellComplex")
        .def(py::init<>())
        .def("maxdim", &CellComplex::maxdim, "maximum dimension cell")
        .def("ncells", py::overload_cast<>(&CellComplex::ncells, py::const_), "number of cells")
        .def("ncells", py::overload_cast<const size_t>(&CellComplex::ncells, py::const_), "number of cells in given dimension")
		.def("add_vertex", &CellComplex::add_vertex, "add vertex to cell complex")
		.def("add_vertices", &CellComplex::add_vertices, "add vertices to cell complex")
        .def("add", (size_t (CellComplex::*)(const std::vector<size_t>&, const std::vector<int>&, size_t))( &CellComplex::add ), "add cell in dimension k by specifying boundary and coefficients.")
        .def("boundary", &CellComplex::boundary_csc);

    py::class_<SimplicialComplex>(m, "SimplicialComplex")
        .def(py::init<>())
        .def("maxdim", &SimplicialComplex::maxdim, "maximum dimension simplex")
        .def("ncells", py::overload_cast<>(&SimplicialComplex::ncells, py::const_), "number of cells")
        .def("ncells", py::overload_cast<const size_t>(&SimplicialComplex::ncells, py::const_), "number of cells in given dimension")
        .def("add", (cell_ind (SimplicialComplex::*)(std::vector<size_t>&))( &SimplicialComplex::add ), "add simplex")
        .def("find_idx", py::overload_cast<const std::vector<size_t> &>(&SimplicialComplex::find_idx))
        .def("boundary", &SimplicialComplex::boundary_csc)
        .def("get_simplex", &SimplicialComplex::get_simplex)
        .def("get_simplices", py::overload_cast<const size_t>(&SimplicialComplex::get_simplices, py::const_), "Returns a list of all simplices in given dimension.")
        .def("get_simplices", py::overload_cast<>(&SimplicialComplex::get_simplices, py::const_), "Returns a list of all simplices.")
        .def("print_summary", &SimplicialComplex::print_summary);

    py::class_<CubicalComplex>(m, "CubicalComplex")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def("maxdim", &CubicalComplex::maxdim, "maximum dimension cube")
        .def("ncells", py::overload_cast<>(&CubicalComplex::ncells, py::const_), "number of cells")
        .def("ncells", py::overload_cast<const size_t>(&CubicalComplex::ncells, py::const_), "number of cells in given dimension")
        .def("add", (cell_ind (CubicalComplex::*)(std::vector<size_t>&))( &CubicalComplex::add ), "add cube")
        .def("add_recursive", (cell_ind (CubicalComplex::*)(const std::vector<size_t>&))( &CubicalComplex::add_recursive ), "add cube as well as faces")
        .def("find_idx", py::overload_cast<const std::vector<size_t> &>(&CubicalComplex::find_idx))
        .def("boundary", &CubicalComplex::boundary_csc, "integer boundary matrix")
        .def("skeleton", &CubicalComplex::skeleton, "k-skeleton of complex")
        .def("get_cube", &CubicalComplex::get_cube, "get cube in given dimension")
        .def("load_cubes", &CubicalComplex::load_cubes, "load cubes from a csv file.")
        .def("get_cubes", py::overload_cast<const size_t>(&CubicalComplex::get_cubes, py::const_), "Returns a list of all cubes in given dimension.")
        .def("get_cubes", py::overload_cast<>(&CubicalComplex::get_cubes, py::const_), "Returns a list of all cubes.");

    FilteredSimplicialComplexInterface(double, "FilteredSimplicialComplex")

    py::class_<CellularMap>(m, "CellularMap")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def("__getitem__", py::overload_cast<size_t>(&CellularMap::operator[], py::const_))\
        .def("__setitem__", [](CellularMap &M, size_t k, ColumnMatrix<VInt> &A){return M[k] = A;} );
	m.def("IdentityMap", (CellularMap (*)(const SimplicialComplex &))(&CellularMap::identity));

    m.def("SimplicialMap", py::overload_cast<const SimplicialComplex&, const SimplicialComplex &>(&SimplicialMap), "Inclusion map of simplicial complexes");
	m.def("SimplicialMap", py::overload_cast<const SimplicialComplex&, const SimplicialComplex &, const std::vector<size_t> &>(&SimplicialMap), "simplicial map extended from function on vertices");
    m.def("CubicalMap", &CubicalMap);

    ChainComplexInterface(M2, "F2ChainComplex")
    ChainComplexInterface(M3, "F3ChainComplex")
    ChainComplexInterface(M5, "F5ChainComplex")
    ChainComplexInterface(MQ, "RationalChainComplex")

    ChainMapInterface(m, M2, "F2ChainMap")
    ChainMapInterface(m, M3, "F3ChainMap")
    ChainMapInterface(m, M5, "F5ChainMap")
    ChainMapInterface(m, MQ, "RationalChainMap")


    ReducedChainComplexInterface(M2, "ReducedF2ChainComplex")
    ReducedChainComplexInterface(M3, "ReducedF3ChainComplex")
    ReducedChainComplexInterface(M5, "ReducedF5ChainComplex")
    ReducedChainComplexInterface(MQ, "ReducedRationalChainComplex")

	InducedMapInterface(m, M2)
	InducedMapInterface(m, M3)

    AutoReducedChainComplexInterface(F3)
    AutoReducedChainComplexInterface(F2)
    AutoReducedChainComplexInterface(F5)
    AutoReducedChainComplexInterface(FQ)

    FilteredChainComplexInterface(double, M2, "FilteredF2ChainComplex")
    FilteredChainComplexInterface(double, M3, "FilteredF3ChainComplex")
    FilteredChainComplexInterface(double, M5, "FilteredF5ChainComplex")
    FilteredChainComplexInterface(double, MQ, "FilteredRationalChainComplex")

    ReducedFilteredChainComplexInterface(double, M2, "ReducedFilteredF2ChainComplex")
    ReducedFilteredChainComplexInterface(double, M3, "ReducedFilteredF3ChainComplex")
    ReducedFilteredChainComplexInterface(double, M5, "ReducedFilteredF5ChainComplex")
    ReducedFilteredChainComplexInterface(double, MQ, "ReducedFilteredRationalChainComplex")

    AutoReducedFilteredChainComplexInterface(F2)
    AutoReducedFilteredChainComplexInterface(F3)
    AutoReducedFilteredChainComplexInterface(F5)
    AutoReducedFilteredChainComplexInterface(FQ)

    PersistencePairInterface(double, "PersistencePair")
    PersistencePairInterface(size_t, "PersistencePair_int")

}
