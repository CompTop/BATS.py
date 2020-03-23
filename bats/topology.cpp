#include "pybats.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>


namespace py = pybind11;


#define MetricInterface(M, name) py::class_<M>(m, name)\
.def(py::init<>());


#define FilteredEdgeInterface(T, name) py::class_<filtered_edge<T>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t, T>());


PYBIND11_MODULE(topology, m) {

	MetricInterface(Euclidean, "Euclidean")
	MetricInterface(L1Dist, "L1Dist")
	MetricInterface(LInfDist, "LInfDist")

	FilteredEdgeInterface(double, "FilteredEdge")

	m.def("bivariate_cover", &bivariate_cover);

	py::class_<DataSet<double>>(m, "DataSet")
		.def(py::init<>())
		.def(py::init<const Matrix<double>& >())
		.def("size", &DataSet<double>::size)
		.def("dim", &DataSet<double>::dim);

	m.def("FlagFiltration", (Filtration<double, SimplicialComplex> (*)(std::vector<filtered_edge<double>>&, const size_t, const size_t, const double))(&FlagFiltration));
	m.def("RipsFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const Euclidean&, double, size_t))(&RipsFiltration));
	m.def("WitnessFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const DataSet<double>&, const Euclidean&, double, size_t))(&WitnessFiltration));
	m.def("RipsCoverFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const bats::Cover&, const Euclidean&, double, size_t))(&RipsFiltration));

	m.def("greedy_landmarks", (DataSet<double> (*)(const DataSet<double>&, const size_t, const Euclidean&, const size_t))(&greedy_landmarks));
	m.def("landmark_cover", (bats::Cover (*)(const DataSet<double>&, const DataSet<double>&, const Euclidean&, const size_t))(&landmark_cover));
}
