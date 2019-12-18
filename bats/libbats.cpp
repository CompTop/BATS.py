#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <bats.h>
#include <vector>

namespace py = pybind11;

using IntVec = SparseVector<int, size_t>;
using IntMat = ColumnMatrix<IntVec>;

PYBIND11_MODULE(libbats, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

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
