# Chain Complexes and Reduction

## Chain Complexes

A chain complex can be obtained from a simplicial or cell complex via the chain functor

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
