# Complexes and Filtrations

## SimplicialComplex

[Documentation](bats?id=simplicialcomplex)

```python
from bats import SimplicialComplex
C = SimplicialComplex()
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
