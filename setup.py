from setuptools import setup, find_packages

from airly_libs import __version__

setup(
    name='airly_libs',
    version=__version__,

    url='https://github.com/airly-eu/Airly-Python-Libraries',
    author='Airly',
    # author_email='',

    py_modules=find_packages(),
    install_requires=[
        'autopep8>=1.5.7',
        'certifi>=2021.5.30',
        'charset-normalizer>=2.0.3',
        'idna>=3.2',
        'pycodestyle>=2.7.0',
        'requests>=2.26.0',
        'toml>=0.10.2',
        'urllib3>=1.26.6',
    ],
)
