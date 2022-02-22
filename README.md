# BATS.py

[![Supported Python Versions](https://img.shields.io/pypi/pyversions/bats-tda.svg)](https://pypi.org/project/bats-tda/)
[![PyPi](https://img.shields.io/pypi/v/bats-tda.svg)](https://pypi.org/project/bats-tda/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

[![Build Static](https://github.com/CompTop/BATS.py/actions/workflows/build-static.yml/badge.svg)](https://github.com/CompTop/BATS.py/actions/workflows/build-static.yml)
[![Ubuntu Tests](https://github.com/CompTop/BATS.py/workflows/ubuntu-latest/badge.svg)](https://github.com/CompTop/BATS.py/actions/workflows/ubuntu-latest.yml)
[![MacOS Tests](https://github.com/CompTop/BATS.py/workflows/macos-latest/badge.svg)](https://github.com/CompTop/BATS.py/actions/workflows/macos-latest.yml)
[![Documentation Status](https://readthedocs.org/projects/bats-tda/badge/?version=latest)](https://bats-tda.readthedocs.io/en/latest/?badge=latest)


Python bindings for the [Basic Applied Topology Subprograms (BATS) library](https://github.com/CompTop/BATS).
This includes:
* Simplicial, Cubical, and Cell Complexes
* Simplicial, Cubical, and Cellular Maps
* Homology and induced maps
* Persistent homology
* Zigzag homology
* A variety of topolgical constructions

Note that the C++ repository is the main library, and contains more features.  This repository provides bindings for a subset of the functionality of BATS, and is under active development.

Documentation, examples, and tutorials can be found at [bats-tda.readthedocs.io](https://bats-tda.readthedocs.io/en/latest/)

Once installed, you can import the `bats` namespace:
```python
import bats
```

## Installation with pip

The easiest way to install `bats` is using `pip`
```
pip install bats-tda # gcc
```
To use clang (e.g. on a Mac) try
```
CC=clang pip install bats-tda # clang
```

Because `bats` uses OpenMP, it has to be compiled from source with a C++17 compliant complier.  This means installation can take a few minutes.  You can pass `--verbose` to `pip` to see what is going on with installation.

If you don't have OpenMP, you can install with a package manager.

GCC (e.g. on Linux)
```
dnf install libgomp-devel # Fedora
```
```
apt-get install libgomp1-dev # Ubuntu
```

Clang (e.g. on Mac)
```
brew install libomp
```
