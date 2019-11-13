/*
Copyright 2017 Danny Nguyen <danny@hexwire.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C

/* Select hand configuration */
#define MASTER_RIGHT
// #define EE_HANDS

/* Rylan's mousekeys overrides
* I prefer faster movement of the mouse here, */
// MOUSEKEY_DELAY defaults to 300, but let's try a quicker one.
#define MOUSEKEY_DELAY 50

// MOUSEKEY_INTERVAL defaults to 50, 25 should make it a bit smoother.
#define MOUSEKEY_INTERVAL 35

// This is like constant speed movement.
#define MOUSEKEY_TIME_TO_MAX 5

//
#define MOUSEKEY_MAX_SPEED 10

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
