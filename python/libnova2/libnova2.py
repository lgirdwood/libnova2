r"""Wrapper for aberration.h

Generated with:
/home/lrg/.local/bin/ctypesgen -l nova2 -a -I /home/lrg/source/libnova/src/ -o /home/lrg/source/libnova/python/libnova/libnova2.py /home/lrg/source/libnova/src/libnova2/aberration.h /home/lrg/source/libnova/src/libnova2/airmass.h /home/lrg/source/libnova/src/libnova2/angular_separation.h /home/lrg/source/libnova/src/libnova2/apparent_position.h /home/lrg/source/libnova/src/libnova2/asteroid.h /home/lrg/source/libnova/src/libnova2/comet.h /home/lrg/source/libnova/src/libnova2/constellation.h /home/lrg/source/libnova/src/libnova2/dynamical_time.h /home/lrg/source/libnova/src/libnova2/earth.h /home/lrg/source/libnova/src/libnova2/elliptic_motion.h /home/lrg/source/libnova/src/libnova2/heliocentric_time.h /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h /home/lrg/source/libnova/src/libnova2/julian_day.h /home/lrg/source/libnova/src/libnova2/jupiter.h /home/lrg/source/libnova/src/libnova2/libnova2.h /home/lrg/source/libnova/src/libnova2/ln_types.h /home/lrg/source/libnova/src/libnova2/lunar.h /home/lrg/source/libnova/src/libnova2/mars.h /home/lrg/source/libnova/src/libnova2/mercury.h /home/lrg/source/libnova/src/libnova2/neptune.h /home/lrg/source/libnova/src/libnova2/nutation.h /home/lrg/source/libnova/src/libnova2/parabolic_motion.h /home/lrg/source/libnova/src/libnova2/parallax.h /home/lrg/source/libnova/src/libnova2/pluto.h /home/lrg/source/libnova/src/libnova2/precession.h /home/lrg/source/libnova/src/libnova2/proper_motion.h /home/lrg/source/libnova/src/libnova2/refraction.h /home/lrg/source/libnova/src/libnova2/rise_set.h /home/lrg/source/libnova/src/libnova2/saturn.h /home/lrg/source/libnova/src/libnova2/sidereal_time.h /home/lrg/source/libnova/src/libnova2/solar.h /home/lrg/source/libnova/src/libnova2/transform.h /home/lrg/source/libnova/src/libnova2/uranus.h /home/lrg/source/libnova/src/libnova2/utility.h /home/lrg/source/libnova/src/libnova2/venus.h /home/lrg/source/libnova/src/libnova2/vsop87.h

Do not modify this file.
"""

__docformat__ = "restructuredtext"

# Begin preamble for Python

import ctypes
import sys
from ctypes import *  # noqa: F401, F403

_int_types = (ctypes.c_int16, ctypes.c_int32)
if hasattr(ctypes, "c_int64"):
    # Some builds of ctypes apparently do not have ctypes.c_int64
    # defined; it's a pretty good bet that these builds do not
    # have 64-bit pointers.
    _int_types += (ctypes.c_int64,)
for t in _int_types:
    if ctypes.sizeof(t) == ctypes.sizeof(ctypes.c_size_t):
        c_ptrdiff_t = t
del t
del _int_types



class UserString:
    def __init__(self, seq):
        if isinstance(seq, bytes):
            self.data = seq
        elif isinstance(seq, UserString):
            self.data = seq.data[:]
        else:
            self.data = str(seq).encode()

    def __bytes__(self):
        return self.data

    def __str__(self):
        return self.data.decode()

    def __repr__(self):
        return repr(self.data)

    def __int__(self):
        return int(self.data.decode())

    def __long__(self):
        return int(self.data.decode())

    def __float__(self):
        return float(self.data.decode())

    def __complex__(self):
        return complex(self.data.decode())

    def __hash__(self):
        return hash(self.data)

    def __le__(self, string):
        if isinstance(string, UserString):
            return self.data <= string.data
        else:
            return self.data <= string

    def __lt__(self, string):
        if isinstance(string, UserString):
            return self.data < string.data
        else:
            return self.data < string

    def __ge__(self, string):
        if isinstance(string, UserString):
            return self.data >= string.data
        else:
            return self.data >= string

    def __gt__(self, string):
        if isinstance(string, UserString):
            return self.data > string.data
        else:
            return self.data > string

    def __eq__(self, string):
        if isinstance(string, UserString):
            return self.data == string.data
        else:
            return self.data == string

    def __ne__(self, string):
        if isinstance(string, UserString):
            return self.data != string.data
        else:
            return self.data != string

    def __contains__(self, char):
        return char in self.data

    def __len__(self):
        return len(self.data)

    def __getitem__(self, index):
        return self.__class__(self.data[index])

    def __getslice__(self, start, end):
        start = max(start, 0)
        end = max(end, 0)
        return self.__class__(self.data[start:end])

    def __add__(self, other):
        if isinstance(other, UserString):
            return self.__class__(self.data + other.data)
        elif isinstance(other, bytes):
            return self.__class__(self.data + other)
        else:
            return self.__class__(self.data + str(other).encode())

    def __radd__(self, other):
        if isinstance(other, bytes):
            return self.__class__(other + self.data)
        else:
            return self.__class__(str(other).encode() + self.data)

    def __mul__(self, n):
        return self.__class__(self.data * n)

    __rmul__ = __mul__

    def __mod__(self, args):
        return self.__class__(self.data % args)

    # the following methods are defined in alphabetical order:
    def capitalize(self):
        return self.__class__(self.data.capitalize())

    def center(self, width, *args):
        return self.__class__(self.data.center(width, *args))

    def count(self, sub, start=0, end=sys.maxsize):
        return self.data.count(sub, start, end)

    def decode(self, encoding=None, errors=None):  # XXX improve this?
        if encoding:
            if errors:
                return self.__class__(self.data.decode(encoding, errors))
            else:
                return self.__class__(self.data.decode(encoding))
        else:
            return self.__class__(self.data.decode())

    def encode(self, encoding=None, errors=None):  # XXX improve this?
        if encoding:
            if errors:
                return self.__class__(self.data.encode(encoding, errors))
            else:
                return self.__class__(self.data.encode(encoding))
        else:
            return self.__class__(self.data.encode())

    def endswith(self, suffix, start=0, end=sys.maxsize):
        return self.data.endswith(suffix, start, end)

    def expandtabs(self, tabsize=8):
        return self.__class__(self.data.expandtabs(tabsize))

    def find(self, sub, start=0, end=sys.maxsize):
        return self.data.find(sub, start, end)

    def index(self, sub, start=0, end=sys.maxsize):
        return self.data.index(sub, start, end)

    def isalpha(self):
        return self.data.isalpha()

    def isalnum(self):
        return self.data.isalnum()

    def isdecimal(self):
        return self.data.isdecimal()

    def isdigit(self):
        return self.data.isdigit()

    def islower(self):
        return self.data.islower()

    def isnumeric(self):
        return self.data.isnumeric()

    def isspace(self):
        return self.data.isspace()

    def istitle(self):
        return self.data.istitle()

    def isupper(self):
        return self.data.isupper()

    def join(self, seq):
        return self.data.join(seq)

    def ljust(self, width, *args):
        return self.__class__(self.data.ljust(width, *args))

    def lower(self):
        return self.__class__(self.data.lower())

    def lstrip(self, chars=None):
        return self.__class__(self.data.lstrip(chars))

    def partition(self, sep):
        return self.data.partition(sep)

    def replace(self, old, new, maxsplit=-1):
        return self.__class__(self.data.replace(old, new, maxsplit))

    def rfind(self, sub, start=0, end=sys.maxsize):
        return self.data.rfind(sub, start, end)

    def rindex(self, sub, start=0, end=sys.maxsize):
        return self.data.rindex(sub, start, end)

    def rjust(self, width, *args):
        return self.__class__(self.data.rjust(width, *args))

    def rpartition(self, sep):
        return self.data.rpartition(sep)

    def rstrip(self, chars=None):
        return self.__class__(self.data.rstrip(chars))

    def split(self, sep=None, maxsplit=-1):
        return self.data.split(sep, maxsplit)

    def rsplit(self, sep=None, maxsplit=-1):
        return self.data.rsplit(sep, maxsplit)

    def splitlines(self, keepends=0):
        return self.data.splitlines(keepends)

    def startswith(self, prefix, start=0, end=sys.maxsize):
        return self.data.startswith(prefix, start, end)

    def strip(self, chars=None):
        return self.__class__(self.data.strip(chars))

    def swapcase(self):
        return self.__class__(self.data.swapcase())

    def title(self):
        return self.__class__(self.data.title())

    def translate(self, *args):
        return self.__class__(self.data.translate(*args))

    def upper(self):
        return self.__class__(self.data.upper())

    def zfill(self, width):
        return self.__class__(self.data.zfill(width))


class MutableString(UserString):
    """mutable string objects

    Python strings are immutable objects.  This has the advantage, that
    strings may be used as dictionary keys.  If this property isn't needed
    and you insist on changing string values in place instead, you may cheat
    and use MutableString.

    But the purpose of this class is an educational one: to prevent
    people from inventing their own mutable string class derived
    from UserString and than forget thereby to remove (override) the
    __hash__ method inherited from UserString.  This would lead to
    errors that would be very hard to track down.

    A faster and better solution is to rewrite your program using lists."""

    def __init__(self, string=""):
        self.data = string

    def __hash__(self):
        raise TypeError("unhashable type (it is mutable)")

    def __setitem__(self, index, sub):
        if index < 0:
            index += len(self.data)
        if index < 0 or index >= len(self.data):
            raise IndexError
        self.data = self.data[:index] + sub + self.data[index + 1 :]

    def __delitem__(self, index):
        if index < 0:
            index += len(self.data)
        if index < 0 or index >= len(self.data):
            raise IndexError
        self.data = self.data[:index] + self.data[index + 1 :]

    def __setslice__(self, start, end, sub):
        start = max(start, 0)
        end = max(end, 0)
        if isinstance(sub, UserString):
            self.data = self.data[:start] + sub.data + self.data[end:]
        elif isinstance(sub, bytes):
            self.data = self.data[:start] + sub + self.data[end:]
        else:
            self.data = self.data[:start] + str(sub).encode() + self.data[end:]

    def __delslice__(self, start, end):
        start = max(start, 0)
        end = max(end, 0)
        self.data = self.data[:start] + self.data[end:]

    def immutable(self):
        return UserString(self.data)

    def __iadd__(self, other):
        if isinstance(other, UserString):
            self.data += other.data
        elif isinstance(other, bytes):
            self.data += other
        else:
            self.data += str(other).encode()
        return self

    def __imul__(self, n):
        self.data *= n
        return self


class String(MutableString, ctypes.Union):

    _fields_ = [("raw", ctypes.POINTER(ctypes.c_char)), ("data", ctypes.c_char_p)]

    def __init__(self, obj=b""):
        if isinstance(obj, (bytes, UserString)):
            self.data = bytes(obj)
        else:
            self.raw = obj

    def __len__(self):
        return self.data and len(self.data) or 0

    def from_param(cls, obj):
        # Convert None or 0
        if obj is None or obj == 0:
            return cls(ctypes.POINTER(ctypes.c_char)())

        # Convert from String
        elif isinstance(obj, String):
            return obj

        # Convert from bytes
        elif isinstance(obj, bytes):
            return cls(obj)

        # Convert from str
        elif isinstance(obj, str):
            return cls(obj.encode())

        # Convert from c_char_p
        elif isinstance(obj, ctypes.c_char_p):
            return obj

        # Convert from POINTER(ctypes.c_char)
        elif isinstance(obj, ctypes.POINTER(ctypes.c_char)):
            return obj

        # Convert from raw pointer
        elif isinstance(obj, int):
            return cls(ctypes.cast(obj, ctypes.POINTER(ctypes.c_char)))

        # Convert from ctypes.c_char array
        elif isinstance(obj, ctypes.c_char * len(obj)):
            return obj

        # Convert from object
        else:
            return String.from_param(obj._as_parameter_)

    from_param = classmethod(from_param)


def ReturnString(obj, func=None, arguments=None):
    return String.from_param(obj)


# As of ctypes 1.0, ctypes does not support custom error-checking
# functions on callbacks, nor does it support custom datatypes on
# callbacks, so we must ensure that all callbacks return
# primitive datatypes.
#
# Non-primitive return values wrapped with UNCHECKED won't be
# typechecked, and will be converted to ctypes.c_void_p.
def UNCHECKED(type):
    if hasattr(type, "_type_") and isinstance(type._type_, str) and type._type_ != "P":
        return type
    else:
        return ctypes.c_void_p


# ctypes doesn't have direct support for variadic functions, so we have to write
# our own wrapper class
class _variadic_function(object):
    def __init__(self, func, restype, argtypes, errcheck):
        self.func = func
        self.func.restype = restype
        self.argtypes = argtypes
        if errcheck:
            self.func.errcheck = errcheck

    def _as_parameter_(self):
        # So we can pass this variadic function as a function pointer
        return self.func

    def __call__(self, *args):
        fixed_args = []
        i = 0
        for argtype in self.argtypes:
            # Typecheck what we can
            fixed_args.append(argtype.from_param(args[i]))
            i += 1
        return self.func(*fixed_args + list(args[i:]))


def ord_if_char(value):
    """
    Simple helper used for casts to simple builtin types:  if the argument is a
    string type, it will be converted to it's ordinal value.

    This function will raise an exception if the argument is string with more
    than one characters.
    """
    return ord(value) if (isinstance(value, bytes) or isinstance(value, str)) else value

# End preamble

_libs = {}
_libdirs = []

# Begin loader

"""
Load libraries - appropriately for all our supported platforms
"""
# ----------------------------------------------------------------------------
# Copyright (c) 2008 David James
# Copyright (c) 2006-2008 Alex Holkner
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#  * Neither the name of pyglet nor the names of its
#    contributors may be used to endorse or promote products
#    derived from this software without specific prior written
#    permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# ----------------------------------------------------------------------------

import ctypes
import ctypes.util
import glob
import os.path
import platform
import re
import sys


def _environ_path(name):
    """Split an environment variable into a path-like list elements"""
    if name in os.environ:
        return os.environ[name].split(":")
    return []


class LibraryLoader:
    """
    A base class For loading of libraries ;-)
    Subclasses load libraries for specific platforms.
    """

    # library names formatted specifically for platforms
    name_formats = ["%s"]

    class Lookup:
        """Looking up calling conventions for a platform"""

        mode = ctypes.DEFAULT_MODE

        def __init__(self, path):
            super(LibraryLoader.Lookup, self).__init__()
            self.access = dict(cdecl=ctypes.CDLL(path, self.mode))

        def get(self, name, calling_convention="cdecl"):
            """Return the given name according to the selected calling convention"""
            if calling_convention not in self.access:
                raise LookupError(
                    "Unknown calling convention '{}' for function '{}'".format(
                        calling_convention, name
                    )
                )
            return getattr(self.access[calling_convention], name)

        def has(self, name, calling_convention="cdecl"):
            """Return True if this given calling convention finds the given 'name'"""
            if calling_convention not in self.access:
                return False
            return hasattr(self.access[calling_convention], name)

        def __getattr__(self, name):
            return getattr(self.access["cdecl"], name)

    def __init__(self):
        self.other_dirs = []

    def __call__(self, libname):
        """Given the name of a library, load it."""
        paths = self.getpaths(libname)

        for path in paths:
            # noinspection PyBroadException
            try:
                return self.Lookup(path)
            except Exception:  # pylint: disable=broad-except
                pass

        raise ImportError("Could not load %s." % libname)

    def getpaths(self, libname):
        """Return a list of paths where the library might be found."""
        if os.path.isabs(libname):
            yield libname
        else:
            # search through a prioritized series of locations for the library

            # we first search any specific directories identified by user
            for dir_i in self.other_dirs:
                for fmt in self.name_formats:
                    # dir_i should be absolute already
                    yield os.path.join(dir_i, fmt % libname)

            # check if this code is even stored in a physical file
            try:
                this_file = __file__
            except NameError:
                this_file = None

            # then we search the directory where the generated python interface is stored
            if this_file is not None:
                for fmt in self.name_formats:
                    yield os.path.abspath(os.path.join(os.path.dirname(__file__), fmt % libname))

            # now, use the ctypes tools to try to find the library
            for fmt in self.name_formats:
                path = ctypes.util.find_library(fmt % libname)
                if path:
                    yield path

            # then we search all paths identified as platform-specific lib paths
            for path in self.getplatformpaths(libname):
                yield path

            # Finally, we'll try the users current working directory
            for fmt in self.name_formats:
                yield os.path.abspath(os.path.join(os.path.curdir, fmt % libname))

    def getplatformpaths(self, _libname):  # pylint: disable=no-self-use
        """Return all the library paths available in this platform"""
        return []


# Darwin (Mac OS X)


class DarwinLibraryLoader(LibraryLoader):
    """Library loader for MacOS"""

    name_formats = [
        "lib%s.dylib",
        "lib%s.so",
        "lib%s.bundle",
        "%s.dylib",
        "%s.so",
        "%s.bundle",
        "%s",
    ]

    class Lookup(LibraryLoader.Lookup):
        """
        Looking up library files for this platform (Darwin aka MacOS)
        """

        # Darwin requires dlopen to be called with mode RTLD_GLOBAL instead
        # of the default RTLD_LOCAL.  Without this, you end up with
        # libraries not being loadable, resulting in "Symbol not found"
        # errors
        mode = ctypes.RTLD_GLOBAL

    def getplatformpaths(self, libname):
        if os.path.pathsep in libname:
            names = [libname]
        else:
            names = [fmt % libname for fmt in self.name_formats]

        for directory in self.getdirs(libname):
            for name in names:
                yield os.path.join(directory, name)

    @staticmethod
    def getdirs(libname):
        """Implements the dylib search as specified in Apple documentation:

        http://developer.apple.com/documentation/DeveloperTools/Conceptual/
            DynamicLibraries/Articles/DynamicLibraryUsageGuidelines.html

        Before commencing the standard search, the method first checks
        the bundle's ``Frameworks`` directory if the application is running
        within a bundle (OS X .app).
        """

        dyld_fallback_library_path = _environ_path("DYLD_FALLBACK_LIBRARY_PATH")
        if not dyld_fallback_library_path:
            dyld_fallback_library_path = [
                os.path.expanduser("~/lib"),
                "/usr/local/lib",
                "/usr/lib",
            ]

        dirs = []

        if "/" in libname:
            dirs.extend(_environ_path("DYLD_LIBRARY_PATH"))
        else:
            dirs.extend(_environ_path("LD_LIBRARY_PATH"))
            dirs.extend(_environ_path("DYLD_LIBRARY_PATH"))
            dirs.extend(_environ_path("LD_RUN_PATH"))

        if hasattr(sys, "frozen") and getattr(sys, "frozen") == "macosx_app":
            dirs.append(os.path.join(os.environ["RESOURCEPATH"], "..", "Frameworks"))

        dirs.extend(dyld_fallback_library_path)

        return dirs


