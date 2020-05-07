## AngleDist
### __init__
__init__(self: bats.topology.AngleDist) -> None

## CSCMatrix
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.CSCMatrix) -> None

2. __init__(self: bats.libbats.CSCMatrix, arg0: int, arg1: int, arg2: List[int], arg3: List[int], arg4: List[int]) -> None

### print
print(self: bats.libbats.CSCMatrix) -> None

## CellularMap
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.CellularMap) -> None

2. __init__(self: bats.libbats.CellularMap, arg0: int) -> None

## CosineDist
### __init__
__init__(self: bats.topology.CosineDist) -> None

## CoverDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.CoverDiagram) -> None

2. __init__(self: bats.diagram.CoverDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.CoverDiagram, arg0: int, arg1: int, arg2: List[int]) -> int

### add_node
add_node(self: bats.diagram.CoverDiagram, arg0: List[Set[int]]) -> int

### edge_data
edge_data(self: bats.diagram.CoverDiagram, arg0: int) -> List[int]

### edge_source
edge_source(self: bats.diagram.CoverDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.CoverDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.CoverDiagram) -> int

### nnode
nnode(self: bats.diagram.CoverDiagram) -> int

### node_data
node_data(self: bats.diagram.CoverDiagram, arg0: int) -> List[Set[int]]

### set_edge
set_edge(self: bats.diagram.CoverDiagram, arg0: int, arg1: int, arg2: int, arg3: List[int]) -> None

### set_node
set_node(self: bats.diagram.CoverDiagram, arg0: int, arg1: List[Set[int]]) -> None

## DataSet
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.dense.DataSet) -> None

2. __init__(self: bats.dense.DataSet, arg0: bats.dense.Matrix) -> None

### data
data(self: bats.dense.DataSet) -> bats.dense.Matrix

### dim
dim(self: bats.dense.DataSet) -> int

### size
size(self: bats.dense.DataSet) -> int

## DowkerCoverFiltration
DowkerCoverFiltration(*args, **kwargs)
Overloaded function.

1. DowkerCoverFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.Euclidean, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

2. DowkerCoverFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.L1Dist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

3. DowkerCoverFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.LInfDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

4. DowkerCoverFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.CosineDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

5. DowkerCoverFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.RPCosineDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

6. DowkerCoverFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.AngleDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

7. DowkerCoverFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.RPAngleDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

8. DowkerCoverFiltration(arg0: A<Dense<double, RowMaj> >, arg1: List[Set[int]], arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

## DowkerFiltration
DowkerFiltration(*args, **kwargs)
Overloaded function.

1. DowkerFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.Euclidean, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

2. DowkerFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.L1Dist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

3. DowkerFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.LInfDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

4. DowkerFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.CosineDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

5. DowkerFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.RPCosineDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

6. DowkerFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.AngleDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

7. DowkerFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.RPAngleDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

8. DowkerFiltration(arg0: A<Dense<double, RowMaj> >, arg1: float, arg2: int) -> bats.libbats.FilteredSimplicialComplex

## Euclidean
### __init__
__init__(self: bats.topology.Euclidean) -> None

## F2
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2) -> None

2. __init__(self: bats.libbats.F2, arg0: int) -> None

## F2Chain
F2Chain(arg0: bats.diagram.SimplicialComplexDiagram) -> bats.diagram.F2ChainDiagram

## F2ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2ChainComplex) -> None

2. __init__(self: bats.libbats.F2ChainComplex, arg0: bats.libbats.SimplicialComplex) -> None

## F2ChainDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.F2ChainDiagram) -> None

2. __init__(self: bats.diagram.F2ChainDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.F2ChainDiagram, arg0: int, arg1: int, arg2: bats.libbats.F2ChainMap) -> int

### add_node
add_node(self: bats.diagram.F2ChainDiagram, arg0: bats.libbats.F2ChainComplex) -> int

### edge_data
edge_data(self: bats.diagram.F2ChainDiagram, arg0: int) -> bats.libbats.F2ChainMap

### edge_source
edge_source(self: bats.diagram.F2ChainDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.F2ChainDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.F2ChainDiagram) -> int

### nnode
nnode(self: bats.diagram.F2ChainDiagram) -> int

### node_data
node_data(self: bats.diagram.F2ChainDiagram, arg0: int) -> bats.libbats.F2ChainComplex

