#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;
using namespace bats;


PYBIND11_MODULE(linalg_f3, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

    FieldInterface(F3, "F3")

    SparseVectorInterface(F3, "F3Vector")


    ColumnMatrixInterface(V3, "F3Mat")

    ChainComplexInterface(M3, "F3ChainComplex")

    ChainMapInterface(m, M3, "F3ChainMap")

    ReducedChainComplexInterface(M3, "ReducedF3ChainComplex")

		DGVectorSpaceInterface(M3, "F3DGVectorSpace")
		DGLinearMapInterface(m, M3, "F3DGLinearMap")
		ReducedDGVectorSpaceInterface(M3, "ReducedF3DGVectorSpace")
		FilteredDGVectorSpaceInterface(double, M3, "FilteredF3DGVectorSpace")
		ReducedFilteredDGVectorSpaceInterface(double, M3, "ReducedFilteredF3DGVectorSpace")

    FilteredChainComplexInterface(double, M3, "FilteredF3ChainComplex")


    ReducedFilteredChainComplexInterface(double, M3, "ReducedFilteredF3ChainComplex")

		DiagramInterface(F3ChainComplex, F3ChainMap, "F3ChainDiagram")
		DiagramInterface(ReducedF3ChainComplex, M3, "F3HomDiagram")
		DiagramInterface(ReducedF3ChainComplex, std::vector<M3>, "F3HomDiagramAll")
		DiagramInterface(F3DGVectorSpace, F3DGLinearMap, "F3DGLinearDiagram")
		DiagramInterface(ReducedF3DGVectorSpace, M3, "F3DGHomDiagram")
		DiagramInterface(ReducedF3DGVectorSpace, std::vector<M3>, "F3DGHomDiagramAll")
		DiagramInterface(size_t, M3, "F3Diagram")

}