# Posix


class PosixLibraryLoader(LibraryLoader):
    """Library loader for POSIX-like systems (including Linux)"""

    _ld_so_cache = None

    _include = re.compile(r"^\s*include\s+(?P<pattern>.*)")

    name_formats = ["lib%s.so", "%s.so", "%s"]

    class _Directories(dict):
        """Deal with directories"""

        def __init__(self):
            dict.__init__(self)
            self.order = 0

        def add(self, directory):
            """Add a directory to our current set of directories"""
            if len(directory) > 1:
                directory = directory.rstrip(os.path.sep)
            # only adds and updates order if exists and not already in set
            if not os.path.exists(directory):
                return
            order = self.setdefault(directory, self.order)
            if order == self.order:
                self.order += 1

        def extend(self, directories):
            """Add a list of directories to our set"""
            for a_dir in directories:
                self.add(a_dir)

        def ordered(self):
            """Sort the list of directories"""
            return (i[0] for i in sorted(self.items(), key=lambda d: d[1]))

    def _get_ld_so_conf_dirs(self, conf, dirs):
        """
        Recursive function to help parse all ld.so.conf files, including proper
        handling of the `include` directive.
        """

        try:
            with open(conf) as fileobj:
                for dirname in fileobj:
                    dirname = dirname.strip()
                    if not dirname:
                        continue

                    match = self._include.match(dirname)
                    if not match:
                        dirs.add(dirname)
                    else:
                        for dir2 in glob.glob(match.group("pattern")):
                            self._get_ld_so_conf_dirs(dir2, dirs)
        except IOError:
            pass

    def _create_ld_so_cache(self):
        # Recreate search path followed by ld.so.  This is going to be
        # slow to build, and incorrect (ld.so uses ld.so.cache, which may
        # not be up-to-date).  Used only as fallback for distros without
        # /sbin/ldconfig.
        #
        # We assume the DT_RPATH and DT_RUNPATH binary sections are omitted.

        directories = self._Directories()
        for name in (
            "LD_LIBRARY_PATH",
            "SHLIB_PATH",  # HP-UX
            "LIBPATH",  # OS/2, AIX
            "LIBRARY_PATH",  # BE/OS
        ):
            if name in os.environ:
                directories.extend(os.environ[name].split(os.pathsep))

        self._get_ld_so_conf_dirs("/etc/ld.so.conf", directories)

        bitage = platform.architecture()[0]

        unix_lib_dirs_list = []
        if bitage.startswith("64"):
            # prefer 64 bit if that is our arch
            unix_lib_dirs_list += ["/lib64", "/usr/lib64"]

        # must include standard libs, since those paths are also used by 64 bit
        # installs
        unix_lib_dirs_list += ["/lib", "/usr/lib"]
        if sys.platform.startswith("linux"):
            # Try and support multiarch work in Ubuntu
            # https://wiki.ubuntu.com/MultiarchSpec
            if bitage.startswith("32"):
                # Assume Intel/AMD x86 compat
                unix_lib_dirs_list += ["/lib/i386-linux-gnu", "/usr/lib/i386-linux-gnu"]
            elif bitage.startswith("64"):
                # Assume Intel/AMD x86 compatible
                unix_lib_dirs_list += [
                    "/lib/x86_64-linux-gnu",
                    "/usr/lib/x86_64-linux-gnu",
                ]
            else:
                # guess...
                unix_lib_dirs_list += glob.glob("/lib/*linux-gnu")
        directories.extend(unix_lib_dirs_list)

        cache = {}
        lib_re = re.compile(r"lib(.*)\.s[ol]")
        # ext_re = re.compile(r"\.s[ol]$")
        for our_dir in directories.ordered():
            try:
                for path in glob.glob("%s/*.s[ol]*" % our_dir):
                    file = os.path.basename(path)

                    # Index by filename
                    cache_i = cache.setdefault(file, set())
                    cache_i.add(path)

                    # Index by library name
                    match = lib_re.match(file)
                    if match:
                        library = match.group(1)
                        cache_i = cache.setdefault(library, set())
                        cache_i.add(path)
            except OSError:
                pass

        self._ld_so_cache = cache

    def getplatformpaths(self, libname):
        if self._ld_so_cache is None:
            self._create_ld_so_cache()

        result = self._ld_so_cache.get(libname, set())
        for i in result:
            # we iterate through all found paths for library, since we may have
            # actually found multiple architectures or other library types that
            # may not load
            yield i


# Windows


class WindowsLibraryLoader(LibraryLoader):
    """Library loader for Microsoft Windows"""

    name_formats = ["%s.dll", "lib%s.dll", "%slib.dll", "%s"]

    class Lookup(LibraryLoader.Lookup):
        """Lookup class for Windows libraries..."""

        def __init__(self, path):
            super(WindowsLibraryLoader.Lookup, self).__init__(path)
            self.access["stdcall"] = ctypes.windll.LoadLibrary(path)


# Platform switching

# If your value of sys.platform does not appear in this dict, please contact
# the Ctypesgen maintainers.

loaderclass = {
    "darwin": DarwinLibraryLoader,
    "cygwin": WindowsLibraryLoader,
    "win32": WindowsLibraryLoader,
    "msys": WindowsLibraryLoader,
}

load_library = loaderclass.get(sys.platform, PosixLibraryLoader)()


def add_library_search_dirs(other_dirs):
    """
    Add libraries to search paths.
    If library paths are relative, convert them to absolute with respect to this
    file's directory
    """
    for path in other_dirs:
        if not os.path.isabs(path):
            path = os.path.abspath(path)
        load_library.other_dirs.append(path)


del loaderclass

# End loader

add_library_search_dirs([])

# Begin libraries
_libs["nova2"] = load_library("nova2")

# 1 libraries
# End libraries

# No modules

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 83
class struct_ln_date(Structure):
    pass

