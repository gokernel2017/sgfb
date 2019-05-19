//--------------------------------------------------------------------
//
// SGFB ( Summer Graphic Frame Buffer ) | Linux Frame Buffer Library.
//
// FILE:
//   sgfb.c
//
// COMPILE:
//   gcc sgfb.c -o sgfb -O1 -Wall
//
// START DATE: 05/05/2019 - 07:00
//
// BY: Francisco - gokernel@hotmail.com
//
//--------------------------------------------------------------------
//
#include "sgfb.h"

#define CHAR_SPACE 32

static const unsigned char fixed_font[14][764] = {
  "                                   xx                                                                                                                                                                                                                                                                                                                                                                                                                                                                              xx             xxx                                                                                                                                                                                                                                                      ",
  "                                   xx    xxx                                                                                                                                                                                                                                                                                                                                                                                                                                                                      xxxx             xx                                                                      xx       xx                                                                                                                                                                     ",
  "           xx    xx  xx   xx xx   xxxx  xx xx     xxx      xx       xx    xx                                                 xx    xxxx     xx    xxxx    xxxx    xx     xxxxxx    xxx   xxxxxx   xxxx    xxxx                       xx          xx       xxxx   xxxxxx    xx    xxxxx    xxxx   xxxx    xxxxxx  xxxxxx   xxxx   xx  xx   xxxx       xx  xx  xx  xx      xx   xx xx   xx  xxxx   xxxxx    xxxx   xxxxx    xxxx   xxxxxx  xx  xx  xx  xx  xx   xx xx  xx  xx  xx  xxxxxx   xxxx   xx       xxxx   xx  xx             xx           xx                  xx            xxxx          xx        xx       xx   xx      xxxx                                                             xx                                                        xx     xx     xx     xxx   x   ",
  "          xxxx   xx  xx   xx xx  xx  xx xx xx x  xx xx     xx      xx      xx                                                xx   xx  xx   xxx   xx  xx  xx  xx   xx     xx        xx        xx  xx  xx  xx  xx                     xx            xx     xx  xx xx    xx  xxxx   xx  xx  xx  xx  xx xx   xx      xx      xx  xx  xx  xx    xx        xx  xx  xx  xx      xx   xx xx   xx xx  xx  xx  xx  xx  xx  xx  xx  xx  xx    xx    xx  xx  xx  xx  xx   xx xx  xx  xx  xx      xx   xx     xx         xx                                   xx                  xx           xx             xx                      xx        xx                                                             xx                                                       xx      xx      xx   xx xx xx   ",
  "          xxxx   xx  xx  xxxxxxx xx      xxx xx  xx xx     xx      xx      xx     xx xx    xx                               xx    xx xxx xxxxx   xx  xx  xx  xx   xx xx  xx       xx        xx   xx  xx  xx  xx    xxx     xxx     xx              xx    xx  xx xx    xx xx  xx  xx  xx  xx  xx  xx  xx  xx      xx      xx  xx  xx  xx    xx        xx  xx xx   xx      xxx xxx xxx  xx xx  xx  xx  xx  xx  xx  xx  xx  xx        xx    xx  xx  xx  xx  xx   xx  xx x   xx  xx      xx   xx      xx        xx                            xxxx   xxxxx    xxxx    xxxxx   xxxx    xx      xxxxx  xxxxx   xxxx     xxxx   xx  xx    xx    xxxxxx  xxxxx    xxxx   xxxxx    xxxxx  xx  xx   xxxxx  xxxxxx  xx  xx  xx  xx  xx   xx xx  xx  xx  xx  xxxxxx    xx      xx      xx   x   xxx    ",
  "          xxxx            xx xx   xx        xx    xxx             xx        xx     xxx     xx                               xx    xx xxx    xx       xx      xx   xx xx  xx      xxxxx      xx   xxx xx  xx  xx    xxx     xxx    xx     xxxxxx     xx      xx  xx  xxxx xx  xx  xx  xx  xx      xx  xx  xx      xx      xx      xx  xx    xx        xx  xx xx   xx      xx x xx xxxx xx xx  xx  xx  xx  xx  xx  xx  xx   xx       xx    xx  xx  xx  xx  xx x xx   xx    xx  xx     xx    xx      xx        xx                               xx  xx  xx  xx  xx  xx  xx  xx  xx   xx     xx  xx  xx  xx    xx       xx   xx  xx    xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xx xxx  xx       xx     xx  xx  xx  xx  xx x xx xx  xx  xx  xx      xx    xx      xx      xx              ",
  "           xx             xx xx    xx      xx    xx               xx        xx   xxxxxxx xxxxxx          xxxxxx            xx     xx  xx    xx      xx     xxx    xx xx  xxxxx   xx  xx    xx     xxxx   xx  xx                  xx                  xx    xx   xx xx xx xx  xx  xxxxx   xx      xx  xx  xxxxx   xxxxx   xx      xxxxxx    xx        xx  xxxx    xx      xx x xx xx xxxx xx  xx  xxxxx   xx  xx  xxxxx     xx      xx    xx  xx  xx  xx  xx x xx   xx     xxxx     xx     xx       xx       xx                               xx  xx  xx  xx      xx  xx  xx  xx  xxxxxx  xx  xx  xx  xx    xx       xx   xx xx     xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xxx     xx       xx     xx  xx  xx  xx  xx x xx  xxxx   xx  xx     xx    xx       xx       xx             ",
  "           xx             xx xx     xx    xx     xx xxxx          xx        xx     xxx     xx                              xx     xxx xx    xx     xx        xx  xx  xx      xx  xx  xx    xx    xx xxx   xxxxx                   xx     xxxxxx     xx     xx   xx xx xx xxxxxx  xx  xx  xx      xx  xx  xx      xx      xx xxx  xx  xx    xx        xx  xx xx   xx      xx x xx xx  xxx xx  xx  xx      xx  xx  xx xx      xx     xx    xx  xx  xx  xx  xx x xx  x xx     xx     xx      xx       xx       xx                            xxxxx  xx  xx  xx      xx  xx  xxxxxx   xx     xx  xx  xx  xx    xx       xx   xxxx      xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xx       xxxx    xx     xx  xx  xx  xx  xx x xx   xx    xx  xx    xx    xx        xx        xx            ",
  "                         xxxxxxx     xx  xx xxx  xx  xx           xx        xx    xx xx    xx                             xx      xxx xx    xx    xx     xx  xx  xxxxxxx     xx  xx  xx   xx     xx  xx     xx                     xx              xx           xx  xxxx xx  xx  xx  xx  xx  xx  xx  xx  xx      xx      xx  xx  xx  xx    xx    xx  xx  xx xx   xx      xx   xx xx   xx xx  xx  xx      xx  xx  xx  xx      xx    xx    xx  xx  xx  xx   xx xx  xx  xx    xx    xx       xx        xx      xx                           xx  xx  xx  xx  xx      xx  xx  xx       xx     xx  xx  xx  xx    xx       xx   xx xx     xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xx          xx   xx     xx  xx  xx  xx  xx x xx  xxxx   xx  xx   xx      xx       xx       xx             ",
  "           xx             xx xx  xx  xx  x xx xx xx  xx           xx        xx                     xxx             xxx    xx      xx  xx    xx   xx      xx  xx      xx     xx   xx  xx   xx     xx  xx    xx      xxx     xxx      xx            xx       xx   xx       xx  xx  xx  xx  xx  xx  xx xx   xx      xx      xx  xx  xx  xx    xx    xx  xx  xx  xx  xx      xx   xx xx   xx xx  xx  xx      xx  xx  xx  xx  xx  xx    xx    xx  xx   xxxx    xx xx  xx  xx    xx    xx       xx        xx      xx                           xx  xx  xx  xx  xx  xx  xx  xx  xx       xx     xx  xx  xx  xx    xx       xx   xx  xx    xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xx          xx   xx     xx  xx   xxxx    xx xx  xx  xx  xx  xx  xx        xx      xx      xx              ",
  "           xx             xx xx   xxxx     xx xx  xxx xx           xx      xx                      xxx             xxx   xx        xxxx     xx   xxxxxx   xxxx       xx  xxxx     xxxx    xx      xxxx    xxx      xxx     xxx       xx          xx        xx    xxxxxxx xx  xx  xxxxx    xxxx   xxxx    xxxxxx  xx       xxxxx  xx  xx   xxxx    xxxx   xx  xx  xxxxxx  xx   xx xx   xx  xxxx   xx       xxxx   xx  xx   xxxx     xx     xxxx     xx     xx xx  xx  xx    xx    xxxxxx   xx         xx     xx                            xxxxx  xxxxx    xxxx    xxxxx   xxxx    xx      xxxxx  xx  xx  xxxxxx     xx   xx  xx  xxxxxx  xx   xx xx  xx   xxxx   xxxxx    xxxxx  xx      xxxxx     xxxx   xxxxx    xx     xx xx  xx  xx   xxxx   xxxxxx    xx      xx      xx              ",
  "                                   xx       xxx                    xx      xx                       xx                   xx                                                                                                 xx                                                                                                                                                                              xx                                                                            xx         xx     xx                                                                               xx                     xx                                           xx          xx                                                             xx             xx      xx      xx              ",
  "                                   xx                               xx    xx                       xx                                                                                                                      xx                                                                                                                                                                                xx                                                                           xx                xx                                                                               xx                     xx                                           xx          xx                                                            xx               xx     xx     xx               ",
  "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          xxxx            xxxx          xxxxxxxx                                                         xxxxx                   xxxx                                            xx          xx                                                         xxxx                       xx                      ",
};

