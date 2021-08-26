# How to make documentation
I highly recommend using a separate conda environment:
```bash
conda create -n doc-bats python=3
conda activate doc-bats 
pip install -r requirements.txt 
CC=clang pip install bats-tda # or pip install bats-tda
python3 -m pip install nbsphinx
conda install -c conda-forge pandoc
conda install -c conda-forge ipython
conda install -c conda-forge ipykernel
conda install ipython notebook
conda install -c anaconda scipy
```