struct_ln_date.__slots__ = [
    'years',
    'months',
    'days',
    'hours',
    'minutes',
    'seconds',
]
struct_ln_date._fields_ = [
    ('years', c_int),
    ('months', c_int),
    ('days', c_int),
    ('hours', c_int),
    ('minutes', c_int),
    ('seconds', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 114
class struct_ln_zonedate(Structure):
    pass

struct_ln_zonedate.__slots__ = [
    'years',
    'months',
    'days',
    'hours',
    'minutes',
    'seconds',
    'gmtoff',
]
struct_ln_zonedate._fields_ = [
    ('years', c_int),
    ('months', c_int),
    ('days', c_int),
    ('hours', c_int),
    ('minutes', c_int),
    ('seconds', c_double),
    ('gmtoff', c_long),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 131
class struct_ln_dms(Structure):
    pass

struct_ln_dms.__slots__ = [
    'neg',
    'degrees',
    'minutes',
    'seconds',
]
struct_ln_dms._fields_ = [
    ('neg', c_ushort),
    ('degrees', c_ushort),
    ('minutes', c_ushort),
    ('seconds', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 144
class struct_ln_hms(Structure):
    pass

struct_ln_hms.__slots__ = [
    'hours',
    'minutes',
    'seconds',
]
struct_ln_hms._fields_ = [
    ('hours', c_ushort),
    ('minutes', c_ushort),
    ('seconds', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 156
class struct_lnh_equ_posn(Structure):
    pass

struct_lnh_equ_posn.__slots__ = [
    'ra',
    'dec',
]
struct_lnh_equ_posn._fields_ = [
    ('ra', struct_ln_hms),
    ('dec', struct_ln_dms),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 167
class struct_lnh_hrz_posn(Structure):
    pass

struct_lnh_hrz_posn.__slots__ = [
    'az',
    'alt',
]
struct_lnh_hrz_posn._fields_ = [
    ('az', struct_ln_dms),
    ('alt', struct_ln_dms),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 178
class struct_lnh_lnlat_posn(Structure):
    pass

struct_lnh_lnlat_posn.__slots__ = [
    'lng',
    'lat',
]
struct_lnh_lnlat_posn._fields_ = [
    ('lng', struct_ln_dms),
    ('lat', struct_ln_dms),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 191
class struct_ln_equ_posn(Structure):
    pass

struct_ln_equ_posn.__slots__ = [
    'ra',
    'dec',
]
struct_ln_equ_posn._fields_ = [
    ('ra', c_double),
    ('dec', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 204
class struct_ln_hrz_posn(Structure):
    pass

struct_ln_hrz_posn.__slots__ = [
    'az',
    'alt',
]
struct_ln_hrz_posn._fields_ = [
    ('az', c_double),
    ('alt', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 219
class struct_ln_lnlat_posn(Structure):
    pass

struct_ln_lnlat_posn.__slots__ = [
    'lng',
    'lat',
]
struct_ln_lnlat_posn._fields_ = [
    ('lng', c_double),
    ('lat', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 233
class struct_ln_helio_posn(Structure):
    pass

struct_ln_helio_posn.__slots__ = [
    'L',
    'B',
    'R',
]
struct_ln_helio_posn._fields_ = [
    ('L', c_double),
    ('B', c_double),
    ('R', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 253
class struct_ln_rect_posn(Structure):
    pass

struct_ln_rect_posn.__slots__ = [
    'X',
    'Y',
    'Z',
]
struct_ln_rect_posn._fields_ = [
    ('X', c_double),
    ('Y', c_double),
    ('Z', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 267
class struct_ln_gal_posn(Structure):
    pass

struct_ln_gal_posn.__slots__ = [
    'l',
    'b',
]
struct_ln_gal_posn._fields_ = [
    ('l', c_double),
    ('b', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 279
class struct_ln_ell_orbit(Structure):
    pass

struct_ln_ell_orbit.__slots__ = [
    'a',
    'e',
    'i',
    'w',
    'omega',
    'n',
    'JD',
]
struct_ln_ell_orbit._fields_ = [
    ('a', c_double),
    ('e', c_double),
    ('i', c_double),
    ('w', c_double),
    ('omega', c_double),
    ('n', c_double),
    ('JD', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 309
class struct_ln_par_orbit(Structure):
    pass

struct_ln_par_orbit.__slots__ = [
    'q',
    'i',
    'w',
    'omega',
    'JD',
]
struct_ln_par_orbit._fields_ = [
    ('q', c_double),
    ('i', c_double),
    ('w', c_double),
    ('omega', c_double),
    ('JD', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 335
class struct_ln_hyp_orbit(Structure):
    pass

struct_ln_hyp_orbit.__slots__ = [
    'q',
    'e',
    'i',
    'w',
    'omega',
    'JD',
]
struct_ln_hyp_orbit._fields_ = [
    ('q', c_double),
    ('e', c_double),
    ('i', c_double),
    ('w', c_double),
    ('omega', c_double),
    ('JD', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 363
class struct_ln_rst_time(Structure):
    pass

struct_ln_rst_time.__slots__ = [
    'rise',
    'set',
    'transit',
]
struct_ln_rst_time._fields_ = [
    ('rise', c_double),
    ('set', c_double),
    ('transit', c_double),
]

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 377
class struct_ln_nutation(Structure):
    pass

struct_ln_nutation.__slots__ = [
    'longitude',
    'obliquity',
    'ecliptic',
]
struct_ln_nutation._fields_ = [
    ('longitude', c_double),
    ('obliquity', c_double),
    ('ecliptic', c_double),
]

# /home/lrg/source/libnova/src/libnova2/aberration.h: 50
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_aber", "cdecl"):
        continue
    ln2_get_equ_aber = _lib.get("ln2_get_equ_aber", "cdecl")
    ln2_get_equ_aber.argtypes = [POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_equ_aber.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/aberration.h: 62
for _lib in _libs.values():
    if not _lib.has("ln2_get_ecl_aber", "cdecl"):
        continue
    ln2_get_ecl_aber = _lib.get("ln2_get_ecl_aber", "cdecl")
    ln2_get_ecl_aber.argtypes = [POINTER(struct_ln_lnlat_posn), c_double, POINTER(struct_ln_lnlat_posn)]
    ln2_get_ecl_aber.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/airmass.h: 49
for _lib in _libs.values():
    if not _lib.has("ln2_get_airmass", "cdecl"):
        continue
    ln2_get_airmass = _lib.get("ln2_get_airmass", "cdecl")
    ln2_get_airmass.argtypes = [c_double, c_double]
    ln2_get_airmass.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/airmass.h: 60
for _lib in _libs.values():
    if not _lib.has("ln2_get_alt_from_airmass", "cdecl"):
        continue
    ln2_get_alt_from_airmass = _lib.get("ln2_get_alt_from_airmass", "cdecl")
    ln2_get_alt_from_airmass.argtypes = [c_double, c_double]
    ln2_get_alt_from_airmass.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/angular_separation.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_angular_separation", "cdecl"):
        continue
    ln2_get_angular_separation = _lib.get("ln2_get_angular_separation", "cdecl")
    ln2_get_angular_separation.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_equ_posn)]
    ln2_get_angular_separation.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/angular_separation.h: 58
for _lib in _libs.values():
    if not _lib.has("ln2_get_rel_posn_angle", "cdecl"):
        continue
    ln2_get_rel_posn_angle = _lib.get("ln2_get_rel_posn_angle", "cdecl")
    ln2_get_rel_posn_angle.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_equ_posn)]
    ln2_get_rel_posn_angle.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/apparent_position.h: 53
for _lib in _libs.values():
    if not _lib.has("ln2_get_apparent_posn", "cdecl"):
        continue
    ln2_get_apparent_posn = _lib.get("ln2_get_apparent_posn", "cdecl")
    ln2_get_apparent_posn.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_apparent_posn.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/asteroid.h: 52
for _lib in _libs.values():
    if not _lib.has("ln2_get_asteroid_mag", "cdecl"):
        continue
    ln2_get_asteroid_mag = _lib.get("ln2_get_asteroid_mag", "cdecl")
    ln2_get_asteroid_mag.argtypes = [c_double, POINTER(struct_ln_ell_orbit), c_double, c_double]
    ln2_get_asteroid_mag.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/asteroid.h: 63
for _lib in _libs.values():
    if not _lib.has("ln2_get_asteroid_sdiam_km", "cdecl"):
        continue
    ln2_get_asteroid_sdiam_km = _lib.get("ln2_get_asteroid_sdiam_km", "cdecl")
    ln2_get_asteroid_sdiam_km.argtypes = [c_double, c_double]
    ln2_get_asteroid_sdiam_km.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/asteroid.h: 74
for _lib in _libs.values():
    if not _lib.has("ln2_get_asteroid_sdiam_arc", "cdecl"):
        continue
    ln2_get_asteroid_sdiam_arc = _lib.get("ln2_get_asteroid_sdiam_arc", "cdecl")
    ln2_get_asteroid_sdiam_arc.argtypes = [c_double, POINTER(struct_ln_ell_orbit), c_double, c_double]
    ln2_get_asteroid_sdiam_arc.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/comet.h: 52
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_comet_mag", "cdecl"):
        continue
    ln2_get_ell_comet_mag = _lib.get("ln2_get_ell_comet_mag", "cdecl")
    ln2_get_ell_comet_mag.argtypes = [c_double, POINTER(struct_ln_ell_orbit), c_double, c_double]
    ln2_get_ell_comet_mag.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/comet.h: 65
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_comet_mag", "cdecl"):
        continue
    ln2_get_par_comet_mag = _lib.get("ln2_get_par_comet_mag", "cdecl")
    ln2_get_par_comet_mag.argtypes = [c_double, POINTER(struct_ln_par_orbit), c_double, c_double]
    ln2_get_par_comet_mag.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/constellation.h: 44
for _lib in _libs.values():
    if not _lib.has("ln2_get_constellation", "cdecl"):
        continue
    ln2_get_constellation = _lib.get("ln2_get_constellation", "cdecl")
    ln2_get_constellation.argtypes = [POINTER(struct_ln_equ_posn)]
    ln2_get_constellation.restype = c_char_p
    break

# /home/lrg/source/libnova/src/libnova2/dynamical_time.h: 48
for _lib in _libs.values():
    if not _lib.has("ln2_get_dynamical_time_diff", "cdecl"):
        continue
    ln2_get_dynamical_time_diff = _lib.get("ln2_get_dynamical_time_diff", "cdecl")
    ln2_get_dynamical_time_diff.argtypes = [c_double]
    ln2_get_dynamical_time_diff.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/dynamical_time.h: 56
for _lib in _libs.values():
    if not _lib.has("ln2_get_jde", "cdecl"):
        continue
    ln2_get_jde = _lib.get("ln2_get_jde", "cdecl")
    ln2_get_jde.argtypes = [c_double]
    ln2_get_jde.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/earth.h: 52
for _lib in _libs.values():
    if not _lib.has("ln2_get_earth_helio_coords", "cdecl"):
        continue
    ln2_get_earth_helio_coords = _lib.get("ln2_get_earth_helio_coords", "cdecl")
    ln2_get_earth_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_earth_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/earth.h: 63
for _lib in _libs.values():
    if not _lib.has("ln2_get_earth_solar_dist", "cdecl"):
        continue
    ln2_get_earth_solar_dist = _lib.get("ln2_get_earth_solar_dist", "cdecl")
    ln2_get_earth_solar_dist.argtypes = [c_double]
    ln2_get_earth_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/earth.h: 71
for _lib in _libs.values():
    if not _lib.has("ln2_get_earth_rect_helio", "cdecl"):
        continue
    ln2_get_earth_rect_helio = _lib.get("ln2_get_earth_rect_helio", "cdecl")
    ln2_get_earth_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_earth_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/earth.h: 81
for _lib in _libs.values():
    if not _lib.has("ln2_get_earth_centre_dist", "cdecl"):
        continue
    ln2_get_earth_centre_dist = _lib.get("ln2_get_earth_centre_dist", "cdecl")
    ln2_get_earth_centre_dist.argtypes = [c_float, c_double, POINTER(c_double), POINTER(c_double)]
    ln2_get_earth_centre_dist.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 51
for _lib in _libs.values():
    if not _lib.has("ln2_solve_kepler", "cdecl"):
        continue
    ln2_solve_kepler = _lib.get("ln2_solve_kepler", "cdecl")
    ln2_solve_kepler.argtypes = [c_double, c_double]
    ln2_solve_kepler.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 60
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_mean_anomaly", "cdecl"):
        continue
    ln2_get_ell_mean_anomaly = _lib.get("ln2_get_ell_mean_anomaly", "cdecl")
    ln2_get_ell_mean_anomaly.argtypes = [c_double, c_double]
    ln2_get_ell_mean_anomaly.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 69
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_true_anomaly", "cdecl"):
        continue
    ln2_get_ell_true_anomaly = _lib.get("ln2_get_ell_true_anomaly", "cdecl")
    ln2_get_ell_true_anomaly.argtypes = [c_double, c_double]
    ln2_get_ell_true_anomaly.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 79
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_radius_vector", "cdecl"):
        continue
    ln2_get_ell_radius_vector = _lib.get("ln2_get_ell_radius_vector", "cdecl")
    ln2_get_ell_radius_vector.argtypes = [c_double, c_double, c_double]
    ln2_get_ell_radius_vector.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 88
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_smajor_diam", "cdecl"):
        continue
    ln2_get_ell_smajor_diam = _lib.get("ln2_get_ell_smajor_diam", "cdecl")
    ln2_get_ell_smajor_diam.argtypes = [c_double, c_double]
    ln2_get_ell_smajor_diam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 97
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_sminor_diam", "cdecl"):
        continue
    ln2_get_ell_sminor_diam = _lib.get("ln2_get_ell_sminor_diam", "cdecl")
    ln2_get_ell_sminor_diam.argtypes = [c_double, c_double]
    ln2_get_ell_sminor_diam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 105
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_mean_motion", "cdecl"):
        continue
    ln2_get_ell_mean_motion = _lib.get("ln2_get_ell_mean_motion", "cdecl")
    ln2_get_ell_mean_motion.argtypes = [c_double]
    ln2_get_ell_mean_motion.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 114
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_geo_rect_posn", "cdecl"):
        continue
    ln2_get_ell_geo_rect_posn = _lib.get("ln2_get_ell_geo_rect_posn", "cdecl")
    ln2_get_ell_geo_rect_posn.argtypes = [POINTER(struct_ln_ell_orbit), c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_ell_geo_rect_posn.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 125
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_helio_rect_posn", "cdecl"):
        continue
    ln2_get_ell_helio_rect_posn = _lib.get("ln2_get_ell_helio_rect_posn", "cdecl")
    ln2_get_ell_helio_rect_posn.argtypes = [POINTER(struct_ln_ell_orbit), c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_ell_helio_rect_posn.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 135
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_orbit_len", "cdecl"):
        continue
    ln2_get_ell_orbit_len = _lib.get("ln2_get_ell_orbit_len", "cdecl")
    ln2_get_ell_orbit_len.argtypes = [POINTER(struct_ln_ell_orbit)]
    ln2_get_ell_orbit_len.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 144
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_orbit_vel", "cdecl"):
        continue
    ln2_get_ell_orbit_vel = _lib.get("ln2_get_ell_orbit_vel", "cdecl")
    ln2_get_ell_orbit_vel.argtypes = [c_double, POINTER(struct_ln_ell_orbit)]
    ln2_get_ell_orbit_vel.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 153
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_orbit_pvel", "cdecl"):
        continue
    ln2_get_ell_orbit_pvel = _lib.get("ln2_get_ell_orbit_pvel", "cdecl")
    ln2_get_ell_orbit_pvel.argtypes = [POINTER(struct_ln_ell_orbit)]
    ln2_get_ell_orbit_pvel.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 161
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_orbit_avel", "cdecl"):
        continue
    ln2_get_ell_orbit_avel = _lib.get("ln2_get_ell_orbit_avel", "cdecl")
    ln2_get_ell_orbit_avel.argtypes = [POINTER(struct_ln_ell_orbit)]
    ln2_get_ell_orbit_avel.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 170
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_phase_angle", "cdecl"):
        continue
    ln2_get_ell_body_phase_angle = _lib.get("ln2_get_ell_body_phase_angle", "cdecl")
    ln2_get_ell_body_phase_angle.argtypes = [c_double, POINTER(struct_ln_ell_orbit)]
    ln2_get_ell_body_phase_angle.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 180
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_elong", "cdecl"):
        continue
    ln2_get_ell_body_elong = _lib.get("ln2_get_ell_body_elong", "cdecl")
    ln2_get_ell_body_elong.argtypes = [c_double, POINTER(struct_ln_ell_orbit)]
    ln2_get_ell_body_elong.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 190
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_solar_dist", "cdecl"):
        continue
    ln2_get_ell_body_solar_dist = _lib.get("ln2_get_ell_body_solar_dist", "cdecl")
    ln2_get_ell_body_solar_dist.argtypes = [c_double, POINTER(struct_ln_ell_orbit)]
    ln2_get_ell_body_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 200
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_earth_dist", "cdecl"):
        continue
    ln2_get_ell_body_earth_dist = _lib.get("ln2_get_ell_body_earth_dist", "cdecl")
    ln2_get_ell_body_earth_dist.argtypes = [c_double, POINTER(struct_ln_ell_orbit)]
    ln2_get_ell_body_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 210
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_equ_coords", "cdecl"):
        continue
    ln2_get_ell_body_equ_coords = _lib.get("ln2_get_ell_body_equ_coords", "cdecl")
    ln2_get_ell_body_equ_coords.argtypes = [c_double, POINTER(struct_ln_ell_orbit), POINTER(struct_ln_equ_posn)]
    ln2_get_ell_body_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 223
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_rst", "cdecl"):
        continue
    ln2_get_ell_body_rst = _lib.get("ln2_get_ell_body_rst", "cdecl")
    ln2_get_ell_body_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_ell_orbit), POINTER(struct_ln_rst_time)]
    ln2_get_ell_body_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 238
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_rst_horizon", "cdecl"):
        continue
    ln2_get_ell_body_rst_horizon = _lib.get("ln2_get_ell_body_rst_horizon", "cdecl")
    ln2_get_ell_body_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_ell_orbit), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_ell_body_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 253
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_next_rst", "cdecl"):
        continue
    ln2_get_ell_body_next_rst = _lib.get("ln2_get_ell_body_next_rst", "cdecl")
    ln2_get_ell_body_next_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_ell_orbit), POINTER(struct_ln_rst_time)]
    ln2_get_ell_body_next_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 268
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_next_rst_horizon", "cdecl"):
        continue
    ln2_get_ell_body_next_rst_horizon = _lib.get("ln2_get_ell_body_next_rst_horizon", "cdecl")
    ln2_get_ell_body_next_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_ell_orbit), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_ell_body_next_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 283
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_body_next_rst_horizon_future", "cdecl"):
        continue
    ln2_get_ell_body_next_rst_horizon_future = _lib.get("ln2_get_ell_body_next_rst_horizon_future", "cdecl")
    ln2_get_ell_body_next_rst_horizon_future.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_ell_orbit), c_double, c_int, POINTER(struct_ln_rst_time)]
    ln2_get_ell_body_next_rst_horizon_future.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/elliptic_motion.h: 295
for _lib in _libs.values():
    if not _lib.has("ln2_get_ell_last_perihelion", "cdecl"):
        continue
    ln2_get_ell_last_perihelion = _lib.get("ln2_get_ell_last_perihelion", "cdecl")
    ln2_get_ell_last_perihelion.argtypes = [c_double, c_double, c_double]
    ln2_get_ell_last_perihelion.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/heliocentric_time.h: 48
for _lib in _libs.values():
    if not _lib.has("ln2_get_heliocentric_time_diff", "cdecl"):
        continue
    ln2_get_heliocentric_time_diff = _lib.get("ln2_get_heliocentric_time_diff", "cdecl")
    ln2_get_heliocentric_time_diff.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_heliocentric_time_diff.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 48
for _lib in _libs.values():
    if not _lib.has("ln2_solve_hyp_barker", "cdecl"):
        continue
    ln2_solve_hyp_barker = _lib.get("ln2_solve_hyp_barker", "cdecl")
    ln2_solve_hyp_barker.argtypes = [c_double, c_double, c_double]
    ln2_solve_hyp_barker.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 58
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_true_anomaly", "cdecl"):
        continue
    ln2_get_hyp_true_anomaly = _lib.get("ln2_get_hyp_true_anomaly", "cdecl")
    ln2_get_hyp_true_anomaly.argtypes = [c_double, c_double, c_double]
    ln2_get_hyp_true_anomaly.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 68
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_radius_vector", "cdecl"):
        continue
    ln2_get_hyp_radius_vector = _lib.get("ln2_get_hyp_radius_vector", "cdecl")
    ln2_get_hyp_radius_vector.argtypes = [c_double, c_double, c_double]
    ln2_get_hyp_radius_vector.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 77
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_geo_rect_posn", "cdecl"):
        continue
    ln2_get_hyp_geo_rect_posn = _lib.get("ln2_get_hyp_geo_rect_posn", "cdecl")
    ln2_get_hyp_geo_rect_posn.argtypes = [POINTER(struct_ln_hyp_orbit), c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_hyp_geo_rect_posn.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 86
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_helio_rect_posn", "cdecl"):
        continue
    ln2_get_hyp_helio_rect_posn = _lib.get("ln2_get_hyp_helio_rect_posn", "cdecl")
    ln2_get_hyp_helio_rect_posn.argtypes = [POINTER(struct_ln_hyp_orbit), c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_hyp_helio_rect_posn.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 95
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_equ_coords", "cdecl"):
        continue
    ln2_get_hyp_body_equ_coords = _lib.get("ln2_get_hyp_body_equ_coords", "cdecl")
    ln2_get_hyp_body_equ_coords.argtypes = [c_double, POINTER(struct_ln_hyp_orbit), POINTER(struct_ln_equ_posn)]
    ln2_get_hyp_body_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 104
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_earth_dist", "cdecl"):
        continue
    ln2_get_hyp_body_earth_dist = _lib.get("ln2_get_hyp_body_earth_dist", "cdecl")
    ln2_get_hyp_body_earth_dist.argtypes = [c_double, POINTER(struct_ln_hyp_orbit)]
    ln2_get_hyp_body_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 113
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_solar_dist", "cdecl"):
        continue
    ln2_get_hyp_body_solar_dist = _lib.get("ln2_get_hyp_body_solar_dist", "cdecl")
    ln2_get_hyp_body_solar_dist.argtypes = [c_double, POINTER(struct_ln_hyp_orbit)]
    ln2_get_hyp_body_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 122
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_phase_angle", "cdecl"):
        continue
    ln2_get_hyp_body_phase_angle = _lib.get("ln2_get_hyp_body_phase_angle", "cdecl")
    ln2_get_hyp_body_phase_angle.argtypes = [c_double, POINTER(struct_ln_hyp_orbit)]
    ln2_get_hyp_body_phase_angle.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 131
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_elong", "cdecl"):
        continue
    ln2_get_hyp_body_elong = _lib.get("ln2_get_hyp_body_elong", "cdecl")
    ln2_get_hyp_body_elong.argtypes = [c_double, POINTER(struct_ln_hyp_orbit)]
    ln2_get_hyp_body_elong.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 142
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_rst", "cdecl"):
        continue
    ln2_get_hyp_body_rst = _lib.get("ln2_get_hyp_body_rst", "cdecl")
    ln2_get_hyp_body_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_hyp_orbit), POINTER(struct_ln_rst_time)]
    ln2_get_hyp_body_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 155
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_rst_horizon", "cdecl"):
        continue
    ln2_get_hyp_body_rst_horizon = _lib.get("ln2_get_hyp_body_rst_horizon", "cdecl")
    ln2_get_hyp_body_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_hyp_orbit), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_hyp_body_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 167
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_next_rst", "cdecl"):
        continue
    ln2_get_hyp_body_next_rst = _lib.get("ln2_get_hyp_body_next_rst", "cdecl")
    ln2_get_hyp_body_next_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_hyp_orbit), POINTER(struct_ln_rst_time)]
    ln2_get_hyp_body_next_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 180
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_next_rst_horizon", "cdecl"):
        continue
    ln2_get_hyp_body_next_rst_horizon = _lib.get("ln2_get_hyp_body_next_rst_horizon", "cdecl")
    ln2_get_hyp_body_next_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_hyp_orbit), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_hyp_body_next_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/hyperbolic_motion.h: 195
for _lib in _libs.values():
    if not _lib.has("ln2_get_hyp_body_next_rst_horizon_future", "cdecl"):
        continue
    ln2_get_hyp_body_next_rst_horizon_future = _lib.get("ln2_get_hyp_body_next_rst_horizon_future", "cdecl")
    ln2_get_hyp_body_next_rst_horizon_future.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_hyp_orbit), c_double, c_int, POINTER(struct_ln_rst_time)]
    ln2_get_hyp_body_next_rst_horizon_future.restype = c_int
    break

size_t = c_ulong# /usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h: 229

__u_char = c_ubyte# /usr/include/x86_64-linux-gnu/bits/types.h: 31

__u_short = c_ushort# /usr/include/x86_64-linux-gnu/bits/types.h: 32

__u_int = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 33

__u_long = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 34

__int8_t = c_char# /usr/include/x86_64-linux-gnu/bits/types.h: 37

__uint8_t = c_ubyte# /usr/include/x86_64-linux-gnu/bits/types.h: 38

__int16_t = c_short# /usr/include/x86_64-linux-gnu/bits/types.h: 39

__uint16_t = c_ushort# /usr/include/x86_64-linux-gnu/bits/types.h: 40

__int32_t = c_int# /usr/include/x86_64-linux-gnu/bits/types.h: 41

__uint32_t = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 42

__int64_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 44

__uint64_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 45

__int_least8_t = c_int8# /usr/include/x86_64-linux-gnu/bits/types.h: 52

__uint_least8_t = __uint8_t# /usr/include/x86_64-linux-gnu/bits/types.h: 53

__int_least16_t = c_int16# /usr/include/x86_64-linux-gnu/bits/types.h: 54

__uint_least16_t = __uint16_t# /usr/include/x86_64-linux-gnu/bits/types.h: 55

__int_least32_t = c_int32# /usr/include/x86_64-linux-gnu/bits/types.h: 56

__uint_least32_t = __uint32_t# /usr/include/x86_64-linux-gnu/bits/types.h: 57

__int_least64_t = c_int64# /usr/include/x86_64-linux-gnu/bits/types.h: 58

__uint_least64_t = __uint64_t# /usr/include/x86_64-linux-gnu/bits/types.h: 59

__quad_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 63

__u_quad_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 64

__intmax_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 72

__uintmax_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 73

__dev_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 145

__uid_t = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 146

__gid_t = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 147

__ino_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 148

__ino64_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 149

__mode_t = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 150

__nlink_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 151

__off_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 152

__off64_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 153

__pid_t = c_int# /usr/include/x86_64-linux-gnu/bits/types.h: 154

# /usr/include/x86_64-linux-gnu/bits/types.h: 155
class struct_anon_1(Structure):
    pass

struct_anon_1.__slots__ = [
    '__val',
]
struct_anon_1._fields_ = [
    ('__val', c_int * int(2)),
]

__fsid_t = struct_anon_1# /usr/include/x86_64-linux-gnu/bits/types.h: 155

__clock_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 156

__rlim_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 157

__rlim64_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 158

__id_t = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 159

__time_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 160

__useconds_t = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 161

__suseconds_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 162

__suseconds64_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 163

__daddr_t = c_int# /usr/include/x86_64-linux-gnu/bits/types.h: 165

__key_t = c_int# /usr/include/x86_64-linux-gnu/bits/types.h: 166

__clockid_t = c_int# /usr/include/x86_64-linux-gnu/bits/types.h: 169

__timer_t = POINTER(None)# /usr/include/x86_64-linux-gnu/bits/types.h: 172

__blksize_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 175

__blkcnt_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 180

__blkcnt64_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 181

__fsblkcnt_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 184

__fsblkcnt64_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 185

__fsfilcnt_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 188

__fsfilcnt64_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 189

__fsword_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 192

__ssize_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 194

__syscall_slong_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 197

__syscall_ulong_t = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 199

__loff_t = __off64_t# /usr/include/x86_64-linux-gnu/bits/types.h: 203

__caddr_t = String# /usr/include/x86_64-linux-gnu/bits/types.h: 204

__intptr_t = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 207

__socklen_t = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 210

__sig_atomic_t = c_int# /usr/include/x86_64-linux-gnu/bits/types.h: 215

clock_t = __clock_t# /usr/include/x86_64-linux-gnu/bits/types/clock_t.h: 7

time_t = __time_t# /usr/include/x86_64-linux-gnu/bits/types/time_t.h: 10

# /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h: 7
class struct_tm(Structure):
    pass

struct_tm.__slots__ = [
    'tm_sec',
    'tm_min',
    'tm_hour',
    'tm_mday',
    'tm_mon',
    'tm_year',
    'tm_wday',
    'tm_yday',
    'tm_isdst',
    'tm_gmtoff',
    'tm_zone',
]
struct_tm._fields_ = [
    ('tm_sec', c_int),
    ('tm_min', c_int),
    ('tm_hour', c_int),
    ('tm_mday', c_int),
    ('tm_mon', c_int),
    ('tm_year', c_int),
    ('tm_wday', c_int),
    ('tm_yday', c_int),
    ('tm_isdst', c_int),
    ('tm_gmtoff', c_long),
    ('tm_zone', String),
]

# /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h: 11
class struct_timespec(Structure):
    pass

struct_timespec.__slots__ = [
    'tv_sec',
    'tv_nsec',
]
struct_timespec._fields_ = [
    ('tv_sec', __time_t),
    ('tv_nsec', __syscall_slong_t),
]

clockid_t = __clockid_t# /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h: 7

timer_t = __timer_t# /usr/include/x86_64-linux-gnu/bits/types/timer_t.h: 7

# /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h: 8
class struct_itimerspec(Structure):
    pass

struct_itimerspec.__slots__ = [
    'it_interval',
    'it_value',
]
struct_itimerspec._fields_ = [
    ('it_interval', struct_timespec),
    ('it_value', struct_timespec),
]

# /usr/include/time.h: 49
class struct_sigevent(Structure):
    pass

pid_t = __pid_t# /usr/include/time.h: 54

# /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h: 30
class struct___locale_data(Structure):
    pass

# /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h: 27
class struct___locale_struct(Structure):
    pass

struct___locale_struct.__slots__ = [
    '__locales',
    '__ctype_b',
    '__ctype_tolower',
    '__ctype_toupper',
    '__names',
]
struct___locale_struct._fields_ = [
    ('__locales', POINTER(struct___locale_data) * int(13)),
    ('__ctype_b', POINTER(c_ushort)),
    ('__ctype_tolower', POINTER(c_int)),
    ('__ctype_toupper', POINTER(c_int)),
    ('__names', POINTER(c_char) * int(13)),
]

__locale_t = POINTER(struct___locale_struct)# /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h: 41

locale_t = __locale_t# /usr/include/x86_64-linux-gnu/bits/types/locale_t.h: 24

# /usr/include/time.h: 72
for _lib in _libs.values():
    if not _lib.has("clock", "cdecl"):
        continue
    clock = _lib.get("clock", "cdecl")
    clock.argtypes = []
    clock.restype = clock_t
    break

# /usr/include/time.h: 76
for _lib in _libs.values():
    if not _lib.has("time", "cdecl"):
        continue
    time = _lib.get("time", "cdecl")
    time.argtypes = [POINTER(time_t)]
    time.restype = time_t
    break

# /usr/include/time.h: 79
for _lib in _libs.values():
    if not _lib.has("difftime", "cdecl"):
        continue
    difftime = _lib.get("difftime", "cdecl")
    difftime.argtypes = [time_t, time_t]
    difftime.restype = c_double
    break

# /usr/include/time.h: 82
for _lib in _libs.values():
    if not _lib.has("mktime", "cdecl"):
        continue
    mktime = _lib.get("mktime", "cdecl")
    mktime.argtypes = [POINTER(struct_tm)]
    mktime.restype = time_t
    break

# /usr/include/time.h: 99
for _lib in _libs.values():
    if not _lib.has("strftime", "cdecl"):
        continue
    strftime = _lib.get("strftime", "cdecl")
    strftime.argtypes = [String, c_size_t, String, POINTER(struct_tm)]
    strftime.restype = c_size_t
    break

# /usr/include/time.h: 116
for _lib in _libs.values():
    if not _lib.has("strftime_l", "cdecl"):
        continue
    strftime_l = _lib.get("strftime_l", "cdecl")
    strftime_l.argtypes = [String, c_size_t, String, POINTER(struct_tm), locale_t]
    strftime_l.restype = c_size_t
    break

# /usr/include/time.h: 132
for _lib in _libs.values():
    if not _lib.has("gmtime", "cdecl"):
        continue
    gmtime = _lib.get("gmtime", "cdecl")
    gmtime.argtypes = [POINTER(time_t)]
    gmtime.restype = POINTER(struct_tm)
    break

# /usr/include/time.h: 136
for _lib in _libs.values():
    if not _lib.has("localtime", "cdecl"):
        continue
    localtime = _lib.get("localtime", "cdecl")
    localtime.argtypes = [POINTER(time_t)]
    localtime.restype = POINTER(struct_tm)
    break

# /usr/include/time.h: 154
for _lib in _libs.values():
    if not _lib.has("gmtime_r", "cdecl"):
        continue
    gmtime_r = _lib.get("gmtime_r", "cdecl")
    gmtime_r.argtypes = [POINTER(time_t), POINTER(struct_tm)]
    gmtime_r.restype = POINTER(struct_tm)
    break

# /usr/include/time.h: 159
for _lib in _libs.values():
    if not _lib.has("localtime_r", "cdecl"):
        continue
    localtime_r = _lib.get("localtime_r", "cdecl")
    localtime_r.argtypes = [POINTER(time_t), POINTER(struct_tm)]
    localtime_r.restype = POINTER(struct_tm)
    break

# /usr/include/time.h: 179
for _lib in _libs.values():
    if not _lib.has("asctime", "cdecl"):
        continue
    asctime = _lib.get("asctime", "cdecl")
    asctime.argtypes = [POINTER(struct_tm)]
    if sizeof(c_int) == sizeof(c_void_p):
        asctime.restype = ReturnString
    else:
        asctime.restype = String
        asctime.errcheck = ReturnString
    break

# /usr/include/time.h: 183
for _lib in _libs.values():
    if not _lib.has("ctime", "cdecl"):
        continue
    ctime = _lib.get("ctime", "cdecl")
    ctime.argtypes = [POINTER(time_t)]
    if sizeof(c_int) == sizeof(c_void_p):
        ctime.restype = ReturnString
    else:
        ctime.restype = String
        ctime.errcheck = ReturnString
    break

# /usr/include/time.h: 197
for _lib in _libs.values():
    if not _lib.has("asctime_r", "cdecl"):
        continue
    asctime_r = _lib.get("asctime_r", "cdecl")
    asctime_r.argtypes = [POINTER(struct_tm), String]
    if sizeof(c_int) == sizeof(c_void_p):
        asctime_r.restype = ReturnString
    else:
        asctime_r.restype = String
        asctime_r.errcheck = ReturnString
    break

# /usr/include/time.h: 202
for _lib in _libs.values():
    if not _lib.has("ctime_r", "cdecl"):
        continue
    ctime_r = _lib.get("ctime_r", "cdecl")
    ctime_r.argtypes = [POINTER(time_t), String]
    if sizeof(c_int) == sizeof(c_void_p):
        ctime_r.restype = ReturnString
    else:
        ctime_r.restype = String
        ctime_r.errcheck = ReturnString
    break

# /usr/include/time.h: 217
for _lib in _libs.values():
    try:
        __tzname = (POINTER(c_char) * int(2)).in_dll(_lib, "__tzname")
        break
    except:
        pass

# /usr/include/time.h: 218
for _lib in _libs.values():
    try:
        __daylight = (c_int).in_dll(_lib, "__daylight")
        break
    except:
        pass

# /usr/include/time.h: 219
for _lib in _libs.values():
    try:
        __timezone = (c_long).in_dll(_lib, "__timezone")
        break
    except:
        pass

# /usr/include/time.h: 224
for _lib in _libs.values():
    try:
        tzname = (POINTER(c_char) * int(2)).in_dll(_lib, "tzname")
        break
    except:
        pass

# /usr/include/time.h: 228
for _lib in _libs.values():
    if not _lib.has("tzset", "cdecl"):
        continue
    tzset = _lib.get("tzset", "cdecl")
    tzset.argtypes = []
    tzset.restype = None
    break

# /usr/include/time.h: 232
for _lib in _libs.values():
    try:
        daylight = (c_int).in_dll(_lib, "daylight")
        break
    except:
        pass

# /usr/include/time.h: 233
for _lib in _libs.values():
    try:
        timezone = (c_long).in_dll(_lib, "timezone")
        break
    except:
        pass

# /usr/include/time.h: 246
for _lib in _libs.values():
    if not _lib.has("timegm", "cdecl"):
        continue
    timegm = _lib.get("timegm", "cdecl")
    timegm.argtypes = [POINTER(struct_tm)]
    timegm.restype = time_t
    break

# /usr/include/time.h: 263
for _lib in _libs.values():
    if not _lib.has("timelocal", "cdecl"):
        continue
    timelocal = _lib.get("timelocal", "cdecl")
    timelocal.argtypes = [POINTER(struct_tm)]
    timelocal.restype = time_t
    break

# /usr/include/time.h: 271
for _lib in _libs.values():
    if not _lib.has("dysize", "cdecl"):
        continue
    dysize = _lib.get("dysize", "cdecl")
    dysize.argtypes = [c_int]
    dysize.restype = c_int
    break

# /usr/include/time.h: 281
for _lib in _libs.values():
    if not _lib.has("nanosleep", "cdecl"):
        continue
    nanosleep = _lib.get("nanosleep", "cdecl")
    nanosleep.argtypes = [POINTER(struct_timespec), POINTER(struct_timespec)]
    nanosleep.restype = c_int
    break

# /usr/include/time.h: 285
for _lib in _libs.values():
    if not _lib.has("clock_getres", "cdecl"):
        continue
    clock_getres = _lib.get("clock_getres", "cdecl")
    clock_getres.argtypes = [clockid_t, POINTER(struct_timespec)]
    clock_getres.restype = c_int
    break

# /usr/include/time.h: 288
for _lib in _libs.values():
    if not _lib.has("clock_gettime", "cdecl"):
        continue
    clock_gettime = _lib.get("clock_gettime", "cdecl")
    clock_gettime.argtypes = [clockid_t, POINTER(struct_timespec)]
    clock_gettime.restype = c_int
    break

# /usr/include/time.h: 292
for _lib in _libs.values():
    if not _lib.has("clock_settime", "cdecl"):
        continue
    clock_settime = _lib.get("clock_settime", "cdecl")
    clock_settime.argtypes = [clockid_t, POINTER(struct_timespec)]
    clock_settime.restype = c_int
    break

# /usr/include/time.h: 323
for _lib in _libs.values():
    if not _lib.has("clock_nanosleep", "cdecl"):
        continue
    clock_nanosleep = _lib.get("clock_nanosleep", "cdecl")
    clock_nanosleep.argtypes = [clockid_t, c_int, POINTER(struct_timespec), POINTER(struct_timespec)]
    clock_nanosleep.restype = c_int
    break

# /usr/include/time.h: 338
for _lib in _libs.values():
    if not _lib.has("clock_getcpuclockid", "cdecl"):
        continue
    clock_getcpuclockid = _lib.get("clock_getcpuclockid", "cdecl")
    clock_getcpuclockid.argtypes = [pid_t, POINTER(clockid_t)]
    clock_getcpuclockid.restype = c_int
    break

# /usr/include/time.h: 343
for _lib in _libs.values():
    if not _lib.has("timer_create", "cdecl"):
        continue
    timer_create = _lib.get("timer_create", "cdecl")
    timer_create.argtypes = [clockid_t, POINTER(struct_sigevent), POINTER(timer_t)]
    timer_create.restype = c_int
    break

# /usr/include/time.h: 348
for _lib in _libs.values():
    if not _lib.has("timer_delete", "cdecl"):
        continue
    timer_delete = _lib.get("timer_delete", "cdecl")
    timer_delete.argtypes = [timer_t]
    timer_delete.restype = c_int
    break

# /usr/include/time.h: 352
for _lib in _libs.values():
    if not _lib.has("timer_settime", "cdecl"):
        continue
    timer_settime = _lib.get("timer_settime", "cdecl")
    timer_settime.argtypes = [timer_t, c_int, POINTER(struct_itimerspec), POINTER(struct_itimerspec)]
    timer_settime.restype = c_int
    break

# /usr/include/time.h: 357
for _lib in _libs.values():
    if not _lib.has("timer_gettime", "cdecl"):
        continue
    timer_gettime = _lib.get("timer_gettime", "cdecl")
    timer_gettime.argtypes = [timer_t, POINTER(struct_itimerspec)]
    timer_gettime.restype = c_int
    break

# /usr/include/time.h: 376
for _lib in _libs.values():
    if not _lib.has("timer_getoverrun", "cdecl"):
        continue
    timer_getoverrun = _lib.get("timer_getoverrun", "cdecl")
    timer_getoverrun.argtypes = [timer_t]
    timer_getoverrun.restype = c_int
    break

# /usr/include/time.h: 383
for _lib in _libs.values():
    if not _lib.has("timespec_get", "cdecl"):
        continue
    timespec_get = _lib.get("timespec_get", "cdecl")
    timespec_get.argtypes = [POINTER(struct_timespec), c_int]
    timespec_get.restype = c_int
    break

# /usr/include/time.h: 399
for _lib in _libs.values():
    if not _lib.has("timespec_getres", "cdecl"):
        continue
    timespec_getres = _lib.get("timespec_getres", "cdecl")
    timespec_getres.argtypes = [POINTER(struct_timespec), c_int]
    timespec_getres.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 51
for _lib in _libs.values():
    if not _lib.has("ln2_get_julian_day", "cdecl"):
        continue
    ln2_get_julian_day = _lib.get("ln2_get_julian_day", "cdecl")
    ln2_get_julian_day.argtypes = [POINTER(struct_ln_date)]
    ln2_get_julian_day.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 61
for _lib in _libs.values():
    if not _lib.has("ln2_get_date", "cdecl"):
        continue
    ln2_get_date = _lib.get("ln2_get_date", "cdecl")
    ln2_get_date.argtypes = [c_double, POINTER(struct_ln_date)]
    ln2_get_date.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 69
for _lib in _libs.values():
    if not _lib.has("ln2_get_date_from_timet", "cdecl"):
        continue
    ln2_get_date_from_timet = _lib.get("ln2_get_date_from_timet", "cdecl")
    ln2_get_date_from_timet.argtypes = [POINTER(time_t), POINTER(struct_ln_date)]
    ln2_get_date_from_timet.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 77
for _lib in _libs.values():
    if not _lib.has("ln2_get_date_from_tm", "cdecl"):
        continue
    ln2_get_date_from_tm = _lib.get("ln2_get_date_from_tm", "cdecl")
    ln2_get_date_from_tm.argtypes = [POINTER(struct_tm), POINTER(struct_ln_date)]
    ln2_get_date_from_tm.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 85
for _lib in _libs.values():
    if not _lib.has("ln2_get_local_date", "cdecl"):
        continue
    ln2_get_local_date = _lib.get("ln2_get_local_date", "cdecl")
    ln2_get_local_date.argtypes = [c_double, POINTER(struct_ln_zonedate)]
    ln2_get_local_date.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 95
for _lib in _libs.values():
    if not _lib.has("ln2_get_day_of_week", "cdecl"):
        continue
    ln2_get_day_of_week = _lib.get("ln2_get_day_of_week", "cdecl")
    ln2_get_day_of_week.argtypes = [POINTER(struct_ln_date)]
    ln2_get_day_of_week.restype = c_uint
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 102
for _lib in _libs.values():
    if not _lib.has("ln2_get_julian_from_sys", "cdecl"):
        continue
    ln2_get_julian_from_sys = _lib.get("ln2_get_julian_from_sys", "cdecl")
    ln2_get_julian_from_sys.argtypes = []
    ln2_get_julian_from_sys.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 109
for _lib in _libs.values():
    if not _lib.has("ln2_get_date_from_sys", "cdecl"):
        continue
    ln2_get_date_from_sys = _lib.get("ln2_get_date_from_sys", "cdecl")
    ln2_get_date_from_sys.argtypes = [POINTER(struct_ln_date)]
    ln2_get_date_from_sys.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 119
for _lib in _libs.values():
    if not _lib.has("ln2_get_julian_from_timet", "cdecl"):
        continue
    ln2_get_julian_from_timet = _lib.get("ln2_get_julian_from_timet", "cdecl")
    ln2_get_julian_from_timet.argtypes = [POINTER(time_t)]
    ln2_get_julian_from_timet.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 127
for _lib in _libs.values():
    if not _lib.has("ln2_get_timet_from_julian", "cdecl"):
        continue
    ln2_get_timet_from_julian = _lib.get("ln2_get_timet_from_julian", "cdecl")
    ln2_get_timet_from_julian.argtypes = [c_double, POINTER(time_t)]
    ln2_get_timet_from_julian.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 135
for _lib in _libs.values():
    if not _lib.has("ln2_get_julian_local_date", "cdecl"):
        continue
    ln2_get_julian_local_date = _lib.get("ln2_get_julian_local_date", "cdecl")
    ln2_get_julian_local_date.argtypes = [POINTER(struct_ln_zonedate)]
    ln2_get_julian_local_date.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 146
for _lib in _libs.values():
    if not _lib.has("ln2_get_date_from_mpc", "cdecl"):
        continue
    ln2_get_date_from_mpc = _lib.get("ln2_get_date_from_mpc", "cdecl")
    ln2_get_date_from_mpc.argtypes = [POINTER(struct_ln_date), String]
    ln2_get_date_from_mpc.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 156
for _lib in _libs.values():
    if not _lib.has("ln2_get_julian_from_mpc", "cdecl"):
        continue
    ln2_get_julian_from_mpc = _lib.get("ln2_get_julian_from_mpc", "cdecl")
    ln2_get_julian_from_mpc.argtypes = [String]
    ln2_get_julian_from_mpc.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 165
for _lib in _libs.values():
    if not _lib.has("ln2_date_to_zonedate", "cdecl"):
        continue
    ln2_date_to_zonedate = _lib.get("ln2_date_to_zonedate", "cdecl")
    ln2_date_to_zonedate.argtypes = [POINTER(struct_ln_date), POINTER(struct_ln_zonedate), c_long]
    ln2_date_to_zonedate.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/julian_day.h: 173
for _lib in _libs.values():
    if not _lib.has("ln2_zonedate_to_date", "cdecl"):
        continue
    ln2_zonedate_to_date = _lib.get("ln2_zonedate_to_date", "cdecl")
    ln2_zonedate_to_date.argtypes = [POINTER(struct_ln_zonedate), POINTER(struct_ln_date)]
    ln2_zonedate_to_date.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_equ_sdiam", "cdecl"):
        continue
    ln2_get_jupiter_equ_sdiam = _lib.get("ln2_get_jupiter_equ_sdiam", "cdecl")
    ln2_get_jupiter_equ_sdiam.argtypes = [c_double]
    ln2_get_jupiter_equ_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 55
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_pol_sdiam", "cdecl"):
        continue
    ln2_get_jupiter_pol_sdiam = _lib.get("ln2_get_jupiter_pol_sdiam", "cdecl")
    ln2_get_jupiter_pol_sdiam.argtypes = [c_double]
    ln2_get_jupiter_pol_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 65
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_rst", "cdecl"):
        continue
    ln2_get_jupiter_rst = _lib.get("ln2_get_jupiter_rst", "cdecl")
    ln2_get_jupiter_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_jupiter_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 74
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_helio_coords", "cdecl"):
        continue
    ln2_get_jupiter_helio_coords = _lib.get("ln2_get_jupiter_helio_coords", "cdecl")
    ln2_get_jupiter_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_jupiter_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 83
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_equ_coords", "cdecl"):
        continue
    ln2_get_jupiter_equ_coords = _lib.get("ln2_get_jupiter_equ_coords", "cdecl")
    ln2_get_jupiter_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_jupiter_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 92
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_earth_dist", "cdecl"):
        continue
    ln2_get_jupiter_earth_dist = _lib.get("ln2_get_jupiter_earth_dist", "cdecl")
    ln2_get_jupiter_earth_dist.argtypes = [c_double]
    ln2_get_jupiter_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 101
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_solar_dist", "cdecl"):
        continue
    ln2_get_jupiter_solar_dist = _lib.get("ln2_get_jupiter_solar_dist", "cdecl")
    ln2_get_jupiter_solar_dist.argtypes = [c_double]
    ln2_get_jupiter_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 110
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_magnitude", "cdecl"):
        continue
    ln2_get_jupiter_magnitude = _lib.get("ln2_get_jupiter_magnitude", "cdecl")
    ln2_get_jupiter_magnitude.argtypes = [c_double]
    ln2_get_jupiter_magnitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 119
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_disk", "cdecl"):
        continue
    ln2_get_jupiter_disk = _lib.get("ln2_get_jupiter_disk", "cdecl")
    ln2_get_jupiter_disk.argtypes = [c_double]
    ln2_get_jupiter_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 128
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_phase", "cdecl"):
        continue
    ln2_get_jupiter_phase = _lib.get("ln2_get_jupiter_phase", "cdecl")
    ln2_get_jupiter_phase.argtypes = [c_double]
    ln2_get_jupiter_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/jupiter.h: 136
for _lib in _libs.values():
    if not _lib.has("ln2_get_jupiter_rect_helio", "cdecl"):
        continue
    ln2_get_jupiter_rect_helio = _lib.get("ln2_get_jupiter_rect_helio", "cdecl")
    ln2_get_jupiter_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_jupiter_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/sidereal_time.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_mean_sidereal_time", "cdecl"):
        continue
    ln2_get_mean_sidereal_time = _lib.get("ln2_get_mean_sidereal_time", "cdecl")
    ln2_get_mean_sidereal_time.argtypes = [c_double]
    ln2_get_mean_sidereal_time.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/sidereal_time.h: 56
for _lib in _libs.values():
    if not _lib.has("ln2_get_apparent_sidereal_time", "cdecl"):
        continue
    ln2_get_apparent_sidereal_time = _lib.get("ln2_get_apparent_sidereal_time", "cdecl")
    ln2_get_apparent_sidereal_time.argtypes = [c_double]
    ln2_get_apparent_sidereal_time.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 51
for _lib in _libs.values():
    if not _lib.has("ln2_get_hrz_from_equ", "cdecl"):
        continue
    ln2_get_hrz_from_equ = _lib.get("ln2_get_hrz_from_equ", "cdecl")
    ln2_get_hrz_from_equ.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_lnlat_posn), c_double, POINTER(struct_ln_hrz_posn)]
    ln2_get_hrz_from_equ.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 66
for _lib in _libs.values():
    if not _lib.has("ln2_get_hrz_from_equ_sidereal_time", "cdecl"):
        continue
    ln2_get_hrz_from_equ_sidereal_time = _lib.get("ln2_get_hrz_from_equ_sidereal_time", "cdecl")
    ln2_get_hrz_from_equ_sidereal_time.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_lnlat_posn), c_double, POINTER(struct_ln_hrz_posn)]
    ln2_get_hrz_from_equ_sidereal_time.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 79
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_from_ecl", "cdecl"):
        continue
    ln2_get_equ_from_ecl = _lib.get("ln2_get_equ_from_ecl", "cdecl")
    ln2_get_equ_from_ecl.argtypes = [POINTER(struct_ln_lnlat_posn), c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_equ_from_ecl.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 91
for _lib in _libs.values():
    if not _lib.has("ln2_get_ecl_from_equ", "cdecl"):
        continue
    ln2_get_ecl_from_equ = _lib.get("ln2_get_ecl_from_equ", "cdecl")
    ln2_get_ecl_from_equ.argtypes = [POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_lnlat_posn)]
    ln2_get_ecl_from_equ.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 102
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_from_hrz", "cdecl"):
        continue
    ln2_get_equ_from_hrz = _lib.get("ln2_get_equ_from_hrz", "cdecl")
    ln2_get_equ_from_hrz.argtypes = [POINTER(struct_ln_hrz_posn), POINTER(struct_ln_lnlat_posn), c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_equ_from_hrz.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 112
for _lib in _libs.values():
    if not _lib.has("ln2_get_rect_from_helio", "cdecl"):
        continue
    ln2_get_rect_from_helio = _lib.get("ln2_get_rect_from_helio", "cdecl")
    ln2_get_rect_from_helio.argtypes = [POINTER(struct_ln_helio_posn), POINTER(struct_ln_rect_posn)]
    ln2_get_rect_from_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 122
for _lib in _libs.values():
    if not _lib.has("ln2_get_ecl_from_rect", "cdecl"):
        continue
    ln2_get_ecl_from_rect = _lib.get("ln2_get_ecl_from_rect", "cdecl")
    ln2_get_ecl_from_rect.argtypes = [POINTER(struct_ln_rect_posn), POINTER(struct_ln_lnlat_posn)]
    ln2_get_ecl_from_rect.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 133
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_from_gal", "cdecl"):
        continue
    ln2_get_equ_from_gal = _lib.get("ln2_get_equ_from_gal", "cdecl")
    ln2_get_equ_from_gal.argtypes = [POINTER(struct_ln_gal_posn), POINTER(struct_ln_equ_posn)]
    ln2_get_equ_from_gal.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 141
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ2000_from_gal", "cdecl"):
        continue
    ln2_get_equ2000_from_gal = _lib.get("ln2_get_equ2000_from_gal", "cdecl")
    ln2_get_equ2000_from_gal.argtypes = [POINTER(struct_ln_gal_posn), POINTER(struct_ln_equ_posn)]
    ln2_get_equ2000_from_gal.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 152
for _lib in _libs.values():
    if not _lib.has("ln2_get_gal_from_equ", "cdecl"):
        continue
    ln2_get_gal_from_equ = _lib.get("ln2_get_gal_from_equ", "cdecl")
    ln2_get_gal_from_equ.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_gal_posn)]
    ln2_get_gal_from_equ.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/transform.h: 160
for _lib in _libs.values():
    if not _lib.has("ln2_get_gal_from_equ2000", "cdecl"):
        continue
    ln2_get_gal_from_equ2000 = _lib.get("ln2_get_gal_from_equ2000", "cdecl")
    ln2_get_gal_from_equ2000.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_gal_posn)]
    ln2_get_gal_from_equ2000.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/nutation.h: 53
for _lib in _libs.values():
    if not _lib.has("ln2_get_nutation", "cdecl"):
        continue
    ln2_get_nutation = _lib.get("ln2_get_nutation", "cdecl")
    ln2_get_nutation.argtypes = [c_double, POINTER(struct_ln_nutation)]
    ln2_get_nutation.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/nutation.h: 64
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_nut", "cdecl"):
        continue
    ln2_get_equ_nut = _lib.get("ln2_get_equ_nut", "cdecl")
    ln2_get_equ_nut.argtypes = [POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_equ_nut.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/solar.h: 58
for _lib in _libs.values():
    if not _lib.has("ln2_get_solar_rst_horizon", "cdecl"):
        continue
    ln2_get_solar_rst_horizon = _lib.get("ln2_get_solar_rst_horizon", "cdecl")
    ln2_get_solar_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_solar_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/solar.h: 71
for _lib in _libs.values():
    if not _lib.has("ln2_get_solar_rst", "cdecl"):
        continue
    ln2_get_solar_rst = _lib.get("ln2_get_solar_rst", "cdecl")
    ln2_get_solar_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_solar_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/solar.h: 80
for _lib in _libs.values():
    if not _lib.has("ln2_get_solar_geom_coords", "cdecl"):
        continue
    ln2_get_solar_geom_coords = _lib.get("ln2_get_solar_geom_coords", "cdecl")
    ln2_get_solar_geom_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_solar_geom_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/solar.h: 89
for _lib in _libs.values():
    if not _lib.has("ln2_get_solar_equ_coords", "cdecl"):
        continue
    ln2_get_solar_equ_coords = _lib.get("ln2_get_solar_equ_coords", "cdecl")
    ln2_get_solar_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_solar_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/solar.h: 98
for _lib in _libs.values():
    if not _lib.has("ln2_get_solar_ecl_coords", "cdecl"):
        continue
    ln2_get_solar_ecl_coords = _lib.get("ln2_get_solar_ecl_coords", "cdecl")
    ln2_get_solar_ecl_coords.argtypes = [c_double, POINTER(struct_ln_lnlat_posn)]
    ln2_get_solar_ecl_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/solar.h: 107
for _lib in _libs.values():
    if not _lib.has("ln2_get_solar_geo_coords", "cdecl"):
        continue
    ln2_get_solar_geo_coords = _lib.get("ln2_get_solar_geo_coords", "cdecl")
    ln2_get_solar_geo_coords.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_solar_geo_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/solar.h: 117
for _lib in _libs.values():
    if not _lib.has("ln2_get_solar_sdiam", "cdecl"):
        continue
    ln2_get_solar_sdiam = _lib.get("ln2_get_solar_sdiam", "cdecl")
    ln2_get_solar_sdiam.argtypes = [c_double]
    ln2_get_solar_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/precession.h: 48
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_prec", "cdecl"):
        continue
    ln2_get_equ_prec = _lib.get("ln2_get_equ_prec", "cdecl")
    ln2_get_equ_prec.argtypes = [POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_equ_prec.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/precession.h: 60
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_prec2", "cdecl"):
        continue
    ln2_get_equ_prec2 = _lib.get("ln2_get_equ_prec2", "cdecl")
    ln2_get_equ_prec2.argtypes = [POINTER(struct_ln_equ_posn), c_double, c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_equ_prec2.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/precession.h: 71
for _lib in _libs.values():
    if not _lib.has("ln2_get_ecl_prec", "cdecl"):
        continue
    ln2_get_ecl_prec = _lib.get("ln2_get_ecl_prec", "cdecl")
    ln2_get_ecl_prec.argtypes = [POINTER(struct_ln_lnlat_posn), c_double, POINTER(struct_ln_lnlat_posn)]
    ln2_get_ecl_prec.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/proper_motion.h: 48
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_pm", "cdecl"):
        continue
    ln2_get_equ_pm = _lib.get("ln2_get_equ_pm", "cdecl")
    ln2_get_equ_pm.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_equ_pm.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/proper_motion.h: 61
for _lib in _libs.values():
    if not _lib.has("ln2_get_equ_pm_epoch", "cdecl"):
        continue
    ln2_get_equ_pm_epoch = _lib.get("ln2_get_equ_pm_epoch", "cdecl")
    ln2_get_equ_pm_epoch.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_ln_equ_posn), c_double, c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_equ_pm_epoch.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_sdiam", "cdecl"):
        continue
    ln2_get_mercury_sdiam = _lib.get("ln2_get_mercury_sdiam", "cdecl")
    ln2_get_mercury_sdiam.argtypes = [c_double]
    ln2_get_mercury_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 57
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_rst", "cdecl"):
        continue
    ln2_get_mercury_rst = _lib.get("ln2_get_mercury_rst", "cdecl")
    ln2_get_mercury_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_mercury_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 66
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_helio_coords", "cdecl"):
        continue
    ln2_get_mercury_helio_coords = _lib.get("ln2_get_mercury_helio_coords", "cdecl")
    ln2_get_mercury_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_mercury_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 75
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_equ_coords", "cdecl"):
        continue
    ln2_get_mercury_equ_coords = _lib.get("ln2_get_mercury_equ_coords", "cdecl")
    ln2_get_mercury_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_mercury_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 84
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_earth_dist", "cdecl"):
        continue
    ln2_get_mercury_earth_dist = _lib.get("ln2_get_mercury_earth_dist", "cdecl")
    ln2_get_mercury_earth_dist.argtypes = [c_double]
    ln2_get_mercury_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 93
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_solar_dist", "cdecl"):
        continue
    ln2_get_mercury_solar_dist = _lib.get("ln2_get_mercury_solar_dist", "cdecl")
    ln2_get_mercury_solar_dist.argtypes = [c_double]
    ln2_get_mercury_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 102
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_magnitude", "cdecl"):
        continue
    ln2_get_mercury_magnitude = _lib.get("ln2_get_mercury_magnitude", "cdecl")
    ln2_get_mercury_magnitude.argtypes = [c_double]
    ln2_get_mercury_magnitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 111
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_disk", "cdecl"):
        continue
    ln2_get_mercury_disk = _lib.get("ln2_get_mercury_disk", "cdecl")
    ln2_get_mercury_disk.argtypes = [c_double]
    ln2_get_mercury_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 120
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_phase", "cdecl"):
        continue
    ln2_get_mercury_phase = _lib.get("ln2_get_mercury_phase", "cdecl")
    ln2_get_mercury_phase.argtypes = [c_double]
    ln2_get_mercury_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mercury.h: 128
for _lib in _libs.values():
    if not _lib.has("ln2_get_mercury_rect_helio", "cdecl"):
        continue
    ln2_get_mercury_rect_helio = _lib.get("ln2_get_mercury_rect_helio", "cdecl")
    ln2_get_mercury_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_mercury_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_sdiam", "cdecl"):
        continue
    ln2_get_venus_sdiam = _lib.get("ln2_get_venus_sdiam", "cdecl")
    ln2_get_venus_sdiam.argtypes = [c_double]
    ln2_get_venus_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 57
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_rst", "cdecl"):
        continue
    ln2_get_venus_rst = _lib.get("ln2_get_venus_rst", "cdecl")
    ln2_get_venus_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_venus_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 66
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_helio_coords", "cdecl"):
        continue
    ln2_get_venus_helio_coords = _lib.get("ln2_get_venus_helio_coords", "cdecl")
    ln2_get_venus_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_venus_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 75
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_equ_coords", "cdecl"):
        continue
    ln2_get_venus_equ_coords = _lib.get("ln2_get_venus_equ_coords", "cdecl")
    ln2_get_venus_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_venus_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 84
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_earth_dist", "cdecl"):
        continue
    ln2_get_venus_earth_dist = _lib.get("ln2_get_venus_earth_dist", "cdecl")
    ln2_get_venus_earth_dist.argtypes = [c_double]
    ln2_get_venus_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 93
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_solar_dist", "cdecl"):
        continue
    ln2_get_venus_solar_dist = _lib.get("ln2_get_venus_solar_dist", "cdecl")
    ln2_get_venus_solar_dist.argtypes = [c_double]
    ln2_get_venus_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 102
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_magnitude", "cdecl"):
        continue
    ln2_get_venus_magnitude = _lib.get("ln2_get_venus_magnitude", "cdecl")
    ln2_get_venus_magnitude.argtypes = [c_double]
    ln2_get_venus_magnitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 111
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_disk", "cdecl"):
        continue
    ln2_get_venus_disk = _lib.get("ln2_get_venus_disk", "cdecl")
    ln2_get_venus_disk.argtypes = [c_double]
    ln2_get_venus_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 120
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_phase", "cdecl"):
        continue
    ln2_get_venus_phase = _lib.get("ln2_get_venus_phase", "cdecl")
    ln2_get_venus_phase.argtypes = [c_double]
    ln2_get_venus_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/venus.h: 128
for _lib in _libs.values():
    if not _lib.has("ln2_get_venus_rect_helio", "cdecl"):
        continue
    ln2_get_venus_rect_helio = _lib.get("ln2_get_venus_rect_helio", "cdecl")
    ln2_get_venus_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_venus_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_sdiam", "cdecl"):
        continue
    ln2_get_mars_sdiam = _lib.get("ln2_get_mars_sdiam", "cdecl")
    ln2_get_mars_sdiam.argtypes = [c_double]
    ln2_get_mars_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 57
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_rst", "cdecl"):
        continue
    ln2_get_mars_rst = _lib.get("ln2_get_mars_rst", "cdecl")
    ln2_get_mars_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_mars_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 66
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_helio_coords", "cdecl"):
        continue
    ln2_get_mars_helio_coords = _lib.get("ln2_get_mars_helio_coords", "cdecl")
    ln2_get_mars_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_mars_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 75
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_equ_coords", "cdecl"):
        continue
    ln2_get_mars_equ_coords = _lib.get("ln2_get_mars_equ_coords", "cdecl")
    ln2_get_mars_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_mars_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 84
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_earth_dist", "cdecl"):
        continue
    ln2_get_mars_earth_dist = _lib.get("ln2_get_mars_earth_dist", "cdecl")
    ln2_get_mars_earth_dist.argtypes = [c_double]
    ln2_get_mars_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 93
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_solar_dist", "cdecl"):
        continue
    ln2_get_mars_solar_dist = _lib.get("ln2_get_mars_solar_dist", "cdecl")
    ln2_get_mars_solar_dist.argtypes = [c_double]
    ln2_get_mars_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 102
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_magnitude", "cdecl"):
        continue
    ln2_get_mars_magnitude = _lib.get("ln2_get_mars_magnitude", "cdecl")
    ln2_get_mars_magnitude.argtypes = [c_double]
    ln2_get_mars_magnitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 111
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_disk", "cdecl"):
        continue
    ln2_get_mars_disk = _lib.get("ln2_get_mars_disk", "cdecl")
    ln2_get_mars_disk.argtypes = [c_double]
    ln2_get_mars_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 120
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_phase", "cdecl"):
        continue
    ln2_get_mars_phase = _lib.get("ln2_get_mars_phase", "cdecl")
    ln2_get_mars_phase.argtypes = [c_double]
    ln2_get_mars_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/mars.h: 128
for _lib in _libs.values():
    if not _lib.has("ln2_get_mars_rect_helio", "cdecl"):
        continue
    ln2_get_mars_rect_helio = _lib.get("ln2_get_mars_rect_helio", "cdecl")
    ln2_get_mars_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_mars_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_equ_sdiam", "cdecl"):
        continue
    ln2_get_saturn_equ_sdiam = _lib.get("ln2_get_saturn_equ_sdiam", "cdecl")
    ln2_get_saturn_equ_sdiam.argtypes = [c_double]
    ln2_get_saturn_equ_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 55
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_pol_sdiam", "cdecl"):
        continue
    ln2_get_saturn_pol_sdiam = _lib.get("ln2_get_saturn_pol_sdiam", "cdecl")
    ln2_get_saturn_pol_sdiam.argtypes = [c_double]
    ln2_get_saturn_pol_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 65
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_rst", "cdecl"):
        continue
    ln2_get_saturn_rst = _lib.get("ln2_get_saturn_rst", "cdecl")
    ln2_get_saturn_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_saturn_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 74
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_helio_coords", "cdecl"):
        continue
    ln2_get_saturn_helio_coords = _lib.get("ln2_get_saturn_helio_coords", "cdecl")
    ln2_get_saturn_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_saturn_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 83
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_equ_coords", "cdecl"):
        continue
    ln2_get_saturn_equ_coords = _lib.get("ln2_get_saturn_equ_coords", "cdecl")
    ln2_get_saturn_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_saturn_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 92
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_earth_dist", "cdecl"):
        continue
    ln2_get_saturn_earth_dist = _lib.get("ln2_get_saturn_earth_dist", "cdecl")
    ln2_get_saturn_earth_dist.argtypes = [c_double]
    ln2_get_saturn_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 101
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_solar_dist", "cdecl"):
        continue
    ln2_get_saturn_solar_dist = _lib.get("ln2_get_saturn_solar_dist", "cdecl")
    ln2_get_saturn_solar_dist.argtypes = [c_double]
    ln2_get_saturn_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 110
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_magnitude", "cdecl"):
        continue
    ln2_get_saturn_magnitude = _lib.get("ln2_get_saturn_magnitude", "cdecl")
    ln2_get_saturn_magnitude.argtypes = [c_double]
    ln2_get_saturn_magnitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 119
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_disk", "cdecl"):
        continue
    ln2_get_saturn_disk = _lib.get("ln2_get_saturn_disk", "cdecl")
    ln2_get_saturn_disk.argtypes = [c_double]
    ln2_get_saturn_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 128
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_phase", "cdecl"):
        continue
    ln2_get_saturn_phase = _lib.get("ln2_get_saturn_phase", "cdecl")
    ln2_get_saturn_phase.argtypes = [c_double]
    ln2_get_saturn_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/saturn.h: 136
for _lib in _libs.values():
    if not _lib.has("ln2_get_saturn_rect_helio", "cdecl"):
        continue
    ln2_get_saturn_rect_helio = _lib.get("ln2_get_saturn_rect_helio", "cdecl")
    ln2_get_saturn_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_saturn_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_sdiam", "cdecl"):
        continue
    ln2_get_uranus_sdiam = _lib.get("ln2_get_uranus_sdiam", "cdecl")
    ln2_get_uranus_sdiam.argtypes = [c_double]
    ln2_get_uranus_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 57
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_rst", "cdecl"):
        continue
    ln2_get_uranus_rst = _lib.get("ln2_get_uranus_rst", "cdecl")
    ln2_get_uranus_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_uranus_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 66
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_helio_coords", "cdecl"):
        continue
    ln2_get_uranus_helio_coords = _lib.get("ln2_get_uranus_helio_coords", "cdecl")
    ln2_get_uranus_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_uranus_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 75
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_equ_coords", "cdecl"):
        continue
    ln2_get_uranus_equ_coords = _lib.get("ln2_get_uranus_equ_coords", "cdecl")
    ln2_get_uranus_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_uranus_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 84
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_earth_dist", "cdecl"):
        continue
    ln2_get_uranus_earth_dist = _lib.get("ln2_get_uranus_earth_dist", "cdecl")
    ln2_get_uranus_earth_dist.argtypes = [c_double]
    ln2_get_uranus_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 93
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_solar_dist", "cdecl"):
        continue
    ln2_get_uranus_solar_dist = _lib.get("ln2_get_uranus_solar_dist", "cdecl")
    ln2_get_uranus_solar_dist.argtypes = [c_double]
    ln2_get_uranus_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 102
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_magnitude", "cdecl"):
        continue
    ln2_get_uranus_magnitude = _lib.get("ln2_get_uranus_magnitude", "cdecl")
    ln2_get_uranus_magnitude.argtypes = [c_double]
    ln2_get_uranus_magnitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 111
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_disk", "cdecl"):
        continue
    ln2_get_uranus_disk = _lib.get("ln2_get_uranus_disk", "cdecl")
    ln2_get_uranus_disk.argtypes = [c_double]
    ln2_get_uranus_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 120
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_phase", "cdecl"):
        continue
    ln2_get_uranus_phase = _lib.get("ln2_get_uranus_phase", "cdecl")
    ln2_get_uranus_phase.argtypes = [c_double]
    ln2_get_uranus_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/uranus.h: 128
for _lib in _libs.values():
    if not _lib.has("ln2_get_uranus_rect_helio", "cdecl"):
        continue
    ln2_get_uranus_rect_helio = _lib.get("ln2_get_uranus_rect_helio", "cdecl")
    ln2_get_uranus_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_uranus_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_sdiam", "cdecl"):
        continue
    ln2_get_neptune_sdiam = _lib.get("ln2_get_neptune_sdiam", "cdecl")
    ln2_get_neptune_sdiam.argtypes = [c_double]
    ln2_get_neptune_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 57
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_rst", "cdecl"):
        continue
    ln2_get_neptune_rst = _lib.get("ln2_get_neptune_rst", "cdecl")
    ln2_get_neptune_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_neptune_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 66
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_helio_coords", "cdecl"):
        continue
    ln2_get_neptune_helio_coords = _lib.get("ln2_get_neptune_helio_coords", "cdecl")
    ln2_get_neptune_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_neptune_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 75
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_equ_coords", "cdecl"):
        continue
    ln2_get_neptune_equ_coords = _lib.get("ln2_get_neptune_equ_coords", "cdecl")
    ln2_get_neptune_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_neptune_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 84
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_earth_dist", "cdecl"):
        continue
    ln2_get_neptune_earth_dist = _lib.get("ln2_get_neptune_earth_dist", "cdecl")
    ln2_get_neptune_earth_dist.argtypes = [c_double]
    ln2_get_neptune_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 93
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_solar_dist", "cdecl"):
        continue
    ln2_get_neptune_solar_dist = _lib.get("ln2_get_neptune_solar_dist", "cdecl")
    ln2_get_neptune_solar_dist.argtypes = [c_double]
    ln2_get_neptune_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 102
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_magnitude", "cdecl"):
        continue
    ln2_get_neptune_magnitude = _lib.get("ln2_get_neptune_magnitude", "cdecl")
    ln2_get_neptune_magnitude.argtypes = [c_double]
    ln2_get_neptune_magnitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 111
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_disk", "cdecl"):
        continue
    ln2_get_neptune_disk = _lib.get("ln2_get_neptune_disk", "cdecl")
    ln2_get_neptune_disk.argtypes = [c_double]
    ln2_get_neptune_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 120
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_phase", "cdecl"):
        continue
    ln2_get_neptune_phase = _lib.get("ln2_get_neptune_phase", "cdecl")
    ln2_get_neptune_phase.argtypes = [c_double]
    ln2_get_neptune_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/neptune.h: 128
for _lib in _libs.values():
    if not _lib.has("ln2_get_neptune_rect_helio", "cdecl"):
        continue
    ln2_get_neptune_rect_helio = _lib.get("ln2_get_neptune_rect_helio", "cdecl")
    ln2_get_neptune_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_neptune_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_sdiam", "cdecl"):
        continue
    ln2_get_pluto_sdiam = _lib.get("ln2_get_pluto_sdiam", "cdecl")
    ln2_get_pluto_sdiam.argtypes = [c_double]
    ln2_get_pluto_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 57
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_rst", "cdecl"):
        continue
    ln2_get_pluto_rst = _lib.get("ln2_get_pluto_rst", "cdecl")
    ln2_get_pluto_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_pluto_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 66
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_helio_coords", "cdecl"):
        continue
    ln2_get_pluto_helio_coords = _lib.get("ln2_get_pluto_helio_coords", "cdecl")
    ln2_get_pluto_helio_coords.argtypes = [c_double, POINTER(struct_ln_helio_posn)]
    ln2_get_pluto_helio_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 75
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_equ_coords", "cdecl"):
        continue
    ln2_get_pluto_equ_coords = _lib.get("ln2_get_pluto_equ_coords", "cdecl")
    ln2_get_pluto_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_pluto_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 84
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_earth_dist", "cdecl"):
        continue
    ln2_get_pluto_earth_dist = _lib.get("ln2_get_pluto_earth_dist", "cdecl")
    ln2_get_pluto_earth_dist.argtypes = [c_double]
    ln2_get_pluto_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 93
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_solar_dist", "cdecl"):
        continue
    ln2_get_pluto_solar_dist = _lib.get("ln2_get_pluto_solar_dist", "cdecl")
    ln2_get_pluto_solar_dist.argtypes = [c_double]
    ln2_get_pluto_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 102
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_magnitude", "cdecl"):
        continue
    ln2_get_pluto_magnitude = _lib.get("ln2_get_pluto_magnitude", "cdecl")
    ln2_get_pluto_magnitude.argtypes = [c_double]
    ln2_get_pluto_magnitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 111
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_disk", "cdecl"):
        continue
    ln2_get_pluto_disk = _lib.get("ln2_get_pluto_disk", "cdecl")
    ln2_get_pluto_disk.argtypes = [c_double]
    ln2_get_pluto_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 120
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_phase", "cdecl"):
        continue
    ln2_get_pluto_phase = _lib.get("ln2_get_pluto_phase", "cdecl")
    ln2_get_pluto_phase.argtypes = [c_double]
    ln2_get_pluto_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/pluto.h: 128
for _lib in _libs.values():
    if not _lib.has("ln2_get_pluto_rect_helio", "cdecl"):
        continue
    ln2_get_pluto_rect_helio = _lib.get("ln2_get_pluto_rect_helio", "cdecl")
    ln2_get_pluto_rect_helio.argtypes = [c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_pluto_rect_helio.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/vsop87.h: 47
for _lib in _libs.values():
    if not _lib.has("ln2_vsop87_to_fk5", "cdecl"):
        continue
    ln2_vsop87_to_fk5 = _lib.get("ln2_vsop87_to_fk5", "cdecl")
    ln2_vsop87_to_fk5.argtypes = [POINTER(struct_ln_helio_posn), c_double]
    ln2_vsop87_to_fk5.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/vsop87.h: 52
class struct_ln_vsop(Structure):
    pass

struct_ln_vsop.__slots__ = [
    'A',
    'B',
    'C',
]
struct_ln_vsop._fields_ = [
    ('A', c_double),
    ('B', c_double),
    ('C', c_double),
]

# /home/lrg/source/libnova/src/libnova2/vsop87.h: 66
for _lib in _libs.values():
    if not _lib.has("ln2_calc_series", "cdecl"):
        continue
    ln2_calc_series = _lib.get("ln2_calc_series", "cdecl")
    ln2_calc_series.argtypes = [POINTER(struct_ln_vsop), c_int, c_double]
    ln2_calc_series.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 46
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_sdiam", "cdecl"):
        continue
    ln2_get_lunar_sdiam = _lib.get("ln2_get_lunar_sdiam", "cdecl")
    ln2_get_lunar_sdiam.argtypes = [c_double]
    ln2_get_lunar_sdiam.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 57
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_rst", "cdecl"):
        continue
    ln2_get_lunar_rst = _lib.get("ln2_get_lunar_rst", "cdecl")
    ln2_get_lunar_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_rst_time)]
    ln2_get_lunar_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 68
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_geo_posn", "cdecl"):
        continue
    ln2_get_lunar_geo_posn = _lib.get("ln2_get_lunar_geo_posn", "cdecl")
    ln2_get_lunar_geo_posn.argtypes = [c_double, POINTER(struct_ln_rect_posn), c_double]
    ln2_get_lunar_geo_posn.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 78
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_equ_coords_prec", "cdecl"):
        continue
    ln2_get_lunar_equ_coords_prec = _lib.get("ln2_get_lunar_equ_coords_prec", "cdecl")
    ln2_get_lunar_equ_coords_prec.argtypes = [c_double, POINTER(struct_ln_equ_posn), c_double]
    ln2_get_lunar_equ_coords_prec.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 88
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_equ_coords", "cdecl"):
        continue
    ln2_get_lunar_equ_coords = _lib.get("ln2_get_lunar_equ_coords", "cdecl")
    ln2_get_lunar_equ_coords.argtypes = [c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_lunar_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 98
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_ecl_coords", "cdecl"):
        continue
    ln2_get_lunar_ecl_coords = _lib.get("ln2_get_lunar_ecl_coords", "cdecl")
    ln2_get_lunar_ecl_coords.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), c_double]
    ln2_get_lunar_ecl_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 110
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_phase", "cdecl"):
        continue
    ln2_get_lunar_phase = _lib.get("ln2_get_lunar_phase", "cdecl")
    ln2_get_lunar_phase.argtypes = [c_double]
    ln2_get_lunar_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 118
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_disk", "cdecl"):
        continue
    ln2_get_lunar_disk = _lib.get("ln2_get_lunar_disk", "cdecl")
    ln2_get_lunar_disk.argtypes = [c_double]
    ln2_get_lunar_disk.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 126
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_earth_dist", "cdecl"):
        continue
    ln2_get_lunar_earth_dist = _lib.get("ln2_get_lunar_earth_dist", "cdecl")
    ln2_get_lunar_earth_dist.argtypes = [c_double]
    ln2_get_lunar_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 134
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_bright_limb", "cdecl"):
        continue
    ln2_get_lunar_bright_limb = _lib.get("ln2_get_lunar_bright_limb", "cdecl")
    ln2_get_lunar_bright_limb.argtypes = [c_double]
    ln2_get_lunar_bright_limb.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 144
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_long_asc_node", "cdecl"):
        continue
    ln2_get_lunar_long_asc_node = _lib.get("ln2_get_lunar_long_asc_node", "cdecl")
    ln2_get_lunar_long_asc_node.argtypes = [c_double]
    ln2_get_lunar_long_asc_node.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 154
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_long_perigee", "cdecl"):
        continue
    ln2_get_lunar_long_perigee = _lib.get("ln2_get_lunar_long_perigee", "cdecl")
    ln2_get_lunar_long_perigee.argtypes = [c_double]
    ln2_get_lunar_long_perigee.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 164
for _lib in _libs.values():
    if not _lib.has("ln2_get_lunar_arg_latitude", "cdecl"):
        continue
    ln2_get_lunar_arg_latitude = _lib.get("ln2_get_lunar_arg_latitude", "cdecl")
    ln2_get_lunar_arg_latitude.argtypes = [c_double]
    ln2_get_lunar_arg_latitude.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 173
for _lib in _libs.values():
    if not _lib.has("ln_get_lunar_opt_libr_coords", "cdecl"):
        continue
    ln_get_lunar_opt_libr_coords = _lib.get("ln_get_lunar_opt_libr_coords", "cdecl")
    ln_get_lunar_opt_libr_coords.argtypes = [c_double, POINTER(struct_ln_lnlat_posn)]
    ln_get_lunar_opt_libr_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 182
for _lib in _libs.values():
    if not _lib.has("ln_get_lunar_subsolar_coords", "cdecl"):
        continue
    ln_get_lunar_subsolar_coords = _lib.get("ln_get_lunar_subsolar_coords", "cdecl")
    ln_get_lunar_subsolar_coords.argtypes = [c_double, POINTER(struct_ln_lnlat_posn)]
    ln_get_lunar_subsolar_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 191
for _lib in _libs.values():
    if not _lib.has("ln2_lunar_next_phase", "cdecl"):
        continue
    ln2_lunar_next_phase = _lib.get("ln2_lunar_next_phase", "cdecl")
    ln2_lunar_next_phase.argtypes = [c_double, c_double]
    ln2_lunar_next_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 200
for _lib in _libs.values():
    if not _lib.has("ln2_lunar_previous_phase", "cdecl"):
        continue
    ln2_lunar_previous_phase = _lib.get("ln2_lunar_previous_phase", "cdecl")
    ln2_lunar_previous_phase.argtypes = [c_double, c_double]
    ln2_lunar_previous_phase.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 209
for _lib in _libs.values():
    if not _lib.has("ln2_lunar_next_apsis", "cdecl"):
        continue
    ln2_lunar_next_apsis = _lib.get("ln2_lunar_next_apsis", "cdecl")
    ln2_lunar_next_apsis.argtypes = [c_double, c_int]
    ln2_lunar_next_apsis.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 218
for _lib in _libs.values():
    if not _lib.has("ln2_lunar_previous_apsis", "cdecl"):
        continue
    ln2_lunar_previous_apsis = _lib.get("ln2_lunar_previous_apsis", "cdecl")
    ln2_lunar_previous_apsis.argtypes = [c_double, c_int]
    ln2_lunar_previous_apsis.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 227
for _lib in _libs.values():
    if not _lib.has("ln2_lunar_next_node", "cdecl"):
        continue
    ln2_lunar_next_node = _lib.get("ln2_lunar_next_node", "cdecl")
    ln2_lunar_next_node.argtypes = [c_double, c_int]
    ln2_lunar_next_node.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/lunar.h: 236
for _lib in _libs.values():
    if not _lib.has("ln2_lunar_previous_node", "cdecl"):
        continue
    ln2_lunar_previous_node = _lib.get("ln2_lunar_previous_node", "cdecl")
    ln2_lunar_previous_node.argtypes = [c_double, c_int]
    ln2_lunar_previous_node.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 44
for _lib in _libs.values():
    if not _lib.has("ln2_solve_barker", "cdecl"):
        continue
    ln2_solve_barker = _lib.get("ln2_solve_barker", "cdecl")
    ln2_solve_barker.argtypes = [c_double, c_double]
    ln2_solve_barker.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 53
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_true_anomaly", "cdecl"):
        continue
    ln2_get_par_true_anomaly = _lib.get("ln2_get_par_true_anomaly", "cdecl")
    ln2_get_par_true_anomaly.argtypes = [c_double, c_double]
    ln2_get_par_true_anomaly.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 62
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_radius_vector", "cdecl"):
        continue
    ln2_get_par_radius_vector = _lib.get("ln2_get_par_radius_vector", "cdecl")
    ln2_get_par_radius_vector.argtypes = [c_double, c_double]
    ln2_get_par_radius_vector.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 71
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_geo_rect_posn", "cdecl"):
        continue
    ln2_get_par_geo_rect_posn = _lib.get("ln2_get_par_geo_rect_posn", "cdecl")
    ln2_get_par_geo_rect_posn.argtypes = [POINTER(struct_ln_par_orbit), c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_par_geo_rect_posn.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 80
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_helio_rect_posn", "cdecl"):
        continue
    ln2_get_par_helio_rect_posn = _lib.get("ln2_get_par_helio_rect_posn", "cdecl")
    ln2_get_par_helio_rect_posn.argtypes = [POINTER(struct_ln_par_orbit), c_double, POINTER(struct_ln_rect_posn)]
    ln2_get_par_helio_rect_posn.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 89
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_equ_coords", "cdecl"):
        continue
    ln2_get_par_body_equ_coords = _lib.get("ln2_get_par_body_equ_coords", "cdecl")
    ln2_get_par_body_equ_coords.argtypes = [c_double, POINTER(struct_ln_par_orbit), POINTER(struct_ln_equ_posn)]
    ln2_get_par_body_equ_coords.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 98
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_earth_dist", "cdecl"):
        continue
    ln2_get_par_body_earth_dist = _lib.get("ln2_get_par_body_earth_dist", "cdecl")
    ln2_get_par_body_earth_dist.argtypes = [c_double, POINTER(struct_ln_par_orbit)]
    ln2_get_par_body_earth_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 107
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_solar_dist", "cdecl"):
        continue
    ln2_get_par_body_solar_dist = _lib.get("ln2_get_par_body_solar_dist", "cdecl")
    ln2_get_par_body_solar_dist.argtypes = [c_double, POINTER(struct_ln_par_orbit)]
    ln2_get_par_body_solar_dist.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 116
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_phase_angle", "cdecl"):
        continue
    ln2_get_par_body_phase_angle = _lib.get("ln2_get_par_body_phase_angle", "cdecl")
    ln2_get_par_body_phase_angle.argtypes = [c_double, POINTER(struct_ln_par_orbit)]
    ln2_get_par_body_phase_angle.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 125
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_elong", "cdecl"):
        continue
    ln2_get_par_body_elong = _lib.get("ln2_get_par_body_elong", "cdecl")
    ln2_get_par_body_elong.argtypes = [c_double, POINTER(struct_ln_par_orbit)]
    ln2_get_par_body_elong.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 136
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_rst", "cdecl"):
        continue
    ln2_get_par_body_rst = _lib.get("ln2_get_par_body_rst", "cdecl")
    ln2_get_par_body_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_par_orbit), POINTER(struct_ln_rst_time)]
    ln2_get_par_body_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 149
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_rst_horizon", "cdecl"):
        continue
    ln2_get_par_body_rst_horizon = _lib.get("ln2_get_par_body_rst_horizon", "cdecl")
    ln2_get_par_body_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_par_orbit), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_par_body_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 161
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_next_rst", "cdecl"):
        continue
    ln2_get_par_body_next_rst = _lib.get("ln2_get_par_body_next_rst", "cdecl")
    ln2_get_par_body_next_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_par_orbit), POINTER(struct_ln_rst_time)]
    ln2_get_par_body_next_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 174
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_next_rst_horizon", "cdecl"):
        continue
    ln2_get_par_body_next_rst_horizon = _lib.get("ln2_get_par_body_next_rst_horizon", "cdecl")
    ln2_get_par_body_next_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_par_orbit), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_par_body_next_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/parabolic_motion.h: 189
for _lib in _libs.values():
    if not _lib.has("ln2_get_par_body_next_rst_horizon_future", "cdecl"):
        continue
    ln2_get_par_body_next_rst_horizon_future = _lib.get("ln2_get_par_body_next_rst_horizon_future", "cdecl")
    ln2_get_par_body_next_rst_horizon_future.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_par_orbit), c_double, c_int, POINTER(struct_ln_rst_time)]
    ln2_get_par_body_next_rst_horizon_future.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/refraction.h: 49
