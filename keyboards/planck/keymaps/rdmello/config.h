#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

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
