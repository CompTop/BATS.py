# BATS.py

[![PyPi](https://img.shields.io/pypi/v/bats-tda.svg)](https://pypi.org/project/bats-tda/)
[![CI](https://github.com/CompTop/BATS.py/workflows/ubuntu-latest/badge.svg)](https://github.com/CompTop/BATS.py/actions)
[![CI](https://github.com/CompTop/BATS.py/workflows/macos-latest/badge.svg)](https://github.com/CompTop/BATS.py/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Python bindings for the [Basic Applied Topology Subprograms (BATS) library](https://github.com/CompTop/BATS).
This includes:
* Simplicial, Cubical, and Cell Complexes
* Simplicial, Cubical, and Cellular Maps
* Homology and induced maps
* Persistent homology
* Zigzag homology
* A variety of topolgical constructions

Note that the C++ repository is the main library, and contains more features.  This repository provides bindings for a subset of the functionality of BATS, and is under active development.

Documentation, examples, and tutorials can be found at [comptop.github.io/BATS.py](https://comptop.github.io/BATS.py/#/)

Once installed, you can import the `bats` namespace:
```python
import bats
```

## Installation with pip

```
pip install bats-tda
```

Note that you need a C++17 compiler and OpenMP installed.  You can also build from source.