for _lib in _libs.values():
    if not _lib.has("ln2_get_refraction_adj", "cdecl"):
        continue
    ln2_get_refraction_adj = _lib.get("ln2_get_refraction_adj", "cdecl")
    ln2_get_refraction_adj.argtypes = [c_double, c_double, c_double]
    ln2_get_refraction_adj.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 52
for _lib in _libs.values():
    if not _lib.has("ln2_get_object_rst", "cdecl"):
        continue
    ln2_get_object_rst = _lib.get("ln2_get_object_rst", "cdecl")
    ln2_get_object_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_equ_posn), POINTER(struct_ln_rst_time)]
    ln2_get_object_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 65
for _lib in _libs.values():
    if not _lib.has("ln2_get_object_rst_horizon", "cdecl"):
        continue
    ln2_get_object_rst_horizon = _lib.get("ln2_get_object_rst_horizon", "cdecl")
    ln2_get_object_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_equ_posn), c_longdouble, POINTER(struct_ln_rst_time)]
    ln2_get_object_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 68
for _lib in _libs.values():
    if not _lib.has("ln2_get_object_rst_horizon_offset", "cdecl"):
        continue
    ln2_get_object_rst_horizon_offset = _lib.get("ln2_get_object_rst_horizon_offset", "cdecl")
    ln2_get_object_rst_horizon_offset.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_equ_posn), c_longdouble, POINTER(struct_ln_rst_time), c_double]
    ln2_get_object_rst_horizon_offset.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 83