### set_edge
set_edge(self: bats.diagram.F2ChainDiagram, arg0: int, arg1: int, arg2: int, arg3: bats.libbats.F2ChainMap) -> None

### set_node
set_node(self: bats.diagram.F2ChainDiagram, arg0: int, arg1: bats.libbats.F2ChainComplex) -> None

## F2ChainMap
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2ChainMap) -> None

2. __init__(self: bats.libbats.F2ChainMap, arg0: bats.libbats.CellularMap) -> None

## F2HomDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.F2HomDiagram) -> None

2. __init__(self: bats.diagram.F2HomDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.F2HomDiagram, arg0: int, arg1: int, arg2: bats.libbats.F2Mat) -> int

### add_node
add_node(self: bats.diagram.F2HomDiagram, arg0: bats.libbats.ReducedF2ChainComplex) -> int

### edge_data
edge_data(self: bats.diagram.F2HomDiagram, arg0: int) -> bats.libbats.F2Mat

### edge_source
edge_source(self: bats.diagram.F2HomDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.F2HomDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.F2HomDiagram) -> int

### nnode
nnode(self: bats.diagram.F2HomDiagram) -> int

### node_data
node_data(self: bats.diagram.F2HomDiagram, arg0: int) -> bats.libbats.ReducedF2ChainComplex

### set_edge
set_edge(self: bats.diagram.F2HomDiagram, arg0: int, arg1: int, arg2: int, arg3: bats.libbats.F2Mat) -> None

### set_node
set_node(self: bats.diagram.F2HomDiagram, arg0: int, arg1: bats.libbats.ReducedF2ChainComplex) -> None

## F2Mat
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2Mat) -> None

2. __init__(self: bats.libbats.F2Mat, arg0: int, arg1: int) -> None

### print
print(self: bats.libbats.F2Mat) -> None

## F2Vector
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2Vector) -> None

2. __init__(self: bats.libbats.F2Vector, arg0: List[int], arg1: List[bats.libbats.F2]) -> None

### nzinds
nzinds(self: bats.libbats.F2Vector) -> List[int]

### print
print(self: bats.libbats.F2Vector) -> None

## F3
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3) -> None

2. __init__(self: bats.libbats.F3, arg0: int) -> None

## F3Chain
F3Chain(arg0: bats.diagram.SimplicialComplexDiagram) -> bats.diagram.F3ChainDiagram

## F3ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3ChainComplex) -> None

2. __init__(self: bats.libbats.F3ChainComplex, arg0: bats.libbats.SimplicialComplex) -> None

## F3ChainDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.F3ChainDiagram) -> None

2. __init__(self: bats.diagram.F3ChainDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.F3ChainDiagram, arg0: int, arg1: int, arg2: bats.libbats.F3ChainMap) -> int

### add_node
add_node(self: bats.diagram.F3ChainDiagram, arg0: bats.libbats.F3ChainComplex) -> int

### edge_data
edge_data(self: bats.diagram.F3ChainDiagram, arg0: int) -> bats.libbats.F3ChainMap

### edge_source
edge_source(self: bats.diagram.F3ChainDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.F3ChainDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.F3ChainDiagram) -> int

### nnode
nnode(self: bats.diagram.F3ChainDiagram) -> int

### node_data
node_data(self: bats.diagram.F3ChainDiagram, arg0: int) -> bats.libbats.F3ChainComplex

### set_edge
set_edge(self: bats.diagram.F3ChainDiagram, arg0: int, arg1: int, arg2: int, arg3: bats.libbats.F3ChainMap) -> None

### set_node
set_node(self: bats.diagram.F3ChainDiagram, arg0: int, arg1: bats.libbats.F3ChainComplex) -> None

## F3ChainMap
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3ChainMap) -> None

2. __init__(self: bats.libbats.F3ChainMap, arg0: bats.libbats.CellularMap) -> None

## F3HomDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.F3HomDiagram) -> None

2. __init__(self: bats.diagram.F3HomDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.F3HomDiagram, arg0: int, arg1: int, arg2: bats.libbats.F3Mat) -> int

### add_node
add_node(self: bats.diagram.F3HomDiagram, arg0: bats.libbats.ReducedF3ChainComplex) -> int