//-----------------------------------------------
//------------------  STRUCT  -------------------
//-----------------------------------------------
//
typedef struct { // opaque/private struct
    UCHAR   *screen;
    int     w;        // fb_var_info.xres
    int     h;        // fb_var_info.yres
    int     bpp;      // 8 | 16 | 32
    int     line_length;
    int     smem_len; // fb_fix_info.smem_len
    int     accel_flags;
    //---------------------
    int     fb_fd;       // file id
    int     tty_fd;
    int     mouse_fd;
    //---------------------
    char    drive_name [20];
    int     initialized;
    struct  termios tty_config;
    struct  termios tty_oldconfig;
}FB_DRIVE;

typedef struct {
    int a, b;
}DATA_8;

//-----------------------------------------------
static FB_DRIVE FB;
static int mouse_x, mouse_y;
static int old_x, old_y;
static int pixel_save1, pixel_save2, pixel_save3, pixel_save4;
static int key = 0;
static int button = 0;
//-----------------------------------------------

SG_Event event;
int count;
int nread;

//-----------------------------------------------
//----------------  PROTOTYPES  -----------------
//-----------------------------------------------
//
static void sgDrawCursor32 (int x, int y);

int init_mouse (void) {
    if ((FB.mouse_fd = open("/dev/psaux", O_RDONLY | O_NONBLOCK)) == -1) {
        printf("Cannot open /dev/psaux\n");
        return 0;
    }
    return 1;
}

