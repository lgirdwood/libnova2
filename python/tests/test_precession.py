import unittest
from libnova2 import libnova2
import ctypes
import math

class TestPrecession(unittest.TestCase):
    def test_precession_test(self):
        JD2000 = 2451545.0
        B1900 = 2415020.3135
        JD2050 = 2469807.50

        object_pos = libnova2.struct_ln_equ_posn()
        pos = libnova2.struct_ln_equ_posn()
        pos2 = libnova2.struct_ln_equ_posn()
        pm = libnova2.struct_ln_equ_posn()
        hobject = libnova2.struct_lnh_equ_posn()

        hobject.ra.hours = 2; hobject.ra.minutes = 44; hobject.ra.seconds = 11.986
        hobject.dec.neg = 0; hobject.dec.degrees = 49; hobject.dec.minutes = 13; hobject.dec.seconds = 42.48

        JD = 2462088.69
        libnova2.ln2_hequ_to_equ(ctypes.byref(hobject), ctypes.byref(object_pos))

        pm.ra = math.radians(0.03425 / 3600.0)
        pm.dec = math.radians(-0.0895 / 3600.0)

        libnova2.ln2_get_equ_pm(ctypes.byref(object_pos), ctypes.byref(pm), JD, ctypes.byref(object_pos))

        self.assertAlmostEqual(math.degrees(object_pos.ra), 41.05021630, delta=0.00001)
        self.assertAlmostEqual(math.degrees(object_pos.dec), 49.227750, delta=0.00001)

        libnova2.ln2_get_equ_prec(ctypes.byref(object_pos), JD, ctypes.byref(pos))
        self.assertAlmostEqual(math.degrees(pos.ra), 41.54333349, delta=0.00003)
        self.assertAlmostEqual(math.degrees(pos.dec), 49.34849687, delta=0.00001)

        libnova2.ln2_get_equ_prec2(ctypes.byref(object_pos), JD2000, JD, ctypes.byref(pos))
        self.assertAlmostEqual(math.degrees(pos.ra), 41.54333349, delta=0.00001)
        self.assertAlmostEqual(math.degrees(pos.dec), 49.34849687, delta=0.00001)

        libnova2.ln2_get_equ_prec2(ctypes.byref(pos), JD, JD2000, ctypes.byref(pos2))
        self.assertAlmostEqual(math.degrees(pos2.ra), math.degrees(object_pos.ra), delta=0.00001)
        self.assertAlmostEqual(math.degrees(pos2.dec), math.degrees(object_pos.dec), delta=0.00001)

        # INTEGRAL GRB050922A
        pos.ra = math.radians(271.2473)
        pos.dec = math.radians(-32.0227)

        grb_date = libnova2.struct_ln_date()
        grb_date.years = 2005; grb_date.months = 9; grb_date.days = 22
        grb_date.hours = 13; grb_date.minutes = 43; grb_date.seconds = 18.0

        JD = libnova2.ln2_get_julian_day(ctypes.byref(grb_date))
        libnova2.ln2_get_equ_prec2(ctypes.byref(pos), JD, JD2000, ctypes.byref(pos2))

        self.assertAlmostEqual(math.degrees(pos2.ra), 271.1541, delta=0.0002)
        self.assertAlmostEqual(math.degrees(pos2.dec), -32.0235, delta=0.0002)

        # second test
        hobject.ra.hours = 2; hobject.ra.minutes = 31; hobject.ra.seconds = 48.704
        hobject.dec.neg = 0; hobject.dec.degrees = 89; hobject.dec.minutes = 15; hobject.dec.seconds = 50.72

        libnova2.ln2_hequ_to_equ(ctypes.byref(hobject), ctypes.byref(object_pos))

        pm.ra = math.radians(0.19877 / 3600.0)
        pm.dec = math.radians(-0.0152 / 3600.0)

        libnova2.ln2_get_equ_pm(ctypes.byref(object_pos), ctypes.byref(pm), B1900, ctypes.byref(pos))
        libnova2.ln2_get_equ_prec2(ctypes.byref(pos), JD2000, B1900, ctypes.byref(pos2))

        self.assertAlmostEqual(math.degrees(pos2.ra), 20.68729628, delta=0.002)
        self.assertAlmostEqual(math.degrees(pos2.dec), 88.77431170, delta=0.0001)

        libnova2.ln2_get_equ_pm(ctypes.byref(object_pos), ctypes.byref(pm), JD2050, ctypes.byref(pos))
        libnova2.ln2_get_equ_prec2(ctypes.byref(pos), JD2000, JD2050, ctypes.byref(pos2))

        self.assertAlmostEqual(math.degrees(pos2.ra), 57.02160084, delta=0.003)
        self.assertAlmostEqual(math.degrees(pos2.dec), 89.45444522, delta=0.0001)

if __name__ == '__main__':
    unittest.main()
