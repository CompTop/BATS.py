#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;
using namespace bats;


PYBIND11_MODULE(linalg_f2, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";


		BasicFieldInterface(F2, "F2")
		      .def("__neg__", py::overload_cast<>(&F2::operator-));

		SparseVectorInterface(F2, "F2Vector")

		ColumnMatrixInterface(V2, "F2Mat")

		ChainComplexInterface(M2, "F2ChainComplex")

		ChainMapInterface(m, M2, "F2ChainMap")

		ReducedChainComplexInterface(M2, "ReducedF2ChainComplex")

		DGVectorSpaceInterface(M2, "F2DGVectorSpace")
		DGLinearMapInterface(m, M2, "F2DGLinearMap")
		ReducedDGVectorSpaceInterface(M2, "ReducedF2DGVectorSpace")
		FilteredDGVectorSpaceInterface(double, M2, "FilteredF2DGVectorSpace")
		ReducedFilteredDGVectorSpaceInterface(double, M2, "ReducedFilteredF2DGVectorSpace")

		FilteredChainComplexInterface(double, M2, "FilteredF2ChainComplex")

		ReducedFilteredChainComplexInterface(double, M2, "ReducedFilteredF2ChainComplex")

		DiagramInterface(F2ChainComplex, F2ChainMap, "F2ChainDiagram")
		DiagramInterface(ReducedF2ChainComplex, M2, "F2HomDiagram")
		DiagramInterface(ReducedF2ChainComplex, std::vector<M2>, "F2HomDiagramAll")
		DiagramInterface(F2DGVectorSpace, F2DGLinearMap, "F2DGLinearDiagram")
		DiagramInterface(ReducedF2DGVectorSpace, M2, "F2DGHomDiagram")
		DiagramInterface(ReducedF2DGVectorSpace, std::vector<M2>, "F2DGHomDiagramAll")
		DiagramInterface(size_t, M2, "F2Diagram")

}
