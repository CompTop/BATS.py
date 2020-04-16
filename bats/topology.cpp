#include "pybats.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>


namespace py = pybind11;


#define MetricInterface(M, name) py::class_<M>(m, name)\
.def(py::init<>())\
.def("__call__", (Matrix<double> (M::*)(const DataSet<double>&, const DataSet<double>&) const)(&M::operator()), "returns Matrix of pairwise distances");


#define FilteredEdgeInterface(T, name) py::class_<filtered_edge<T>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t, T>());

// define filtration interfaces for metric
#define FiltrationInterface(M) \
m.def("RipsFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const M&, double, size_t))(&RipsFiltration));\
m.def("RipsCoverFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const bats::Cover&, const M&, double, size_t))(&RipsFiltration));\
m.def("DowkerFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const DataSet<double>&, const M&, double, size_t))(&DowkerFiltration));\
m.def("DowkerCoverFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const DataSet<double>&, const M&, const bats::Cover&, double, size_t))(&DowkerFiltration));

// define landmark interfaces for metric
#define LandmarkInterface(M) \
m.def("greedy_landmarks", (DataSet<double> (*)(const DataSet<double>&, const size_t, const M&, const size_t))(&greedy_landmarks));\
m.def("landmark_cover", (bats::Cover (*)(const DataSet<double>&, const DataSet<double>&, const M&, const size_t))(&landmark_cover));

#define MetricInterfaceAll(M, name) \
MetricInterface(M, name)\
FiltrationInterface(M)\
LandmarkInterface(M)


PYBIND11_MODULE(topology, m) {

	MetricInterfaceAll(Euclidean, "Euclidean")
	MetricInterfaceAll(L1Dist, "L1Dist")
	MetricInterfaceAll(LInfDist, "LInfDist")
	MetricInterfaceAll(CosineDist, "CosineDist")
	MetricInterfaceAll(RPCosineDist, "RPCosineDist")
	MetricInterfaceAll(AngleDist, "AngleDist")
	MetricInterfaceAll(RPAngleDist, "RPAngleDist")

	FilteredEdgeInterface(double, "FilteredEdge")

	m.def("bivariate_cover", &bivariate_cover);

	//RipsFiltrationInterface(Euclidean)
	//RipsFiltrationInterface(L1Dist)

	m.def("FlagFiltration", (Filtration<double, SimplicialComplex> (*)(std::vector<filtered_edge<double>>&, const size_t, const size_t, const double))(&FlagFiltration));
	m.def("WitnessFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const DataSet<double>&, const Euclidean&, double, size_t))(&WitnessFiltration));
	m.def("DowkerFiltration", (Filtration<double, SimplicialComplex> (*)(const Matrix<double>&, double, size_t))(&DowkerFiltration));
	m.def("DowkerCoverFiltration", (Filtration<double, SimplicialComplex> (*)(const Matrix<double>&, const bats::Cover&, double, size_t))(&DowkerFiltration));

	m.def("Nerve", (SimplicialComplex (*)(const bats::Cover&, const size_t))(&Nerve));

	m.def("sample_sphere", (DataSet<double> (*)(const size_t, const size_t))(&sample_sphere));
	m.def("force_repel_rp", (void (*)(DataSet<double>&, double))(&force_repel_rp));
}
