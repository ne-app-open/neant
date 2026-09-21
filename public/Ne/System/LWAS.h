// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#ifndef _NE_LWAS_SUBSYSTEM_H_
#define _NE_LWAS_SUBSYSTEM_H_

#ifndef _LWAS
#define _LWAS (202608L)
#endif

/// *******************************************************
/// @brief Local Window Application Subsystem.
/// *******************************************************

#include <Ne/System/CAS.h>
#include <Ne/System/Detail/Config.h>

struct LHANDLE;

#ifndef kNeAntPadLen
#define kNeAntPadLen (8)
#endif

struct _SHARED LHANDLE _FINAL {
  Ref fHandle;  /// @brief Mandatory for NeAnt handles.
  Char    fPad[kNeAntPadLen];
  SInt64  fMagic;
  SInt32  fHostID, fFlags, fKind;
  Char    fPad2[kNeAntPadLen];
};

typedef enum {
  /* Alphabetic */
  LWAS_VKEY_A,
  LWAS_VKEY_B,
  LWAS_VKEY_C,
  LWAS_VKEY_D,
  LWAS_VKEY_E,
  LWAS_VKEY_F,
  LWAS_VKEY_G,
  LWAS_VKEY_H,
  LWAS_VKEY_I,
  LWAS_VKEY_J,
  LWAS_VKEY_K,
  LWAS_VKEY_L,
  LWAS_VKEY_M,
  LWAS_VKEY_N,
  LWAS_VKEY_O,
  LWAS_VKEY_P,
  LWAS_VKEY_Q,
  LWAS_VKEY_R,
  LWAS_VKEY_S,
  LWAS_VKEY_T,
  LWAS_VKEY_U,
  LWAS_VKEY_V,
  LWAS_VKEY_W,
  LWAS_VKEY_X,
  LWAS_VKEY_Y,
  LWAS_VKEY_Z,

  /* Numeric row */
  LWAS_VKEY_0,
  LWAS_VKEY_1,
  LWAS_VKEY_2,
  LWAS_VKEY_3,
  LWAS_VKEY_4,
  LWAS_VKEY_5,
  LWAS_VKEY_6,
  LWAS_VKEY_7,
  LWAS_VKEY_8,
  LWAS_VKEY_9,

  /* Function keys */
  LWAS_VKEY_F1,
  LWAS_VKEY_F2,
  LWAS_VKEY_F3,
  LWAS_VKEY_F4,
  LWAS_VKEY_F5,
  LWAS_VKEY_F6,
  LWAS_VKEY_F7,
  LWAS_VKEY_F8,
  LWAS_VKEY_F9,
  LWAS_VKEY_F10,
  LWAS_VKEY_F11,
  LWAS_VKEY_F12,

  /* Modifiers */
  LWAS_VKEY_LSHIFT,
  LWAS_VKEY_RSHIFT,
  LWAS_VKEY_LCTRL,
  LWAS_VKEY_RCTRL,
  LWAS_VKEY_LALT,
  LWAS_VKEY_RALT,
  LWAS_VKEY_LSUPER,
  LWAS_VKEY_RSUPER,

  /* Control */
  LWAS_VKEY_ESCAPE,
  LWAS_VKEY_TAB,
  LWAS_VKEY_CAPSLOCK,
  LWAS_VKEY_ENTER,
  LWAS_VKEY_BACKSPACE,
  LWAS_VKEY_SPACE,
  LWAS_VKEY_MENU,

  /* Navigation */
  LWAS_VKEY_UP,
  LWAS_VKEY_DOWN,
  LWAS_VKEY_LEFT,
  LWAS_VKEY_RIGHT,
  LWAS_VKEY_INSERT,
  LWAS_VKEY_DELETE,
  LWAS_VKEY_HOME,
  LWAS_VKEY_END,
  LWAS_VKEY_PAGEUP,
  LWAS_VKEY_PAGEDOWN,
  LWAS_VKEY_PRINTSCR,
  LWAS_VKEY_SCROLLLOCK,
  LWAS_VKEY_PAUSE,

  /* Numpad */
  LWAS_VKEY_NUM0,
  LWAS_VKEY_NUM1,
  LWAS_VKEY_NUM2,
  LWAS_VKEY_NUM3,
  LWAS_VKEY_NUM4,
  LWAS_VKEY_NUM5,
  LWAS_VKEY_NUM6,
  LWAS_VKEY_NUM7,
  LWAS_VKEY_NUM8,
  LWAS_VKEY_NUM9,
  LWAS_VKEY_NUMLOCK,
  LWAS_VKEY_NUMDIVIDE,
  LWAS_VKEY_NUMMULTIPLY,
  LWAS_VKEY_NUMMINUS,
  LWAS_VKEY_NUMPLUS,
  LWAS_VKEY_NUMENTER,
  LWAS_VKEY_NUMDECIMAL,

  /* Punctuation / symbols */
  LWAS_VKEY_GRAVE,      /* ` ~ */
  LWAS_VKEY_MINUS,      /* - _ */
  LWAS_VKEY_EQUAL,      /* = + */
  LWAS_VKEY_LBRACKET,   /* [ { */
  LWAS_VKEY_RBRACKET,   /* ] } */
  LWAS_VKEY_BACKSLASH,  /* \ | */
  LWAS_VKEY_SEMICOLON,  /* ; : */
  LWAS_VKEY_APOSTROPHE, /* ' " */
  LWAS_VKEY_COMMA,      /* , < */
  LWAS_VKEY_PERIOD,     /* . > */
  LWAS_VKEY_SLASH,      /* / ? */

  LWAS_VKEY_COUNT /* sentinel / array sizing */
} LWAS_VKey;

IMPORT_C struct LHANDLE* UsrCreateWindow(VoidPtr, SizeT*);

IMPORT_C Void UsrDestroyWindow(struct LHANDLE*);

/// @brief Is Virtual Key Up?
IMPORT_C SInt32 UsrGetVKeyUp(const SInt32 key);

/// @brief Is Virtual Key Down?
IMPORT_C SInt32 UsrGetVKeyDown(const SInt32 key);

/// @brief Is Virtual Key?
IMPORT_C Bool UsrIsVKey(const SInt32 key);

typedef struct LHANDLE HLWAS;
typedef HLWAS*         PHLWAS;

#endif  // _NE_LWAS_SUBSYSTEM_H_
