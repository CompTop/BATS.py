# setup file to compile C++ library
import setuptools
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys, os

# from pybind11.setup_helpers import Pybind11Extension, build_ext


this_dir = os.path.dirname(os.path.realpath(__file__))
include_dirs = [
this_dir + '/BATS_include/include/',
this_dir + '/pybind11/include/'
]
extra = {'cxx': ['-std=c++17', '-fopenmp']} # '-fopenmp'

__version__ = '0.0.1'


ext_modules = [
    Extension(
        'bats.libbats',
        ['bats/libbats.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=["-lgomp"],
        language='c++'
    ),
    Extension(
        'bats.topology',
        ['bats/topology.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=["-lgomp"],
        language='c++'
    ),
    Extension(
        'bats.dense',
        ['bats/dense.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=["-lgomp"],
        language='c++'
    ),
    Extension(
        'bats.diagram',
        ['bats/diagram.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=["-lgomp"],
        language='c++'
    ),
]

with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

setup(
    name='bats-tda',
    version=__version__,
    author='Brad Nelson',
    author_email='bradnelson@uchicago.edu',
    packages=['bats','bats.visualization'],
    ext_modules=ext_modules,
    zip_safe=False,
    description="Python bindings for the Basic Applied Topology Subprograms",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/CompTop/BATS.py",
    project_urls={
        "Bug Tracker": "https://github.com/CompTop/BATS.py/issues",
    },
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'Intended Audience :: Education',
        'Intended Audience :: Science/Research',
        'Topic :: Software Development :: Libraries :: Python Modules',
        'Topic :: Utilities',
        'Topic :: Scientific/Engineering :: Mathematics',
        'Programming Language :: C++',
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',
        'Operating System :: POSIX :: Linux'
    ],
    install_requires=[
        'numpy',
        'matplotlib',
      ],
    python_requires=">=3.7",
    keywords='algebraic topology, topological data analysis, persistent homology, zigzag homology',
)
