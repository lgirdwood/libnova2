import os
import ctypes
from libnova2 import libnova2

# Create a date object for J2000.0 (January 1.5, 2000)
date = libnova2.struct_ln_date()
date.years = 2000
date.months = 1
date.days = 1
date.hours = 12
date.minutes = 0
date.seconds = 0.0

jd = libnova2.ln2_get_julian_day(ctypes.byref(date))
print(f"JD for 2000-01-01 12:00:00: {jd}")
