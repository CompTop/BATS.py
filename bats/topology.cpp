#include "pybats.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>


namespace py = pybind11;


#define MetricInterface(M, name) py::class_<M>(m, name)\
.def(py::init<>());

PYBIND11_MODULE(topology, m) {

	MetricInterface(Euclidean, "Euclidean")
	MetricInterface(L1Dist, "L1Dist")
	MetricInterface(LInfDist, "LInfDist")

	m.def("bivariate_cover", &bivariate_cover);

	py::class_<DataSet<double>>(m, "DataSet")
		.def(py::init<>())
		.def(py::init<const Matrix<double>& >())
		.def("size", &DataSet<double>::size)
		.def("dim", &DataSet<double>::dim);

}
