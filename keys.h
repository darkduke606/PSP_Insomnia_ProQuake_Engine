/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

// these are the key numbers that should be passed to Key_Event
typedef enum
{
	K_TAB = 9,
	K_ENTER = 13,
	K_ESCAPE = 27,
	K_SPACE	= 32,

// normal keys should be passed as lowercased ascii

	K_BACKSPACE = 127,

	K_CAPSLOCK,
	K_PRINTSCR,
	K_SCRLCK,
	K_PAUSE,

	K_UPARROW,
	K_DOWNARROW,
	K_LEFTARROW,
	K_RIGHTARROW,

	K_ALT,
	K_LALT,
	K_RALT,
	K_CTRL,
	K_LCTRL,
	K_RCTRL,
	K_SHIFT,
	K_LSHIFT,
	K_RSHIFT,
	K_F1,
	K_F2,
	K_F3,
	K_F4,
	K_F5,
	K_F6,
	K_F7,
	K_F8,
	K_F9,
	K_F10,
	K_F11,
	K_F12,
	K_INS,
	K_DEL,
	K_PGDN,
	K_PGUP,
	K_HOME,
	K_END,

	K_WIN,
	K_LWIN,
	K_RWIN,
	K_MENU,

// keypad keys
	KP_NUMLOCK,
	KP_SLASH,
	KP_STAR,
	KP_MINUS,
	KP_HOME,
	KP_UPARROW,
	KP_PGUP,
	KP_PLUS,
	KP_LEFTARROW,
	KP_5,
	KP_RIGHTARROW,
	KP_END,
	KP_DOWNARROW,
	KP_PGDN,
	KP_ENTER,
	KP_INS,
	KP_DEL,

// mouse buttons generate virtual keys

	K_MOUSE1 = 200,
	K_MOUSE2,
	K_MOUSE3,
	K_MOUSE4,
	K_MOUSE5,
	K_MOUSE6,
	K_MOUSE7,
	K_MOUSE8,

// joystick buttons

	K_JOY1,
	K_JOY2,
	K_JOY3,
	K_JOY4,

// aux keys are for multi-buttoned joysticks to generate so they can use
// the normal binding process

	K_AUX1,
	K_AUX2,
	K_AUX3,
	K_AUX4,
	K_AUX5,
	K_AUX6,
	K_AUX7,
	K_AUX8,
	K_AUX9,
	K_AUX10,
	K_AUX11,
	K_AUX12,
	K_AUX13,
	K_AUX14,
	K_AUX15,
	K_AUX16,
	K_AUX17,
	K_AUX18,
	K_AUX19,
	K_AUX20,
	K_AUX21,
	K_AUX22,
	K_AUX23,
	K_AUX24,
	K_AUX25,
	K_AUX26,
	K_AUX27,
	K_AUX28,
	K_AUX29,
	K_AUX30,
	K_AUX31,
	K_AUX32,

// JACK: Intellimouse(c) Mouse Wheel Support

	K_MWHEELUP,
	K_MWHEELDOWN,

// Special capture when mouse is freed	
	K_MOUSECLICK_BUTTON1 = 1024,
	K_MOUSECLICK_BUTTON2,
	K_MOUSECLICK_BUTTON3,
	K_MOUSECLICK_BUTTON4,
	K_MOUSECLICK_BUTTON5

// 	These are unnecessary; we receive them anyway
//	K_MOUSECLICK_MWHEELUP
//	K_MOUSECLICK_MWHEELDOWN
} keynum_t;

#define	MAXCMDLINE		256


typedef enum {
	key_game, key_console, key_message, key_menu
} keydest_t;

extern keydest_t	key_dest;
extern char *keybindings[256];
extern	int		key_repeats[256];
extern	int		key_count;			// incremented every key event
extern	int		key_lastpress;

#ifdef PSP_FIXME
void Key_Event (int key, qboolean down);
#else
void Key_Event (int key, int ascii, qboolean down);
qboolean Key_InternationalON(void);
#endif
void Key_Init (void);
void Key_WriteBindings (FILE *f);
void Key_SetBinding (int keynum, char *binding);
void Key_ClearStates (void);

void History_Shutdown (void);
