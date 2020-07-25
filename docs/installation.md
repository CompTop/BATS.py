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

```bash
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
