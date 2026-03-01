import unittest
from libnova2 import libnova2
import ctypes
import math

class TestNutation(unittest.TestCase):
    def test_nutation_test(self):
        JD = 2446895.5
        nutation = libnova2.struct_ln_nutation()

        libnova2.ln2_get_nutation(JD, ctypes.byref(nutation))
        self.assertAlmostEqual(math.degrees(nutation.longitude), -3.788 / (60.0 * 360.0), delta=0.0000001)
        self.assertAlmostEqual(math.degrees(nutation.obliquity), 9.443 / (60.0 * 360.0), delta=0.000001)
        self.assertAlmostEqual(math.degrees(nutation.ecliptic), 23.0 + 26.0 / 60.0 + 27.407 / (60.0 * 360.0), delta=0.000001)

        date = libnova2.struct_ln_date()
        date.years = 2028; date.months = 11; date.days = 13
        date.hours = 4; date.minutes = 33; date.seconds = 36.0

        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))

        libnova2.ln2_get_nutation(JD, ctypes.byref(nutation))
        self.assertAlmostEqual(math.degrees(nutation.longitude), 14.861 / (60.0 * 360.0), delta=0.0000001)
        self.assertAlmostEqual(math.degrees(nutation.obliquity), 2.705 / (60.0 * 360.0), delta=0.000001)
        self.assertAlmostEqual(math.degrees(nutation.ecliptic), math.degrees(0.40899523), delta=0.000001)

if __name__ == '__main__':
    unittest.main()