for _lib in _libs.values():
    if not _lib.has("ln2_get_object_next_rst", "cdecl"):
        continue
    ln2_get_object_next_rst = _lib.get("ln2_get_object_next_rst", "cdecl")
    ln2_get_object_next_rst.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_equ_posn), POINTER(struct_ln_rst_time)]
    ln2_get_object_next_rst.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 97
for _lib in _libs.values():
    if not _lib.has("ln2_get_object_next_rst_horizon", "cdecl"):
        continue
    ln2_get_object_next_rst_horizon = _lib.get("ln2_get_object_next_rst_horizon", "cdecl")
    ln2_get_object_next_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_object_next_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 110
for _lib in _libs.values():
    if not _lib.has("ln2_get_body_rst_horizon", "cdecl"):
        continue
    ln2_get_body_rst_horizon = _lib.get("ln2_get_body_rst_horizon", "cdecl")
    ln2_get_body_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), CFUNCTYPE(UNCHECKED(None), c_double, POINTER(struct_ln_equ_posn)), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_body_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 114
for _lib in _libs.values():
    if not _lib.has("ln2_get_body_rst_horizon_offset", "cdecl"):
        continue
    ln2_get_body_rst_horizon_offset = _lib.get("ln2_get_body_rst_horizon_offset", "cdecl")
    ln2_get_body_rst_horizon_offset.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), CFUNCTYPE(UNCHECKED(None), c_double, POINTER(struct_ln_equ_posn)), c_double, POINTER(struct_ln_rst_time), c_double]
    ln2_get_body_rst_horizon_offset.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 129