static int mouse_event (void) {
//    int rd;
    signed char state[3] = {0, 0, 0};

//    if ((rd = read(FB.mouse_fd, state, 3)) == -1) {
    if (read(FB.mouse_fd, state, 3) == -1) {
        return 0;
    }

    button = state[0] & 7;
    mouse_x += state[1];
    mouse_y -= state[2];

    if (mouse_x < 0) mouse_x = 0;
    if (mouse_y < 0) mouse_y = 0;
    if (mouse_x > 799) mouse_x = 799;
    if (mouse_y > 599) mouse_y = 599;

    return 1;
}

int keyboard_event (void) {
    unsigned char buf [5];
    if ((nread = read(FB.tty_fd, buf, sizeof(buf))) < 1) {
        return 0;
    }
/*
    for (i = 0; i < nread; i++) {
        key = buf[i] & 0x7F;
        if (buf[i] & 0x80 ) {
            pressed = 0;
        } else {
            pressed = 1;
        }
    }
*/
    key = buf[0] & 0x7F;
    if (nread == 1)
        return 1;

    switch (nread) {
    case 3:
        key = buf[1] & 0x7F;
        key = buf[2] & 0x7F;
        if (key=='A') key = SGK_UP;
        if (key=='B') key = SGK_DOWN;
        if (key=='C') key = SGK_RIGHT;
        if (key=='D') key = SGK_LEFT;
        return 1;

    case 4:
    case 5:
        key = buf[1] & 0x7F;
        key = buf[2] & 0x7F;
        key = buf[3] & 0x7F;

        if (nread == 4) {
            if (key=='~') {
                key = buf[2];
                if (key=='1') key = SGK_HOME;
                else
                if (key=='3') key = SGK_DELETE;
                else
                if (key=='4') key = SGK_END;
                else
                if (key=='5') key = SGK_PAGEUP;
                else
                if (key=='6') key = SGK_PAGEDOWN;
            } else {
                if (key=='A') key = SGK_F1;
                else
                if (key=='B') key = SGK_F2;
                else
                if (key=='C') key = SGK_F3;
                else
                if (key=='D') key = SGK_F4;
                else
                if (key=='E') key = SGK_F5;
            }
            return 1;
        }
        if (nread == 5) {
            if (key=='7') key = SGK_F6;
            else
            if (key=='8') key = SGK_F7;
            else
            if (key=='9') key = SGK_F8;
            else
            if (key=='0') key = SGK_F9;
            else
            //------------------------
            if (key=='1') key = SGK_F10;
            else
//            if (buf[3]=='3') key = SGK_F11;
            if (key=='3') key = SGK_F11;
            else
            if (key=='4') key = SGK_F12;
        }
    }

    return 1;

}// keyboard_event ()

