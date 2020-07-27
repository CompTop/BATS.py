# Testing

BATS.py uses the `unittest` framework. See [documentation here](https://docs.python.org/3.8/library/unittest.html).

There are also unit tests in the BATS C++ repository.

## Running all tests

First, you need to have the `bats` module built in-place.
```bash
python setup.py build_ext --inplace
```

From the root of the repository, run
```bash
python -m unittest discover
```


## Running individual test files

From `BATS.py/test`, you can run individual test files
```bash
python -m unittest simplicial.py
```
