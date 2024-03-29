"""Minimal setup file for phonebook project."""

from setuptools import setup, find_packages
setup(
    name='phonebook',
    version='0.1.0',
    description='Manage a collection of phone numbers',
    packages=find_packages('src'),
    package_dir={'':'src'},
    entry_points={
        'console_scripts': ['phonebook=phonebook.cli:main'],
    },

    # metadata
    author='Emily Bache',
    author_email='via Pluralsight',
    license='proprietary',
    install_requires=['pytest']
)