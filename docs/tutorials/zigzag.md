# Zigzag Homology

There are two ways to compute zigzag homology in BATS.
1. Zigzag homology of a diagram of spaces over a line graph
2. Zigzag homology of a zigzag-filtered space

(2) is a special case of (1) which uses different data structures and functions for (potential) memory efficiency and performance gains.

## Zigzag homology of a diagram of spaces

There are three categories you can use to create a diagram of spaces

1. Simplicial complexes/cellular maps: `SimplicialComplexDiagram`
2. Cubical complexes/cellular maps: `CubicalComplexDiagram`
3. Cell complexes/cellular maps: `CellComplexDiagram`

For zigzag homology, you want to create a diagram of spaces on a directed line graph
```
* --> * <-- * --> * --> ...
```

Where the arrows can go in any direction.  This means you will have `n` nodes (spaces) and `n-1` edges (maps).

?> It is important to arrange your nodes in order i.e. there should be an edge between node 0 and 1, an edge between 1 and 2, etc.  BATS will assume this, but won't check.


Let's use the following example of complexes:
```
0 <- 0 -> 0
|         |
1 <- 1 -> 1
```
The spaces on the left and right are identical (two vertices, numbered "0" and "1" connected by a single edge), and the space in the middle has the edge removed.  The maps are identical inclusion maps.  We expect a 0-dimensional zigzag barcode that looks like
```
*----*----*
     *
```

### Simplicial Complexes

```python
import bats

n = 3 # number of spaces

D = bats.SimplicialComplexDiagram(n, n-1)

# first, we add SimplicialComplexes to the diagram
X = bats.SimplicialComplex()
X.add_recursive([0,1])
D.set_node(0, X) # left node
D.set_node(2, X) # right node

Y = bats.SimplicialComplex()
Y.add([0])
Y.add([1])
D.set_node(1, Y)

# now, we add SimplicialMaps
f = bats.SimplicialMap(Y, X, [0, 1])
D.set_edge(0, 1, 0, f) # edge 0 maps space at node 1 to space at node 0.  The map is f
D.set_edge(1, 1, 2, f) # edge 1 maps space at node 1 to space at node 2.  The map is f
```
note that the type of `f` is a `CellularMap`.  `SimplicialMap` is just a convenient way to construct cellular maps which are also simplicial maps.
```python
type(f)
```
```
bats.libbats.CellularMap
```

Now, we apply the Chain functor.  This creates a new diagram of `ChainComplexes` and `ChainMaps`.  We simply have to provide the diagram of spaces and the field we wish to use.  Let's do `F3` coefficients.

```python
CD = bats.Chain(D, bats.F3())
```

Now, we apply the Homology functor.  This creates a new diagram of `ReducedChainComplexes` and induced maps on Homology, stored as matrices.

```python
HD = bats.Hom(CD, 0) # 0 is homology dimension
HD.edge_data(0).tolist() # [[1, 1]]
```
```
[[1, 1]]
```

To extract the barcode, we use the `barcode` function.  We pass in the homology dimension for book-keeping.  The output is a list of `PersistencePairs` which tell us about birth and death indices of homology classes.

```python
ps = bats.barcode(HD, 0) # homology dimension is 0
for p in ps:
    print(p) # output is dimension : (birth, death) <birth basis index, death basis index>
```
```
0 : (0,2) <0,0>
0 : (1,1) <1,1>
```
We see a class that is born at index 0 in the diagram and dies at index 2, and a second class that is only present at index 1, just as we expect.

### Cubical Complexes

We'll now do the same example with a diagram of `CubicalComplexes`

```python
n = 3 # number of spaces

D = bats.CubicalComplexDiagram(n, n-1)

# first, we add CubicalComplexes to the diagram
X = bats.CubicalComplex(1) # 1 is dimension of cubical complex
X.add_recursive([0,1])
D.set_node(0, X) # left node
D.set_node(2, X) # right node

Y = bats.CubicalComplex(1)
Y.add([0, 0])
Y.add([1, 1])
D.set_node(1, Y)

# now, we add maps
f = bats.CubicalMap(Y, X) # inclusion of Y into X
D.set_edge(0, 1, 0, f) # edge 0 maps space at node 1 to space at node 0.  The map is f
D.set_edge(1, 1, 2, f) # edge 1 maps space at node 1 to space at node 2.  The map is f
```

