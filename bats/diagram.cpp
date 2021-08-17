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
.def("set_edge", (void (Diagram<NT, ET>::*)(size_t, size_t, size_t, ET&))(&Diagram<NT, ET>::set_edge))\
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


#define HomFunctorInterface(MT, name) \
m.def(name, [](const Diagram<ChainComplex<MT>, ChainMap<MT>> &D, size_t k) {return Hom(D, k);});\
m.def(name, [](const Diagram<DGVectorSpace<MT>, DGLinearMap<MT>> &D, size_t k) {return Hom(D, k);});\
m.def("barcode", [](const Diagram<ReducedChainComplex<MT>, MT>& D, size_t hdim){return barcode(D, hdim); });\
m.def("barcode", [](const Diagram<ReducedDGVectorSpace<MT>, MT>& D, size_t hdim){return barcode(D, hdim); });\
m.def("barcode", [](const Diagram<size_t, MT>& D, size_t hdim){return barcode(D, hdim); });\
m.def("barcode_leftward", (std::vector<PersistencePair<size_t>> (*)(const Diagram<ReducedDGVectorSpace<MT>, MT>&, size_t))(&barcode_sparse_leftright));\
m.def("barcode_leftward", (std::vector<PersistencePair<size_t>> (*)(const Diagram<ReducedChainComplex<MT>, MT>&, size_t))(&barcode_sparse_leftright));\
m.def("barcode_leftward", (std::vector<PersistencePair<size_t>> (*)(const Diagram<size_t, MT>&, size_t))(&barcode_sparse_leftright));\
m.def("barcode_rightward", (std::vector<PersistencePair<size_t>> (*)(const Diagram<ReducedDGVectorSpace<MT>, MT>&, size_t))(&barcode_sparse_rightleft));\
m.def("barcode_rightward", (std::vector<PersistencePair<size_t>> (*)(const Diagram<ReducedChainComplex<MT>, MT>&, size_t))(&barcode_sparse_rightleft));\
m.def("barcode_rightward", (std::vector<PersistencePair<size_t>> (*)(const Diagram<size_t, MT>&, size_t))(&barcode_sparse_rightleft));\
m.def("barcode_dq", (std::vector<PersistencePair<size_t>> (*)(const Diagram<ReducedDGVectorSpace<MT>, MT>&, size_t))(&barcode_sparse_divide_conquer));\
m.def("barcode_dq", (std::vector<PersistencePair<size_t>> (*)(const Diagram<ReducedChainComplex<MT>, MT>&, size_t))(&barcode_sparse_divide_conquer));\
m.def("barcode_dq", (std::vector<PersistencePair<size_t>> (*)(const Diagram<size_t, MT>&, size_t))(&barcode_sparse_divide_conquer));


PYBIND11_MODULE(diagram, m) {

	DiagramInterface(bats::Cover, std::vector<size_t>, "CoverDiagram")
	DiagramInterface(std::set<size_t>, std::vector<size_t>, "SetDiagram")
	DiagramInterface(SimplicialComplex, CellularMap, "SimplicialComplexDiagram")
	DiagramInterface(CubicalComplex, CellularMap, "CubicalComplexDiagram")
	DiagramInterface(CellComplex, CellularMap, "CellComplexDiagram")
	DiagramInterface(F2ChainComplex, F2ChainMap, "F2ChainDiagram")
	DiagramInterface(F3ChainComplex, F3ChainMap, "F3ChainDiagram")
	DiagramInterface(ReducedF2ChainComplex, M2, "F2HomDiagram")
	DiagramInterface(ReducedF3ChainComplex, M3, "F3HomDiagram")
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
	DGLinearFunctorInterface(M2, SimplicialComplexDiagram, "F2DGLinearFunctor")

	AutoChainFunctorInterface(SimplicialComplexDiagram, F2)
	AutoChainFunctorInterface(SimplicialComplexDiagram, F3)
	AutoChainFunctorInterface(CubicalComplexDiagram, F2)
	AutoChainFunctorInterface(CubicalComplexDiagram, F3)
	AutoChainFunctorInterface(CellComplexDiagram, F2)
	AutoChainFunctorInterface(CellComplexDiagram, F3)

	SimpleChainFunctorInterface(m, F2)
	SimpleChainFunctorInterface(m, F3)

	HomFunctorInterface(M2, "Hom")
	HomFunctorInterface(M3, "Hom")

	m.def("RipsHom", [](SetDiagram& D, DataSet<double>& X, Euclidean& M, std::vector<double>& rmax, size_t hdim, F2) {return RipsHom(D, X, M, rmax, hdim, F2()); });

}