int sgInit (void) {
    struct fb_var_screeninfo fb_var_info;
    struct fb_fix_screeninfo fb_fix_info;

    if (FB.initialized == 0) {
        FB.initialized = 1;
        FB.fb_fd = open ("/dev/fb0", O_RDWR);
        if (FB.fb_fd < 0) {
            printf ("Frame Buffer Not Found ( /dev/fb0 )\n");
            return 0;
        }
        ioctl (FB.fb_fd, FBIOGET_FSCREENINFO, &fb_fix_info);
        ioctl (FB.fb_fd, FBIOGET_VSCREENINFO, &fb_var_info);

        FB.smem_len = fb_fix_info.smem_len;
        FB.w        = fb_var_info.xres;
        FB.h        = fb_var_info.yres;
        FB.bpp      = fb_var_info.bits_per_pixel;
        FB.line_length = fb_fix_info.line_length;
        FB.accel_flags = fb_var_info.accel_flags;

        sprintf (FB.drive_name, "%s", fb_fix_info.id);

        FB.screen = (UCHAR*) mmap (NULL, FB.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, FB.fb_fd, 0);

        printf ("... Starting LIBFB ...\n");
        printf ("    Dive: %s\n", FB.drive_name);
        printf ("       w: %d\n", FB.w);
        printf ("       h: %d\n", FB.h);
        printf ("     bpp: %d\n", FB.bpp);
        printf ("smem_len: %d\n", FB.smem_len);
        printf ("    fb_fd: %d\n", FB.fb_fd);
        printf ("line_length = %d\n", FB.line_length);
        printf (" WIDTH  * 4 = %d\n", (FB.w * 4));
        printf (" HEIGHT * 4 = %d\n", FB.h * 4);
        printf ("accel_flags = %d\n", FB.accel_flags);

        init_mouse ();

        // tty set FB
        //---------------------------------------
        char *ret = ttyname(STDIN_FILENO);
  
        FB.tty_fd = open(ret, O_RDWR | O_NOCTTY | O_NDELAY);

        if (FB.tty_fd < 0) {
            puts("Failed to open tty");
            return 0;
        }
        tcgetattr(FB.tty_fd, &FB.tty_oldconfig);


        FB.tty_config = FB.tty_oldconfig;
        FB.tty_config.c_iflag = 0;
        FB.tty_config.c_lflag &= ~(ECHO | ICANON | ISIG);

/*
    // SDL CONFIG:
		FB.tty_config.c_lflag &= ~(ICANON | ECHO | ISIG);
		FB.tty_config.c_iflag &= ~(ISTRIP | IGNCR | ICRNL | INLCR | IXOFF | IXON);
		FB.tty_config.c_cc[VMIN] = 0;
		FB.tty_config.c_cc[VTIME] = 0;
*/
        tcsetattr(FB.tty_fd, TCSAFLUSH, &FB.tty_config);

        printf("\e[?25l");
        fflush(stdout);

        mouse_x = mouse_y = old_x = old_y = 300;

        if (FB.bpp == 32) {
            pixel_save1 = *(unsigned int *)(FB.screen + mouse_y * FB.line_length + mouse_x * 4);
            pixel_save2 = *(unsigned int *)(FB.screen + mouse_y * FB.line_length + (mouse_x+1) * 4);
            //
            pixel_save3 = *(unsigned int *)(FB.screen + (mouse_y+1) * FB.line_length + mouse_x * 4);
            pixel_save4 = *(unsigned int *)(FB.screen + (mouse_y+1) * FB.line_length + (mouse_x+1) * 4);
        }

        atexit (sgQuit);

        return 1;
    }
    return 0;
}

