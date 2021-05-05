## AngleDist
### __init__
__init__(self: bats.topology.AngleDist) -> None

## CSCMatrix
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.CSCMatrix) -> None

2. __init__(self: bats.libbats.CSCMatrix, arg0: int, arg1: int, arg2: List[int], arg3: List[int], arg4: List[int]) -> None

### ncol
ncol(self: bats.libbats.CSCMatrix) -> int

number of columns.

### nrow
nrow(self: bats.libbats.CSCMatrix) -> int

number of rows.

### print
print(self: bats.libbats.CSCMatrix) -> None

## CellComplex
### __init__
__init__(self: bats.libbats.CellComplex) -> None

### add
add(self: bats.libbats.CellComplex, arg0: List[int], arg1: List[int], arg2: int) -> int

add cell in dimension k by specifying boundary and coefficients.

### add_vertex
add_vertex(self: bats.libbats.CellComplex) -> int

add vertex to cell complex

### add_vertices
add_vertices(self: bats.libbats.CellComplex, arg0: int) -> int

add vertices to cell complex

### boundary
boundary(self: bats.libbats.CellComplex, arg0: int) -> bats.libbats.CSCMatrix

### maxdim
maxdim(self: bats.libbats.CellComplex) -> int

maximum dimension cell

### ncells
ncells(*args, **kwargs)
Overloaded function.

1. ncells(self: bats.libbats.CellComplex) -> int

number of cells

2. ncells(self: bats.libbats.CellComplex, arg0: int) -> int

number of cells in given dimension

## CellComplexDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.CellComplexDiagram) -> None

2. __init__(self: bats.diagram.CellComplexDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.CellComplexDiagram, arg0: int, arg1: int, arg2: bats.libbats.CellularMap) -> int

### add_node
add_node(self: bats.diagram.CellComplexDiagram, arg0: bats.libbats.CellComplex) -> int

### edge_data
edge_data(self: bats.diagram.CellComplexDiagram, arg0: int) -> bats.libbats.CellularMap

### edge_source
edge_source(self: bats.diagram.CellComplexDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.CellComplexDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.CellComplexDiagram) -> int

### nnode
nnode(self: bats.diagram.CellComplexDiagram) -> int

### node_data
node_data(self: bats.diagram.CellComplexDiagram, arg0: int) -> bats.libbats.CellComplex

### set_edge
set_edge(self: bats.diagram.CellComplexDiagram, arg0: int, arg1: int, arg2: int, arg3: bats.libbats.CellularMap) -> None

### set_node
set_node(self: bats.diagram.CellComplexDiagram, arg0: int, arg1: bats.libbats.CellComplex) -> None

## CellularMap
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.CellularMap) -> None

2. __init__(self: bats.libbats.CellularMap, arg0: int) -> None

## Chain
Chain(*args, **kwargs)
Overloaded function.

1. Chain(arg0: bats.diagram.SimplicialComplexDiagram, arg1: bats.libbats.F2) -> bats.diagram.F2ChainDiagram

2. Chain(arg0: bats.diagram.SimplicialComplexDiagram, arg1: bats.libbats.F3) -> bats.diagram.F3ChainDiagram

3. Chain(arg0: bats.diagram.CubicalComplexDiagram, arg1: bats.libbats.F2) -> bats.diagram.F2ChainDiagram

4. Chain(arg0: bats.diagram.CubicalComplexDiagram, arg1: bats.libbats.F3) -> bats.diagram.F3ChainDiagram

5. Chain(arg0: bats.diagram.CellComplexDiagram, arg1: bats.libbats.F2) -> bats.diagram.F2ChainDiagram

6. Chain(arg0: bats.diagram.CellComplexDiagram, arg1: bats.libbats.F3) -> bats.diagram.F3ChainDiagram

7. Chain(arg0: bats.libbats.CellularMap, arg1: bats.libbats.F2) -> bats.libbats.F2ChainMap

8. Chain(arg0: bats.libbats.CellularMap, arg1: bats.libbats.SimplicialComplex, arg2: bats.libbats.SimplicialComplex, arg3: bats.libbats.SimplicialComplex, arg4: bats.libbats.SimplicialComplex, arg5: bats.libbats.F2) -> bats.libbats.F2ChainMap

9. Chain(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.F2ChainComplex

10. Chain(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex, arg2: bats.libbats.F2) -> bats.libbats.F2ChainComplex

11. Chain(arg0: bats.libbats.CubicalComplex, arg1: bats.libbats.F2) -> bats.libbats.F2ChainComplex

12. Chain(arg0: bats.libbats.CellComplex, arg1: bats.libbats.F2) -> bats.libbats.F2ChainComplex

13. Chain(arg0: bats.libbats.CellularMap, arg1: bats.libbats.F3) -> bats.libbats.F3ChainMap

14. Chain(arg0: bats.libbats.CellularMap, arg1: bats.libbats.SimplicialComplex, arg2: bats.libbats.SimplicialComplex, arg3: bats.libbats.SimplicialComplex, arg4: bats.libbats.SimplicialComplex, arg5: bats.libbats.F3) -> bats.libbats.F3ChainMap

15. Chain(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.F3ChainComplex

16. Chain(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex, arg2: bats.libbats.F3) -> bats.libbats.F3ChainComplex

17. Chain(arg0: bats.libbats.CubicalComplex, arg1: bats.libbats.F3) -> bats.libbats.F3ChainComplex

18. Chain(arg0: bats.libbats.CellComplex, arg1: bats.libbats.F3) -> bats.libbats.F3ChainComplex

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

## CubicalComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.CubicalComplex) -> None

2. __init__(self: bats.libbats.CubicalComplex, arg0: int) -> None

### add
add(self: bats.libbats.CubicalComplex, arg0: List[int]) -> bats.libbats.cell_ind

add cube

### add_recursive
add_recursive(self: bats.libbats.CubicalComplex, arg0: List[int]) -> List[bats.libbats.cell_ind]

add cube as well as faces

### boundary
boundary(self: bats.libbats.CubicalComplex, arg0: int) -> bats.libbats.CSCMatrix

integer boundary matrix

### find_idx
find_idx(self: bats.libbats.CubicalComplex, arg0: List[int]) -> int

### get_cube
get_cube(self: bats.libbats.CubicalComplex, arg0: int, arg1: int) -> List[int]

get cube in given dimension

### get_cubes
get_cubes(*args, **kwargs)
Overloaded function.

1. get_cubes(self: bats.libbats.CubicalComplex, arg0: int) -> List[List[int]]

Returns a list of all cubes in given dimension.

2. get_cubes(self: bats.libbats.CubicalComplex) -> List[List[int]]

Returns a list of all cubes.

### load_cubes
load_cubes(self: bats.libbats.CubicalComplex, arg0: str) -> None

load cubes from a csv file.

### maxdim
maxdim(self: bats.libbats.CubicalComplex) -> int

maximum dimension cube

### ncells
ncells(*args, **kwargs)
Overloaded function.

1. ncells(self: bats.libbats.CubicalComplex) -> int

number of cells

2. ncells(self: bats.libbats.CubicalComplex, arg0: int) -> int

number of cells in given dimension

### skeleton
skeleton(self: bats.libbats.CubicalComplex, arg0: int) -> bats.libbats.CubicalComplex

k-skeleton of complex

## CubicalComplexDiagram
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.diagram.CubicalComplexDiagram) -> None

2. __init__(self: bats.diagram.CubicalComplexDiagram, arg0: int, arg1: int) -> None

### add_edge
add_edge(self: bats.diagram.CubicalComplexDiagram, arg0: int, arg1: int, arg2: bats.libbats.CellularMap) -> int

### add_node
add_node(self: bats.diagram.CubicalComplexDiagram, arg0: bats.libbats.CubicalComplex) -> int

### edge_data
edge_data(self: bats.diagram.CubicalComplexDiagram, arg0: int) -> bats.libbats.CellularMap

### edge_source
edge_source(self: bats.diagram.CubicalComplexDiagram, arg0: int) -> int

### edge_target
edge_target(self: bats.diagram.CubicalComplexDiagram, arg0: int) -> int

### nedge
nedge(self: bats.diagram.CubicalComplexDiagram) -> int

### nnode
nnode(self: bats.diagram.CubicalComplexDiagram) -> int

### node_data
node_data(self: bats.diagram.CubicalComplexDiagram, arg0: int) -> bats.libbats.CubicalComplex

### set_edge
set_edge(self: bats.diagram.CubicalComplexDiagram, arg0: int, arg1: int, arg2: int, arg3: bats.libbats.CellularMap) -> None

### set_node
set_node(self: bats.diagram.CubicalComplexDiagram, arg0: int, arg1: bats.libbats.CubicalComplex) -> None

## CubicalMap
CubicalMap(arg0: bats.libbats.CubicalComplex, arg1: bats.libbats.CubicalComplex) -> bats.libbats.CellularMap

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

## DiscreteMorozovZigzag
DiscreteMorozovZigzag(*args, **kwargs)
Overloaded function.

1. DiscreteMorozovZigzag(arg0: bats::DataSet<double>, arg1: bats.topology.Euclidean, arg2: float, arg3: int) -> Tuple[bats::Diagram<bats::SimplicialComplex, bats::CellularMap>, List[float]]

discrete Morozov Zigzag (dM-ZZ) construction.

2. DiscreteMorozovZigzag(arg0: bats::DataSet<double>, arg1: bats.topology.L1Dist, arg2: float, arg3: int) -> Tuple[bats::Diagram<bats::SimplicialComplex, bats::CellularMap>, List[float]]

discrete Morozov Zigzag (dM-ZZ) construction.

3. DiscreteMorozovZigzag(arg0: bats::DataSet<double>, arg1: bats.topology.LInfDist, arg2: float, arg3: int) -> Tuple[bats::Diagram<bats::SimplicialComplex, bats::CellularMap>, List[float]]

discrete Morozov Zigzag (dM-ZZ) construction.

4. DiscreteMorozovZigzag(arg0: bats::DataSet<double>, arg1: bats.topology.CosineDist, arg2: float, arg3: int) -> Tuple[bats::Diagram<bats::SimplicialComplex, bats::CellularMap>, List[float]]

discrete Morozov Zigzag (dM-ZZ) construction.

5. DiscreteMorozovZigzag(arg0: bats::DataSet<double>, arg1: bats.topology.RPCosineDist, arg2: float, arg3: int) -> Tuple[bats::Diagram<bats::SimplicialComplex, bats::CellularMap>, List[float]]

discrete Morozov Zigzag (dM-ZZ) construction.

6. DiscreteMorozovZigzag(arg0: bats::DataSet<double>, arg1: bats.topology.AngleDist, arg2: float, arg3: int) -> Tuple[bats::Diagram<bats::SimplicialComplex, bats::CellularMap>, List[float]]

discrete Morozov Zigzag (dM-ZZ) construction.

7. DiscreteMorozovZigzag(arg0: bats::DataSet<double>, arg1: bats.topology.RPAngleDist, arg2: float, arg3: int) -> Tuple[bats::Diagram<bats::SimplicialComplex, bats::CellularMap>, List[float]]

discrete Morozov Zigzag (dM-ZZ) construction.

## DiscreteMorozovZigzagSets
DiscreteMorozovZigzagSets(*args, **kwargs)
Overloaded function.

1. DiscreteMorozovZigzagSets(arg0: bats::DataSet<double>, arg1: bats.topology.Euclidean, arg2: float) -> Tuple[bats::Diagram<std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> >, std::vector<unsigned long, std::allocator<unsigned long> > >, List[float]]

SetDiagram for discrete Morozov Zigzag (dM-ZZ) construction.

2. DiscreteMorozovZigzagSets(arg0: bats::DataSet<double>, arg1: bats.topology.L1Dist, arg2: float) -> Tuple[bats::Diagram<std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> >, std::vector<unsigned long, std::allocator<unsigned long> > >, List[float]]

SetDiagram for discrete Morozov Zigzag (dM-ZZ) construction.

3. DiscreteMorozovZigzagSets(arg0: bats::DataSet<double>, arg1: bats.topology.LInfDist, arg2: float) -> Tuple[bats::Diagram<std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> >, std::vector<unsigned long, std::allocator<unsigned long> > >, List[float]]

SetDiagram for discrete Morozov Zigzag (dM-ZZ) construction.

4. DiscreteMorozovZigzagSets(arg0: bats::DataSet<double>, arg1: bats.topology.CosineDist, arg2: float) -> Tuple[bats::Diagram<std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> >, std::vector<unsigned long, std::allocator<unsigned long> > >, List[float]]

SetDiagram for discrete Morozov Zigzag (dM-ZZ) construction.

5. DiscreteMorozovZigzagSets(arg0: bats::DataSet<double>, arg1: bats.topology.RPCosineDist, arg2: float) -> Tuple[bats::Diagram<std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> >, std::vector<unsigned long, std::allocator<unsigned long> > >, List[float]]

SetDiagram for discrete Morozov Zigzag (dM-ZZ) construction.

6. DiscreteMorozovZigzagSets(arg0: bats::DataSet<double>, arg1: bats.topology.AngleDist, arg2: float) -> Tuple[bats::Diagram<std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> >, std::vector<unsigned long, std::allocator<unsigned long> > >, List[float]]

SetDiagram for discrete Morozov Zigzag (dM-ZZ) construction.

7. DiscreteMorozovZigzagSets(arg0: bats::DataSet<double>, arg1: bats.topology.RPAngleDist, arg2: float) -> Tuple[bats::Diagram<std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> >, std::vector<unsigned long, std::allocator<unsigned long> > >, List[float]]

SetDiagram for discrete Morozov Zigzag (dM-ZZ) construction.

## DowkerCoverFiltration
DowkerCoverFiltration(*args, **kwargs)
Overloaded function.

1. DowkerCoverFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.Euclidean, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

2. DowkerCoverFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.L1Dist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

3. DowkerCoverFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.LInfDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

4. DowkerCoverFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.CosineDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

5. DowkerCoverFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.RPCosineDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

6. DowkerCoverFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.AngleDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

7. DowkerCoverFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.RPAngleDist, arg3: List[Set[int]], arg4: float, arg5: int) -> bats.libbats.FilteredSimplicialComplex

