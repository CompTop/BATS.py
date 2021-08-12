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