void sgQuit (void) {
    if (FB.initialized == 1) {
        FB.initialized = 0;
        munmap (FB.screen, FB.smem_len);
        close (FB.fb_fd);
        close (FB.mouse_fd);
        //-----------------------
        // tty restore text mode:
        //-----------------------
        printf ("\e[?25h");
        fflush (stdout);
        tcsetattr (FB.tty_fd, TCSAFLUSH, &FB.tty_oldconfig);
        close (FB.tty_fd);

        printf ("<<<<<<<<<<  sgQuit  >>>>>>>>>>\n");
    }
}


//
// draw direct in the screen ... SLOW
//
void hline32 (int x1, int y, int x2, int color) {
    UCHAR *p = (UCHAR*)(FB.screen + (y * FB.line_length + x1 * 4));
    int i;
    for (i = x1; i <= x2; i++) {
        *(unsigned int*)p = color; // Set color
        p += 4;
    }
}
//
// draw direct in the screen ... SLOW
//
void vline32 (int x, int y1, int y2, int color) {
    UCHAR *p = (UCHAR*)(FB.screen + (y1 * FB.line_length + x * 4));
    int i;
    for (i = y1; i <= y2; i++) {
        *(unsigned int *)p = color; // Set color
        p += FB.line_length;
    }
}
//
// draw direct in the screen ... SLOW
//
void hline16 (int x1, int y, int x2, int color) {
    UCHAR *p = (UCHAR*)(FB.screen + (y * FB.line_length + x1 * 2));
    int i;
    for (i = x1; i <= x2; i++) {
        *(unsigned short *)p = color; // Set color
        p += 2;
    }
}
//
// draw direct in the screen ... SLOW
//
void vline16 (int x, int y1, int y2, int color) {
    UCHAR *p = (UCHAR*)(FB.screen + (y1 * FB.line_length + x * 2));
    int i;
    for (i = y1; i <= y2; i++) {
        *(unsigned short *)p = color; // Set color
        p += FB.line_length;
    }
}

int makecol16 (UCHAR r, UCHAR g, UCHAR b) {
    r >>= 3; // 5-bit red
    g >>= 2; // 6-bit green
    b >>= 3; // 5-bit blue
    return b + (g << 5) + (r << (5+6));
}

int makecol32 (UCHAR r, UCHAR g, UCHAR b) {
    return b + (g << 8) + (r << 16);
}

void sgBlit32 (BMP *bmp) {
    int i, y, size_w_div_2 = bmp->w/2;
    register UCHAR *data = bmp->data;
    for (y = 0; y < bmp->h; y++) {
        UCHAR *p = (UCHAR*)(FB.screen + (y * FB.line_length + 0 * 4));
        for (i = 0; i < size_w_div_2; i++) {
            //
            // ... copy 8 bytes (long) ... ;)
            //
            *(DATA_8 *)( p ) = *(DATA_8 *)( data );
            p += 8;
            data += 8;
        }
    }
    sgDrawCursor32 (mouse_x, mouse_y);
}

void sgBlit16 (BMP *bmp) {
    int i, y, size_w_div_2 = bmp->w/2;
    register UCHAR *data = bmp->data;
    for (y = 0; y < bmp->h; y++) {
        UCHAR *p = (UCHAR*)(FB.screen + (y * FB.line_length + 0 * 2));
        for (i = 0; i < size_w_div_2; i++) {
            //
            // ... copy 8 bytes (long) ... ;)
            //
            *(unsigned int *)( p ) = *(unsigned int *)( data );
            p += 4;
            data += 4;
        }
    }
//    sgDrawCursor32 (mouse_x, mouse_y);
}

