#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;
using namespace bats;


PYBIND11_MODULE(linalg, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

		#ifdef BATS_OPCOUNT
		m.def("reset_field_ops", [](){bats::field_ops = 0; return;}, "Set global counter for field operations to be zero.");
		m.def("get_field_ops", [](){return bats::field_ops;}, "return global counter of field operations.");
		m.def("reset_column_ops", [](){bats::column_ops = 0; return;}, "Set global counter for column operations to be zero");
		m.def("get_column_ops", [](){return bats::column_ops;}, "return global counter of column operations");
		#endif

    SparseVectorInterface(int, "IntVector")

    ColumnMatrixInterface(VInt, "IntMat")
		m.def("Mat", [](const CSCMatrix<int, size_t> &A) { return ColumnMatrix<VInt>(A); });

    py::class_<CSCMatrix<int, size_t>>(m, "CSCMatrix")
        .def(py::init<>())
        .def(py::init<size_t, size_t, const std::vector<size_t> &, const std::vector<size_t> &, const std::vector<int> &>())
        .def("__call__", &CSCMatrix<int, size_t>::getval)
				.def("nrow", &CSCMatrix<int, size_t>::nrow, "number of rows.")\
				.def("ncol", &CSCMatrix<int, size_t>::ncol, "number of columns.")\
        .def("print", py::overload_cast<>(&CSCMatrix<int, size_t>::print, py::const_));

		ColumnMatrixInterfaceExtra(V2)
		ColumnMatrixInterfaceExtra(V3)

		FlagInterface(bats::no_optimization_flag, "no_optimization_flag")
		FlagInterface(bats::clearing_flag, "clearing_flag")
		FlagInterface(bats::compression_flag, "compression_flag")
		FlagInterface(bats::standard_reduction_flag, "standard_reduction_flag")
		FlagInterface(bats::extra_reduction_flag, "extra_reduction_flag")
		FlagInterface(bats::compute_basis_flag, "compute_basis_flag")
		FlagInterface(flags::divide_conquer, "divide_conquer")
		FlagInterface(flags::rightward, "rightward")
		FlagInterface(flags::leftward, "leftward")

    PersistencePairInterface(double, "PersistencePair")
    PersistencePairInterface(size_t, "PersistencePair_int")
		ZigzagPairInterface(double, "ZigzagPair")


}
