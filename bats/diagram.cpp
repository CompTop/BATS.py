#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;
using namespace bats;

#define DiagramInterface(NT, ET, name) py::class_<Diagram<NT, ET>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t>())\
.def("set_node", (void (Diagram<NT, ET>::*)(size_t, NT&))(&Diagram<NT, ET>::set_node))\
.def("set_edge", (void (Diagram<NT, ET>::*)(size_t, size_t, size_t, const ET&))(&Diagram<NT, ET>::set_edge))\
.def("add_node", (size_t (Diagram<NT, ET>::*)(NT&))(&Diagram<NT, ET>::add_node))\
.def("add_edge", (size_t (Diagram<NT, ET>::*)(size_t, size_t, ET&))(&Diagram<NT, ET>::add_edge))\
.def("nnode", (size_t (Diagram<NT, ET>::*)())(&Diagram<NT, ET>::nnode))\
.def("nedge", (size_t (Diagram<NT, ET>::*)())(&Diagram<NT, ET>::nedge))\
.def("node_data", [](Diagram<NT, ET>& D, size_t k){return D.node_data(k);})\
.def("edge_data", [](Diagram<NT, ET>& D, size_t k){return D.edge_data(k);})\
.def("edge_source", [](Diagram<NT, ET>& D, size_t k){return D.edge_source(k);})\
.def("edge_target", [](Diagram<NT, ET>& D, size_t k){return D.edge_target(k);});

#define ChainFunctorInterface(MT, DT, name)\
m.def(name, [](const DT& diag) {return ChainFunctor<MT>(diag);});\
m.def("ChainFunctor", [](const DT& diag, typename MT::val_type) {return ChainFunctor(diag, typename MT::val_type());});

#define DGLinearFunctorInterface(MT, DT, name) m.def(name, &(DGLinearFunctor<MT, DT>));

#define AutoChainFunctorInterface(DT, FT) \
m.def("Chain", (Diagram<ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>, ChainMap<ColumnMatrix<SparseVector<FT, size_t>>>> (*)(const DT&, FT))(&__ChainFunctor)); \

#define SimpleChainFunctorInterface(m, FT) \
m.def("Chain", [](const CellularMap & A, FT) { return ChainMap<ColumnMatrix<SparseVector<FT, size_t>>>(A); });\
m.def("Chain", [](const CellularMap & f, const SimplicialComplex &X, const SimplicialComplex &A, const SimplicialComplex &Y, const SimplicialComplex &B, FT) { return ChainMap<ColumnMatrix<SparseVector<FT, size_t>>>(f, X, A, Y, B); });\
m.def("Chain", [](const SimplicialComplex &X, FT) {return ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>(X); });\
m.def("Chain", [](const SimplicialComplex &X, const SimplicialComplex &A, FT) {return ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>(X, A); });\
m.def("Chain", [](const CubicalComplex &X, FT) {return ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>(X); });\
m.def("Chain", [](const CellComplex &X, FT) {return ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>(X); });

#define FlagInterface(T, name) py::class_<T>(m, name) \
	.def(py::init<>());

#define BarcodeInterface(NT, MT) \
m.def("barcode", [](const Diagram<NT, MT>& D, size_t hdim){return barcode(D, hdim); });\
m.def("barcode", [](const Diagram<NT, MT>& D, size_t hdim, flags::divide_conquer){return barcode(D, hdim, flags::divide_conquer()); });\
m.def("barcode", [](const Diagram<NT, MT>& D, size_t hdim, flags::rightward){return barcode(D, hdim, flags::rightward()); });\
m.def("barcode", [](const Diagram<NT, MT>& D, size_t hdim, flags::leftward){return barcode(D, hdim, flags::leftward()); });\
m.def("barcode", [](const Diagram<NT, std::vector<MT>>& D){return barcode(D); });\
m.def("barcode", [](const Diagram<NT, std::vector<MT>>& D, flags::divide_conquer){return barcode(D, flags::divide_conquer()); });\
m.def("barcode", [](const Diagram<NT, std::vector<MT>>& D, flags::rightward){return barcode(D, flags::rightward()); });\
m.def("barcode", [](const Diagram<NT, std::vector<MT>>& D, flags::leftward){return barcode(D, flags::leftward()); });



