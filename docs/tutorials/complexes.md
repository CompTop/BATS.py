# Complexes and Filtrations

## SimplicialComplex

[Documentation](bats?id=simplicialcomplex)

```python
from bats import SimplicialComplex
C = SimplicialComplex()
```

```python
X = bats.SimplicialComplex()
X.add([0])
X.add([1])
X.add([0,1])
X.print_summary()
X.boundary(1).print()
```

### Add Simplices

Simplices are added as python lists
```python
C.add([0])
C.add([1])
C.add([0,1])
```

### Get Simplices

You can get a list of all simplices in a given dimension
```python
C.get_simplices(0) # [[0], [1]]
G.get_simplices(1) # [[0, 1]]
```

## Cell Complex

[Documentation](bats?id=simplicialcomplex)


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
