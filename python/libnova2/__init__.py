import os

def load_nova2():
    """
    Helper to add common library paths to LD_LIBRARY_PATH or 
    os.add_dll_directory for Windows before loading libnova2.
    """
    import ctypes
    import sys
    
    lib_name = 'nova2'
    
    # Try finding it in the system first
    try:
        from . import libnova2
        return libnova2
    except ImportError:
        pass
        
    print("Warning: libnova2 shared library not found in standard paths.")
    print("Please ensure libnova2 is installed or LD_LIBRARY_PATH is set.")
    from . import libnova2
    return libnova2

# Expose everything from libnova2 at the top level of the package
from .libnova2 import *

__all__ = [name for name in dir() if not name.startswith('_')]
