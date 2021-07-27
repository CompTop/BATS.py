# Diagrams

## Diagrams

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
ND = bats.NerveDiagram(D, 1)

# F2 Chain functor applied to diagram of spaces
CD = bats.F2Chain(ND)

# Hom functor applied to diagram of Chain complexes
HD = bats.Hom(CD, 0)

# extract barcode
PD = bats.barcode(HD, 0)

for p in PD:
    print(p)
```
```
0 : (0,2) <0,0>
0 : (1,1) <1,1>
```
