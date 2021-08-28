# How to make documentation
It is recommended to use a separate conda environment to ensure the Sphinx version is correct.
```bash
conda create -n doc-bats python=3
conda activate doc-bats 
conda install -c anaconda scipy # install scipy
cd ../..
python setup.py install # install bats
```

Then, you need to install necessary packages for Sphinx
```bash
pip install -r requirements.txt
conda install -c conda-forge pandoc
conda install -c conda-forge ipython
conda install -c conda-forge ipykernel
conda install ipython notebook
```

Finally, you are free to build documentation locally by Sphinx.
```bash
cd docs/sphinx
make html # makes HTML
```