### edge_data
edge_data(self: bats.diagram.F3HomDiagram, arg0: int) -> bats.libbats.F3Mat

### edge_source
edge_source(self: bats.diagram.F3HomDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.F3HomDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.F3HomDiagram) -> int

### nnode
nnode(self: bats.diagram.F3HomDiagram) -> int

### node_data
node_data(self: bats.diagram.F3HomDiagram, arg0: int) -> bats.libbats.ReducedF3ChainComplex

### set_edge
set_edge(self: bats.diagram.F3HomDiagram, arg0: int, arg1: int, arg2: int, arg3: bats.libbats.F3Mat) -> None

### set_node
set_node(self: bats.diagram.F3HomDiagram, arg0: int, arg1: bats.libbats.ReducedF3ChainComplex) -> None

## F3Mat
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3Mat) -> None

2. __init__(self: bats.libbats.F3Mat, arg0: int, arg1: int) -> None

### print
print(self: bats.libbats.F3Mat) -> None

## F3Vector
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3Vector) -> None

2. __init__(self: bats.libbats.F3Vector, arg0: List[int], arg1: List[bats.libbats.F3]) -> None

### nzinds
nzinds(self: bats.libbats.F3Vector) -> List[int]

### print
print(self: bats.libbats.F3Vector) -> None

## F5
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F5) -> None

2. __init__(self: bats.libbats.F5, arg0: int) -> None

## F5ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F5ChainComplex) -> None

2. __init__(self: bats.libbats.F5ChainComplex, arg0: bats.libbats.SimplicialComplex) -> None

## F5ChainMap
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F5ChainMap) -> None

2. __init__(self: bats.libbats.F5ChainMap, arg0: bats.libbats.CellularMap) -> None

## FilteredEdge
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.topology.FilteredEdge) -> None

2. __init__(self: bats.topology.FilteredEdge, arg0: int, arg1: int, arg2: float) -> None

## FilteredF2ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.FilteredF2ChainComplex) -> None

2. __init__(self: bats.libbats.FilteredF2ChainComplex, arg0: bats.libbats.FilteredSimplicialComplex) -> None

## FilteredF3ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.FilteredF3ChainComplex) -> None

2. __init__(self: bats.libbats.FilteredF3ChainComplex, arg0: bats.libbats.FilteredSimplicialComplex) -> None

## FilteredF5ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.FilteredF5ChainComplex) -> None

2. __init__(self: bats.libbats.FilteredF5ChainComplex, arg0: bats.libbats.FilteredSimplicialComplex) -> None

## FilteredRationalChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.FilteredRationalChainComplex) -> None

2. __init__(self: bats.libbats.FilteredRationalChainComplex, arg0: bats.libbats.FilteredSimplicialComplex) -> None

## FilteredSimplicialComplex
### __init__
__init__(self: bats.libbats.FilteredSimplicialComplex) -> None

### add
add(self: bats.libbats.FilteredSimplicialComplex, arg0: float, arg1: List[int]) -> bats.libbats.cell_ind

### all_vals
all_vals(self: bats.libbats.FilteredSimplicialComplex) -> List[List[float]]

### complex
complex(self: bats.libbats.FilteredSimplicialComplex) -> bats.libbats.SimplicialComplex

### maxdim
maxdim(self: bats.libbats.FilteredSimplicialComplex) -> int

### ncells
ncells(self: bats.libbats.FilteredSimplicialComplex, arg0: int) -> int

### vals
vals(self: bats.libbats.FilteredSimplicialComplex, arg0: int) -> List[float]

## FlagFiltration
FlagFiltration(arg0: List[bats.topology.FilteredEdge], arg1: int, arg2: int, arg3: float) -> bats.libbats.FilteredSimplicialComplex

## Hom
Hom(*args, **kwargs)
Overloaded function.

1. Hom(arg0: bats.diagram.F2ChainDiagram, arg1: int) -> bats.diagram.F2HomDiagram

2. Hom(arg0: bats.diagram.F3ChainDiagram, arg1: int) -> bats.diagram.F3HomDiagram

## IntMat
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.IntMat) -> None

2. __init__(self: bats.libbats.IntMat, arg0: int, arg1: int) -> None

### print
print(self: bats.libbats.IntMat) -> None

## IntVector
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.IntVector) -> None