BMP * sgNewBmp (int w, int h) {
    BMP *bmp;
    int len;

    if (FB.bpp == 32) {
        len = w * h * 4;
    }
    else if (FB.bpp == 16) {
        len = w * h * 2;
    } else {
        printf ("Create BMP only: 16, 32 BPP\n");
        return NULL;
    }

    if ((bmp = (BMP*)malloc(sizeof(BMP))) != NULL) {
        if ((bmp->data = (UCHAR*)malloc(len)) != NULL) {
            bmp->w = w;
            bmp->h = h;
            if (FB.bpp == 32) {
                bmp->line_length = w * 4;
            }
            else if (FB.bpp == 16) {
                bmp->line_length = w * 2;
            }
            memset (bmp->data, 32, len);
            return bmp;
        }
    }
    return NULL;
}

void sgFreeBmp (BMP *bmp) {
    if (bmp) {
        printf ("Freeing BMP ... ;)\n");
        if (bmp->data) {
            free (bmp->data);
            bmp->data = NULL;
        }
        free (bmp);
    }
}

void sgDrawHline16 (BMP *bmp, int x1, int y, int x2, int color) {
    UCHAR *p = (UCHAR*)(bmp->data + (y * bmp->line_length + x1 * 2));
    int i;
    for (i = x1; i <= x2; i++) {
        *(unsigned short *)p = color; // Set color
        p += 2;
    }
}
void sgDrawVline16 (BMP *bmp, int x, int y1, int y2, int color) {
    UCHAR *p = (UCHAR*)(bmp->data + (y1 * bmp->line_length + x * 2));
    int i;
    for (i = y1; i <= y2; i++) {
        *(unsigned short *)p = color; // Set color
        p += bmp->line_length;
    }
}

void sgDrawHline32 (BMP *bmp, int x1, int y, int x2, int color) {
    UCHAR *p = (UCHAR*)(bmp->data + (y * bmp->line_length + x1 * 4));
    int i;
    for (i = x1; i <= x2; i++) {
        *(unsigned int *)p = color; // Set color
        p += 4;
    }
}
void sgDrawVline32 (BMP *bmp, int x, int y1, int y2, int color) {
    UCHAR *p = (UCHAR*)(bmp->data + (y1 * bmp->line_length + x * 4));
    int i;
    for (i = y1; i <= y2; i++) {
        *(unsigned int *)p = color; // Set color
        p += bmp->line_length;
    }
}

void sgDrawRectFill (BMP *bmp, int x, int y, int w, int h, int color) {
    int i, width = x + w;
    if (FB.bpp==32) {
        for (i = 0; i < h; i++) {
            sgDrawHline32 (bmp, x, y++, width, color);
        }
        return;
    }
    if (FB.bpp==16) {
        for (i = 0; i < h; i++) {
            sgDrawHline16 (bmp, x, y++, width, color);
        }
        return;
    }
}

void sgDrawRect (BMP *bmp, int x, int y, int w, int h, int color) {
    if (FB.bpp==32) {
        sgDrawHline32(bmp, x, y, x+w, color);
        sgDrawHline32(bmp, x, y+h, x+w, color);
        sgDrawVline32(bmp, x, y, y+h, color);
        sgDrawVline32(bmp, x+w, y, y+h, color);
        return;
    }
    if (FB.bpp==16) {
        sgDrawHline16(bmp, x, y, x+w, color);
        sgDrawHline16(bmp, x, y+h, x+w, color);
        sgDrawVline16(bmp, x, y, y+h, color);
        sgDrawVline16(bmp, x+w, y, y+h, color);
    }
}


void DrawPixel16 (BMP *bmp, int x, int y, int color) {
//    int location = (x+fb_var_info.xoffset) * (fb_var_info.bits_per_pixel/8) +
//                       (y+fb_var_info.yoffset) * fb_fix_info.line_length;

    *(unsigned short *)(bmp->data + y * bmp->line_length + x * 2) = color;
}

void DrawPixel32 (BMP *bmp, int x, int y, int color) {
//    int location = (x+fb_var_info.xoffset) * (fb_var_info.bits_per_pixel/8) +
//                       (y+fb_var_info.yoffset) * fb_fix_info.line_length;

    *(unsigned int *)(bmp->data + y * bmp->line_length + x * 4) = color;
}


