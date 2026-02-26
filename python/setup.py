from setuptools import setup, find_packages

setup(
    name='libnova2',
    version='0.1.0',
    description='Python ctypes bindings for libnova',
    author='libnova contributors',
    packages=['libnova2'],
    package_data={'libnova2': ['*.py']},
)