Again, the type of `f` is a `CellularMap` even though we constructed it as a `CubicalMap`.

Again, we then apply the Chain and Hom functors and then extract the barcode

```python
CD = bats.Chain(D, bats.F3())
HD = bats.Hom(CD, 0) # 0 is homology dimension
print("Induced map: {}".format(HD.edge_data(0).tolist())) # [[1, 1]]

ps = bats.barcode(HD, 0)
for p in ps:
    print(p) # output is dimension : (birth, death) <birth basis index, death basis index>
```
```
Induced map: [[1, 1]]
0 : (0,2) <0,0>
0 : (1,1) <1,1>
```

### Cell Complexes

Now we'll use `CellComplexes`.  These are more general, but also not combinatorially defined so they can be a bit more work to deal with if (it's not too bad in this simple example).

```python
n = 3 # number of spaces

D = bats.CellComplexDiagram(n, n-1)

X = bats.CellComplex()
X.add_vertices(2)
# first list is boundary indices, second list is boundary coefficients, final argument is dimension
X.add([0,1], [-1,1], 1)
D.set_node(0, X) # left node
D.set_node(2, X) # right node

Y = bats.CellComplex()
Y.add_vertices(2)
D.set_node(1, Y)

# now we create the map
f = bats.CellularMap(0) # 0-dimensional Cellular map.
f[0] = bats.IntMat(bats.CSCMatrix(2,2,[0,1,2],[0,1],[1,1])) # CSCMatrix to specify map
print("f[0] = {}".format(f[0].tolist())) # identity map on 0-cells
D.set_edge(0, 1, 0, f) # edge 0 maps space at node 1 to space at node 0.  The map is f
D.set_edge(1, 1, 2, f) # edge 1 maps space at node 1 to space at node 2.  The map is f
```
```
f[0] = [[1, 0], [0, 1]]
```

```python
CD = bats.Chain(D, bats.F3())
HD = bats.Hom(CD, 0) # 0 is homology dimension
print("Induced map: {}".format(HD.edge_data(0).tolist())) # [[1, 1]]

ps = bats.barcode(HD, 0)
for p in ps:
    print(p) # output is dimension : (birth, death) <birth basis index, death basis index>
```
```
Induced map: [[1, 1]]
0 : (0,2) <0,0>
0 : (1,1) <1,1>
```

## Zigzag-Filtered Spaces

The above example also works for a zigzag filtered space.  You can construct a zigzag filtration in a way that is similar to a regular filtration.  You simply need to provide entry and exit times.

Our original example had discrete indices, but zigzag filtrations have continuous parameters.  We'll say that the edge was removed for a small interval of radius `0.01` around parameter 1.  Note that if a cell is added and removed at the same parameter, both copies of the cell will be considered present at that instant and the zigzag barcode will be different than if you were to remove one copy and then add the other.

```python
eps = 0.01 # infentesimal
X = bats.ZigzagSimplicialComplex()
X.add(0, 2, [0]) # vertex is present for interval [0,2]
X.add(0, 2, [1]) # vertex is present for interval [0,2]
X.add(0, 1-eps, [0,1]) # edge is present at index 0 but not at index 1
X.add(1+eps, 2, [0,1]) # edge is added back and survives until parameter 2
```

You can see the tuples of entry/exit times of cells stored in a single list for each cell

```python
X.vals()
```
```
[[[(0.0, 2.0)], [(0.0, 2.0)]], [[(0.0, 0.99), (1.01, 2.0)]]]
```

we can now print the Zigzag barcode
```python
ps = bats.ZigzagBarcode(X, 0, bats.F2()) # second argument is maximum homology dimension
for p in ps[0]:
    print(p)
```

The behavior here is a bit different than the diagram.  We see that there are some 0-length zigzag bars at parameters 0 and 2 which are due to the addition of the 0-cells before 1-cells.  To filter these out, we can do the following:

```python
for p in ps[0]:
    if p.length() > 0:
        print(p)
```
```
0 : (0,2) <0(1),0(0)>
0 : (0.99,1.01) <0(0),1(1)>
```
