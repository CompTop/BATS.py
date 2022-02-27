#pragma once
/*
header with typedefs and includes
*/

#include <vector>
#include <set>
#include <iostream>
#include <bats.hpp>

using namespace bats;

using DefaultLightSimplicialComplex = bats::LightSimplicialComplex<size_t, std::unordered_map<size_t, size_t>>;

using IntVec = SparseVector<int, size_t>;
using IntMat = ColumnMatrix<IntVec>;
using F2 = ModP<int, 2>;
using F3 = ModP<int, 3>;
using F5 = ModP<int, 5>;
using FQ = Rational<int>;

using VInt = SparseVector<int, size_t>;
using V2 = SparseVector<F2, size_t>;
using V3 = SparseVector<F3, size_t>;
using V5 = SparseVector<F5, size_t>;
using VQ = SparseVector<FQ, size_t>;

using M2 = ColumnMatrix<V2>;
using M3 = ColumnMatrix<V3>;
using M5 = ColumnMatrix<V5>;
using MQ = ColumnMatrix<VQ>;

using F2ChainComplex = ChainComplex<M2>;
using F3ChainComplex = ChainComplex<M3>;
using F5ChainComplex = ChainComplex<M5>;
using FQChainComplex = ChainComplex<MQ>;

using ReducedF2ChainComplex = ReducedChainComplex<M2>;
using ReducedF3ChainComplex = ReducedChainComplex<M3>;
using ReducedF5ChainComplex = ReducedChainComplex<M5>;
using ReducedFQChainComplex = ReducedChainComplex<MQ>;

using F2ChainMap = ChainMap<M2>;
using F3ChainMap = ChainMap<M3>;
using F5ChainMap = ChainMap<M5>;
using FQChainMap = ChainMap<MQ>;

using F2DGVectorSpace = DGVectorSpace<M2>;
using F3DGVectorSpace = DGVectorSpace<M3>;
using F2DGLinearMap = DGLinearMap<M2>;
using F3DGLinearMap = DGLinearMap<M3>;
using ReducedF2DGVectorSpace = ReducedDGVectorSpace<M2>;
using ReducedF3DGVectorSpace = ReducedDGVectorSpace<M3>;

// diagrams
using CoverDiagram = Diagram<bats::Cover, std::vector<size_t>>;
using SetDiagram = Diagram<std::set<size_t>, std::vector<size_t>>;
using SimplicialComplexDiagram = Diagram<SimplicialComplex, CellularMap>;
using CubicalComplexDiagram = Diagram<CubicalComplex, CellularMap>;
using CellComplexDiagram = Diagram<CellComplex, CellularMap>;
using F2ChainDiagram = Diagram<F2ChainComplex, F2ChainMap>;
using F3ChainDiagram = Diagram<F3ChainComplex, F3ChainMap>;
using F2DGLinearDiagram = Diagram<F2DGVectorSpace, F2DGLinearMap>;
using F3DGLinearDiagram = Diagram<F3DGVectorSpace, F3DGLinearMap>;

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

#define DGVectorSpaceInterface(MT, name) py::class_<DGVectorSpace<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const SimplicialComplex&, int>())\
.def(py::init<const SimplicialComplex&, int, bool>())\
.def(py::init<const DefaultLightSimplicialComplex&, int>())\
.def(py::init<const CubicalComplex&, int>())\
.def_readwrite("degree", &DGVectorSpace<MT>::degree)\
.def("maxdim", &DGVectorSpace<MT>::maxdim)\
.def("__getitem__", py::overload_cast<ssize_t>(&DGVectorSpace<MT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<ssize_t>(&DGVectorSpace<MT>::operator[]));

#define DGLinearMapInterface(m, MT, name) py::class_<DGLinearMap<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const CellularMap&>())\
.def("__getitem__", py::overload_cast<ssize_t>(&DGLinearMap<MT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<ssize_t>(&DGLinearMap<MT>::operator[]));

#define ReducedDGVectorSpaceInterface(MT, name) py::class_<ReducedDGVectorSpace<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const DGVectorSpace<MT>&>())\
.def("hdim", &ReducedDGVectorSpace<MT>::hdim)\
.def("maxdim", &ReducedDGVectorSpace<MT>::maxdim);

#define FilteredDGVectorSpaceInterface(T, MT, name) py::class_<FilteredDGVectorSpace<T, MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const Filtration<T, SimplicialComplex>&, int>())\
.def(py::init<const Filtration<T, DefaultLightSimplicialComplex>&, int>())\
.def(py::init<const Filtration<T, CubicalComplex>&, int>())\
.def("val", [](FilteredDGVectorSpace<T, MT>& C) {return C.val;}, "filtration values.")\
.def("perm", [](FilteredDGVectorSpace<T, MT>& C) {return C.perm;}, "permutation from original order")\
.def("update_filtration", &FilteredDGVectorSpace<T, MT>::update_filtration, "update filtration with new values");

#define ReducedFilteredDGVectorSpaceInterface(T, MT, name) py::class_<ReducedFilteredDGVectorSpace<T, MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const FilteredDGVectorSpace<T, MT>&>())\
.def("dim", &ReducedFilteredDGVectorSpace<T, MT>::dim)\
.def("hdim", &ReducedFilteredDGVectorSpace<T, MT>::hdim)\
.def("maxdim", &ReducedFilteredDGVectorSpace<T, MT>::maxdim)\
.def("persistence_pairs", [](ReducedFilteredDGVectorSpace<T, MT>& F, size_t k){return F.persistence_pairs(k);} );