// 8 x 13
void DrawChar32 (BMP *bmp, char ch, int x, int y, int color) {
    if (ch > CHAR_SPACE) {
        register unsigned char count;
        register int xx;

        xx = (ch - CHAR_SPACE) * 8;

        if (FB.bpp==32) {
            // insert color
            for (count=0; count < 8; count++) {
                if (fixed_font[ 0][xx] == 'x') { DrawPixel32(bmp, x, y+0,  color); }
                if (fixed_font[ 1][xx] == 'x') { DrawPixel32(bmp, x, y+1,  color); }
                if (fixed_font[ 2][xx] == 'x') { DrawPixel32(bmp, x, y+2,  color); }
                if (fixed_font[ 3][xx] == 'x') { DrawPixel32(bmp, x, y+3,  color); }
                if (fixed_font[ 4][xx] == 'x') { DrawPixel32(bmp, x, y+4,  color); }
                if (fixed_font[ 5][xx] == 'x') { DrawPixel32(bmp, x, y+5,  color); }
                if (fixed_font[ 6][xx] == 'x') { DrawPixel32(bmp, x, y+6,  color); }
                if (fixed_font[ 7][xx] == 'x') { DrawPixel32(bmp, x, y+7,  color); }
                if (fixed_font[ 8][xx] == 'x') { DrawPixel32(bmp, x, y+8,  color); }
                if (fixed_font[ 9][xx] == 'x') { DrawPixel32(bmp, x, y+9,  color); }
                if (fixed_font[10][xx] == 'x') { DrawPixel32(bmp, x, y+10, color); }
                if (fixed_font[11][xx] == 'x') { DrawPixel32(bmp, x, y+11, color); }
                if (fixed_font[12][xx] == 'x') { DrawPixel32(bmp, x, y+12, color); }
                if (fixed_font[13][xx] == 'x') { DrawPixel32(bmp, x, y+13, color); }
                xx++; x++;
            }
            return;
        }
    }
}
// 8 x 13
void DrawChar16 (BMP *bmp, char ch, int x, int y, int color) {
    if (ch > CHAR_SPACE) {
        register unsigned char count;
        register int xx;

        xx = (ch - CHAR_SPACE) * 8;

        if (FB.bpp==16) {
            // insert color
            for (count=0; count < 8; count++) {
                if (fixed_font[ 0][xx] == 'x') { DrawPixel16(bmp, x, y+0,  color); }
                if (fixed_font[ 1][xx] == 'x') { DrawPixel16(bmp, x, y+1,  color); }
                if (fixed_font[ 2][xx] == 'x') { DrawPixel16(bmp, x, y+2,  color); }
                if (fixed_font[ 3][xx] == 'x') { DrawPixel16(bmp, x, y+3,  color); }
                if (fixed_font[ 4][xx] == 'x') { DrawPixel16(bmp, x, y+4,  color); }
                if (fixed_font[ 5][xx] == 'x') { DrawPixel16(bmp, x, y+5,  color); }
                if (fixed_font[ 6][xx] == 'x') { DrawPixel16(bmp, x, y+6,  color); }
                if (fixed_font[ 7][xx] == 'x') { DrawPixel16(bmp, x, y+7,  color); }
                if (fixed_font[ 8][xx] == 'x') { DrawPixel16(bmp, x, y+8,  color); }
                if (fixed_font[ 9][xx] == 'x') { DrawPixel16(bmp, x, y+9,  color); }
                if (fixed_font[10][xx] == 'x') { DrawPixel16(bmp, x, y+10, color); }
                if (fixed_font[11][xx] == 'x') { DrawPixel16(bmp, x, y+11, color); }
                if (fixed_font[12][xx] == 'x') { DrawPixel16(bmp, x, y+12, color); }
                if (fixed_font[13][xx] == 'x') { DrawPixel16(bmp, x, y+13, color); }
                xx++; x++;
            }
            return;
        }
    }
}


void sgDrawText (BMP *bmp, char *text, int x, int y, int color) {
    if (FB.bpp==32) {
        while (*text) {
            if (*text > CHAR_SPACE)
                DrawChar32 (bmp, *text, x, y, color);
            text++;
            x += 8;
        }
        return;
    }
    if (FB.bpp==16) {
        while (*text) {
            if (*text > CHAR_SPACE)
                DrawChar16 (bmp, *text, x, y, color);
            text++;
            x += 8;
        }
    }
}

