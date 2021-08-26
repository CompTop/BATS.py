# How to make documentation
I highly recommend using a separate conda environment:
```bash
conda create -n doc-bats python=3
conda activate doc-bats 
pip install -r requirements.txt 
CC=clang pip install bats-tda # or pip install bats-tda
```