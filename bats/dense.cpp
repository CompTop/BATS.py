#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <pybind11/numpy.h>
#include <pybind11/buffer_info.h>
#include <bats.h>
#include <tuple>
#include <utility>

namespace py = pybind11;

PYBIND11_MODULE(dense, m) {

	// column major - side effect is that the matrix makes a transpose
	py::class_< Matrix<double> >(m, "DenseDoubleMatrix", py::buffer_protocol())
		.def(py::init<>())
		.def(py::init<size_t, size_t>())
		.def("nrow", &Matrix<double>::nrow)
		.def("ncol", &Matrix<double>::ncol)
		.def("__getitem__", py::overload_cast<int, int>(&Matrix<double>::operator(), py::const_))
		.def("__call__", py::overload_cast<int, int>(&Matrix<double>::operator(), py::const_))
		.def("__init__", [](Matrix<double> &m, py::buffer b) {

	        /* Request a buffer descriptor from Python */
	        py::buffer_info info = b.request();

	        /* Some sanity checks ... */
	        if (info.format != py::format_descriptor<double>::format())
	            throw std::runtime_error("Incompatible format: expected a double array!");

	        if (info.ndim != 2)
	            throw std::runtime_error("Incompatible buffer dimension!");

	        new (&m) Matrix<double>(info.shape[1], info.shape[0], (double*) info.ptr);
	    })
		.def("print", &Matrix<double>::print)
		.def("__str__", &Matrix<double>::str)
		.def_buffer([](Matrix<double> &m) -> py::buffer_info { // turn into np.array
	        return py::buffer_info(
	            m.mat,                               /* Pointer to buffer */
	            sizeof(double),                          /* Size of one scalar */
	            py::format_descriptor<double>::format(), /* Python struct-style format descriptor */
	            2,                                      /* Number of dimensions */
	            { m.nrow(), m.ncol() },                 /* Buffer dimensions */
	            { sizeof(double),                        /* Strides (in bytes) for each index */
	              sizeof(double) * m.nrow()}
	        );
	    });
		// .def("__getitem__", py::overload_cast<int, int>(&Matrix<double>::operator()))
		//.def("__getitem__", [](const Matrix<double> &m, std::tuple<int, int> &inds) {return m(std::get<0>(inds), std::get<1>(inds)); } )
		//.def("__setitem__", py::overload_cast<int, int>(&Matrix<double>::operator()))

}
