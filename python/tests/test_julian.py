import unittest
import ctypes
import math
from libnova2 import libnova2

class TestJulian(unittest.TestCase):
    def test_julian_day_calculation(self):
        # Get julian day for 04/10/1957 19:00:00
        date = libnova2.struct_ln_date()
        date.years = 1957; date.months = 10; date.days = 4
        date.hours = 19; date.minutes = 0; date.seconds = 0.0
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 2436116.29166667, delta=0.00001)

        # Get julian day for 27/01/333 12:00:00
        date = libnova2.struct_ln_date()
        date.years = 333; date.months = 1; date.days = 27
        date.hours = 12; date.minutes = 0; date.seconds = 0.0
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 1842713.0, delta=0.1)

        # Get julian day for 30/06/1954 00:00:00
        date = libnova2.struct_ln_date()
        date.years = 1954; date.months = 6; date.days = 30
        date.hours = 0; date.minutes = 0; date.seconds = 0.0
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 2434923.5, delta=0.1)

        wday = libnova2.ln2_get_day_of_week(ctypes.byref(date))
        self.assertEqual(wday, 3)

        # Test ln2_date_to_zonedate and back
        zonedate = libnova2.struct_ln_zonedate()
        libnova2.ln2_date_to_zonedate(ctypes.byref(date), ctypes.byref(zonedate), 7200)
        libnova2.ln2_zonedate_to_date(ctypes.byref(zonedate), ctypes.byref(date))
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 2434923.5, delta=0.1)

        pdate = libnova2.struct_ln_date()
        libnova2.ln2_get_date(JD, ctypes.byref(pdate))
        self.assertEqual(pdate.days, 30)
        self.assertEqual(pdate.months, 6)
        self.assertEqual(pdate.years, 1954)
        self.assertEqual(pdate.hours, 0)
        self.assertEqual(pdate.minutes, 0)
        self.assertAlmostEqual(pdate.seconds, 0.0, delta=0.001)

        # Get julian day for 01/01/1987 00:00:00
        date = libnova2.struct_ln_date()
        date.years = 1987; date.months = 1; date.days = 1
        date.hours = 0; date.minutes = 0; date.seconds = 0.0
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 2446796.5, delta=0.00001)

        # Get julian day for 01/01/1900 00:00:00
        date = libnova2.struct_ln_date()
        date.years = 1900; date.months = 1; date.days = 1
        date.hours = 0; date.minutes = 0; date.seconds = 0.0
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 2415020.5, delta=0.00001)

        # Get julian day for 01/01/1600 00:00:00
        date = libnova2.struct_ln_date()
        date.years = 1600; date.months = 1; date.days = 1
        date.hours = 0; date.minutes = 0; date.seconds = 0.0
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 2305447.5, delta=0.00001)

        # Get julian day for 31/12/1600 00:00:00
        date = libnova2.struct_ln_date()
        date.years = 1600; date.months = 12; date.days = 31
        date.hours = 0; date.minutes = 0; date.seconds = 0.0
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 2305812.5, delta=0.00001)

        # Get julian day for 10/04/1957 19:26:24
        date = libnova2.struct_ln_date()
        date.years = 1957; date.months = 10; date.days = 4
        date.hours = 19; date.minutes = 26; date.seconds = 24.0
        JD = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, 2436116.31, delta=0.00001)

    def test_date_time(self):
        # Time_t <-> JD
        # We simulate pointers to long using ctypes.c_long
        t = ctypes.c_long(1000000000)
        JD = libnova2.ln2_get_julian_from_timet(ctypes.byref(t))
        t2 = ctypes.c_long()
        libnova2.ln2_get_timet_from_julian(JD, ctypes.byref(t2))
        self.assertTrue(abs(t.value - t2.value) <= 1.0)

        # MPC Date
        # Have to pass bytestring to char* in ctypes
        mpc_str = b"K019090"
        JD = libnova2.ln2_get_julian_from_mpc(mpc_str)
        date = libnova2.struct_ln_date()
        date.years = 2001; date.months = 9; date.days = 9
        date.hours = 0; date.minutes = 0; date.seconds = 0.0
        JD_expected = libnova2.ln2_get_julian_day(ctypes.byref(date))
        self.assertAlmostEqual(JD, JD_expected, delta=1e-6)

        # Dynamical Time Diff
        TD_diff = libnova2.ln2_get_dynamical_time_diff(2451545.0)
        self.assertAlmostEqual(TD_diff, 64.0, delta=5.0)

        # 12th April 1957 19:21:00 (Though it tests 4th Oct 1957 from C test)
        JD = 2436116.31
        libnova2.ln2_get_date(JD, ctypes.byref(date))
        self.assertEqual(date.years, 1957)
        self.assertEqual(date.months, 10)
        self.assertEqual(date.days, 4)
        self.assertEqual(date.hours, 19)
        self.assertEqual(date.minutes, 26)
        self.assertAlmostEqual(date.seconds, 24.0, delta=0.001)

if __name__ == '__main__':
    unittest.main()