for _lib in _libs.values():
    if not _lib.has("ln2_get_body_next_rst_horizon", "cdecl"):
        continue
    ln2_get_body_next_rst_horizon = _lib.get("ln2_get_body_next_rst_horizon", "cdecl")
    ln2_get_body_next_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), CFUNCTYPE(UNCHECKED(None), c_double, POINTER(struct_ln_equ_posn)), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_body_next_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 145
for _lib in _libs.values():
    if not _lib.has("ln2_get_body_next_rst_horizon_future", "cdecl"):
        continue
    ln2_get_body_next_rst_horizon_future = _lib.get("ln2_get_body_next_rst_horizon_future", "cdecl")
    ln2_get_body_next_rst_horizon_future.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), CFUNCTYPE(UNCHECKED(None), c_double, POINTER(struct_ln_equ_posn)), c_double, c_int, POINTER(struct_ln_rst_time)]
    ln2_get_body_next_rst_horizon_future.restype = c_int
    break

get_motion_body_coords_t = CFUNCTYPE(UNCHECKED(None), c_double, POINTER(None), POINTER(struct_ln_equ_posn))# /home/lrg/source/libnova/src/libnova2/rise_set.h: 149

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 162
for _lib in _libs.values():
    if not _lib.has("ln2_get_motion_body_rst_horizon", "cdecl"):
        continue
    ln2_get_motion_body_rst_horizon = _lib.get("ln2_get_motion_body_rst_horizon", "cdecl")
    ln2_get_motion_body_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), get_motion_body_coords_t, POINTER(None), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_motion_body_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 166
