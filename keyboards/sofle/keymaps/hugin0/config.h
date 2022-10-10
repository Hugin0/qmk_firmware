#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

/******************************/
/*     CAPS_WORD settings     */
/******************************/
#define CAPS_WORD_IDLE_TIMEOUT 3000

/*********************/
/* TAP_HOLD settings */
/*********************/
#ifdef TAPPING_TERM
  #undef TAPPING_TERM
  #define TAPPING_TERM 200
#endif
#define TAPPING_TERM_PER_KEY