8. DowkerCoverFiltration(arg0: A<Dense<double, RowMaj> >, arg1: List[Set[int]], arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

## DowkerFiltration
DowkerFiltration(*args, **kwargs)
Overloaded function.

1. DowkerFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.Euclidean, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

2. DowkerFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.L1Dist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

3. DowkerFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.LInfDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

4. DowkerFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.CosineDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

5. DowkerFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.RPCosineDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

6. DowkerFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.AngleDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

7. DowkerFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.RPAngleDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

8. DowkerFiltration(arg0: A<Dense<double, RowMaj> >, arg1: float, arg2: int) -> bats.libbats.FilteredSimplicialComplex

## EL_L_commute
EL_L_commute(*args, **kwargs)
Overloaded function.

1. EL_L_commute(arg0: bats.libbats.F2Mat, arg1: bats.libbats.F2Mat) -> bats.libbats.F2Mat

E_L, L commutation

2. EL_L_commute(arg0: bats.libbats.F3Mat, arg1: bats.libbats.F3Mat) -> bats.libbats.F3Mat

E_L, L commutation

3. EL_L_commute(arg0: bats.libbats.RationalMat, arg1: bats.libbats.RationalMat) -> bats.libbats.RationalMat

E_L, L commutation

## EU_U_commute
EU_U_commute(*args, **kwargs)
Overloaded function.

1. EU_U_commute(arg0: bats.libbats.F2Mat, arg1: bats.libbats.F2Mat) -> bats.libbats.F2Mat

E_U, U commutation

2. EU_U_commute(arg0: bats.libbats.F3Mat, arg1: bats.libbats.F3Mat) -> bats.libbats.F3Mat

E_U, U commutation

3. EU_U_commute(arg0: bats.libbats.RationalMat, arg1: bats.libbats.RationalMat) -> bats.libbats.RationalMat

E_U, U commutation

## Euclidean
### __init__
__init__(self: bats.topology.Euclidean) -> None

## F2
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2) -> None

2. __init__(self: bats.libbats.F2, arg0: int) -> None

### to_int
to_int(self: bats.libbats.F2) -> int

convert to integer.

## F2Chain
F2Chain(arg0: bats.diagram.SimplicialComplexDiagram) -> bats.diagram.F2ChainDiagram

## F2ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2ChainComplex) -> None

2. __init__(self: bats.libbats.F2ChainComplex, arg0: bats.libbats.SimplicialComplex) -> None

3. __init__(self: bats.libbats.F2ChainComplex, arg0: bats.libbats.LightSimplicialComplex) -> None

4. __init__(self: bats.libbats.F2ChainComplex, arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex) -> None

relative chain complex

5. __init__(self: bats.libbats.F2ChainComplex, arg0: bats.libbats.CubicalComplex) -> None

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

3. __init__(self: bats.libbats.F2ChainMap, arg0: bats.libbats.CellularMap, arg1: bats.libbats.SimplicialComplex, arg2: bats.libbats.SimplicialComplex, arg3: bats.libbats.SimplicialComplex, arg4: bats.libbats.SimplicialComplex) -> None

relative chain map

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
### T
T(self: bats.libbats.F2Mat) -> bats.libbats.F2Mat

transpose

### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2Mat) -> None

2. __init__(self: bats.libbats.F2Mat, arg0: int, arg1: int) -> None

3. __init__(self: bats.libbats.F2Mat, arg0: int, arg1: int, arg2: List[bats.libbats.F2Vector]) -> None

4. __init__(self: bats.libbats.F2Mat, arg0: CSCMatrix<int, unsigned long>) -> None

### append_column
append_column(self: bats.libbats.F2Mat, arg0: bats.libbats.F2Vector) -> None

appends column

### ncol
ncol(self: bats.libbats.F2Mat) -> int

number of columns.

### nrow
nrow(self: bats.libbats.F2Mat) -> int

number of rows.

### permute_cols
permute_cols(self: bats.libbats.F2Mat, arg0: List[int]) -> None

permute columns

### permute_rows
permute_rows(self: bats.libbats.F2Mat, arg0: List[int]) -> None

permute rows

### tolist
tolist(self: bats.libbats.F2Mat) -> List[List[bats.libbats.F2]]

return as C-style array

## F2Vector
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F2Vector) -> None

2. __init__(self: bats.libbats.F2Vector, arg0: List[int], arg1: List[bats.libbats.F2]) -> None

3. __init__(self: bats.libbats.F2Vector, arg0: List[Tuple[int, int]]) -> None

construct from a list of index-value tuples

### nnz
nnz(self: bats.libbats.F2Vector) -> int

number of non-zeros