for _lib in _libs.values():
    if not _lib.has("ln2_get_motion_body_rst_horizon_offset", "cdecl"):
        continue
    ln2_get_motion_body_rst_horizon_offset = _lib.get("ln2_get_motion_body_rst_horizon_offset", "cdecl")
    ln2_get_motion_body_rst_horizon_offset.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), get_motion_body_coords_t, POINTER(None), c_double, POINTER(struct_ln_rst_time), c_double]
    ln2_get_motion_body_rst_horizon_offset.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 182
for _lib in _libs.values():
    if not _lib.has("ln2_get_motion_body_next_rst_horizon", "cdecl"):
        continue
    ln2_get_motion_body_next_rst_horizon = _lib.get("ln2_get_motion_body_next_rst_horizon", "cdecl")
    ln2_get_motion_body_next_rst_horizon.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), get_motion_body_coords_t, POINTER(None), c_double, POINTER(struct_ln_rst_time)]
    ln2_get_motion_body_next_rst_horizon.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 199
for _lib in _libs.values():
    if not _lib.has("ln2_get_motion_body_next_rst_horizon_future", "cdecl"):
        continue
    ln2_get_motion_body_next_rst_horizon_future = _lib.get("ln2_get_motion_body_next_rst_horizon_future", "cdecl")
    ln2_get_motion_body_next_rst_horizon_future.argtypes = [c_double, POINTER(struct_ln_lnlat_posn), get_motion_body_coords_t, POINTER(None), c_double, c_int, POINTER(struct_ln_rst_time)]
    ln2_get_motion_body_next_rst_horizon_future.restype = c_int
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 42
for _lib in _libs.values():
    if not _lib.has("ln_get_version", "cdecl"):
        continue
    ln_get_version = _lib.get("ln_get_version", "cdecl")
    ln_get_version.argtypes = []
    ln_get_version.restype = c_char_p
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 58
for _lib in _libs.values():
    if not _lib.has("ln2_get_dec_location", "cdecl"):
        continue
    ln2_get_dec_location = _lib.get("ln2_get_dec_location", "cdecl")
    ln2_get_dec_location.argtypes = [String]
    ln2_get_dec_location.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 66
for _lib in _libs.values():
    if not _lib.has("ln_get_humanr_location", "cdecl"):
        continue
    ln_get_humanr_location = _lib.get("ln_get_humanr_location", "cdecl")
    ln_get_humanr_location.argtypes = [c_double]
    ln_get_humanr_location.restype = c_char_p
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 75
for _lib in _libs.values():
    if not _lib.has("ln2_get_rect_distance", "cdecl"):
        continue
    ln2_get_rect_distance = _lib.get("ln2_get_rect_distance", "cdecl")
    ln2_get_rect_distance.argtypes = [POINTER(struct_ln_rect_posn), POINTER(struct_ln_rect_posn)]
    ln2_get_rect_distance.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 89
for _lib in _libs.values():
    if not _lib.has("ln2_rad_to_deg", "cdecl"):
        continue
    ln2_rad_to_deg = _lib.get("ln2_rad_to_deg", "cdecl")
    ln2_rad_to_deg.argtypes = [c_double]
    ln2_rad_to_deg.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 97
for _lib in _libs.values():
    if not _lib.has("ln2_deg_to_rad", "cdecl"):
        continue
    ln2_deg_to_rad = _lib.get("ln2_deg_to_rad", "cdecl")
    ln2_deg_to_rad.argtypes = [c_double]
    ln2_deg_to_rad.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 105
for _lib in _libs.values():
    if not _lib.has("ln2_hms_to_deg", "cdecl"):
        continue
    ln2_hms_to_deg = _lib.get("ln2_hms_to_deg", "cdecl")
    ln2_hms_to_deg.argtypes = [POINTER(struct_ln_hms)]
    ln2_hms_to_deg.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 113
for _lib in _libs.values():
    if not _lib.has("ln2_deg_to_hms", "cdecl"):
        continue
    ln2_deg_to_hms = _lib.get("ln2_deg_to_hms", "cdecl")
    ln2_deg_to_hms.argtypes = [c_double, POINTER(struct_ln_hms)]
    ln2_deg_to_hms.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 121
for _lib in _libs.values():
    if not _lib.has("ln2_hms_to_rad", "cdecl"):
        continue
    ln2_hms_to_rad = _lib.get("ln2_hms_to_rad", "cdecl")
    ln2_hms_to_rad.argtypes = [POINTER(struct_ln_hms)]
    ln2_hms_to_rad.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 129
for _lib in _libs.values():
    if not _lib.has("ln2_rad_to_hms", "cdecl"):
        continue
    ln2_rad_to_hms = _lib.get("ln2_rad_to_hms", "cdecl")
    ln2_rad_to_hms.argtypes = [c_double, POINTER(struct_ln_hms)]
    ln2_rad_to_hms.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 137
for _lib in _libs.values():
    if not _lib.has("ln2_dms_to_deg", "cdecl"):
        continue
    ln2_dms_to_deg = _lib.get("ln2_dms_to_deg", "cdecl")
    ln2_dms_to_deg.argtypes = [POINTER(struct_ln_dms)]
    ln2_dms_to_deg.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 145
for _lib in _libs.values():
    if not _lib.has("ln2_deg_to_dms", "cdecl"):
        continue
    ln2_deg_to_dms = _lib.get("ln2_deg_to_dms", "cdecl")
    ln2_deg_to_dms.argtypes = [c_double, POINTER(struct_ln_dms)]
    ln2_deg_to_dms.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 153
for _lib in _libs.values():
    if not _lib.has("ln2_dms_to_rad", "cdecl"):
        continue
    ln2_dms_to_rad = _lib.get("ln2_dms_to_rad", "cdecl")
    ln2_dms_to_rad.argtypes = [POINTER(struct_ln_dms)]
    ln2_dms_to_rad.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 163
for _lib in _libs.values():
    if not _lib.has("ln2_dms2_to_rad", "cdecl"):
        continue
    ln2_dms2_to_rad = _lib.get("ln2_dms2_to_rad", "cdecl")
    ln2_dms2_to_rad.argtypes = [c_int, c_int, c_double]
    ln2_dms2_to_rad.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 171
for _lib in _libs.values():
    if not _lib.has("ln2_rad_to_dms", "cdecl"):
        continue
    ln2_rad_to_dms = _lib.get("ln2_rad_to_dms", "cdecl")
    ln2_rad_to_dms.argtypes = [c_double, POINTER(struct_ln_dms)]
    ln2_rad_to_dms.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 179
for _lib in _libs.values():
    if not _lib.has("ln2_hequ_to_equ", "cdecl"):
        continue
    ln2_hequ_to_equ = _lib.get("ln2_hequ_to_equ", "cdecl")
    ln2_hequ_to_equ.argtypes = [POINTER(struct_lnh_equ_posn), POINTER(struct_ln_equ_posn)]
    ln2_hequ_to_equ.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 188
for _lib in _libs.values():
    if not _lib.has("ln2_equ_to_hequ", "cdecl"):
        continue
    ln2_equ_to_hequ = _lib.get("ln2_equ_to_hequ", "cdecl")
    ln2_equ_to_hequ.argtypes = [POINTER(struct_ln_equ_posn), POINTER(struct_lnh_equ_posn)]
    ln2_equ_to_hequ.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 197
for _lib in _libs.values():
    if not _lib.has("ln2_hhrz_to_hrz", "cdecl"):
        continue
    ln2_hhrz_to_hrz = _lib.get("ln2_hhrz_to_hrz", "cdecl")
    ln2_hhrz_to_hrz.argtypes = [POINTER(struct_lnh_hrz_posn), POINTER(struct_ln_hrz_posn)]
    ln2_hhrz_to_hrz.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 206
for _lib in _libs.values():
    if not _lib.has("ln2_hrz_to_hhrz", "cdecl"):
        continue
    ln2_hrz_to_hhrz = _lib.get("ln2_hrz_to_hhrz", "cdecl")
    ln2_hrz_to_hhrz.argtypes = [POINTER(struct_ln_hrz_posn), POINTER(struct_lnh_hrz_posn)]
    ln2_hrz_to_hhrz.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 215
for _lib in _libs.values():
    if not _lib.has("ln_hrz_to_nswe", "cdecl"):
        continue
    ln_hrz_to_nswe = _lib.get("ln_hrz_to_nswe", "cdecl")
    ln_hrz_to_nswe.argtypes = [POINTER(struct_ln_hrz_posn)]
    ln_hrz_to_nswe.restype = c_char_p
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 224
for _lib in _libs.values():
    if not _lib.has("ln2_hlnlat_to_lnlat", "cdecl"):
        continue
    ln2_hlnlat_to_lnlat = _lib.get("ln2_hlnlat_to_lnlat", "cdecl")
    ln2_hlnlat_to_lnlat.argtypes = [POINTER(struct_lnh_lnlat_posn), POINTER(struct_ln_lnlat_posn)]
    ln2_hlnlat_to_lnlat.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 234
for _lib in _libs.values():
    if not _lib.has("ln2_lnlat_to_hlnlat", "cdecl"):
        continue
    ln2_lnlat_to_hlnlat = _lib.get("ln2_lnlat_to_hlnlat", "cdecl")
    ln2_lnlat_to_hlnlat.argtypes = [POINTER(struct_ln_lnlat_posn), POINTER(struct_lnh_lnlat_posn)]
    ln2_lnlat_to_hlnlat.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 243
for _lib in _libs.values():
    if not _lib.has("ln2_add_secs_hms", "cdecl"):
        continue
    ln2_add_secs_hms = _lib.get("ln2_add_secs_hms", "cdecl")
    ln2_add_secs_hms.argtypes = [POINTER(struct_ln_hms), c_double]
    ln2_add_secs_hms.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 251
for _lib in _libs.values():
    if not _lib.has("ln2_add_hms", "cdecl"):
        continue
    ln2_add_hms = _lib.get("ln2_add_hms", "cdecl")
    ln2_add_hms.argtypes = [POINTER(struct_ln_hms), POINTER(struct_ln_hms)]
    ln2_add_hms.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 259
