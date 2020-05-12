#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

#define DiagramInterface(NT, ET, name) py::class_<Diagram<NT, ET>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t>())\
.def("set_node", (void (Diagram<NT, ET>::*)(size_t, NT&))(&Diagram<NT, ET>::set_node))\
.def("set_edge", (void (Diagram<NT, ET>::*)(size_t, size_t, size_t, ET&))(&Diagram<NT, ET>::set_edge))\
.def("add_node", (size_t (Diagram<NT, ET>::*)(NT&))(&Diagram<NT, ET>::add_node))\
.def("add_edge", (size_t (Diagram<NT, ET>::*)(size_t, size_t, ET&))(&Diagram<NT, ET>::add_edge))\
.def("nnode", (size_t (Diagram<NT, ET>::*)())(&Diagram<NT, ET>::nnode))\
.def("nedge", (size_t (Diagram<NT, ET>::*)())(&Diagram<NT, ET>::nedge))\
.def("node_data", (NT (Diagram<NT, ET>::*)(size_t))(&Diagram<NT, ET>::node_data))\
.def("edge_data", (ET (Diagram<NT, ET>::*)(size_t))(&Diagram<NT, ET>::edge_data))\
.def("edge_source", (size_t (Diagram<NT, ET>::*)(size_t))(&Diagram<NT, ET>::edge_source))\
.def("edge_target", (size_t (Diagram<NT, ET>::*)(size_t))(&Diagram<NT, ET>::edge_target));

#define ChainFunctorInterface(MT, DT, name) m.def(name, &(Chain<MT, DT>));

#define AutoChainFunctorInterface(DT, FT) m.def("Chain", (Diagram<ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>, ChainMap<ColumnMatrix<SparseVector<FT, size_t>>>> (*)(const DT&, FT))(&__Chain));

#define HomFunctorInterface(MT, name) \
m.def(name, &(Hom<MT>));\
m.def("barcode", &(barcode<MT>));


PYBIND11_MODULE(diagram, m) {

	DiagramInterface(bats::Cover, std::vector<size_t>, "CoverDiagram")
	DiagramInterface(std::set<size_t>, std::vector<size_t>, "SetDiagram")
	DiagramInterface(SimplicialComplex, CellularMap, "SimplicialComplexDiagram")
	DiagramInterface(CellComplex, CellularMap, "CellComplexDiagram")
	DiagramInterface(F2ChainComplex, F2ChainMap, "F2ChainDiagram")
	DiagramInterface(F3ChainComplex, F3ChainMap, "F3ChainDiagram")
	DiagramInterface(ReducedF2ChainComplex, M2, "F2HomDiagram")
	DiagramInterface(ReducedF3ChainComplex, M3, "F3HomDiagram")

	// NerveFunctor
    m.def("NerveDiagram", py::overload_cast<const CoverDiagram&, const size_t>(&Nerve));

	// zigzag diagram of sets
	m.def("ZigzagSetDiagram", &linear_subset_union_diagram, "Create a zigzag diagram of sets and pairwise unions.");

	// Rips functor
	m.def("Rips", (SimplicialComplexDiagram (*)(const SetDiagram&, const DataSet<double>&, const Euclidean&, const double, const size_t))(&Rips), "Construct a diagram of Rips complexes from a SetDiagram.");
	m.def("Rips", (SimplicialComplexDiagram (*)(const SetDiagram&, const DataSet<double>&, const Euclidean&, const std::vector<double>&, const size_t))(&Rips), "Construct a diagram of Rips complexes from a SetDiagram.");

    ChainFunctorInterface(M2, SimplicialComplexDiagram, "F2Chain")
    ChainFunctorInterface(M3, SimplicialComplexDiagram, "F3Chain")

	AutoChainFunctorInterface(SimplicialComplexDiagram, F2)
	AutoChainFunctorInterface(SimplicialComplexDiagram, F3)
	AutoChainFunctorInterface(CellComplexDiagram, F2)
	AutoChainFunctorInterface(CellComplexDiagram, F3)

	HomFunctorInterface(M2, "Hom")
	HomFunctorInterface(M3, "Hom")

}
