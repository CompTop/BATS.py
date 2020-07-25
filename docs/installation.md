## Setup

```bash
conda create -n bats python=3
conda install numpy matplotlib
```

if you want to use ipython notebooks, you may want to install
```bash
conda install ipython notebook
```

clone repository *use recursive option for submodules*
```bash
git clone --recursive git@github.com:bnels/BATS.py.git
```
or if you want to use `https` protocol:
```bash
git clone --recursive https://github.com/bnels/BATS.py.git
```

Assuming you cloned the repository successfully, just move to the root directory of the repository and install
```bash
cd BATS.py
python setup.py install
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

## Upgrading

If you want to update BATS.py to the latest development version, you need to pull and re-build.
From the repository root directory:
```bash
git pull --recurse-submodules
python setup.py install
```
