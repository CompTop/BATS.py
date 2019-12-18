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
