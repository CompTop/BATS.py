# setup file to compile C++ library
import setuptools
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys, os
import distutils
import platform
# from pybind11.setup_helpers import Pybind11Extension, build_ext
sys.path = [os.path.dirname(os.path.abspath(sys.argv[0])) + '/bats'] + sys.path
from _version import __version__
sys.path = sys.path[1:]


this_dir = os.path.dirname(os.path.realpath(__file__))
include_dirs = [
this_dir + '/BATS_include/include/',
this_dir + '/pybind11/include/'
]

# print('default compiler:', distutils.ccompiler.get_default_compiler())
print('default compiler:', platform.python_compiler()[:5] )

clang = False
try:
    if os.environ['CC'] == "clang":
        clang = True
except KeyError:
    clang = False

# if clang or distutils.ccompiler.get_default_compiler() == 'clang':
if clang or platform.python_compiler()[:5] == 'Clang':
    # We're using clang
    extra = {'cxx': ['-std=c++17']} # '-fopenmp'
    extra_link = ['-lomp']
else:
    # assume we're using gcc
    extra = {'cxx': ['-std=c++17', '-fopenmp', '-march=native']} # '-fopenmp'
    extra_link = ['-lgomp']


ext_modules = [
    Extension(
        'bats.linalg',
        ['bats/linalg.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=extra_link,
        language='c++'
    ),
    Extension(
        'bats.linalg_f2',
        ['bats/linalg_f2.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=extra_link,
        language='c++'
    ),
    Extension(
        'bats.linalg_f3',
        ['bats/linalg_f3.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=extra_link,
        language='c++'
    ),
    Extension(
        'bats.linalg_auto',
        ['bats/linalg_auto.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=extra_link,
        language='c++'
    ),
    Extension(
        'bats.topology',
        ['bats/topology.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=extra_link,
        language='c++'
    ),
    Extension(
        'bats.dense',
        ['bats/dense.cpp'],
        include_dirs=include_dirs,
        extra_compile_args=extra['cxx'],
        extra_link_args=extra_link,
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
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'License :: OSI Approved :: MIT License',
        'Operating System :: POSIX :: Linux',
        'Operating System :: MacOS :: MacOS X'
    ],
    python_requires=">=3.6",
    keywords='algebraic topology, topological data analysis, persistent homology, zigzag homology',
)
