#!/usr/bin/env python
from setuptools import setup, Extension
from Cython.Build import cythonize

import subprocess

import numpy as np
try:
    numpy_include = np.get_include()
except AttributeError:
    numpy_include = np.get_numpy_include()


def pkgconfig(package, kw):
    flag_map = {'-I': 'include_dirs', '-L': 'library_dirs', '-l': 'libraries'}
    output = subprocess.getoutput(
        'pkg-config --cflags --libs {}'.format(package))
    for token in output.strip().split():
        kw.setdefault(flag_map.get(token[:2]), []).append(token[2:])
    return kw

extension_kwargs = {
    'sources': [
        'src/ShotSegmentation.cpp',
        'src/Utils.cpp',
        'src/scenedetector.cpp',
        'python/scenedetector.pyx'
    ],
    'include_dirs': [
        'src',
        numpy_include
    ],
    'language': 'c++',
    'libraries': ['pthread'],
    'define_macros' : [('NPY_NO_DEPRECATED_API', 'NPY_1_7_API_VERSION')]
    #'extra_compile_args': ['-O2 -std=c++11 -pthread -Wl,--no-as-needed']
}

extension_kwargs = pkgconfig('opencv4', extension_kwargs)
example_ext = Extension(
    'fastscenedetect', 
    **extension_kwargs)


setup(
    name="fastscenedetect",
    version="0.1",
    ext_modules = cythonize(
        [example_ext],
        annotate=True,
        compiler_directives={'language_level' : "3"}
    ),
    install_requires=[
        'numpy',
        'cython',
        'opencv-python'
    ]
)