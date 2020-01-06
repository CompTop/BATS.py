# setup file to compile C++ library

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys, os
import setuptools

this_dir = os.path.dirname(os.path.realpath(__file__))
include_dirs = [
this_dir + '/BATS_include/include/',
this_dir + '/pybind11/include/'
]
extra = {'cxx': ['-std=c++17', '-fopenmp']} # '-fopenmp'

__version__ = '0.0.0'


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


setup(
    name='bats',
    version=__version__,
    author='Brad Nelson',
    author_email='bradnelson@stanford.edu',
    ext_modules=ext_modules,
    zip_safe=False
)
