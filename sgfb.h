//--------------------------------------------------------------------
//
// SGFB ( Summer Graphic Frame Buffer ) | Linux Frame Buffer Library.
//
// FILE:
//   sgfb.h
//
// START DATE: 05/05/2019 - 07:00
//
// BY: Francisco - gokernel@hotmail.com
//
//--------------------------------------------------------------------
//
#ifndef _SGFB_H_
#define _SGFB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <time.h>
#include <termios.h>

//-----------------------------------------------
//---------------  DEFINE / ENUM  ---------------
//-----------------------------------------------
//
#define SGFB_VERSION        0
#define SGFB_VERSION_SUB    10
#define SGFB_VERSION_PATCH  0
#define SGFB_VERSION_NAME   "BETA"

#define LIBIMPORT           extern

#define UCHAR               unsigned char
#define COLOR_WHITE32       16777215

#define FREE_BMP(b) sgFreeBmp(b); b = NULL;

#define CTRL_KEY(k) ((k) & 0x1f)

//---------------------------
// START KEYS:
//---------------------------
#define SGK_TAB       9
#define SGK_ENTER     13
#define SGK_ESC       27
#define SGK_SPACE     32
//
// ...
//
#define SGK_BACKSPACE 127
// std SDLK_:
#define SGK_UP        273
#define SGK_DOWN      274
#define SGK_RIGHT     275 // ->
#define SGK_LEFT      276 // <-
#define SGK_INSERT    277
#define SGK_HOME      278
#define SGK_END       279
#define SGK_PAGEUP    280
#define SGK_PAGEDOWN  281
// std SDLK_:
#define SGK_F1        282
#define SGK_F2        283
#define SGK_F3        284
#define SGK_F4        285
#define SGK_F5        286
#define SGK_F6        287
#define SGK_F7        288
#define SGK_F8        289
#define SGK_F9        290
#define SGK_F10       291
#define SGK_F11       292
#define SGK_F12       293
//
#define SGK_DELETE    400
//---------------------------
// END KEYS:
//---------------------------

enum {
    EV_KEY = 1,
    EV_MOUSE_MOVE,
    EV_MOUSE_DOWN,
    EV_MOUSE_UP
};

//-----------------------------------------------
//------------------  STRUCT  -------------------
//-----------------------------------------------
//
typedef struct {
    char  type;
    int   x;
    int   y;
    int   button;
    int   key;
}SG_Event;

typedef struct {
    UCHAR   *data; // pixels
    int     w;
    int     h;
    int     line_length;
}BMP;

//-----------------------------------------------
//-----------------  PUBLIC API  ----------------
//-----------------------------------------------
//
LIBIMPORT int   sgInit          (void);
LIBIMPORT void  sgQuit          (void);
LIBIMPORT int   sgEvent         (SG_Event *ev);

LIBIMPORT BMP * sgNewBmp        (int w, int h); // 16/32 BPP

LIBIMPORT void  sgBlit16        (BMP *bmp);
LIBIMPORT void  sgBlit32        (BMP *bmp);

// 16/32 BPP:
LIBIMPORT void  sgDrawRect      (BMP *bmp, int x, int y, int w, int h, int color);
LIBIMPORT void  sgDrawRectFill  (BMP *bmp, int x, int y, int w, int h, int color);
LIBIMPORT void  sgDrawText      (BMP *bmp, char *text, int x, int y, int color);


LIBIMPORT void  sgFreeBmp       (BMP *bmp);

#ifdef __cplusplus
}
#endif
#endif // ! _SGFB_H_