//--------------------------------------------------------------------
// 1: restore
// 2: save
// 3: plot
//--------------------------------------------------------------------
//
static void sgDrawCursor32 (int x, int y) {
    UCHAR *save  = (UCHAR*)(FB.screen + old_y * FB.line_length + old_x * 4);
    UCHAR *pixel = (UCHAR*)(FB.screen +     y * FB.line_length +     x * 4);

    // 1 - restore:
    //
    //   PUT_PIXEL, in old position
    //
    *(unsigned int *)save       = pixel_save1;
    *(unsigned int *)(save + 4) = pixel_save2;
    //
    *(unsigned int *)(save + FB.line_length)     = pixel_save3;
    *(unsigned int *)(save + FB.line_length + 4) = pixel_save4;

    // 2 - save:
    //
    //   GET_PIXEL
    //
    pixel_save1 = *(unsigned int *)pixel;
    pixel_save2 = *(unsigned int *)(pixel + 4);
    //
    pixel_save3 = *(unsigned int *)(pixel + FB.line_length);
    pixel_save4 = *(unsigned int *)(pixel + FB.line_length + 4);

    // 3 - plot
    //
    //   PUT_PIXEL
    //
    // draw new pixel := CURSOR
    //
    *(unsigned int *)pixel = COLOR_WHITE32;
    *(unsigned int *)(pixel + 4) = COLOR_WHITE32;
    //
    *(unsigned int *)(pixel + FB.line_length) = 0;     // color black
    *(unsigned int *)(pixel + FB.line_length + 4) = 0; // color black
}

int sgEvent (SG_Event *ev) {
    if (keyboard_event()) {
        ev->key = key;
        return (ev->type = EV_KEY);
    }
    if (mouse_event()) {
        if (old_x != mouse_x || old_y != mouse_y) {
            sgDrawCursor32 (mouse_x, mouse_y);
            old_x = mouse_x; old_y = mouse_y;
            ev->x = mouse_x;
            ev->y = mouse_y;
            return (ev->type = EV_MOUSE_MOVE);
        }
        ev->button = button;
        if (ev->button) {
            return (ev->type = EV_MOUSE_DOWN);
        } else {
            return (ev->type = EV_MOUSE_UP);
        }
    }
    return 0;
}

int main (void) {
    int color;
    char buf[100];
    BMP *bmp = NULL;

    if (sgInit()) {

        if ((bmp = sgNewBmp(800,600)) == NULL)
            return -1;

        if (FB.bpp == 16)
            color = makecol16(255,130,30); // orange
        if (FB.bpp == 32) {
            color = makecol32(255,130,30);
        }

        sgDrawRect (bmp, 50, 50, 450, 150, color);
        sprintf (buf, "%s", "Move The Mouse | Press Any Key");
        sgDrawText (bmp, "Please Wait 15 SECONDS: ...", 100, 75, color);
        sgDrawText (bmp, buf, 100, 100, color);
        sgDrawText (bmp, "To exit press the key: ESC", 100, 125, color);

        if (FB.bpp == 32 && bmp) {

            sgBlit32 (bmp);

            for (;;) {

                if (sgEvent(&event)) {

                    if (event.button == 1 && event.x > 500) break;

                    if (event.type == EV_KEY) {
                        if (event.key == SGK_ESC) {
                            break;
                        }
                        sprintf (buf, "count: %d | key(%c) %d | NREAD: %d", count++, event.key, event.key, nread);
                    } else {
                        sprintf (buf, "X: %d, Y: %d | %d", mouse_x, mouse_y, count++);
                    }

                    // bg: FPS test
                    sgDrawRectFill (bmp, 100, 100, 300, 15, 12345);
                    sgDrawText (bmp, buf, 100, 100, color);

                    //
                    // Update/display the BMP
                    //
                    sgBlit32 (bmp);

                }// if (sgEvent(&event))

                usleep (1000);

            }// for (;;)

        }// if (FB.bpp == 32 && b)

        if (FB.bpp == 16) {
            sgBlit16 (bmp);
        }

        sgQuit();
    }

    FREE_BMP (bmp);
    FREE_BMP (bmp);

    printf ("Exiting With Sucess KEY: %d >>> nread: %d\n", key, nread);

    return 0;
}

