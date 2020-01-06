#pragma once

/*
header with typedefs and includes
*/


#include <vector>
#include <set>
#include <iostream>

#include <bats.h>

using IntVec = SparseVector<int, size_t>;
using IntMat = ColumnMatrix<IntVec>;
using F2 = ModP<int, 2>;
using F3 = ModP<int, 3>;
using F5 = ModP<int, 5>;

using VInt = SparseVector<int, size_t>;
using V2 = SparseVector<F2, size_t>;
using V3 = SparseVector<F3, size_t>;
using V5 = SparseVector<F5, size_t>;

using M2 = ColumnMatrix<V2>;
using M3 = ColumnMatrix<V3>;

using F2ChainComplex = ChainComplex<M2>;
using F3ChainComplex = ChainComplex<M3>;

using F2ChainMap = ChainMap<M2>;
using F3ChainMap = ChainMap<M3>;

// diagrams
using CoverDiagram = Diagram<bats::Cover, std::vector<size_t>>;
using SetDiagram = Diagram<std::set<size_t>, std::vector<size_t>>;
using SimplicialComplexDiagram = Diagram<SimplicialComplex, CellularMap>;
using F2ChainDiagram = Diagram<F2ChainComplex, F2ChainMap>;
using F3ChainDiagram = Diagram<F3ChainComplex, F3ChainMap>;
