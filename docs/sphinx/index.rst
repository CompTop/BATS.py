.. Basic Applied Topology Subprograms documentation master file, created by
   sphinx-quickstart on Thu Aug 19 22:24:14 2021.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to Basic Applied Topology Subprograms Python Bindings!
==============================================================

Python bindings for the `BATS library <https://github.com/CompTop/BATS>`_.
This includes:

* Simplicial, Cubical, and Cell Complexes
* Simplicial, Cubical, and Cellular Maps
* Homology and induced maps
* Persistent homology
* Zigzag homology
* A variety of topolgical constructions

Note that the C++ repository is the main library, and contains more features.  This repository provides bindings for a subset of the functionality of BATS, and is under active development.

For background on what this repository does, refer to the paper `Persistent and Zigzag Homology: A Matrix Factorization Viewpoint <https://arxiv.org/abs/1911.10693>`_ by Gunnar Carlsson, Anjan Dwaraknath, and Bradley J. Nelson.

Get Started
-----------
First, `install BATS.py <installation.html>`_.

Now, you can load BATS in python via

.. code-block:: python

   import bats


Next, check out the `quickstart guide <quickstart.html>`_.


.. toctree::
   :maxdepth: 2
   :caption: Contents:

   installation
   quickstart
   tutorials/index
   examples/index
   api
   about



Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
