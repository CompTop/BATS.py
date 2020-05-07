## BATS.py
Python bindings for the [BATS library](https://github.com/bnels/BATS).

Note that the C++ repository is the main library, and contains more features.  This repository provides bindings for a subset of the functionality of BATS, and is under active development.

For background on what this repository does, refer to the paper [Persistent and Zigzag Homology: A Matrix Factorization Viewpoint](https://arxiv.org/abs/1911.10693) by Gunnar Carlsson, Anjan Dwaraknath, and Bradley J. Nelson.



# Interface

You can load BATS via
```python
import bats
````

## Fields

The fields `F2 = ModP<int, 2>`, `F3 = ModP<int, 3>`, and `F5 = ModP<int, 5>` are supported.  Additional fields can be added to `libbats.cpp` if desired.

```python
from bats import F2
print(F2(1) + F2(1)) # should be 0
```

## SimplicialComplex

```python
X = bats.SimplicialComplex()
X.add([0])
X.add([1])
X.add([0,1])
X.print_summary()
X.boundary(1).print()
```

## CSCMatrix

```python
A = bats.CSCMatrix(2,2,[0,1,2],[0,1],[-1,-1])
A.print() # prints matrix
A(0,0) # returns -1
```

## ChainComplex

```python
X = bats.SimplicialComplex()
X.add([0])
X.add([1])
X.add([0,1])

C2 = bats.F2ChainComplex(X)
C3 = bats.F3ChainComplex(X)
```

## Reduced Chain Complex

```python
R2 = bats.ReducedF2ChainComplex(C2)

R2.hdim(1) # = 1

v = bats.F2Vector([1], [bats.F2(1)])
print(v[0], v[1], v[2]) # 0 1 0

R2.find_preferred_representative(v, 0)
print(v[0], v[1], v[2]) # 1 0 0

# get preferred rep for first basis element in dim 0
v = R2.get_preferred_representative(0,0)
print(v[0], v[1], v[2]) # 1 0 0
```

## Dense Matrices

BATS dense matrices are by default stored in column major order.  For numpy compatibility, use the
`order='F'` flag when initializing an array to pass to BATS.  

```python
import bats
import numpy as np
Bnp = np.array([[0,1,2],[3,4,5]], dtype=np.float, order='F')
B = bats.DenseDoubleMatrix(Bnp)
Bnp2 = np.array(B)
```

You can check `Bnp.flags` to see `C_CONTIGUOUS : False, F_CONTIGUOUS : True`

# Diagrams

Several Types of diagrams are available for use
```python
import bats

c1 = [{0,1}, {1,2}]
c2 = [{0,2}, {0,1}]
c3, f1, f2 = bats.bivariate_cover(c1, c2)

D = bats.CoverDiagram(3,2)
D.set_node(0, c1)
D.set_node(1, c3)
D.set_node(2, c2)
D.set_edge(0, 1, 0, f1)
D.set_edge(1, 1, 2, f2)

# Nerve Functor applied to cover diagram
ND = bats.Nerve(D, 0)

# F2 Chain functor applied to diagram of spaces
bats.F2Chain(ND)

```

# Filtrations

BATS also exposes functionality for filtered verisons of `SimplicialComplex`, `ChainComplex`, and `ReducedChainComplex`

```python
import bats

# create FilteredSimplicialComplex
F = bats.FilteredSimplicialComplex()
F.add(0.0, [0])
F.add(0.0, [1])
F.add(0.0, [2])
F.add(1.0, [0,1])
F.add(1.0, [0,2])
F.add(1.0, [1,2])

FC2 = bats.FilteredF2ChainComplex(F)

RFC2 = bats.ReducedFilteredF2ChainComplex(FC2)

# H1, first generator
p = RFC2.persistence_pairs(1)[0]

# extract a homology representative for the generator
v = RFC2.representative(p)
```
