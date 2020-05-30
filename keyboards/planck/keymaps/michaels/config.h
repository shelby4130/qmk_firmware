#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(MARIO_THEME)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
    #define MUSIC_MAP

    #define AUDIO_CLICKY
    //#define MUSIC_MASK (keycode != KC_NO)

    //Enable Polyphony
    #define AUDIO_VOICES

#endif

//TapDance
#define TAPPING_TERM 200

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

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
//#define ENCODER_RESOLUTION 4

//#define RGBLIGHT_ANIMATIONS
//#define RGBLIGHT_HUE_STEP 12
//#define RGBLIGHT_SAT_STEP 25
//#define RGBLIGHT_VAL_STEP 12
//#define RGBLED_NUM 9
//#define RGB_DI_PIN
                                