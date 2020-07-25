# Cubical Complexes

In this example, we'll now see how to create cubical complexes using toplices, and how to compute a zigzag diagram through levelsets of an image.

```python
import bats
import numpy as np
import matplotlib.pyplot as plt
```

## Cubical Complexes

In BATS, cubical complexes are given a maximal dimension.

```python
X = bats.CubicalComplex(3) # 3 = max dimension
```

maximum dimension cubes are defined by a list of length `2*d`, where `d` is the dimension
```python
[0,1,1,2,0,1] # cube (0,1) x (1,2) x (0,1)
```

lower dimensional cubes have degeneracies, but are still a list of length `2*d`
```python
[0,0,1,2,1,1] # cube (0) x (1,2) x (1)
```

## Toplex

A toplex is a complex described by maximum dimension cells.  All faces that must exist exist.  Cubical complexes can be created by adding these top-level cells.

```python
X.add_recursive([0,1,0,1,0,1]) # adds cube (0,1) x (0,1) x (0,1)
print(X.ncells()) # 27
```

## Image Levelset Zigzag

Images are a common way to obtain cubical complexes.  Let's generate one.

```python
# generate image
m = 100
n = 100
A = np.empty((m,n))
for i in range(m):
    for j in range(n):
        A[i,j] = np.sin(i/10) * np.cos(j/10)
plt.imshow(A)
```
![image](figures/cubical_image.png")

We'll zigzag through cubical complexes defined by level sets and their unions:

```python
lsets = [[x/10, (x+2)/10] for x in range(-10,9,1)]
```

We'll operate on boolean images which indicate the support of each level set.  The first thing to do is to compute top-level cubes from these images
```python
def to_toplexes(A):
    """
    Create list of toplexes from boolean array A

    assume 2-dimensional for now
    """
    dims = A.shape
    toplex_list = []
    for i in range(dims[0]-1):
        for j in range(dims[1]-1):
            if (A[i,j] and A[i+1,j] and A[i,j+1] and A[i+1,j+1]):
                toplex_list.append([i,i+1,j,j+1])

    return toplex_list
```

Then we turn this list of cubes into a complex
```python
def image_to_complex(A):
    """
    Create cubical complex from boolean image A
    """
    toplex_list = to_toplexes(A)
    X = bats.CubicalComplex(2)
    for t in toplex_list:
        X.add_recursive(t)
    return X
```

Let's now create our diagram of complexes:
```python
# create diagram of cubical complexes
D = bats.CubicalComplexDiagram()
for i in range(len(lsets)):
    lb = lsets[i][0]
    ub = lsets[i][1]
    AL = np.logical_and(lb < A, A < ub)
    ii = D.add_node(image_to_complex(AL))

    if i != 0:
        # add edge to previous union
        D.add_edge(ii, ii-1, bats.CubicalMap(D.node_data(ii), D.node_data(ii-1)))

    if i != len(lsets)-1:
        # add node for union
        ub = lsets[i+1][1]
        AL = np.logical_and(lb < A, A < ub)
        D.add_node(image_to_complex(AL))

        # add edge to union
        D.add_edge(ii, ii+1, bats.CubicalMap(D.node_data(ii), D.node_data(ii+1)))
```

And we can compute the zigzag barcode:
```python
FD = bats.Chain(D, bats.F2()) # F2 coefficients

ps = []
for hdim in range(2):
    RD = bats.Hom(FD, hdim)
    ps.extend(bats.barcode(RD, hdim))

fig, ax = bats.visualization.persistence_barcode(ps)
```
![diagram](figures/cubical_levelset_zz.png)
