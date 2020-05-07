# Linear Algebra

## Fields

The fields `F2 = ModP<int, 2>`, `F3 = ModP<int, 3>`, and `F5 = ModP<int, 5>` are supported.  Additional fields can be added to `libbats.cpp` if desired.

```python
from bats import F2
print(F2(1) + F2(1)) # should be 0
```

## CSCMatrix

```python
A = bats.CSCMatrix(2,2,[0,1,2],[0,1],[-1,-1])
A.print() # prints matrix
A(0,0) # returns -1
```

## Dense Matrices

BATS dense matrices are by default stored in row major order to be compatible with numpy.  

```python
import bats
import numpy as np
Bnp = np.array([[0,1,2],[3,4,5]], dtype=np.float)
B = bats.Matrix(Bnp)
Bnp2 = np.array(B)
```
