/* Copyright 2019 Takuya Urakawa (dm9records.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define MOUSEKEY_DELAY 50
#define MOUSEKEY_INTERVAL 35
#define MOUSEKEY_TIME_TO_MAX 5
#define MOUSEKEY_MAX_SPEED 10

// Playing around with tapping term settings (again)
#define TAPPING_TERM 250 // default: 200
// #define TAPPING_TERM_PER_KEY
// #define PERMISSIVE_HOLD // Sends MOD if any other key is tapped within TAPPING_TERM
// #define IGNORE_MOD_TAP_INTERRUPT // Does something, IDK what.
// #define TAPPING_FORCE_HOLD // Disables key repeat for MOD(TAP) keys if they're held down after one tap.
// #define RETRO_TAPPING // Sends the TAP key if nothing else is pressed outside the TAPPING_TERM.
// place overrides here
