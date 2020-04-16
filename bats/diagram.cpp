#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

#define DiagramInterface(NT, ET, name) py::class_<Diagram<NT, ET>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t>())\
.def("set_node", (void (Diagram<NT, ET>::*)(size_t, NT&))(&Diagram<NT, ET>::set_node))\
.def("set_edge", (void (Diagram<NT, ET>::*)(size_t, size_t, size_t, ET&))(&Diagram<NT, ET>::set_edge));

#define ChainFunctorInterface(MT, DT, name) m.def(name, &(Chain<MT, DT>));

PYBIND11_MODULE(diagram, m) {

	DiagramInterface(bats::Cover, std::vector<size_t>, "CoverDiagram")
	DiagramInterface(std::set<size_t>, std::vector<size_t>, "SetDiagram")
	DiagramInterface(SimplicialComplex, CellularMap, "SimplicialComplexDiagram")
	DiagramInterface(F2ChainComplex, F2ChainMap, "F2ChainDiagram")
	DiagramInterface(F3ChainComplex, F3ChainMap, "F3ChainDiagram")

	// NerveFunctor
    m.def("NerveDiagram", py::overload_cast<const CoverDiagram&, const size_t>(&Nerve));

	// RipsFunctor
	// m.def("Rips", (SimplicialComplexDiagram (const SetDiagram&, const DataSet<double>&, const Euclidean&, const double, const size_t))(&Rips));

    ChainFunctorInterface(M2, SimplicialComplexDiagram, "F2Chain")
    ChainFunctorInterface(M3, SimplicialComplexDiagram, "F3Chain")

}
