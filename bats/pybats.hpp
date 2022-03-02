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
.def(py::init<const DGVectorSpace<MT>&, bats::standard_reduction_flag>())\
.def(py::init<const DGVectorSpace<MT>&, bats::extra_reduction_flag>())\
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
.def(py::init<const FilteredDGVectorSpace<T, MT>&, bats::standard_reduction_flag>())\
.def(py::init<const FilteredDGVectorSpace<T, MT>&, bats::standard_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const FilteredDGVectorSpace<T, MT>&, bats::standard_reduction_flag, bats::clearing_flag>())\
.def(py::init<const FilteredDGVectorSpace<T, MT>&, bats::standard_reduction_flag, bats::compression_flag>())\
.def(py::init<const FilteredDGVectorSpace<T, MT>&, bats::extra_reduction_flag>())\
.def(py::init<const FilteredDGVectorSpace<T, MT>&, bats::extra_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const FilteredDGVectorSpace<T, MT>&, bats::extra_reduction_flag, bats::clearing_flag>())\
.def(py::init<const FilteredDGVectorSpace<T, MT>&, bats::extra_reduction_flag, bats::compression_flag>())\
.def("dim", &ReducedFilteredDGVectorSpace<T, MT>::dim)\
.def("hdim", &ReducedFilteredDGVectorSpace<T, MT>::hdim)\
.def("maxdim", &ReducedFilteredDGVectorSpace<T, MT>::maxdim)\
.def("persistence_pairs", [](ReducedFilteredDGVectorSpace<T, MT>& F, size_t k){return F.persistence_pairs(k);} );

#define ReducedChainComplexInterface(MT, name) py::class_<ReducedChainComplex<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const ChainComplex<MT>&>())\
.def(py::init<const ChainComplex<MT>&, bats::standard_reduction_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::standard_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::standard_reduction_flag, bats::clearing_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::standard_reduction_flag, bats::compression_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::extra_reduction_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::extra_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::extra_reduction_flag, bats::clearing_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::extra_reduction_flag, bats::compression_flag>())\
.def("__getitem__", &ReducedChainComplex<MT>::operator[]) \
.def("U", [](ReducedChainComplex<MT> &R, size_t k){return R.U[k];}, "basis matrix in specified dimension")\
.def("R", [](ReducedChainComplex<MT> &R, size_t k){return R.R[k];}, "reduced matrix in specified dimension")\
.def("hdim", &ReducedChainComplex<MT>::hdim)\
.def("get_preferred_representative", &ReducedChainComplex<MT>::get_preferred_representative, "get the preferred representative for homology class")\
.def("chain_preferred_representative", &ReducedChainComplex<MT>::chain_preferred_representative, "return the preferred representative of a chain")\
.def("find_preferred_representative", &ReducedChainComplex<MT>::find_preferred_representative)\
.def("to_hom_basis", [](const ReducedChainComplex<MT> &R, const MT &A, size_t k) {return R.to_hom_basis(A, k);})\
.def("to_hom_basis", [](const ReducedChainComplex<MT> &R, const MT::col_type &A, size_t k) {return R.to_hom_basis(A, k);})\
.def("from_hom_basis", [](const ReducedChainComplex<MT> &R, const MT &A, size_t k) {return R.from_hom_basis(A, k);})\
.def("from_hom_basis", [](const ReducedChainComplex<MT> &R, const MT::col_type &A, size_t k) {return R.from_hom_basis(A, k);})\
.def("maxdim", &ReducedChainComplex<MT>::maxdim);

#define ReducedFilteredChainComplexInterface(T, MT, name) py::class_<ReducedFilteredChainComplex<T, MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const FilteredChainComplex<T, MT>&>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::standard_reduction_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::standard_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::standard_reduction_flag, bats::clearing_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::standard_reduction_flag, bats::compression_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::extra_reduction_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::extra_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::extra_reduction_flag, bats::clearing_flag>())\
.def("nnz_U", &ReducedFilteredChainComplex<T, MT>::get_nnz_U, "get the number of non-zeros in U")\
.def("nnz_R", &ReducedFilteredChainComplex<T, MT>::get_nnz_R, "get the number of non-zeros in R")\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::extra_reduction_flag, bats::compression_flag>())\
.def("reduced_complex", [](ReducedFilteredChainComplex<T, MT>& C){return C.RC;}, "underlying reduced complex")\
.def("val", [](ReducedFilteredChainComplex<T, MT>& C) {return C.val;}, "filtration values")\
.def("perm", [](ReducedFilteredChainComplex<T, MT>& C) {return C.perm;}, "permutation from original order")\
.def("dim", &ReducedFilteredChainComplex<T, MT>::dim)\
.def("maxdim", &ReducedFilteredChainComplex<T, MT>::maxdim)\
.def("representative", [](ReducedFilteredChainComplex<T, MT>& F, PersistencePair<T>& p){return F.representative(p, false); })\
.def("representative", [](ReducedFilteredChainComplex<T, MT>& F, PersistencePair<T>& p, bool perm){return F.representative(p, perm); })\
.def("persistence_pairs", [](ReducedFilteredChainComplex<T, MT>& F, size_t k){return F.persistence_pairs(k);} )\
.def("persistence_pairs", [](ReducedFilteredChainComplex<T, MT>& F, size_t k, bool perm){return F.persistence_pairs(k, perm);} )\
.def("persistence_pairs_vec", [](ReducedFilteredChainComplex<T, MT>& F, size_t k){return F.persistence_pairs_vec(k);} )\
.def("update_filtration", &ReducedFilteredChainComplex<T, MT>::update_filtration, "update filtration with new values")\
.def("update_filtration_general", &ReducedFilteredChainComplex<T, MT>::update_filtration_general<Update_info<Filtration<T, SimplicialComplex>>>, "generally update filtration with updating information")\
.def("update_filtration_general", &ReducedFilteredChainComplex<T, MT>::update_filtration_general<Update_info<Filtration<T, DefaultLightSimplicialComplex>>>, "generally update filtration with updating information");
