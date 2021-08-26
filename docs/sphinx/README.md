# How to make documentation
It is recommended to use a separate conda environment to ensure the Sphinx version is correct.
```bash
conda create -n doc-bats python=3
conda activate doc-bats
pip install -r requirements.txt
cd ../..
python setup.py install # installs bats
cd docs/sphinx
make html # makes HTML
```