### nzinds
nzinds(self: bats.libbats.F2Vector) -> List[int]

### nzs
nzs(self: bats.libbats.F2Vector) -> Tuple[List[int], List[bats.libbats.F2]]

tuple of lists: non-zero indices, and non-zero values

### nzvals
nzvals(self: bats.libbats.F2Vector) -> List[bats.libbats.F2]

### permute
permute(self: bats.libbats.F2Vector, arg0: List[int]) -> None

permute the indices

### sort
sort(self: bats.libbats.F2Vector) -> None

put non-zeros in sorted order

## F3
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3) -> None

2. __init__(self: bats.libbats.F3, arg0: int) -> None

### to_int
to_int(self: bats.libbats.F3) -> int

convert to integer.

## F3Chain
F3Chain(arg0: bats.diagram.SimplicialComplexDiagram) -> bats.diagram.F3ChainDiagram

## F3ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3ChainComplex) -> None

2. __init__(self: bats.libbats.F3ChainComplex, arg0: bats.libbats.SimplicialComplex) -> None

3. __init__(self: bats.libbats.F3ChainComplex, arg0: bats.libbats.LightSimplicialComplex) -> None

4. __init__(self: bats.libbats.F3ChainComplex, arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex) -> None

relative chain complex

5. __init__(self: bats.libbats.F3ChainComplex, arg0: bats.libbats.CubicalComplex) -> None

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

3. __init__(self: bats.libbats.F3ChainMap, arg0: bats.libbats.CellularMap, arg1: bats.libbats.SimplicialComplex, arg2: bats.libbats.SimplicialComplex, arg3: bats.libbats.SimplicialComplex, arg4: bats.libbats.SimplicialComplex) -> None

relative chain map

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
### T
T(self: bats.libbats.F3Mat) -> bats.libbats.F3Mat

transpose

### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3Mat) -> None

2. __init__(self: bats.libbats.F3Mat, arg0: int, arg1: int) -> None

3. __init__(self: bats.libbats.F3Mat, arg0: int, arg1: int, arg2: List[bats.libbats.F3Vector]) -> None

4. __init__(self: bats.libbats.F3Mat, arg0: CSCMatrix<int, unsigned long>) -> None

### append_column
append_column(self: bats.libbats.F3Mat, arg0: bats.libbats.F3Vector) -> None

appends column

### ncol
ncol(self: bats.libbats.F3Mat) -> int

number of columns.

### nrow
nrow(self: bats.libbats.F3Mat) -> int

number of rows.

### permute_cols
permute_cols(self: bats.libbats.F3Mat, arg0: List[int]) -> None

permute columns

### permute_rows
permute_rows(self: bats.libbats.F3Mat, arg0: List[int]) -> None

permute rows

### tolist
tolist(self: bats.libbats.F3Mat) -> List[List[bats.libbats.F3]]

return as C-style array

## F3Vector
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F3Vector) -> None

2. __init__(self: bats.libbats.F3Vector, arg0: List[int], arg1: List[bats.libbats.F3]) -> None

3. __init__(self: bats.libbats.F3Vector, arg0: List[Tuple[int, int]]) -> None

construct from a list of index-value tuples

### nnz
nnz(self: bats.libbats.F3Vector) -> int

number of non-zeros

### nzinds
nzinds(self: bats.libbats.F3Vector) -> List[int]

### nzs
nzs(self: bats.libbats.F3Vector) -> Tuple[List[int], List[bats.libbats.F3]]

tuple of lists: non-zero indices, and non-zero values

### nzvals
nzvals(self: bats.libbats.F3Vector) -> List[bats.libbats.F3]

### permute
permute(self: bats.libbats.F3Vector, arg0: List[int]) -> None

permute the indices

### sort
sort(self: bats.libbats.F3Vector) -> None

put non-zeros in sorted order

## F5
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F5) -> None

2. __init__(self: bats.libbats.F5, arg0: int) -> None

### to_int
to_int(self: bats.libbats.F5) -> int

convert to integer.

## F5ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F5ChainComplex) -> None

2. __init__(self: bats.libbats.F5ChainComplex, arg0: bats.libbats.SimplicialComplex) -> None

3. __init__(self: bats.libbats.F5ChainComplex, arg0: bats.libbats.LightSimplicialComplex) -> None

4. __init__(self: bats.libbats.F5ChainComplex, arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex) -> None

relative chain complex

5. __init__(self: bats.libbats.F5ChainComplex, arg0: bats.libbats.CubicalComplex) -> None

## F5ChainMap
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.F5ChainMap) -> None

2. __init__(self: bats.libbats.F5ChainMap, arg0: bats.libbats.CellularMap) -> None

3. __init__(self: bats.libbats.F5ChainMap, arg0: bats.libbats.CellularMap, arg1: bats.libbats.SimplicialComplex, arg2: bats.libbats.SimplicialComplex, arg3: bats.libbats.SimplicialComplex, arg4: bats.libbats.SimplicialComplex) -> None

relative chain map

## FilteredCubicalComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.FilteredCubicalComplex) -> None

2. __init__(self: bats.libbats.FilteredCubicalComplex, arg0: int) -> None

### add
add(self: bats.libbats.FilteredCubicalComplex, arg0: float, arg1: List[int]) -> bats.libbats.cell_ind

### add_recursive
add_recursive(self: bats.libbats.FilteredCubicalComplex, arg0: float, arg1: List[int]) -> List[bats.libbats.cell_ind]

### all_vals
all_vals(self: bats.libbats.FilteredCubicalComplex) -> List[List[float]]

### complex
complex(self: bats.libbats.FilteredCubicalComplex) -> bats.libbats.CubicalComplex

### maxdim
maxdim(self: bats.libbats.FilteredCubicalComplex) -> int

### ncells
ncells(self: bats.libbats.FilteredCubicalComplex, arg0: int) -> int

### vals
vals(self: bats.libbats.FilteredCubicalComplex, arg0: int) -> List[float]

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

3. __init__(self: bats.libbats.FilteredF2ChainComplex, arg0: bats.libbats.FilteredLightSimplicialComplex) -> None

4. __init__(self: bats.libbats.FilteredF2ChainComplex, arg0: bats.libbats.FilteredCubicalComplex) -> None

## FilteredF3ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.FilteredF3ChainComplex) -> None

2. __init__(self: bats.libbats.FilteredF3ChainComplex, arg0: bats.libbats.FilteredSimplicialComplex) -> None

3. __init__(self: bats.libbats.FilteredF3ChainComplex, arg0: bats.libbats.FilteredLightSimplicialComplex) -> None

4. __init__(self: bats.libbats.FilteredF3ChainComplex, arg0: bats.libbats.FilteredCubicalComplex) -> None

## FilteredF5ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.FilteredF5ChainComplex) -> None

2. __init__(self: bats.libbats.FilteredF5ChainComplex, arg0: bats.libbats.FilteredSimplicialComplex) -> None

3. __init__(self: bats.libbats.FilteredF5ChainComplex, arg0: bats.libbats.FilteredLightSimplicialComplex) -> None

4. __init__(self: bats.libbats.FilteredF5ChainComplex, arg0: bats.libbats.FilteredCubicalComplex) -> None

## FilteredLightSimplicialComplex
### __init__
__init__(self: bats.libbats.FilteredLightSimplicialComplex) -> None

### add
add(self: bats.libbats.FilteredLightSimplicialComplex, arg0: float, arg1: List[int]) -> bats.libbats.cell_ind

### add_recursive
add_recursive(self: bats.libbats.FilteredLightSimplicialComplex, arg0: float, arg1: List[int]) -> List[bats.libbats.cell_ind]

### all_vals
all_vals(self: bats.libbats.FilteredLightSimplicialComplex) -> List[List[float]]

### complex
complex(self: bats.libbats.FilteredLightSimplicialComplex) -> bats.libbats.LightSimplicialComplex

### maxdim
maxdim(self: bats.libbats.FilteredLightSimplicialComplex) -> int

### ncells
ncells(self: bats.libbats.FilteredLightSimplicialComplex, arg0: int) -> int

### vals
vals(self: bats.libbats.FilteredLightSimplicialComplex, arg0: int) -> List[float]

## FilteredRationalChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.FilteredRationalChainComplex) -> None

2. __init__(self: bats.libbats.FilteredRationalChainComplex, arg0: bats.libbats.FilteredSimplicialComplex) -> None

3. __init__(self: bats.libbats.FilteredRationalChainComplex, arg0: bats.libbats.FilteredLightSimplicialComplex) -> None

4. __init__(self: bats.libbats.FilteredRationalChainComplex, arg0: bats.libbats.FilteredCubicalComplex) -> None

## FilteredSimplicialComplex
### __init__
__init__(self: bats.libbats.FilteredSimplicialComplex) -> None

### add
add(self: bats.libbats.FilteredSimplicialComplex, arg0: float, arg1: List[int]) -> bats.libbats.cell_ind

### add_recursive
add_recursive(self: bats.libbats.FilteredSimplicialComplex, arg0: float, arg1: List[int]) -> List[bats.libbats.cell_ind]

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

## Hom
Hom(*args, **kwargs)
Overloaded function.

1. Hom(arg0: bats.diagram.F2ChainDiagram, arg1: int) -> bats.diagram.F2HomDiagram

2. Hom(arg0: bats.diagram.F3ChainDiagram, arg1: int) -> bats.diagram.F3HomDiagram

## Identity
Identity(*args, **kwargs)
Overloaded function.

