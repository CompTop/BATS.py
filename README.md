# BATS.py
Python bindings for the BATS library

```bash
conda create -n bats python=3
```

clone repository *use recursive option for submodules*
```bash
git clone --recursive git@github.com:bnels/BATS.py.git
```


## Development

build in directory
```bash
python setup.py build_ext --inplace
```

update submodules
```bash
git submodule update --remote
```

pull and update submodules
```bash
git pull --recurse-submodules
```

# Interface

You can load BATS via
```python
import bats
````

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
