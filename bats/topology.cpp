#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <bats.h>
#include <vector>
#include <set>

namespace py = pybind11;


#define MetricInterface(M, name) py::class_<M>(m, name)\
.def(py::init<>());

PYBIND11_MODULE(topology, m) {

	MetricInterface(Euclidean, "Euclidean")
	MetricInterface(L1Dist, "L1Dist")
	MetricInterface(LInfDist, "LInfDist")

}