2. __init__(self: bats.libbats.IntVector, arg0: List[int], arg1: List[int]) -> None

### nzinds
nzinds(self: bats.libbats.IntVector) -> List[int]

### print
print(self: bats.libbats.IntVector) -> None

## L1Dist
### __init__
__init__(self: bats.topology.L1Dist) -> None

## LInfDist
### __init__
__init__(self: bats.topology.LInfDist) -> None

## Matrix
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.dense.Matrix) -> None

2. __init__(self: bats.dense.Matrix, arg0: int, arg1: int) -> None

3. __init__(self: bats.dense.Matrix, arg0: buffer) -> None

### ncol
ncol(self: bats.dense.Matrix) -> int

### nrow
nrow(self: bats.dense.Matrix) -> int

### print
print(self: bats.dense.Matrix) -> None

## Nerve
Nerve(arg0: List[Set[int]], arg1: int) -> bats.libbats.SimplicialComplex

## NerveDiagram
NerveDiagram(arg0: bats.diagram.CoverDiagram, arg1: int) -> bats.diagram.SimplicialComplexDiagram

## PersistencePair
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.PersistencePair) -> None

2. __init__(self: bats.libbats.PersistencePair, arg0: int, arg1: int, arg2: int, arg3: float, arg4: float) -> None

### birth
birth(self: bats.libbats.PersistencePair) -> float

### birth_ind
birth_ind(self: bats.libbats.PersistencePair) -> int

### death
death(self: bats.libbats.PersistencePair) -> float

### death_ind
death_ind(self: bats.libbats.PersistencePair) -> int

### dim
dim(self: bats.libbats.PersistencePair) -> int

### length
length(self: bats.libbats.PersistencePair) -> float

### mid
mid(self: bats.libbats.PersistencePair) -> float

## PersistencePair_int
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.PersistencePair_int) -> None

2. __init__(self: bats.libbats.PersistencePair_int, arg0: int, arg1: int, arg2: int, arg3: int, arg4: int) -> None

### birth
birth(self: bats.libbats.PersistencePair_int) -> int

### birth_ind
birth_ind(self: bats.libbats.PersistencePair_int) -> int

### death
death(self: bats.libbats.PersistencePair_int) -> int

### death_ind
death_ind(self: bats.libbats.PersistencePair_int) -> int

### dim
dim(self: bats.libbats.PersistencePair_int) -> int

### length
length(self: bats.libbats.PersistencePair_int) -> int

### mid
mid(self: bats.libbats.PersistencePair_int) -> int

## RPAngleDist
### __init__
__init__(self: bats.topology.RPAngleDist) -> None

## RPCosineDist
### __init__
__init__(self: bats.topology.RPCosineDist) -> None

## Rational
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.Rational) -> None

2. __init__(self: bats.libbats.Rational, arg0: int) -> None

## RationalChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.RationalChainComplex) -> None

2. __init__(self: bats.libbats.RationalChainComplex, arg0: bats.libbats.SimplicialComplex) -> None

## RationalChainMap
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.RationalChainMap) -> None

2. __init__(self: bats.libbats.RationalChainMap, arg0: bats.libbats.CellularMap) -> None

## RationalMat
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.RationalMat) -> None

2. __init__(self: bats.libbats.RationalMat, arg0: int, arg1: int) -> None

### print
print(self: bats.libbats.RationalMat) -> None

## RationalVector
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.RationalVector) -> None

2. __init__(self: bats.libbats.RationalVector, arg0: List[int], arg1: List[bats.libbats.Rational]) -> None

### nzinds
nzinds(self: bats.libbats.RationalVector) -> List[int]

### print
print(self: bats.libbats.RationalVector) -> None

## ReducedChainComplex
ReducedChainComplex(*args, **kwargs)
Overloaded function.

