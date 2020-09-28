/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

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
#define MASTER_LEFT
// #define EE_HANDS

/* Rylan's mousekeys overrides
* I prefer faster movement of the mouse here, */
// MOUSEKEY_DELAY defaults to 300, but let's try a quicker one.
#define MOUSEKEY_DELAY 50
// MOUSEKEY_INTERVAL defaults to 50, 25 should make it a bit smoother.
#define MOUSEKEY_INTERVAL 35
// This is like constant speed movement.
#define MOUSEKEY_TIME_TO_MAX 5
// ???
#define MOUSEKEY_MAX_SPEED 10

// Playing around with tapping term settings (again)
#define TAPPING_TERM 250 // default: 200
// #define PERMISSIVE_HOLD // Sends MOD if any other key is tapped within TAPPING_TERM
// #define IGNORE_MOD_TAP_INTERRUPT // Does something, IDK what.
// #define TAPPING_FORCE_HOLD // Disables key repeat for MOD(TAP) keys if they're held down after one tap.
// #define RETRO_TAPPING // Sends the TAP key if nothing else is pressed outside the TAPPING_TERM.
// place overrides here
