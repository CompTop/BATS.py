#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <bats.h>
#include <vector>
#include <iostream>

namespace py = pybind11;

using IntVec = SparseVector<int, size_t>;
using IntMat = ColumnMatrix<IntVec>;
using F2 = ModP<int, 2>;
using F3 = ModP<int, 3>;
using F3 = ModP<int, 5>;

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
.def("__neg__", py::overload_cast<>(&F3::operator-, py::const_));

PYBIND11_MODULE(libbats, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

    BasicModPInterface(F2, "F2")
        .def("__neg__", py::overload_cast<>(&F2::operator-));

    ModPInterface(F3, "F3")
    ModPInterface(F5, "F5")

    py::class_<IntVec>(m, "IntVector")
        .def(py::init<>())
        .def("print", &IntVec::print);

    py::class_<IntMat>(m, "IntMatrix")
        .def(py::init<>())
        .def(py::init<size_t, size_t>())
        .def("print", &IntMat::print);

    py::class_<CSCMatrix<int, size_t>>(m, "CSCMatrix")
        .def(py::init<>())
        .def(py::init<size_t, size_t, const std::vector<size_t> &, const std::vector<size_t> &, const std::vector<int> &>())
        .def("__call__", &CSCMatrix<int, size_t>::getval)
        .def("print", py::overload_cast<>(&CSCMatrix<int, size_t>::print, py::const_));

    py::class_<cell_ind>(m, "cell_ind")
        .def(py::init<>())
        .def(py::init<size_t, size_t>());

    py::class_<SimplicialComplex>(m, "SimplicialComplex")
        .def(py::init<>())
        .def("maxdim", &SimplicialComplex::maxdim, "maximum dimension simplex")
        .def("ncells", py::overload_cast<>(&SimplicialComplex::ncells, py::const_), "number of cells")
        .def("ncells", py::overload_cast<const size_t>(&SimplicialComplex::ncells, py::const_), "number of cells in given dimension")
        .def("add", (cell_ind (SimplicialComplex::*)(std::vector<size_t>&))( &SimplicialComplex::add ), "add simplex")
        .def("boundary", &SimplicialComplex::boundary_csc)
        .def("print_summary", &SimplicialComplex::print_summary);

    py::class_<CellularMap>(m, "CellularMap")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def("__getitem__", py::overload_cast<size_t>(&CellularMap::operator[], py::const_));
}
