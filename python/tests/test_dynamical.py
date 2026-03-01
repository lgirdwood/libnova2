import unittest
from libnova2 import libnova2
import ctypes

class TestDynamical(unittest.TestCase):
    def test_dynamical(self):
        date = libnova2.struct_ln_date()
        date.years = 2000; date.months = 1; date.days = 1
        date.hours = 0; date.minutes = 0; date.seconds = 0.0

        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        TD = libnova2.ln2_get_jde(JD)
        
        self.assertAlmostEqual(TD, 2451544.50073877, delta=0.000001)

if __name__ == '__main__':
    unittest.main()
