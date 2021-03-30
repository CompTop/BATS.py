#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <pybind11/numpy.h>
#include <pybind11/buffer_info.h>


namespace py = pybind11;
using namespace bats;

PYBIND11_MODULE(dense, m) {

	py::class_< Matrix<double> >(m, "Matrix", py::buffer_protocol())
		.def(py::init<>())
		.def(py::init<size_t, size_t>())
		.def("nrow", &Matrix<double>::nrow)
		.def("ncol", &Matrix<double>::ncol)
		.def("__call__", py::overload_cast<int, int>(&Matrix<double>::operator(), py::const_))
		.def("__init__", [](Matrix<double> &m, py::buffer b) {
			// WARNING: this has the side-effect of transposing the matrix if not
			// in row major order

	        /* Request a buffer descriptor from Python */
	        py::buffer_info info = b.request();

	        /* Some sanity checks ... */
	        if (info.format != py::format_descriptor<double>::format())
	            throw std::runtime_error("Incompatible format: expected a double array!");

	        if (info.ndim != 2)
	            throw std::runtime_error("Incompatible buffer dimension!");

			size_t nrow = info.shape[0];
			size_t ncol = info.shape[1];

			if (info.strides[0] == sizeof(double)) {
				// transpose matrix
				nrow = info.shape[1];
				ncol = info.shape[0];
			}

	        new (&m) Matrix<double>(nrow, ncol, (double*) info.ptr);
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
	            { sizeof(double) * m.ncol(),                        /* Strides (in bytes) for each index */
	              sizeof(double)}
	        );
	    })
		.def("__getitem__", [](const Matrix<double> &m, std::vector<int> &inds) {return m(inds[0], inds[1]); } );
		// .def("__getitem__", py::overload_cast<int, int>(&Matrix<double>::operator(), py::const_))
		// .def("__getitem__", py::overload_cast<int, int>(&Matrix<double>::operator()))
		//.def("__setitem__", py::overload_cast<int, int>(&Matrix<double>::operator()))

		py::class_<DataSet<double>>(m, "DataSet")
			.def(py::init<>())
			.def(py::init<const Matrix<double>& >())
			.def("size", &DataSet<double>::size)
			.def("data", &DataSet<double>::get_data)
			.def("dim", &DataSet<double>::dim);

}