for _lib in _libs.values():
    if not _lib.has("ln2_range_degrees", "cdecl"):
        continue
    ln2_range_degrees = _lib.get("ln2_range_degrees", "cdecl")
    ln2_range_degrees.argtypes = [c_double]
    ln2_range_degrees.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 267
for _lib in _libs.values():
    if not _lib.has("ln2_range_radians", "cdecl"):
        continue
    ln2_range_radians = _lib.get("ln2_range_radians", "cdecl")
    ln2_range_radians.argtypes = [c_double]
    ln2_range_radians.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 275
for _lib in _libs.values():
    if not _lib.has("ln2_range_radians2", "cdecl"):
        continue
    ln2_range_radians2 = _lib.get("ln2_range_radians2", "cdecl")
    ln2_range_radians2.argtypes = [c_double]
    ln2_range_radians2.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 283
for _lib in _libs.values():
    if not _lib.has("ln2_range_hours", "cdecl"):
        continue
    ln2_range_hours = _lib.get("ln2_range_hours", "cdecl")
    ln2_range_hours.argtypes = [c_double]
    ln2_range_hours.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 291
for _lib in _libs.values():
    if not _lib.has("ln2_get_light_time", "cdecl"):
        continue
    ln2_get_light_time = _lib.get("ln2_get_light_time", "cdecl")
    ln2_get_light_time.argtypes = [c_double]
    ln2_get_light_time.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 302
for _lib in _libs.values():
    if not _lib.has("ln2_interpolate3", "cdecl"):
        continue
    ln2_interpolate3 = _lib.get("ln2_interpolate3", "cdecl")
    ln2_interpolate3.argtypes = [c_double, c_double, c_double, c_double]
    ln2_interpolate3.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 317
for _lib in _libs.values():
    if not _lib.has("ln2_interpolate5", "cdecl"):
        continue
    ln2_interpolate5 = _lib.get("ln2_interpolate5", "cdecl")
    ln2_interpolate5.argtypes = [c_double, c_double, c_double, c_double, c_double, c_double]
    ln2_interpolate5.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 331
for _lib in _libs.values():
    if not _lib.has("ln2_find_max", "cdecl"):
        continue
    ln2_find_max = _lib.get("ln2_find_max", "cdecl")
    ln2_find_max.argtypes = [CFUNCTYPE(UNCHECKED(c_double), c_double, POINTER(c_double)), c_double, c_double, POINTER(c_double)]
    ln2_find_max.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/utility.h: 344
for _lib in _libs.values():
    if not _lib.has("ln2_find_zero", "cdecl"):
        continue
    ln2_find_zero = _lib.get("ln2_find_zero", "cdecl")
    ln2_find_zero.argtypes = [CFUNCTYPE(UNCHECKED(c_double), c_double, POINTER(c_double)), c_double, c_double, POINTER(c_double)]
    ln2_find_zero.restype = c_double
    break

# /home/lrg/source/libnova/src/libnova2/parallax.h: 54
for _lib in _libs.values():
    if not _lib.has("ln2_get_parallax", "cdecl"):
        continue
    ln2_get_parallax = _lib.get("ln2_get_parallax", "cdecl")
    ln2_get_parallax.argtypes = [POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_lnlat_posn), c_double, c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_parallax.restype = None
    break

# /home/lrg/source/libnova/src/libnova2/parallax.h: 67
for _lib in _libs.values():
    if not _lib.has("ln2_get_parallax_ha", "cdecl"):
        continue
    ln2_get_parallax_ha = _lib.get("ln2_get_parallax_ha", "cdecl")
    ln2_get_parallax_ha.argtypes = [POINTER(struct_ln_equ_posn), c_double, POINTER(struct_ln_lnlat_posn), c_double, c_double, POINTER(struct_ln_equ_posn)]
    ln2_get_parallax_ha.restype = None
    break

__const = c_int# <command-line>: 0

# <command-line>: 0
try:
    CTYPESGEN = 1
except:
    pass

# /usr/include/stdc-predef.h: 19
try:
    _STDC_PREDEF_H = 1
except:
    pass

# /usr/include/stdc-predef.h: 38
try:
    __STDC_IEC_559__ = 1
except:
    pass

# /usr/include/stdc-predef.h: 39
try:
    __STDC_IEC_60559_BFP__ = 201404
except:
    pass

# /usr/include/stdc-predef.h: 48
try:
    __STDC_IEC_559_COMPLEX__ = 1
except:
    pass

# /usr/include/stdc-predef.h: 49
try:
    __STDC_IEC_60559_COMPLEX__ = 201404
except:
    pass

# /usr/include/stdc-predef.h: 62
try:
    __STDC_ISO_10646__ = 201706
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 53
try:
    M_PI_2 = 1.5707963267948966192313216916398
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 54
try:
    M_PI_4 = 0.78539816339744830961566084581988
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 55
try:
    M_PI = 3.1415926535897932384626433832795
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 59
try:
    LN_SIDEREAL_DAY_SEC = 86164.09
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 60
try:
    LN_SIDEREAL_DAY_DAY = (LN_SIDEREAL_DAY_SEC / 86400.0)
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 63
def LN_D2R(d):
    return (d * (M_PI / 180.0))

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 64
def LN_R2D(r):
    return (r * (180.0 / M_PI))

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 67
try:
    JD2000 = 2451545.0
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 68
try:
    JD2050 = 2469807.50
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 70
try:
    B1900 = 2415020.3135
except:
    pass

# /home/lrg/source/libnova/src/libnova2/ln_types.h: 71
try:
    B1950 = 2433282.4235
except:
    pass

# /usr/include/time.h: 23
try:
    _TIME_H = 1
except:
    pass

# /usr/include/features.h: 19
try:
    _FEATURES_H = 1
except:
    pass

# /usr/include/features.h: 176
def __GNUC_PREREQ(maj, min):
    return 0

# /usr/include/features.h: 187
def __glibc_clang_prereq(maj, min):
    return 0

# /usr/include/features.h: 250
try:
    _DEFAULT_SOURCE = 1
except:
    pass

# /usr/include/features.h: 258
try:
    __GLIBC_USE_ISOC2Y = 0
except:
    pass

# /usr/include/features.h: 264
try:
    __GLIBC_USE_ISOC23 = 1
except:
    pass

# /usr/include/features.h: 273
try:
    __USE_ISOC11 = 1
except:
    pass

# /usr/include/features.h: 280
try:
    __USE_ISOC99 = 1
except:
    pass

# /usr/include/features.h: 287
try:
    __USE_ISOC95 = 1
except:
    pass

# /usr/include/features.h: 308
try:
    __USE_POSIX_IMPLICITLY = 1
except:
    pass

# /usr/include/features.h: 311
try:
    _POSIX_SOURCE = 1
except:
    pass

# /usr/include/features.h: 313
try:
    _POSIX_C_SOURCE = 200809
except:
    pass

# /usr/include/features.h: 348
try:
    __USE_POSIX = 1
except:
    pass

# /usr/include/features.h: 352
try:
    __USE_POSIX2 = 1
except:
    pass

# /usr/include/features.h: 356
try:
    __USE_POSIX199309 = 1
except:
    pass

# /usr/include/features.h: 360
try:
    __USE_POSIX199506 = 1
except:
    pass

# /usr/include/features.h: 364
try:
    __USE_XOPEN2K = 1
except:
    pass

# /usr/include/features.h: 365
# #undef __USE_ISOC95
try:
    del __USE_ISOC95
except NameError:
    pass

# /usr/include/features.h: 366
try:
    __USE_ISOC95 = 1
except:
    pass

# /usr/include/features.h: 367
# #undef __USE_ISOC99
try:
    del __USE_ISOC99
except NameError:
    pass

# /usr/include/features.h: 368
try:
    __USE_ISOC99 = 1
except:
    pass

# /usr/include/features.h: 372
try:
    __USE_XOPEN2K8 = 1
except:
    pass

# /usr/include/features.h: 374
try:
    _ATFILE_SOURCE = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 4
try:
    __WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 11
try:
    __WORDSIZE_TIME64_COMPAT32 = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 15
try:
    __SYSCALL_WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 4
try:
    __WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 11
try:
    __WORDSIZE_TIME64_COMPAT32 = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 15
try:
    __SYSCALL_WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/timesize.h: 26
try:
    __TIMESIZE = __WORDSIZE
except:
    pass

# /usr/include/features-time64.h: 37
try:
    __USE_TIME_BITS64 = 1
except:
    pass

# /usr/include/features.h: 418
try:
    __USE_MISC = 1
except:
    pass

# /usr/include/features.h: 422
try:
    __USE_ATFILE = 1
except:
    pass

# /usr/include/features.h: 454
try:
    __USE_FORTIFY_LEVEL = 0
except:
    pass

# /usr/include/features.h: 462
try:
    __GLIBC_USE_DEPRECATED_GETS = 0
except:
    pass

# /usr/include/features.h: 485
try:
    __GLIBC_USE_DEPRECATED_SCANF = 0
except:
    pass

# /usr/include/features.h: 494
try:
    __GLIBC_USE_C23_STRTOL = 1
except:
    pass

# /usr/include/features.h: 510
try:
    __GNU_LIBRARY__ = 6
except:
    pass

# /usr/include/features.h: 514
try:
    __GLIBC__ = 2
except:
    pass

# /usr/include/features.h: 515
try:
    __GLIBC_MINOR__ = 42
except:
    pass

# /usr/include/features.h: 517
def __GLIBC_PREREQ(maj, min):
    return (((__GLIBC__ << 16) + __GLIBC_MINOR__) >= ((maj << 16) + min))

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 20
try:
    _SYS_CDEFS_H = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 118
def __NTH(fct):
    return fct

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 125
def __P(args):
    return args

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 126
def __PMT(args):
    return args

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 132
def __STRING(x):
    return x

__ptr_t = POINTER(None)# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 135

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 380
try:
    __glibc_c99_flexarr_available = 1
except:
    pass

__restrict = c_int# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 655

__restrict_arr = c_int# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 672

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 4
try:
    __WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 11
try:
    __WORDSIZE_TIME64_COMPAT32 = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 15
try:
    __SYSCALL_WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/long-double.h: 21
try:
    __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI = 0
except:
    pass

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 788
def __LDBL_REDIR1(name, proto, alias):
    return (name + proto)

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 789
def __LDBL_REDIR(name, proto):
    return (name + proto)

# /usr/include/x86_64-linux-gnu/sys/cdefs.h: 826
try:
    __HAVE_GENERIC_SELECTION = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 24
try:
    _BITS_TIME_H = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types.h: 24
try:
    _BITS_TYPES_H = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 4
try:
    __WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 11
try:
    __WORDSIZE_TIME64_COMPAT32 = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 15
try:
    __SYSCALL_WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 4
try:
    __WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 11
try:
    __WORDSIZE_TIME64_COMPAT32 = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/wordsize.h: 15
try:
    __SYSCALL_WORDSIZE = 64
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/timesize.h: 26
try:
    __TIMESIZE = __WORDSIZE
except:
    pass

__S16_TYPE = c_short# /usr/include/x86_64-linux-gnu/bits/types.h: 109

__U16_TYPE = c_ushort# /usr/include/x86_64-linux-gnu/bits/types.h: 110

__S32_TYPE = c_int# /usr/include/x86_64-linux-gnu/bits/types.h: 111

__U32_TYPE = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 112

__SLONGWORD_TYPE = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 113

__ULONGWORD_TYPE = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 114

__SQUAD_TYPE = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 128

__UQUAD_TYPE = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 129

__SWORD_TYPE = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 130

__UWORD_TYPE = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 131

__SLONG32_TYPE = c_int# /usr/include/x86_64-linux-gnu/bits/types.h: 132

__ULONG32_TYPE = c_uint# /usr/include/x86_64-linux-gnu/bits/types.h: 133

__S64_TYPE = c_long# /usr/include/x86_64-linux-gnu/bits/types.h: 134

__U64_TYPE = c_ulong# /usr/include/x86_64-linux-gnu/bits/types.h: 135

# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 24
try:
    _BITS_TYPESIZES_H = 1
except:
    pass

__TIMER_T_TYPE = POINTER(None)# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 71

# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 73
class struct_anon_2(Structure):
    pass

struct_anon_2.__slots__ = [
    '__val',
]
struct_anon_2._fields_ = [
    ('__val', c_int * int(2)),
]

__FSID_T_TYPE = struct_anon_2# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 73

# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 81
try:
    __OFF_T_MATCHES_OFF64_T = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 84
try:
    __INO_T_MATCHES_INO64_T = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 87
try:
    __RLIM_T_MATCHES_RLIM64_T = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 90
try:
    __STATFS_MATCHES_STATFS64 = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 93
try:
    __KERNEL_OLD_TIMEVAL_MATCHES_TIMEVAL64 = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/typesizes.h: 103
try:
    __FD_SETSIZE = 1024
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time64.h: 24
try:
    _BITS_TIME64_H = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 34
try:
    CLOCKS_PER_SEC = (__clock_t (ord_if_char(1000000))).value
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 46
try:
    CLOCK_REALTIME = 0
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 48
try:
    CLOCK_MONOTONIC = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 50
try:
    CLOCK_PROCESS_CPUTIME_ID = 2
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 52
try:
    CLOCK_THREAD_CPUTIME_ID = 3
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 54
try:
    CLOCK_MONOTONIC_RAW = 4
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 56
try:
    CLOCK_REALTIME_COARSE = 5
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 58
try:
    CLOCK_MONOTONIC_COARSE = 6
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 60
try:
    CLOCK_BOOTTIME = 7
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 62
try:
    CLOCK_REALTIME_ALARM = 8
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 64
try:
    CLOCK_BOOTTIME_ALARM = 9
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 66
try:
    CLOCK_TAI = 11
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/time.h: 69
try:
    TIMER_ABSTIME = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/clock_t.h: 2
try:
    __clock_t_defined = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/time_t.h: 2
try:
    __time_t_defined = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h: 2
try:
    __struct_tm_defined = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h: 3
try:
    _STRUCT_TIMESPEC = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/endian.h: 20
try:
    _BITS_ENDIAN_H = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/endian.h: 30
try:
    __LITTLE_ENDIAN = 1234
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/endian.h: 31
try:
    __BIG_ENDIAN = 4321
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/endian.h: 32
try:
    __PDP_ENDIAN = 3412
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/endianness.h: 2
try:
    _BITS_ENDIANNESS_H = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/endianness.h: 9
try:
    __BYTE_ORDER = __LITTLE_ENDIAN
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/endian.h: 40
try:
    __FLOAT_WORD_ORDER = __BYTE_ORDER
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h: 2
try:
    __clockid_t_defined = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/timer_t.h: 2
try:
    __timer_t_defined = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h: 2
try:
    __itimerspec_defined = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/locale_t.h: 20
try:
    _BITS_TYPES_LOCALE_T_H = 1
except:
    pass

# /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h: 20
try:
    _BITS_TYPES___LOCALE_T_H = 1
except:
    pass

# /usr/include/time.h: 65
try:
    TIME_UTC = 1
except:
    pass

# /usr/include/time.h: 239
def __isleap(year):
    return (((year % 4) == 0) and (((year % 100) != 0) or ((year % 400) == 0)))

# /home/lrg/source/libnova/src/libnova2/libnova2.h: 19
try:
    LIBNOVA2_VERSION = '0.99.0'
except:
    pass

# /home/lrg/source/libnova/src/libnova2/solar.h: 24
try:
    LN_SOLAR_STANDART_HORIZON = (-0.8333)
except:
    pass

# /home/lrg/source/libnova/src/libnova2/solar.h: 25
try:
    LN_SOLAR_CIVIL_HORIZON = (-6.0)
except:
    pass

# /home/lrg/source/libnova/src/libnova2/solar.h: 26
try:
    LN_SOLAR_NAUTIC_HORIZON = (-12.0)
except:
    pass

# /home/lrg/source/libnova/src/libnova2/solar.h: 27
try:
    LN_SOLAR_ASTRONOMICAL_HORIZON = (-18.0)
except:
    pass

# /home/lrg/source/libnova/src/libnova2/lunar.h: 24
try:
    LN_LUNAR_STANDART_HORIZON = 0.125
except:
    pass

# /home/lrg/source/libnova/src/libnova2/rise_set.h: 24
try:
    LN_STAR_STANDART_HORIZON = (-0.00989019909)
except:
    pass

ln_date = struct_ln_date# /home/lrg/source/libnova/src/libnova2/ln_types.h: 83

ln_zonedate = struct_ln_zonedate# /home/lrg/source/libnova/src/libnova2/ln_types.h: 114

ln_dms = struct_ln_dms# /home/lrg/source/libnova/src/libnova2/ln_types.h: 131

ln_hms = struct_ln_hms# /home/lrg/source/libnova/src/libnova2/ln_types.h: 144

lnh_equ_posn = struct_lnh_equ_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 156

lnh_hrz_posn = struct_lnh_hrz_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 167

lnh_lnlat_posn = struct_lnh_lnlat_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 178

ln_equ_posn = struct_ln_equ_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 191

ln_hrz_posn = struct_ln_hrz_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 204

ln_lnlat_posn = struct_ln_lnlat_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 219

ln_helio_posn = struct_ln_helio_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 233

ln_rect_posn = struct_ln_rect_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 253

ln_gal_posn = struct_ln_gal_posn# /home/lrg/source/libnova/src/libnova2/ln_types.h: 267

ln_ell_orbit = struct_ln_ell_orbit# /home/lrg/source/libnova/src/libnova2/ln_types.h: 279

ln_par_orbit = struct_ln_par_orbit# /home/lrg/source/libnova/src/libnova2/ln_types.h: 309

ln_hyp_orbit = struct_ln_hyp_orbit# /home/lrg/source/libnova/src/libnova2/ln_types.h: 335

ln_rst_time = struct_ln_rst_time# /home/lrg/source/libnova/src/libnova2/ln_types.h: 363

ln_nutation = struct_ln_nutation# /home/lrg/source/libnova/src/libnova2/ln_types.h: 377

tm = struct_tm# /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h: 7

timespec = struct_timespec# /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h: 11

itimerspec = struct_itimerspec# /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h: 8

sigevent = struct_sigevent# /usr/include/time.h: 49

__locale_data = struct___locale_data# /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h: 30

__locale_struct = struct___locale_struct# /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h: 27

ln_vsop = struct_ln_vsop# /home/lrg/source/libnova/src/libnova2/vsop87.h: 52

# No inserted files

# No prefix-stripping

