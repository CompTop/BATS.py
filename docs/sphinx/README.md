# How to make documentation
It is recommended to use a separate conda environment to ensure the Sphinx version is correct.
```bash
conda create -n doc-bats python=3
conda activate doc-bats 
pip install -r requirements.txt
conda install -c anaconda scipy
cd ../..
python setup.py install # installs bats
conda install -c conda-forge pandoc
conda install -c conda-forge ipython
conda install -c conda-forge ipykernel
conda install ipython notebook
```

Then, you are free to build documentation locally by Sphinx.
```bash
conda activate doc-bats
pip install -r requirements.txt
cd ../..
python setup.py install # installs bats
cd docs/sphinx
make html # makes HTML
```
