from setuptools import setup, find_packages

from FilesManager import __version__

setup(
    name='airly_libs',
    version=__version__,

    url='https://github.com/airly-eu/Airly-Python-Libraries',
    author='Airly',
    # author_email='',

    py_modules=find_packages(),
    install_requires=[

    ],
)