1. ReducedChainComplex(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedF3ChainComplex

2. ReducedChainComplex(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedF2ChainComplex

3. ReducedChainComplex(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedF5ChainComplex

4. ReducedChainComplex(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedRationalChainComplex

## ReducedF2ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedF2ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex) -> None

### find_preferred_representative
find_preferred_representative(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2Vector, arg1: int) -> None

### get_preferred_representative
get_preferred_representative(self: bats.libbats.ReducedF2ChainComplex, arg0: int, arg1: int) -> bats.libbats.F2Vector

### hdim
hdim(self: bats.libbats.ReducedF2ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedF2ChainComplex) -> int

## ReducedF3ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedF3ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex) -> None

### find_preferred_representative
find_preferred_representative(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3Vector, arg1: int) -> None

### get_preferred_representative
get_preferred_representative(self: bats.libbats.ReducedF3ChainComplex, arg0: int, arg1: int) -> bats.libbats.F3Vector

### hdim
hdim(self: bats.libbats.ReducedF3ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedF3ChainComplex) -> int

## ReducedF5ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedF5ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex) -> None

### find_preferred_representative
find_preferred_representative(self: bats.libbats.ReducedF5ChainComplex, arg0: SparseVector<ModP<int, 5u>, unsigned long>, arg1: int) -> None

### get_preferred_representative
get_preferred_representative(self: bats.libbats.ReducedF5ChainComplex, arg0: int, arg1: int) -> SparseVector<ModP<int, 5u>, unsigned long>

### hdim
hdim(self: bats.libbats.ReducedF5ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedF5ChainComplex) -> int

## ReducedFilteredChainComplex
ReducedFilteredChainComplex(*args, **kwargs)
Overloaded function.

1. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedFilteredF2ChainComplex

2. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedFilteredF3ChainComplex

3. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedFilteredF5ChainComplex

4. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedFilteredRationalChainComplex

## ReducedFilteredF2ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex) -> None

### dim
dim(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedFilteredF2ChainComplex) -> int

### persistence_pairs
persistence_pairs(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: int) -> List[PersistencePair<double>]

### representative
representative(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: PersistencePair<double>) -> bats.libbats.F2Vector

## ReducedFilteredF3ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex) -> None

### dim
dim(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedFilteredF3ChainComplex) -> int

### persistence_pairs
persistence_pairs(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: int) -> List[PersistencePair<double>]

### representative
representative(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: PersistencePair<double>) -> bats.libbats.F3Vector

## ReducedFilteredF5ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex) -> None

### dim
dim(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedFilteredF5ChainComplex) -> int

### persistence_pairs
persistence_pairs(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: int) -> List[PersistencePair<double>]

### representative
representative(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: PersistencePair<double>) -> SparseVector<ModP<int, 5u>, unsigned long>

## ReducedFilteredRationalChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex) -> None

2. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex) -> None

### dim
dim(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedFilteredRationalChainComplex) -> int

### persistence_pairs
persistence_pairs(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: int) -> List[PersistencePair<double>]

### representative
representative(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: PersistencePair<double>) -> bats.libbats.RationalVector

## ReducedRationalChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedRationalChainComplex) -> None

2. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex) -> None

### find_preferred_representative
find_preferred_representative(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalVector, arg1: int) -> None

### get_preferred_representative
get_preferred_representative(self: bats.libbats.ReducedRationalChainComplex, arg0: int, arg1: int) -> bats.libbats.RationalVector

### hdim
hdim(self: bats.libbats.ReducedRationalChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedRationalChainComplex) -> int

## RipsCoverFiltration
RipsCoverFiltration(*args, **kwargs)
Overloaded function.

1. RipsCoverFiltration(arg0: DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.Euclidean, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

2. RipsCoverFiltration(arg0: DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.L1Dist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

3. RipsCoverFiltration(arg0: DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.LInfDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

4. RipsCoverFiltration(arg0: DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.CosineDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

5. RipsCoverFiltration(arg0: DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.RPCosineDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

6. RipsCoverFiltration(arg0: DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.AngleDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

7. RipsCoverFiltration(arg0: DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.RPAngleDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

## RipsFiltration
RipsFiltration(*args, **kwargs)
Overloaded function.

1. RipsFiltration(arg0: DataSet<double>, arg1: bats.topology.Euclidean, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

2. RipsFiltration(arg0: DataSet<double>, arg1: bats.topology.L1Dist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

3. RipsFiltration(arg0: DataSet<double>, arg1: bats.topology.LInfDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

4. RipsFiltration(arg0: DataSet<double>, arg1: bats.topology.CosineDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

5. RipsFiltration(arg0: DataSet<double>, arg1: bats.topology.RPCosineDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

6. RipsFiltration(arg0: DataSet<double>, arg1: bats.topology.AngleDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

7. RipsFiltration(arg0: DataSet<double>, arg1: bats.topology.RPAngleDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

## SetDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.SetDiagram) -> None

2. __init__(self: bats.diagram.SetDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.SetDiagram, arg0: int, arg1: int, arg2: List[int]) -> int

### add_node
add_node(self: bats.diagram.SetDiagram, arg0: Set[int]) -> int

### edge_data
edge_data(self: bats.diagram.SetDiagram, arg0: int) -> List[int]

### edge_source
edge_source(self: bats.diagram.SetDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.SetDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.SetDiagram) -> int

### nnode
nnode(self: bats.diagram.SetDiagram) -> int

### node_data
node_data(self: bats.diagram.SetDiagram, arg0: int) -> Set[int]

### set_edge
set_edge(self: bats.diagram.SetDiagram, arg0: int, arg1: int, arg2: int, arg3: List[int]) -> None

### set_node
set_node(self: bats.diagram.SetDiagram, arg0: int, arg1: Set[int]) -> None

## SimplicialComplex
### __init__
__init__(self: bats.libbats.SimplicialComplex) -> None

### add
add(self: bats.libbats.SimplicialComplex, arg0: List[int]) -> bats.libbats.cell_ind

add simplex

### boundary
boundary(self: bats.libbats.SimplicialComplex, arg0: int) -> bats.libbats.CSCMatrix

### find_idx
find_idx(self: bats.libbats.SimplicialComplex, arg0: List[int]) -> int

### get_simplex
get_simplex(self: bats.libbats.SimplicialComplex, arg0: int, arg1: int) -> List[int]

### get_simplices
get_simplices(self: bats.libbats.SimplicialComplex, arg0: int) -> List[List[int]]

### maxdim
maxdim(self: bats.libbats.SimplicialComplex) -> int

maximum dimension simplex

### ncells
ncells(*args, **kwargs)
Overloaded function.

1. ncells(self: bats.libbats.SimplicialComplex) -> int

number of cells

2. ncells(self: bats.libbats.SimplicialComplex, arg0: int) -> int

number of cells in given dimension

### print_summary
print_summary(self: bats.libbats.SimplicialComplex) -> None

## SimplicialComplexDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.SimplicialComplexDiagram) -> None

2. __init__(self: bats.diagram.SimplicialComplexDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.SimplicialComplexDiagram, arg0: int, arg1: int, arg2: bats.libbats.CellularMap) -> int

### add_node
add_node(self: bats.diagram.SimplicialComplexDiagram, arg0: bats.libbats.SimplicialComplex) -> int

### edge_data
edge_data(self: bats.diagram.SimplicialComplexDiagram, arg0: int) -> bats.libbats.CellularMap

### edge_source
edge_source(self: bats.diagram.SimplicialComplexDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.SimplicialComplexDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.SimplicialComplexDiagram) -> int

### nnode
nnode(self: bats.diagram.SimplicialComplexDiagram) -> int

### node_data
node_data(self: bats.diagram.SimplicialComplexDiagram, arg0: int) -> bats.libbats.SimplicialComplex

### set_edge
set_edge(self: bats.diagram.SimplicialComplexDiagram, arg0: int, arg1: int, arg2: int, arg3: bats.libbats.CellularMap) -> None

### set_node
set_node(self: bats.diagram.SimplicialComplexDiagram, arg0: int, arg1: bats.libbats.SimplicialComplex) -> None

## SimplicialMap
SimplicialMap(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex, arg2: List[int]) -> bats.libbats.CellularMap

## WitnessFiltration
WitnessFiltration(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.Euclidean, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

## barcode
barcode(*args, **kwargs)
Overloaded function.

1. barcode(arg0: bats.diagram.F2HomDiagram, arg1: int) -> List[bats.libbats.PersistencePair_int]

2. barcode(arg0: bats.diagram.F3HomDiagram, arg1: int) -> List[bats.libbats.PersistencePair_int]

## bivariate_cover
bivariate_cover(arg0: List[Set[int]], arg1: List[Set[int]]) -> Tuple[List[Set[int]], List[int], List[int]]

## cell_ind
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.cell_ind) -> None

2. __init__(self: bats.libbats.cell_ind, arg0: int, arg1: int) -> None

## dense
## diagram
## force_repel_rp
force_repel_rp(arg0: DataSet<double>, arg1: float) -> None

## greedy_landmarks
greedy_landmarks(*args, **kwargs)
Overloaded function.

1. greedy_landmarks(arg0: DataSet<double>, arg1: int, arg2: bats.topology.Euclidean, arg3: int) -> DataSet<double>

2. greedy_landmarks(arg0: DataSet<double>, arg1: int, arg2: bats.topology.L1Dist, arg3: int) -> DataSet<double>

3. greedy_landmarks(arg0: DataSet<double>, arg1: int, arg2: bats.topology.LInfDist, arg3: int) -> DataSet<double>

4. greedy_landmarks(arg0: DataSet<double>, arg1: int, arg2: bats.topology.CosineDist, arg3: int) -> DataSet<double>

5. greedy_landmarks(arg0: DataSet<double>, arg1: int, arg2: bats.topology.RPCosineDist, arg3: int) -> DataSet<double>

6. greedy_landmarks(arg0: DataSet<double>, arg1: int, arg2: bats.topology.AngleDist, arg3: int) -> DataSet<double>

7. greedy_landmarks(arg0: DataSet<double>, arg1: int, arg2: bats.topology.RPAngleDist, arg3: int) -> DataSet<double>

## hausdorff_landmarks
hausdorff_landmarks(*args, **kwargs)
Overloaded function.

1. hausdorff_landmarks(arg0: DataSet<double>, arg1: float, arg2: bats.topology.Euclidean, arg3: int) -> DataSet<double>

2. hausdorff_landmarks(arg0: DataSet<double>, arg1: float, arg2: bats.topology.L1Dist, arg3: int) -> DataSet<double>

3. hausdorff_landmarks(arg0: DataSet<double>, arg1: float, arg2: bats.topology.LInfDist, arg3: int) -> DataSet<double>

4. hausdorff_landmarks(arg0: DataSet<double>, arg1: float, arg2: bats.topology.CosineDist, arg3: int) -> DataSet<double>

5. hausdorff_landmarks(arg0: DataSet<double>, arg1: float, arg2: bats.topology.RPCosineDist, arg3: int) -> DataSet<double>

6. hausdorff_landmarks(arg0: DataSet<double>, arg1: float, arg2: bats.topology.AngleDist, arg3: int) -> DataSet<double>

7. hausdorff_landmarks(arg0: DataSet<double>, arg1: float, arg2: bats.topology.RPAngleDist, arg3: int) -> DataSet<double>

## landmark_cover
landmark_cover(*args, **kwargs)
Overloaded function.

1. landmark_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.Euclidean, arg3: int) -> List[Set[int]]

2. landmark_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.L1Dist, arg3: int) -> List[Set[int]]

3. landmark_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.LInfDist, arg3: int) -> List[Set[int]]

4. landmark_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.CosineDist, arg3: int) -> List[Set[int]]

5. landmark_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.RPCosineDist, arg3: int) -> List[Set[int]]

6. landmark_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.AngleDist, arg3: int) -> List[Set[int]]

7. landmark_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.RPAngleDist, arg3: int) -> List[Set[int]]

## landmark_eps_cover
landmark_eps_cover(*args, **kwargs)
Overloaded function.

1. landmark_eps_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.Euclidean, arg3: float) -> List[Set[int]]

2. landmark_eps_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.L1Dist, arg3: float) -> List[Set[int]]

3. landmark_eps_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.LInfDist, arg3: float) -> List[Set[int]]

4. landmark_eps_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.CosineDist, arg3: float) -> List[Set[int]]

5. landmark_eps_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.RPCosineDist, arg3: float) -> List[Set[int]]

6. landmark_eps_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.AngleDist, arg3: float) -> List[Set[int]]

7. landmark_eps_cover(arg0: DataSet<double>, arg1: DataSet<double>, arg2: bats.topology.RPAngleDist, arg3: float) -> List[Set[int]]

## libbats
Basic Applied Topology Subprograms interface
## persistence_diagram
## random_landmarks
random_landmarks(arg0: DataSet<double>, arg1: int) -> DataSet<double>

## sample_sphere
sample_sphere(arg0: int, arg1: int) -> DataSet<double>

## topology
## visualization
