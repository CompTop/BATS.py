# Linear Algebra

## Fields

The fields `F2 = ModP<int, 2>`, `F3 = ModP<int, 3>`, and `F5 = ModP<int, 5>` are supported.  Additional fields can be added to `libbats.cpp` if desired.

```python
from bats import F2
print(F2(1) + F2(1)) # should be 0
```

## Vectors

Sparse vectors for each supported field class are available: `F2Vector`, `F3Vector`, etc. as well as an `IntVector`.

The easiest way to construct these vectors is from a list of tuples, where each tuple contains a index-value pair (where the value is an integer - it will be cast to the relevant field).

```python
from bats import F2Vector
v = F2Vector([(0,1), (2,1)])
```

## Matrices
### CSCMatrix

```python
A = bats.CSCMatrix(2,2,[0,1,2],[0,1],[-1,-1])
A.print() # prints matrix
A(0,0) # returns -1
```

To construct a `CSCMatrix` using `scipy.sparse`:
```python
import scipy.sparse as sparse

# create 2x2 identity matrix
data = [1, 1]
row = [0,1,2]
col = [0, 1]
A = sparse.csc_matrix((data, col, row), shape=[2,2])

# create BATS CSCMatrix
Ab = bats.CSCMatrix(*A.shape, A.indptr, A.indices, A.data)
```
You could also construct the `scipy.sparse` `csc_matrix` in a variety of different ways before passing to BATS.

### Column Matrices

Column matrices can be created from `CSCMatrix`
```python
A = bats.CSCMatrix(2,2,[0,1,2],[0,1],[1,1]) # 2x2 identity
C = bats.IntMat(A)
C2 = bats.F2Mat(A)
C3 = bats.F3mat(A)
CQ = bats.RationalMat(A)
```

You can also use `bats.Mat` and pass in the field.
```python
C = bats.Mat(A) # IntMat
C = bats.Mat(A, bats.F2()) # F2Mat
```

In order to get the contents of a ColumnMatrix in Python, use the `tolist()` method
```python
C.tolist()
```

You can add columns of the appropriate type to a column matrix
```python
A = bats.F2Mat(3,0)
A.append_column(bats.F2Vector([(0,1), (1,1)]))
A.append_column(bats.F2Vector([(0,1), (2,1)]))
A.append_column(bats.F2Vector([(1,1), (2,1)]))
np.array(A.tolist()) # this will display the matrix in a nice way
```

To generate an identity matrix, just pass the desired size and relevant field type to `bats.Identity`
```python
I = bats.Identity(3, bats.F2())
```

### Dense Matrices

BATS dense matrices are by default stored in row major order to be compatible with numpy.  

```python
import bats
import numpy as np
Bnp = np.array([[0,1,2],[3,4,5]], dtype=np.float)
B = bats.Matrix(Bnp)
Bnp2 = np.array(B)
```