#define HomFunctorInterface(MT, name) \
m.def(name, [](const Diagram<ChainComplex<MT>, ChainMap<MT>> &D, size_t k) {return Hom(D, k);});\
m.def(name, [](const Diagram<DGVectorSpace<MT>, DGLinearMap<MT>> &D, size_t k) {return Hom(D, k);});\
m.def(name, [](const Diagram<ChainComplex<MT>, ChainMap<MT>> &D) {return Hom(D);});\
m.def(name, [](const Diagram<ChainComplex<MT>, ChainMap<MT>> &D, bool topd) {return Hom(D, topd);});\
BarcodeInterface(ReducedChainComplex<MT>, MT)\
BarcodeInterface(ReducedDGVectorSpace<MT>, MT)\
BarcodeInterface(int, MT)


PYBIND11_MODULE(diagram, m) {

	DiagramInterface(bats::Cover, std::vector<size_t>, "CoverDiagram")
	DiagramInterface(std::set<size_t>, std::vector<size_t>, "SetDiagram")
	DiagramInterface(SimplicialComplex, CellularMap, "SimplicialComplexDiagram")
	DiagramInterface(CubicalComplex, CellularMap, "CubicalComplexDiagram")
	DiagramInterface(CellComplex, CellularMap, "CellComplexDiagram")
	DiagramInterface(F2ChainComplex, F2ChainMap, "F2ChainDiagram")
	DiagramInterface(F3ChainComplex, F3ChainMap, "F3ChainDiagram")
	DiagramInterface(ReducedF2ChainComplex, M2, "F2HomDiagram")
	DiagramInterface(ReducedF2ChainComplex, std::vector<M2>, "F2HomDiagramAll")
	DiagramInterface(ReducedF3ChainComplex, M3, "F3HomDiagram")
	DiagramInterface(ReducedF3ChainComplex, std::vector<M3>, "F3HomDiagramAll")
	DiagramInterface(F2DGVectorSpace, F2DGLinearMap, "F2DGLinearDiagram")
	DiagramInterface(F3DGVectorSpace, F3DGLinearMap, "F3DGLinearDiagram")
	DiagramInterface(ReducedF2DGVectorSpace, M2, "F2DGHomDiagram")
	DiagramInterface(ReducedF3DGVectorSpace, M3, "F3DGHomDiagram")
	DiagramInterface(size_t, M2, "F2Diagram")
	DiagramInterface(size_t, M3, "F3Diagram")

	// NerveFunctor
    m.def("NerveDiagram", py::overload_cast<const CoverDiagram&, const size_t>(&Nerve));

	// zigzag diagram of sets
	m.def("ZigzagSetDiagram", &linear_subset_union_diagram, "Create a zigzag diagram of sets and pairwise unions.");

	// Rips functor
	m.def("Rips", (SimplicialComplexDiagram (*)(const SetDiagram&, const DataSet<double>&, const Euclidean&, const double, const size_t))(&Rips), "Construct a diagram of Rips complexes from a SetDiagram.");
	m.def("Rips", (SimplicialComplexDiagram (*)(const SetDiagram&, const DataSet<double>&, const Euclidean&, const std::vector<double>&, const size_t))(&Rips), "Construct a diagram of Rips complexes from a SetDiagram.");

    ChainFunctorInterface(M2, SimplicialComplexDiagram, "F2Chain")
    ChainFunctorInterface(M3, SimplicialComplexDiagram, "F3Chain")

	DGLinearFunctorInterface(M2, SimplicialComplexDiagram, "F2DGLinearFunctor")
	DGLinearFunctorInterface(M2, CubicalComplexDiagram, "F2DGLinearFunctor")

	AutoChainFunctorInterface(SimplicialComplexDiagram, F2)
	AutoChainFunctorInterface(SimplicialComplexDiagram, F3)
	AutoChainFunctorInterface(CubicalComplexDiagram, F2)
	AutoChainFunctorInterface(CubicalComplexDiagram, F3)
	AutoChainFunctorInterface(CellComplexDiagram, F2)
	AutoChainFunctorInterface(CellComplexDiagram, F3)

	SimpleChainFunctorInterface(m, F2)
	SimpleChainFunctorInterface(m, F3)

	FlagInterface(flags::divide_conquer, "divide_conquer")
	FlagInterface(flags::rightward, "rightward")
	FlagInterface(flags::leftward, "leftward")

	HomFunctorInterface(M2, "Hom")
	HomFunctorInterface(M3, "Hom")

	m.def("RipsHom", [](SetDiagram& D, DataSet<double>& X, Euclidean& M, std::vector<double>& rmax, size_t hdim, F2) {return RipsHom(D, X, M, rmax, hdim, F2()); });

}
