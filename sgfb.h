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

#define LIBIMPORT extern

#define UCHAR unsigned char
#define CHAR_SPACE 32
#define COLOR_WHITE32 16777215

#define FREE_BMP(b) sgFreeBmp(b); b=NULL;

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
LIBIMPORT int   sgInit      (void);
LIBIMPORT void  sgQuit      (void);
LIBIMPORT int   sgEvent     (SG_Event *ev);

LIBIMPORT BMP * sgNewBmp    (int w, int h);

LIBIMPORT void  sgBlit16    (BMP *bmp);
LIBIMPORT void  sgBlit32    (BMP *bmp);

LIBIMPORT void  sgFreeBmp   (BMP *bmp);

