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

You can also use `bats.Chain`:
```python
C2 = bats.Chain(X, bats.F2())
C3 = bats.Chain(X, bats.F3())
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

## `bats.reduce`

You can use `bats.reduce` to create a reduced chain complex from either a `SimplicialComplex`, or `ChainComplex`

For a chain complex:
```python
C = bats.Chain(X, bats.F2())
R = bats.reduce(C)
```

You can also skip the explicit chain complex construction for `SimplicialComplex`
```python
R = bats.reduce(X, bats.F2())
```

### Reduction Flags

You can provide a variety of flags to `bats.reduce` which govern behavior of the reduction algorithm.

**Algorithm Flags**
* `bats.standard_reduction_flag()` - standard reduction algorithm
* `bats.extra_reduction_flag()` - eliminates all entries to the right of a pivot, even when not necessary for reduction

**Optimization Flags**
* `bats.clearing_flag()` - performs clearing optimization
* `bats.compression_flag()` - performs compression optimization

**Basis Flags**
By default, when you pass in flags, the basis is not computed, which is fine when you just want the betti numbers or a persistence diagram. If you want to compute the basis, you can use `bats.compute_basis_flag()`, with either no optimizations, or the compression optimization.  You can not compute the basis with the clearing optimization.

**Valid Combinations**
When using flags, you must always first provide an algorithm flag.  This is followed by an optional algorithm flag, and then an optional basis flag.

```python
flags = (
    bats.standard_reduction_flag(), bats.compression_flag(), bats.compute_basis_flag()
)

R = bats.reduce(X, bats.F2(), *flags)
```

* You can only get homology generators if you compute a basis
* You must compute a basis and not use optimizations to compute induced maps.

**Performance**
Computing a basis will always be slower than not computing a basis.

Clearing or compression optimizations will almost always be faster than not using them.  Which optimization is better can be problem dependent.

The choice of reduction algorithm can also affect performance.  The `bats.extra_reduction_flag()` is sometimes faster than the standard reduction - this may be because it encourages sparsity.

As a suggestion, try using
```python
bats.standard_reduction_flag(), bats.compression_flag()
```
and see how this compares to just using
```python
bats.standard_reduction_flag()
```
