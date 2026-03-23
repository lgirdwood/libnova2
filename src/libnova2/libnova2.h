/*
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Copyright (C) 2000 - 2026 Liam Girdwood <lgirdwood@gmail.com>
 */

#define LIBNOVA2_VERSION "0.99.0"

/** \mainpage libnova2
 * \image html libnova2.png
 * Celestial Mechanics, Astrometry and Astrodynamics Library
 *
 * \section intro Introduction
 * libnova2 is a general purpose, double precision, Celestial Mechanics,
 * Astrometry and Astrodynamics library. Its a successor to libnova with the
 * significant change being use of radians instead of degrees.
 *
 * The intended audience of libnova2 is C / C++ programmers, astronomers and
 * anyone else interested in calculating positions of astronomical objects or
 * celestial mechanics. libnova2 is the calculation engine used by the <A
 * href="http://nova.sf.net">Nova</A> project and most importantly, is free
 * software.
 *
 * \section scientific Scientific Details
 * libnova2 implements algorithms from Jean Meeus's *Astronomical Algorithms*
 * (2nd Edition), providing high-precision calculations for:
 * - **Planetary Positions**: Using the VSOP87 solution (Variations Séculaires
 * des Orbites Planétaires) by Bretagnon and Francou, which provides high
 * accuracy for Mercury through Neptune. Pluto's position is calculated using
 * Meeus's truncation of the full VSOP87 theory.
 * - **Lunar Position**: Using the ELP 2000-82B theory (Ephemeride Lunaire
 * Parisienne) by Chapront-Touze and Chapront.
 * - **Time Scales**: Support for Julian Day (JD), Modified Julian Day (MJD),
 * and Conversions between UTC and Dynamical Time (TD).
 * - **Coordinate Systems**: Transformations between Equatorial, Ecliptic,
 * Horizontal, and Galactic coordinates, including effects of Precession,
 * Nutation, Aberration, and Refraction.
 *
 * \section features Features
 * The current version of libnova2 can calculate:
 *
 * - Aberration (Annual)
 * - Nutation (IAU 1980 Theory)
 * - Apparent Position
 * - Dynamical Time
 * - Julian Day
 * - Precession (IAU 1976)
 * - Proper Motion
 * - Sidereal Time (Mean and Apparent)
 * - Solar Coordinates (VSOP87)
 * - Coordinate Transformations
 * - Planetary Positions Mercury - Pluto (Mercury - Neptune using VSOP87)
 * - Planetary Magnitude, illuminated disk and phase angle.
 * - Lunar Position (ELP82), phase angle.
 * - Elliptic Motion of bodies (Asteroid + Comet positional and orbit data)
 * - Asteroid + Comet magnitudes
 * - Parabolic Motion of bodies (Comet positional data)
 * - Orbit velocities and lengths
 * - Atmospheric refraction (Bennett/Saeemundsson)
 * - Rise, Set and Transit times.
 * - Semidiameters of the Sun, Moon, Planets and asteroids.
 * - Angular separation of bodies
 * - Hyperbolic motion of bodies
 * - Heliocentric (barycentric) time correction
 *
 * \section docs Documentation
 * API documentation for libnova2 is included in the source. It can also be
 * found in this website and an offline tarball is available <A
 * href="http://libnova2.sf.net/libnova2docs.tar.gz">here</A>.
 *
 * \section download Download
 * The latest released version of libnova2 is 0.99.0
 *
 * \section licence Licence
 * libnova2 is released under the <A href="http://www.gnu.org">GNU</A> LGPL.
 *
 * \section help Help
 * If you are interested in helping in the future development of libnova2, then
 * please get in touch. Currently, we are needing help in the folowing areas.
 * - Documentation. (Not just API reference, but also astronomy info for novice
 * users)
 * - Programming (in C) astronomical solutions or algorithms.
 *
 * \section authors Authors
 * libnova2 is maintained by <A href="mailto:lgirdwood@gmail.com">Liam
 * Girdwood</A> and <A href="mailto:petr@kubanek.net">Petr Kubanek</A>.
 *
 * \section thanks Thanks
 * Thanks to Jean Meeus for most of the algorithms used in this library.
 * From his book "Astronomical Algorithms".
 *
 * Thanks to Michelle Chapront-Touze and Jean Chapront for publishing
 * the Lunar Solution ELP 2000-82B.
 *
 * Thanks to Messrs. Bretagnon and Francou for publishing planetary
 * solution VSOP87.
 */

#ifndef _LN_LIBNOVA2_H
#define _LN_LIBNOVA2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <libnova2/ln_types.h>
#include <libnova2/julian_day.h>
#include <libnova2/dynamical_time.h>
#include <libnova2/sidereal_time.h>
#include <libnova2/transform.h>
#include <libnova2/nutation.h>
#include <libnova2/aberration.h>
#include <libnova2/apparent_position.h>
#include <libnova2/solar.h>
#include <libnova2/precession.h>
#include <libnova2/proper_motion.h>
#include <libnova2/mercury.h>
#include <libnova2/venus.h>
#include <libnova2/earth.h>
#include <libnova2/mars.h>
#include <libnova2/jupiter.h>
#include <libnova2/saturn.h>
#include <libnova2/uranus.h>
#include <libnova2/neptune.h>
#include <libnova2/pluto.h>
#include <libnova2/vsop87.h>
#include <libnova2/lunar.h>
#include <libnova2/elliptic_motion.h>
#include <libnova2/asteroid.h>
#include <libnova2/comet.h>
#include <libnova2/parabolic_motion.h>
#include <libnova2/refraction.h>
#include <libnova2/rise_set.h>
#include <libnova2/angular_separation.h>
#include <libnova2/utility.h>
#include <libnova2/hyperbolic_motion.h>
#include <libnova2/parallax.h>
#include <libnova2/airmass.h>
#include <libnova2/heliocentric_time.h>
#include <libnova2/constellation.h>

#ifdef __cplusplus
}
#endif

#endif