1. Identity(arg0: int, arg1: int) -> bats.libbats.IntMat

2. Identity(arg0: int, arg1: bats.libbats.F2) -> bats.libbats.F2Mat

3. Identity(arg0: int, arg1: bats.libbats.F3) -> bats.libbats.F3Mat

4. Identity(arg0: int, arg1: bats.libbats.Rational) -> bats.libbats.RationalMat

## IdentityMap
IdentityMap(arg0: bats.libbats.SimplicialComplex) -> bats.libbats.CellularMap

## InducedMap
InducedMap(*args, **kwargs)
Overloaded function.

1. InducedMap(arg0: bats.libbats.F2ChainMap, arg1: bats.libbats.ReducedF2ChainComplex, arg2: bats.libbats.ReducedF2ChainComplex, arg3: int) -> bats.libbats.F2Mat

Induced map on homology.

2. InducedMap(arg0: bats.libbats.F3ChainMap, arg1: bats.libbats.ReducedF3ChainComplex, arg2: bats.libbats.ReducedF3ChainComplex, arg3: int) -> bats.libbats.F3Mat

Induced map on homology.

## IntMat
### T
T(self: bats.libbats.IntMat) -> bats.libbats.IntMat

transpose

### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.IntMat) -> None

2. __init__(self: bats.libbats.IntMat, arg0: int, arg1: int) -> None

3. __init__(self: bats.libbats.IntMat, arg0: int, arg1: int, arg2: List[bats.libbats.IntVector]) -> None

4. __init__(self: bats.libbats.IntMat, arg0: CSCMatrix<int, unsigned long>) -> None

### append_column
append_column(self: bats.libbats.IntMat, arg0: bats.libbats.IntVector) -> None

appends column

### ncol
ncol(self: bats.libbats.IntMat) -> int

number of columns.

### nrow
nrow(self: bats.libbats.IntMat) -> int

number of rows.

### permute_cols
permute_cols(self: bats.libbats.IntMat, arg0: List[int]) -> None

permute columns

### permute_rows
permute_rows(self: bats.libbats.IntMat, arg0: List[int]) -> None

permute rows

### tolist
tolist(self: bats.libbats.IntMat) -> List[List[int]]

return as C-style array

## IntVector
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.IntVector) -> None

2. __init__(self: bats.libbats.IntVector, arg0: List[int], arg1: List[int]) -> None

3. __init__(self: bats.libbats.IntVector, arg0: List[Tuple[int, int]]) -> None

construct from a list of index-value tuples

### nnz
nnz(self: bats.libbats.IntVector) -> int

number of non-zeros

### nzinds
nzinds(self: bats.libbats.IntVector) -> List[int]

### nzs
nzs(self: bats.libbats.IntVector) -> Tuple[List[int], List[int]]

tuple of lists: non-zero indices, and non-zero values

### nzvals
nzvals(self: bats.libbats.IntVector) -> List[int]

### permute
permute(self: bats.libbats.IntVector, arg0: List[int]) -> None

permute the indices

### sort
sort(self: bats.libbats.IntVector) -> None

put non-zeros in sorted order

## L1Dist
### __init__
__init__(self: bats.topology.L1Dist) -> None

## LEUP
LEUP(*args, **kwargs)
Overloaded function.

1. LEUP(arg0: bats.libbats.F2Mat) -> Tuple[bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat]

LEUP factorization

2. LEUP(arg0: bats.libbats.F3Mat) -> Tuple[bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat]

LEUP factorization

3. LEUP(arg0: bats.libbats.RationalMat) -> Tuple[bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat]

LEUP factorization

## LInfDist
### __init__
__init__(self: bats.topology.LInfDist) -> None

## LQU
LQU(*args, **kwargs)
Overloaded function.

1. LQU(arg0: bats.libbats.F2Mat) -> Tuple[bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat]

LQU factorization

2. LQU(arg0: bats.libbats.F3Mat) -> Tuple[bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat]

LQU factorization

3. LQU(arg0: bats.libbats.RationalMat) -> Tuple[bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat]

LQU factorization

## L_EL_commute
L_EL_commute(*args, **kwargs)
Overloaded function.

1. L_EL_commute(arg0: bats.libbats.F2Mat, arg1: bats.libbats.F2Mat) -> bats.libbats.F2Mat

L, E_L commutation

2. L_EL_commute(arg0: bats.libbats.F3Mat, arg1: bats.libbats.F3Mat) -> bats.libbats.F3Mat

L, E_L commutation

3. L_EL_commute(arg0: bats.libbats.RationalMat, arg1: bats.libbats.RationalMat) -> bats.libbats.RationalMat

L, E_L commutation

## LightRipsComplex
LightRipsComplex(arg0: A<Dense<double, RowMaj> >, arg1: float, arg2: int) -> bats.libbats.LightSimplicialComplex

Rips Complex constructed from pairwise distances.

## LightRipsFiltration
LightRipsFiltration(*args, **kwargs)
Overloaded function.

1. LightRipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.Euclidean, arg2: float, arg3: int) -> bats.libbats.FilteredLightSimplicialComplex

2. LightRipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.L1Dist, arg2: float, arg3: int) -> bats.libbats.FilteredLightSimplicialComplex

3. LightRipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.LInfDist, arg2: float, arg3: int) -> bats.libbats.FilteredLightSimplicialComplex

4. LightRipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.CosineDist, arg2: float, arg3: int) -> bats.libbats.FilteredLightSimplicialComplex

5. LightRipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.RPCosineDist, arg2: float, arg3: int) -> bats.libbats.FilteredLightSimplicialComplex

6. LightRipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.AngleDist, arg2: float, arg3: int) -> bats.libbats.FilteredLightSimplicialComplex

7. LightRipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.RPAngleDist, arg2: float, arg3: int) -> bats.libbats.FilteredLightSimplicialComplex

8. LightRipsFiltration(arg0: A<Dense<double, RowMaj> >, arg1: float, arg2: int) -> bats.libbats.FilteredLightSimplicialComplex

Rips Filtration using built using pairwise distances.

## LightSimplicialComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.LightSimplicialComplex) -> None

2. __init__(self: bats.libbats.LightSimplicialComplex, arg0: int, arg1: int) -> None

### add
add(self: bats.libbats.LightSimplicialComplex, arg0: List[int]) -> bats.libbats.cell_ind

add simplex

### add_recursive
add_recursive(self: bats.libbats.LightSimplicialComplex, arg0: List[int]) -> List[bats.libbats.cell_ind]

add simplex and missing faces

### boundary
boundary(self: bats.libbats.LightSimplicialComplex, arg0: int) -> bats.libbats.CSCMatrix

### find_idx
find_idx(self: bats.libbats.LightSimplicialComplex, arg0: List[int]) -> int

### get_simplex
get_simplex(self: bats.libbats.LightSimplicialComplex, arg0: int, arg1: int) -> List[int]

### get_simplices
get_simplices(*args, **kwargs)
Overloaded function.

1. get_simplices(self: bats.libbats.LightSimplicialComplex, arg0: int) -> List[List[int]]

Returns a list of all simplices in given dimension.

2. get_simplices(self: bats.libbats.LightSimplicialComplex) -> List[List[int]]

Returns a list of all simplices.

### maxdim
maxdim(self: bats.libbats.LightSimplicialComplex) -> int

maximum dimension simplex

### ncells
ncells(*args, **kwargs)
Overloaded function.

1. ncells(self: bats.libbats.LightSimplicialComplex) -> int

number of cells

2. ncells(self: bats.libbats.LightSimplicialComplex, arg0: int) -> int

number of cells in given dimension

## Mat
Mat(*args, **kwargs)
Overloaded function.

1. Mat(arg0: CSCMatrix<int, unsigned long>, arg1: int) -> bats.libbats.IntMat

2. Mat(arg0: CSCMatrix<int, unsigned long>) -> bats.libbats.IntMat

3. Mat(arg0: CSCMatrix<int, unsigned long>, arg1: bats.libbats.F2) -> bats.libbats.F2Mat

4. Mat(arg0: CSCMatrix<int, unsigned long>, arg1: bats.libbats.F3) -> bats.libbats.F3Mat

5. Mat(arg0: CSCMatrix<int, unsigned long>, arg1: bats.libbats.Rational) -> bats.libbats.RationalMat

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

## PLEU
PLEU(*args, **kwargs)
Overloaded function.

1. PLEU(arg0: bats.libbats.F2Mat) -> Tuple[bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat]

PLEU factorization

2. PLEU(arg0: bats.libbats.F3Mat) -> Tuple[bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat]

PLEU factorization

3. PLEU(arg0: bats.libbats.RationalMat) -> Tuple[bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat]

PLEU factorization

## PUEL
PUEL(*args, **kwargs)
Overloaded function.

1. PUEL(arg0: bats.libbats.F2Mat) -> Tuple[bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat]

PUEL factorization

2. PUEL(arg0: bats.libbats.F3Mat) -> Tuple[bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat]

PUEL factorization

3. PUEL(arg0: bats.libbats.RationalMat) -> Tuple[bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat]

PUEL factorization

## PersistencePair
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.PersistencePair) -> None

2. __init__(self: bats.libbats.PersistencePair, arg0: int, arg1: int, arg2: int, arg3: float, arg4: float) -> None

initialize with hdim, birth_ind, death_ind, birth, death.

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

initialize with hdim, birth_ind, death_ind, birth, death.

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

### to_int
to_int(self: bats.libbats.Rational) -> int

