import unittest
from libnova2 import libnova2
import ctypes
import math

class TestSolar(unittest.TestCase):
    def test_solar_coord_test(self):
        JD = 2451545.0
        
        pos = libnova2.struct_ln_helio_posn()
        equ = libnova2.struct_ln_equ_posn()
        ecl = libnova2.struct_ln_lnlat_posn()
        rect = libnova2.struct_ln_rect_posn()

        # Geom Coords
        libnova2.ln2_get_solar_geom_coords(JD, ctypes.byref(pos))
        self.assertAlmostEqual(pos.L, 4.893491425560, delta=1e-6)
        self.assertAlmostEqual(pos.B, 0.000016624912, delta=1e-6)
        self.assertAlmostEqual(pos.R, 0.983327682322, delta=1e-6)

        # Equ Coords
        libnova2.ln2_get_solar_equ_coords(JD, ctypes.byref(equ))
        self.assertAlmostEqual(equ.ra, 4.909247947251, delta=1e-6)
        self.assertAlmostEqual(equ.dec, -0.401920348764, delta=1e-6)

        # Ecl Coords
        libnova2.ln2_get_solar_ecl_coords(JD, ctypes.byref(ecl))
        self.assertAlmostEqual(ecl.lng, 4.893379153722, delta=1e-6)
        self.assertAlmostEqual(ecl.lat, 0.000016624912, delta=1e-6)

        # Geo Coords
        libnova2.ln2_get_solar_geo_coords(JD, ctypes.byref(rect))
        self.assertAlmostEqual(rect.X, 0.177111178657, delta=1e-6)
        self.assertAlmostEqual(rect.Y, -0.887437422004, delta=1e-6)
        self.assertAlmostEqual(rect.Z, -0.384733392332, delta=1e-6)

        # Sdiam
        val = libnova2.ln2_get_solar_sdiam(JD)
        self.assertAlmostEqual(val, 975.900523550473, delta=1e-6)

    def test_solar_earth_test(self):
        JD = 2451545.0

        rect = libnova2.struct_ln_rect_posn()
        ecl = libnova2.struct_ln_lnlat_posn()
        rst = libnova2.struct_ln_rst_time()
        observer = libnova2.struct_ln_lnlat_posn()

        libnova2.ln2_get_solar_geo_coords(JD, ctypes.byref(rect))
        self.assertTrue(rect.X != 0.0 or rect.Y != 0.0 or rect.Z != 0.0)

        libnova2.ln2_get_solar_ecl_coords(JD, ctypes.byref(ecl))
        self.assertAlmostEqual(math.degrees(ecl.lng), 280.46, delta=1.0)

        observer.lng = math.radians(0.0)
        observer.lat = math.radians(50.0)
        libnova2.ln2_get_solar_rst_horizon(JD, ctypes.byref(observer), math.radians(-18.0), ctypes.byref(rst))

        res = libnova2.ln2_get_solar_sdiam(JD)
        self.assertAlmostEqual(res, 976.0, delta=10.0)

        sin_o = ctypes.c_double()
        cos_o = ctypes.c_double()
        libnova2.ln2_get_earth_centre_dist(100.0, 45.0, ctypes.byref(sin_o), ctypes.byref(cos_o))
        
        res = math.sqrt(sin_o.value * sin_o.value + cos_o.value * cos_o.value)
        self.assertAlmostEqual(res, 1.0, delta=0.01)

        libnova2.ln2_get_earth_rect_helio(JD, ctypes.byref(rect))
        res = math.sqrt(rect.X * rect.X + rect.Y * rect.Y + rect.Z * rect.Z)
        self.assertAlmostEqual(res, 0.983, delta=0.01)

if __name__ == '__main__':
    unittest.main()
