import unittest
from libnova2 import libnova2
import ctypes

class TestMars(unittest.TestCase):
    def test_mars(self):
        JD = 2451545.0
        
        helio = libnova2.struct_ln_helio_posn()
        equ = libnova2.struct_ln_equ_posn()
        rect = libnova2.struct_ln_rect_posn()

        libnova2.ln2_get_mars_helio_coords(JD, ctypes.byref(helio))
        self.assertAlmostEqual(helio.L, 6.273513628573, delta=1e-6)
        self.assertAlmostEqual(helio.B, -0.024767000164, delta=1e-6)
        self.assertAlmostEqual(helio.R, 1.391207693716, delta=1e-6)

        libnova2.ln2_get_mars_equ_coords(JD, ctypes.byref(equ))
        self.assertAlmostEqual(equ.ra, 5.768703792263, delta=1e-6)
        self.assertAlmostEqual(equ.dec, -0.230041415922, delta=1e-6)

        libnova2.ln2_get_mars_rect_helio(JD, ctypes.byref(rect))
        self.assertAlmostEqual(rect.X, 1.390715981865, delta=1e-6)
        self.assertAlmostEqual(rect.Y, 0.001363394408, delta=1e-6)
        self.assertAlmostEqual(rect.Z, -0.036960059447, delta=1e-6)

        dist = libnova2.ln2_get_mars_earth_dist(JD)
        self.assertAlmostEqual(dist, 1.849603891357, delta=1e-6)

        dist = libnova2.ln2_get_mars_solar_dist(JD)
        self.assertAlmostEqual(dist, 1.391207693716, delta=1e-6)

        val = libnova2.ln2_get_mars_magnitude(JD)
        self.assertAlmostEqual(val, 0.541140670105, delta=1e-6)

        val = libnova2.ln2_get_mars_disk(JD)
        self.assertAlmostEqual(val, 0.926471785277, delta=1e-6)

        val = libnova2.ln2_get_mars_phase(JD)
        self.assertAlmostEqual(val, 0.549197755642, delta=1e-6)

        val = libnova2.ln2_get_mars_sdiam(JD)
        self.assertAlmostEqual(val, 0.000012267102, delta=1e-8)

if __name__ == '__main__':
    unittest.main()