convert to integer.

## RationalChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.RationalChainComplex) -> None

2. __init__(self: bats.libbats.RationalChainComplex, arg0: bats.libbats.SimplicialComplex) -> None

3. __init__(self: bats.libbats.RationalChainComplex, arg0: bats.libbats.LightSimplicialComplex) -> None

4. __init__(self: bats.libbats.RationalChainComplex, arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex) -> None

relative chain complex

5. __init__(self: bats.libbats.RationalChainComplex, arg0: bats.libbats.CubicalComplex) -> None

## RationalChainMap
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.RationalChainMap) -> None

2. __init__(self: bats.libbats.RationalChainMap, arg0: bats.libbats.CellularMap) -> None

3. __init__(self: bats.libbats.RationalChainMap, arg0: bats.libbats.CellularMap, arg1: bats.libbats.SimplicialComplex, arg2: bats.libbats.SimplicialComplex, arg3: bats.libbats.SimplicialComplex, arg4: bats.libbats.SimplicialComplex) -> None

relative chain map

## RationalMat
### T
T(self: bats.libbats.RationalMat) -> bats.libbats.RationalMat

transpose

### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.RationalMat) -> None

2. __init__(self: bats.libbats.RationalMat, arg0: int, arg1: int) -> None

3. __init__(self: bats.libbats.RationalMat, arg0: int, arg1: int, arg2: List[bats.libbats.RationalVector]) -> None

4. __init__(self: bats.libbats.RationalMat, arg0: CSCMatrix<int, unsigned long>) -> None

### append_column
append_column(self: bats.libbats.RationalMat, arg0: bats.libbats.RationalVector) -> None

appends column

### ncol
ncol(self: bats.libbats.RationalMat) -> int

number of columns.

### nrow
nrow(self: bats.libbats.RationalMat) -> int

number of rows.

### permute_cols
permute_cols(self: bats.libbats.RationalMat, arg0: List[int]) -> None

permute columns

### permute_rows
permute_rows(self: bats.libbats.RationalMat, arg0: List[int]) -> None

permute rows

### tolist
tolist(self: bats.libbats.RationalMat) -> List[List[bats.libbats.Rational]]

return as C-style array

## RationalVector
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.RationalVector) -> None

2. __init__(self: bats.libbats.RationalVector, arg0: List[int], arg1: List[bats.libbats.Rational]) -> None

3. __init__(self: bats.libbats.RationalVector, arg0: List[Tuple[int, int]]) -> None

construct from a list of index-value tuples

### nnz
nnz(self: bats.libbats.RationalVector) -> int

number of non-zeros

### nzinds
nzinds(self: bats.libbats.RationalVector) -> List[int]

### nzs
nzs(self: bats.libbats.RationalVector) -> Tuple[List[int], List[bats.libbats.Rational]]

tuple of lists: non-zero indices, and non-zero values

### nzvals
nzvals(self: bats.libbats.RationalVector) -> List[bats.libbats.Rational]

### permute
permute(self: bats.libbats.RationalVector, arg0: List[int]) -> None

permute the indices

### sort
sort(self: bats.libbats.RationalVector) -> None

put non-zeros in sorted order

## ReducedChainComplex
ReducedChainComplex(*args, **kwargs)
Overloaded function.

1. ReducedChainComplex(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedF3ChainComplex

2. ReducedChainComplex(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedF3ChainComplex

3. ReducedChainComplex(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedF2ChainComplex

4. ReducedChainComplex(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedF2ChainComplex

5. ReducedChainComplex(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedF5ChainComplex

6. ReducedChainComplex(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedF5ChainComplex

7. ReducedChainComplex(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedRationalChainComplex

8. ReducedChainComplex(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedRationalChainComplex

## ReducedF2ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedF2ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex) -> None

3. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> None

4. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

5. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

6. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> None

7. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> None

8. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

9. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

10. __init__(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> None

### chain_preferred_representative
chain_preferred_representative(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2Vector, arg1: int) -> bats.libbats.F2Vector

return the preferred representative of a chain

### find_preferred_representative
find_preferred_representative(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2Vector, arg1: int) -> None

### from_hom_basis
from_hom_basis(*args, **kwargs)
Overloaded function.

1. from_hom_basis(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2Mat, arg1: int) -> bats.libbats.F2Mat

2. from_hom_basis(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2Vector, arg1: int) -> bats.libbats.F2Vector

### get_preferred_representative
get_preferred_representative(self: bats.libbats.ReducedF2ChainComplex, arg0: int, arg1: int) -> bats.libbats.F2Vector

get the preferred representative for homology class

### hdim
hdim(self: bats.libbats.ReducedF2ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedF2ChainComplex) -> int

### to_hom_basis
to_hom_basis(*args, **kwargs)
Overloaded function.

1. to_hom_basis(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2Mat, arg1: int) -> bats.libbats.F2Mat

2. to_hom_basis(self: bats.libbats.ReducedF2ChainComplex, arg0: bats.libbats.F2Vector, arg1: int) -> bats.libbats.F2Vector

## ReducedF3ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedF3ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex) -> None

3. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> None

4. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

5. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

6. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> None

7. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> None

8. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

9. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

10. __init__(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> None

### chain_preferred_representative
chain_preferred_representative(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3Vector, arg1: int) -> bats.libbats.F3Vector

return the preferred representative of a chain

### find_preferred_representative
find_preferred_representative(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3Vector, arg1: int) -> None

### from_hom_basis
from_hom_basis(*args, **kwargs)
Overloaded function.

1. from_hom_basis(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3Mat, arg1: int) -> bats.libbats.F3Mat

2. from_hom_basis(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3Vector, arg1: int) -> bats.libbats.F3Vector

### get_preferred_representative
get_preferred_representative(self: bats.libbats.ReducedF3ChainComplex, arg0: int, arg1: int) -> bats.libbats.F3Vector

get the preferred representative for homology class

### hdim
hdim(self: bats.libbats.ReducedF3ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedF3ChainComplex) -> int

### to_hom_basis
to_hom_basis(*args, **kwargs)
Overloaded function.

1. to_hom_basis(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3Mat, arg1: int) -> bats.libbats.F3Mat

2. to_hom_basis(self: bats.libbats.ReducedF3ChainComplex, arg0: bats.libbats.F3Vector, arg1: int) -> bats.libbats.F3Vector

## ReducedF5ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedF5ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex) -> None

3. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> None

4. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

5. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

6. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> None

7. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> None

8. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

9. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

10. __init__(self: bats.libbats.ReducedF5ChainComplex, arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> None

### chain_preferred_representative
chain_preferred_representative(self: bats.libbats.ReducedF5ChainComplex, arg0: SparseVector<ModP<int, 5u>, unsigned long>, arg1: int) -> SparseVector<ModP<int, 5u>, unsigned long>

return the preferred representative of a chain

### find_preferred_representative
find_preferred_representative(self: bats.libbats.ReducedF5ChainComplex, arg0: SparseVector<ModP<int, 5u>, unsigned long>, arg1: int) -> None

### from_hom_basis
from_hom_basis(*args, **kwargs)
Overloaded function.

1. from_hom_basis(self: bats.libbats.ReducedF5ChainComplex, arg0: ColumnMatrix<SparseVector<ModP<int, 5u>, unsigned long> >, arg1: int) -> ColumnMatrix<SparseVector<ModP<int, 5u>, unsigned long> >

2. from_hom_basis(self: bats.libbats.ReducedF5ChainComplex, arg0: SparseVector<ModP<int, 5u>, unsigned long>, arg1: int) -> SparseVector<ModP<int, 5u>, unsigned long>

### get_preferred_representative
get_preferred_representative(self: bats.libbats.ReducedF5ChainComplex, arg0: int, arg1: int) -> SparseVector<ModP<int, 5u>, unsigned long>

get the preferred representative for homology class

### hdim
hdim(self: bats.libbats.ReducedF5ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedF5ChainComplex) -> int

### to_hom_basis
to_hom_basis(*args, **kwargs)
Overloaded function.

1. to_hom_basis(self: bats.libbats.ReducedF5ChainComplex, arg0: ColumnMatrix<SparseVector<ModP<int, 5u>, unsigned long> >, arg1: int) -> ColumnMatrix<SparseVector<ModP<int, 5u>, unsigned long> >

2. to_hom_basis(self: bats.libbats.ReducedF5ChainComplex, arg0: SparseVector<ModP<int, 5u>, unsigned long>, arg1: int) -> SparseVector<ModP<int, 5u>, unsigned long>

## ReducedFilteredChainComplex
ReducedFilteredChainComplex(*args, **kwargs)
Overloaded function.

1. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedFilteredF2ChainComplex

2. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedFilteredF2ChainComplex

3. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedFilteredF3ChainComplex

4. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedFilteredF3ChainComplex

5. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedFilteredF5ChainComplex

6. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedFilteredF5ChainComplex

7. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedFilteredRationalChainComplex

8. ReducedFilteredChainComplex(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedFilteredRationalChainComplex

## ReducedFilteredF2ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex) -> None

3. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> None

4. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

5. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

6. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> None

7. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> None

8. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

9. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

10. __init__(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> None

### dim
dim(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedFilteredF2ChainComplex) -> int

### persistence_pairs
persistence_pairs(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: int) -> List[bats::PersistencePair<double>]

### representative
representative(self: bats.libbats.ReducedFilteredF2ChainComplex, arg0: bats::PersistencePair<double>) -> bats.libbats.F2Vector

## ReducedFilteredF3ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex) -> None

3. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> None

4. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

5. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

6. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> None

7. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> None

8. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

9. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

10. __init__(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> None

### dim
dim(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedFilteredF3ChainComplex) -> int

### persistence_pairs
persistence_pairs(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: int) -> List[bats::PersistencePair<double>]

### representative
representative(self: bats.libbats.ReducedFilteredF3ChainComplex, arg0: bats::PersistencePair<double>) -> bats.libbats.F3Vector

## ReducedFilteredF5ChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex) -> None

2. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex) -> None

3. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> None

4. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

5. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

6. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> None

7. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> None

8. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

9. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

10. __init__(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> None

### dim
dim(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedFilteredF5ChainComplex) -> int

### persistence_pairs
persistence_pairs(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: int) -> List[bats::PersistencePair<double>]

### representative
representative(self: bats.libbats.ReducedFilteredF5ChainComplex, arg0: bats::PersistencePair<double>) -> SparseVector<ModP<int, 5u>, unsigned long>

## ReducedFilteredRationalChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex) -> None

2. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex) -> None

3. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag) -> None

4. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

5. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

6. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> None

7. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag) -> None

8. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

9. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

10. __init__(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> None

### dim
dim(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedFilteredRationalChainComplex) -> int

### persistence_pairs
persistence_pairs(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: int) -> List[bats::PersistencePair<double>]

### representative
representative(self: bats.libbats.ReducedFilteredRationalChainComplex, arg0: bats::PersistencePair<double>) -> bats.libbats.RationalVector

## ReducedRationalChainComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.ReducedRationalChainComplex) -> None

2. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex) -> None

3. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag) -> None

4. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

5. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

6. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> None

7. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag) -> None

8. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> None

9. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> None

10. __init__(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> None

### chain_preferred_representative
chain_preferred_representative(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalVector, arg1: int) -> bats.libbats.RationalVector

return the preferred representative of a chain

### find_preferred_representative
find_preferred_representative(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalVector, arg1: int) -> None

### from_hom_basis
from_hom_basis(*args, **kwargs)
Overloaded function.

1. from_hom_basis(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalMat, arg1: int) -> bats.libbats.RationalMat

2. from_hom_basis(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalVector, arg1: int) -> bats.libbats.RationalVector

### get_preferred_representative
get_preferred_representative(self: bats.libbats.ReducedRationalChainComplex, arg0: int, arg1: int) -> bats.libbats.RationalVector

get the preferred representative for homology class

### hdim
hdim(self: bats.libbats.ReducedRationalChainComplex, arg0: int) -> int

### maxdim
maxdim(self: bats.libbats.ReducedRationalChainComplex) -> int

### to_hom_basis
to_hom_basis(*args, **kwargs)
Overloaded function.

1. to_hom_basis(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalMat, arg1: int) -> bats.libbats.RationalMat

2. to_hom_basis(self: bats.libbats.ReducedRationalChainComplex, arg0: bats.libbats.RationalVector, arg1: int) -> bats.libbats.RationalVector

## Rips
Rips(*args, **kwargs)
Overloaded function.

1. Rips(arg0: bats.diagram.SetDiagram, arg1: bats.dense.DataSet, arg2: bats.topology.Euclidean, arg3: float, arg4: int) -> bats.diagram.SimplicialComplexDiagram

Construct a diagram of Rips complexes from a SetDiagram.

2. Rips(arg0: bats.diagram.SetDiagram, arg1: bats.dense.DataSet, arg2: bats.topology.Euclidean, arg3: List[float], arg4: int) -> bats.diagram.SimplicialComplexDiagram

Construct a diagram of Rips complexes from a SetDiagram.

## RipsComplex
RipsComplex(*args, **kwargs)
Overloaded function.

1. RipsComplex(arg0: bats::DataSet<double>, arg1: bats.topology.Euclidean, arg2: float, arg3: int) -> bats.libbats.SimplicialComplex

Rips Complex constructed from data set and metric.

2. RipsComplex(arg0: bats::DataSet<double>, arg1: bats.topology.L1Dist, arg2: float, arg3: int) -> bats.libbats.SimplicialComplex

Rips Complex constructed from data set and metric.

3. RipsComplex(arg0: bats::DataSet<double>, arg1: bats.topology.LInfDist, arg2: float, arg3: int) -> bats.libbats.SimplicialComplex

Rips Complex constructed from data set and metric.

4. RipsComplex(arg0: bats::DataSet<double>, arg1: bats.topology.CosineDist, arg2: float, arg3: int) -> bats.libbats.SimplicialComplex

Rips Complex constructed from data set and metric.

5. RipsComplex(arg0: bats::DataSet<double>, arg1: bats.topology.RPCosineDist, arg2: float, arg3: int) -> bats.libbats.SimplicialComplex

Rips Complex constructed from data set and metric.

6. RipsComplex(arg0: bats::DataSet<double>, arg1: bats.topology.AngleDist, arg2: float, arg3: int) -> bats.libbats.SimplicialComplex

Rips Complex constructed from data set and metric.

7. RipsComplex(arg0: bats::DataSet<double>, arg1: bats.topology.RPAngleDist, arg2: float, arg3: int) -> bats.libbats.SimplicialComplex

Rips Complex constructed from data set and metric.

8. RipsComplex(arg0: A<Dense<double, RowMaj> >, arg1: float, arg2: int) -> bats.libbats.SimplicialComplex

Rips Complex constructed from pairwise distances.

## RipsCoverFiltration
RipsCoverFiltration(*args, **kwargs)
Overloaded function.

1. RipsCoverFiltration(arg0: bats::DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.Euclidean, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

2. RipsCoverFiltration(arg0: bats::DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.L1Dist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

3. RipsCoverFiltration(arg0: bats::DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.LInfDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

4. RipsCoverFiltration(arg0: bats::DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.CosineDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

5. RipsCoverFiltration(arg0: bats::DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.RPCosineDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

6. RipsCoverFiltration(arg0: bats::DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.AngleDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

7. RipsCoverFiltration(arg0: bats::DataSet<double>, arg1: List[Set[int]], arg2: bats.topology.RPAngleDist, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

## RipsFiltration
RipsFiltration(*args, **kwargs)
Overloaded function.

1. RipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.Euclidean, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

2. RipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.L1Dist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

3. RipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.LInfDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

4. RipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.CosineDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

5. RipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.RPCosineDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

6. RipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.AngleDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

7. RipsFiltration(arg0: bats::DataSet<double>, arg1: bats.topology.RPAngleDist, arg2: float, arg3: int) -> bats.libbats.FilteredSimplicialComplex

8. RipsFiltration(arg0: A<Dense<double, RowMaj> >, arg1: float, arg2: int) -> bats.libbats.FilteredSimplicialComplex

Rips Filtration using built using pairwise distances.

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

## SierpinskiDiagram
SierpinskiDiagram(arg0: int) -> bats::Diagram<bats::CellComplex, bats::CellularMap>

Diagram of Sierpinski triangle iterations.

## SimplicialComplex
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.SimplicialComplex) -> None

2. __init__(self: bats.libbats.SimplicialComplex, arg0: int, arg1: int) -> None

### add
add(self: bats.libbats.SimplicialComplex, arg0: List[int]) -> bats.libbats.cell_ind

add simplex

### add_recursive
add_recursive(self: bats.libbats.SimplicialComplex, arg0: List[int]) -> List[bats.libbats.cell_ind]

add simplex and missing faces

### boundary
boundary(self: bats.libbats.SimplicialComplex, arg0: int) -> bats.libbats.CSCMatrix

### find_idx
find_idx(self: bats.libbats.SimplicialComplex, arg0: List[int]) -> int

### get_simplex
get_simplex(self: bats.libbats.SimplicialComplex, arg0: int, arg1: int) -> List[int]

### get_simplices
get_simplices(*args, **kwargs)
Overloaded function.

1. get_simplices(self: bats.libbats.SimplicialComplex, arg0: int) -> List[List[int]]

Returns a list of all simplices in given dimension.

2. get_simplices(self: bats.libbats.SimplicialComplex) -> List[List[int]]

Returns a list of all simplices.

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
SimplicialMap(*args, **kwargs)
Overloaded function.

1. SimplicialMap(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex) -> bats.libbats.CellularMap

Inclusion map of simplicial complexes

2. SimplicialMap(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex, arg2: List[int]) -> bats.libbats.CellularMap

simplicial map extended from function on vertices

## TriangulatedProduct
TriangulatedProduct(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.SimplicialComplex) -> bats.libbats.SimplicialComplex

## UELP
UELP(*args, **kwargs)
Overloaded function.

1. UELP(arg0: bats.libbats.F2Mat) -> Tuple[bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat, bats.libbats.F2Mat]

UELP factorization

2. UELP(arg0: bats.libbats.F3Mat) -> Tuple[bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat, bats.libbats.F3Mat]

UELP factorization

3. UELP(arg0: bats.libbats.RationalMat) -> Tuple[bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat, bats.libbats.RationalMat]

UELP factorization

## U_EU_commute
U_EU_commute(*args, **kwargs)
Overloaded function.

1. U_EU_commute(arg0: bats.libbats.F2Mat, arg1: bats.libbats.F2Mat) -> bats.libbats.F2Mat

U, E_U commutation

2. U_EU_commute(arg0: bats.libbats.F3Mat, arg1: bats.libbats.F3Mat) -> bats.libbats.F3Mat

U, E_U commutation

3. U_EU_commute(arg0: bats.libbats.RationalMat, arg1: bats.libbats.RationalMat) -> bats.libbats.RationalMat

U, E_U commutation

## WitnessFiltration
WitnessFiltration(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.Euclidean, arg3: float, arg4: int) -> bats.libbats.FilteredSimplicialComplex

## ZigzagSetDiagram
ZigzagSetDiagram(arg0: List[Set[int]]) -> bats.diagram.SetDiagram

Create a zigzag diagram of sets and pairwise unions.

## approx_center
approx_center(*args, **kwargs)
Overloaded function.

1. approx_center(arg0: bats::DataSet<double>, arg1: bats.topology.Euclidean, arg2: int, arg3: int) -> int

2. approx_center(arg0: bats::DataSet<double>, arg1: bats.topology.L1Dist, arg2: int, arg3: int) -> int

3. approx_center(arg0: bats::DataSet<double>, arg1: bats.topology.LInfDist, arg2: int, arg3: int) -> int

4. approx_center(arg0: bats::DataSet<double>, arg1: bats.topology.CosineDist, arg2: int, arg3: int) -> int

5. approx_center(arg0: bats::DataSet<double>, arg1: bats.topology.RPCosineDist, arg2: int, arg3: int) -> int

6. approx_center(arg0: bats::DataSet<double>, arg1: bats.topology.AngleDist, arg2: int, arg3: int) -> int

7. approx_center(arg0: bats::DataSet<double>, arg1: bats.topology.RPAngleDist, arg2: int, arg3: int) -> int

## barcode
barcode(*args, **kwargs)
Overloaded function.

1. barcode(arg0: bats.diagram.F2HomDiagram, arg1: int) -> List[bats.libbats.PersistencePair_int]

2. barcode(arg0: bats.diagram.F3HomDiagram, arg1: int) -> List[bats.libbats.PersistencePair_int]

## barcode_sparse
barcode_sparse(*args, **kwargs)
Overloaded function.

1. barcode_sparse(arg0: bats.diagram.F2HomDiagram, arg1: int) -> List[bats.libbats.PersistencePair_int]

2. barcode_sparse(arg0: bats.diagram.F3HomDiagram, arg1: int) -> List[bats.libbats.PersistencePair_int]

## bivariate_cover
bivariate_cover(arg0: List[Set[int]], arg1: List[Set[int]]) -> Tuple[List[Set[int]], List[int], List[int]]

## cell_ind
### __init__
__init__(*args, **kwargs)
Overloaded function.

1. __init__(self: bats.libbats.cell_ind) -> None

2. __init__(self: bats.libbats.cell_ind, arg0: int, arg1: int) -> None

## clearing_flag
### __init__
__init__(self: bats.libbats.clearing_flag) -> None

## compression_flag
### __init__
__init__(self: bats.libbats.compression_flag) -> None

## compute_basis_flag
### __init__
__init__(self: bats.libbats.compute_basis_flag) -> None

## dense
## diagram
## extra_reduction_flag
### __init__
__init__(self: bats.libbats.extra_reduction_flag) -> None

## force_repel_rp
force_repel_rp(arg0: bats::DataSet<double>, arg1: float) -> None

## greedy_landmarks
greedy_landmarks(*args, **kwargs)
Overloaded function.

1. greedy_landmarks(arg0: bats::DataSet<double>, arg1: int, arg2: bats.topology.Euclidean, arg3: int) -> bats::DataSet<double>

2. greedy_landmarks(arg0: bats::DataSet<double>, arg1: int, arg2: bats.topology.L1Dist, arg3: int) -> bats::DataSet<double>

3. greedy_landmarks(arg0: bats::DataSet<double>, arg1: int, arg2: bats.topology.LInfDist, arg3: int) -> bats::DataSet<double>

4. greedy_landmarks(arg0: bats::DataSet<double>, arg1: int, arg2: bats.topology.CosineDist, arg3: int) -> bats::DataSet<double>

5. greedy_landmarks(arg0: bats::DataSet<double>, arg1: int, arg2: bats.topology.RPCosineDist, arg3: int) -> bats::DataSet<double>

6. greedy_landmarks(arg0: bats::DataSet<double>, arg1: int, arg2: bats.topology.AngleDist, arg3: int) -> bats::DataSet<double>

7. greedy_landmarks(arg0: bats::DataSet<double>, arg1: int, arg2: bats.topology.RPAngleDist, arg3: int) -> bats::DataSet<double>

## greedy_landmarks_hausdorff
greedy_landmarks_hausdorff(*args, **kwargs)
Overloaded function.

1. greedy_landmarks_hausdorff(arg0: bats::DataSet<double>, arg1: bats.topology.Euclidean, arg2: int) -> Tuple[List[int], List[float]]

2. greedy_landmarks_hausdorff(arg0: bats::DataSet<double>, arg1: bats.topology.L1Dist, arg2: int) -> Tuple[List[int], List[float]]

3. greedy_landmarks_hausdorff(arg0: bats::DataSet<double>, arg1: bats.topology.LInfDist, arg2: int) -> Tuple[List[int], List[float]]

4. greedy_landmarks_hausdorff(arg0: bats::DataSet<double>, arg1: bats.topology.CosineDist, arg2: int) -> Tuple[List[int], List[float]]

5. greedy_landmarks_hausdorff(arg0: bats::DataSet<double>, arg1: bats.topology.RPCosineDist, arg2: int) -> Tuple[List[int], List[float]]

6. greedy_landmarks_hausdorff(arg0: bats::DataSet<double>, arg1: bats.topology.AngleDist, arg2: int) -> Tuple[List[int], List[float]]

7. greedy_landmarks_hausdorff(arg0: bats::DataSet<double>, arg1: bats.topology.RPAngleDist, arg2: int) -> Tuple[List[int], List[float]]

8. greedy_landmarks_hausdorff(arg0: A<Dense<double, RowMaj> >, arg1: int) -> Tuple[List[int], List[float]]

## hausdorff_landmarks
hausdorff_landmarks(*args, **kwargs)
Overloaded function.

1. hausdorff_landmarks(arg0: bats::DataSet<double>, arg1: float, arg2: bats.topology.Euclidean, arg3: int) -> bats::DataSet<double>

2. hausdorff_landmarks(arg0: bats::DataSet<double>, arg1: float, arg2: bats.topology.L1Dist, arg3: int) -> bats::DataSet<double>

3. hausdorff_landmarks(arg0: bats::DataSet<double>, arg1: float, arg2: bats.topology.LInfDist, arg3: int) -> bats::DataSet<double>

4. hausdorff_landmarks(arg0: bats::DataSet<double>, arg1: float, arg2: bats.topology.CosineDist, arg3: int) -> bats::DataSet<double>

5. hausdorff_landmarks(arg0: bats::DataSet<double>, arg1: float, arg2: bats.topology.RPCosineDist, arg3: int) -> bats::DataSet<double>

6. hausdorff_landmarks(arg0: bats::DataSet<double>, arg1: float, arg2: bats.topology.AngleDist, arg3: int) -> bats::DataSet<double>

7. hausdorff_landmarks(arg0: bats::DataSet<double>, arg1: float, arg2: bats.topology.RPAngleDist, arg3: int) -> bats::DataSet<double>

## landmark_cover
landmark_cover(*args, **kwargs)
Overloaded function.

1. landmark_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.Euclidean, arg3: int) -> List[Set[int]]

2. landmark_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.L1Dist, arg3: int) -> List[Set[int]]

3. landmark_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.LInfDist, arg3: int) -> List[Set[int]]

4. landmark_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.CosineDist, arg3: int) -> List[Set[int]]

5. landmark_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.RPCosineDist, arg3: int) -> List[Set[int]]

6. landmark_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.AngleDist, arg3: int) -> List[Set[int]]

7. landmark_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.RPAngleDist, arg3: int) -> List[Set[int]]

## landmark_eps_cover
landmark_eps_cover(*args, **kwargs)
Overloaded function.

1. landmark_eps_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.Euclidean, arg3: float) -> List[Set[int]]

2. landmark_eps_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.L1Dist, arg3: float) -> List[Set[int]]

3. landmark_eps_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.LInfDist, arg3: float) -> List[Set[int]]

4. landmark_eps_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.CosineDist, arg3: float) -> List[Set[int]]

5. landmark_eps_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.RPCosineDist, arg3: float) -> List[Set[int]]

6. landmark_eps_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.AngleDist, arg3: float) -> List[Set[int]]

7. landmark_eps_cover(arg0: bats::DataSet<double>, arg1: bats::DataSet<double>, arg2: bats.topology.RPAngleDist, arg3: float) -> List[Set[int]]

## libbats
Basic Applied Topology Subprograms interface
## no_optimization_flag
### __init__
__init__(self: bats.libbats.no_optimization_flag) -> None

## persistence_barcode

    plot a persistence barcode for pairs in ps.
    Each barcode is a pyplot axis.
    Barcodes are stacked horizontally in figure.

    Parameters:

        ps: List of PersistencePair

        remove_zeros: flag to remove zero-length bars (default: True)

        tlb: lower bound on filtration parameter to display.  (default: 0.0)

        tlb: upper bound on filtration parameter to display.  (default: inf)

        essential_color: color for essential pairs (defualt: 'r')

        figargs - passed onto pyplot subplots construction (default {})

        lineargs - passed onto hlines construction (default {"linewidth":1})

    Returns:
        fig, ax - pyplot figure and axes
    
## persistence_diagram
## random_landmarks
random_landmarks(arg0: bats::DataSet<double>, arg1: int) -> bats::DataSet<double>

## reduce
reduce(*args, **kwargs)
Overloaded function.

1. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedF3ChainComplex

2. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF3ChainComplex

3. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

4. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF3ChainComplex

5. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF3ChainComplex

6. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

7. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF3ChainComplex

8. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

9. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF3ChainComplex

10. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF3ChainComplex

11. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

12. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedF3ChainComplex

13. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF3ChainComplex

14. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

15. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF3ChainComplex

16. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF3ChainComplex

17. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

18. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF3ChainComplex

19. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

20. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF3ChainComplex

21. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF3ChainComplex

22. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

23. reduce(arg0: bats.libbats.F3ChainComplex) -> bats.libbats.ReducedF3ChainComplex

24. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF3ChainComplex

25. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

26. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedF3ChainComplex

27. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedF3ChainComplex

28. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

29. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF3ChainComplex

30. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

31. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedF3ChainComplex

32. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedF3ChainComplex

33. reduce(arg0: bats.libbats.F3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF3ChainComplex

34. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedF2ChainComplex

35. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF2ChainComplex

36. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

37. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF2ChainComplex

38. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF2ChainComplex

39. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

40. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF2ChainComplex

41. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

42. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF2ChainComplex

43. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF2ChainComplex

44. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

45. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedF2ChainComplex

46. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF2ChainComplex

47. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

48. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF2ChainComplex

49. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF2ChainComplex

50. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

51. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF2ChainComplex

52. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

53. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF2ChainComplex

54. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF2ChainComplex

55. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

56. reduce(arg0: bats.libbats.F2ChainComplex) -> bats.libbats.ReducedF2ChainComplex

57. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF2ChainComplex

58. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

59. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedF2ChainComplex

60. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedF2ChainComplex

61. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

62. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF2ChainComplex

63. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

64. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedF2ChainComplex

65. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedF2ChainComplex

66. reduce(arg0: bats.libbats.F2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF2ChainComplex

67. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedF5ChainComplex

68. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF5ChainComplex

69. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

70. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF5ChainComplex

71. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF5ChainComplex

72. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

73. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF5ChainComplex

74. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

75. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF5ChainComplex

76. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF5ChainComplex

77. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

78. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedF5ChainComplex

79. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF5ChainComplex

80. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

81. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF5ChainComplex

82. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF5ChainComplex

83. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

84. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF5ChainComplex

85. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

86. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedF5ChainComplex

87. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedF5ChainComplex

88. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

89. reduce(arg0: bats.libbats.F5ChainComplex) -> bats.libbats.ReducedF5ChainComplex

90. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedF5ChainComplex

91. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

92. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedF5ChainComplex

93. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedF5ChainComplex

94. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

95. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedF5ChainComplex

96. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

97. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedF5ChainComplex

98. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedF5ChainComplex

99. reduce(arg0: bats.libbats.F5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedF5ChainComplex

100. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedRationalChainComplex

101. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedRationalChainComplex

102. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

103. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedRationalChainComplex

104. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedRationalChainComplex

105. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

106. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedRationalChainComplex

107. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

108. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedRationalChainComplex

109. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedRationalChainComplex

110. reduce(arg0: bats.libbats.SimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

111. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedRationalChainComplex

112. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedRationalChainComplex

113. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

114. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedRationalChainComplex

115. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedRationalChainComplex

116. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

117. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedRationalChainComplex

118. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

119. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedRationalChainComplex

120. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedRationalChainComplex

121. reduce(arg0: bats.libbats.LightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

122. reduce(arg0: bats.libbats.RationalChainComplex) -> bats.libbats.ReducedRationalChainComplex

123. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedRationalChainComplex

124. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

125. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedRationalChainComplex

126. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedRationalChainComplex

127. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

128. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedRationalChainComplex

129. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

130. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedRationalChainComplex

131. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedRationalChainComplex

132. reduce(arg0: bats.libbats.RationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedRationalChainComplex

133. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedFilteredF2ChainComplex

134. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

135. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

136. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

137. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

138. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

139. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

140. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

141. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

142. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

143. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

144. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2) -> bats.libbats.ReducedFilteredF2ChainComplex

145. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

146. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

147. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

148. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

149. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

150. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

151. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

152. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

153. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

154. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F2, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

155. reduce(arg0: bats.libbats.FilteredF2ChainComplex) -> bats.libbats.ReducedFilteredF2ChainComplex

156. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

157. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

158. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

159. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

160. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

161. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

162. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

163. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

164. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

165. reduce(arg0: bats.libbats.FilteredF2ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF2ChainComplex

166. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedFilteredF3ChainComplex

167. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

168. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

169. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

170. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

171. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

172. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

173. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

174. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

175. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

176. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

177. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3) -> bats.libbats.ReducedFilteredF3ChainComplex

178. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

179. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

180. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

181. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

182. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

183. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

184. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

185. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

186. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

187. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F3, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

188. reduce(arg0: bats.libbats.FilteredF3ChainComplex) -> bats.libbats.ReducedFilteredF3ChainComplex

189. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

190. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

191. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

192. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

193. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

194. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

195. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

196. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

197. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

198. reduce(arg0: bats.libbats.FilteredF3ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF3ChainComplex

199. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedFilteredF5ChainComplex

200. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

201. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

202. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

203. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

204. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

205. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

206. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

207. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

208. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

209. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

210. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5) -> bats.libbats.ReducedFilteredF5ChainComplex

211. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

212. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

213. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

214. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

215. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

216. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

217. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

218. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

219. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

220. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.F5, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

221. reduce(arg0: bats.libbats.FilteredF5ChainComplex) -> bats.libbats.ReducedFilteredF5ChainComplex

222. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

223. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

224. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

225. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

226. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

227. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

228. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

229. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

230. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

231. reduce(arg0: bats.libbats.FilteredF5ChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredF5ChainComplex

232. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedFilteredRationalChainComplex

233. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

234. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

235. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

236. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

237. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

238. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

239. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

240. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

241. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

242. reduce(arg0: bats.libbats.FilteredSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

243. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational) -> bats.libbats.ReducedFilteredRationalChainComplex

244. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

245. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

246. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

247. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

248. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.standard_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

249. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

250. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

251. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

252. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

253. reduce(arg0: bats.libbats.FilteredLightSimplicialComplex, arg1: bats.libbats.Rational, arg2: bats.libbats.extra_reduction_flag, arg3: bats.libbats.compression_flag, arg4: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

254. reduce(arg0: bats.libbats.FilteredRationalChainComplex) -> bats.libbats.ReducedFilteredRationalChainComplex

255. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

256. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

257. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

258. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

259. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.standard_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

260. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

261. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

262. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.clearing_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

263. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

264. reduce(arg0: bats.libbats.FilteredRationalChainComplex, arg1: bats.libbats.extra_reduction_flag, arg2: bats.libbats.compression_flag, arg3: bats.libbats.compute_basis_flag) -> bats.libbats.ReducedFilteredRationalChainComplex

## reduce_matrix
reduce_matrix(*args, **kwargs)
Overloaded function.

1. reduce_matrix(arg0: bats.libbats.IntMat) -> List[int]

2. reduce_matrix(arg0: bats.libbats.IntMat, arg1: bats::extra_reduction_flag) -> List[int]

3. reduce_matrix(arg0: bats.libbats.IntMat, arg1: bats.libbats.IntMat) -> List[int]

4. reduce_matrix(arg0: bats.libbats.IntMat, arg1: bats.libbats.IntMat, arg2: bats::extra_reduction_flag) -> List[int]

5. reduce_matrix(arg0: bats.libbats.F2Mat) -> List[int]

6. reduce_matrix(arg0: bats.libbats.F2Mat, arg1: bats::extra_reduction_flag) -> List[int]

7. reduce_matrix(arg0: bats.libbats.F2Mat, arg1: bats.libbats.F2Mat) -> List[int]

8. reduce_matrix(arg0: bats.libbats.F2Mat, arg1: bats.libbats.F2Mat, arg2: bats::extra_reduction_flag) -> List[int]

9. reduce_matrix(arg0: bats.libbats.F3Mat) -> List[int]

10. reduce_matrix(arg0: bats.libbats.F3Mat, arg1: bats::extra_reduction_flag) -> List[int]

11. reduce_matrix(arg0: bats.libbats.F3Mat, arg1: bats.libbats.F3Mat) -> List[int]

12. reduce_matrix(arg0: bats.libbats.F3Mat, arg1: bats.libbats.F3Mat, arg2: bats::extra_reduction_flag) -> List[int]

13. reduce_matrix(arg0: bats.libbats.RationalMat) -> List[int]

14. reduce_matrix(arg0: bats.libbats.RationalMat, arg1: bats::extra_reduction_flag) -> List[int]

15. reduce_matrix(arg0: bats.libbats.RationalMat, arg1: bats.libbats.RationalMat) -> List[int]

16. reduce_matrix(arg0: bats.libbats.RationalMat, arg1: bats.libbats.RationalMat, arg2: bats::extra_reduction_flag) -> List[int]

## sample_sphere
sample_sphere(arg0: int, arg1: int) -> bats::DataSet<double>

## standard_reduction_flag
### __init__
__init__(self: bats.libbats.standard_reduction_flag) -> None

## topology
## visualization
