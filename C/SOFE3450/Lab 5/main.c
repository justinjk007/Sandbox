/* This program implements a line drawing algorithm. */
#include <math.h>
#include <stdio.h>

/******************************************************************************/
/**** GLOBAL MACROS ***********************************************************/
/******************************************************************************/

/* Screen size. */
#define RESOLUTION_X 320
#define RESOLUTION_Y 240
#define ABS(x) (((x) > 0) ? (x) : -(x))

/******************************************************************************/
/**** MEMORY MAPPED REGISTERS *************************************************/
/******************************************************************************/

/* VGA Control registers. */
volatile int* vga_pixel_buffer_buffer_reg      = (int*)0x10003020;
volatile int* vga_pixel_buffer_back_buffer_reg = (int*)0x10003024;

/* Video memory */
volatile int* vga_screen_front_buffer = (int*)0x08000000;
volatile int* vga_screen_back_buffer  = (int*)0x08040000;

/******************************************************************************/
/**** SOURCE CODE *************************************************************/
/******************************************************************************/

/******************************************************************************/
/**** LINE DRAWING AND CLEAR SCREEN FUNCTIONS *********************************/
/******************************************************************************/

void clear_screen(int back_buffer)
{
    register int* buffer = (back_buffer != 0) ? vga_screen_back_buffer : vga_screen_front_buffer;
    register int y, x;
    for (y = 0; y < RESOLUTION_Y; y++) {
        register int* buf = (buffer + (y << 8));
        for (x = 0; x < RESOLUTION_X / 2; x++) {
            *buf++ = 0;
        }
    }
}

void helper_plot_pixel(int buffer_start, int x, int y, short int line_color)
{
    *((short int*)(buffer_start + (y << 10) + (x << 1))) = (short int)line_color;
}

/* Bresenham's line drawing algorithm. */
void draw_line(int x0, int y0, int x1, int y1, int color, int backbuffer)
/* This function draws a line between points (x0, y0) and (x1,
 * y1). The function does not check if it draws a pixel within screen
 * boundaries.  users should ensure that the line is drawn within the
 * screen boundaries. */
{
    register int x_0    = x0;
    register int y_0    = y0;
    register int x_1    = x1;
    register int y_1    = y1;
    register int temp   = 0;
    register char steep = (ABS(y_1 - y_0) > ABS(x_1 - x_0)) ? 1 : 0;
    register int deltax, deltay, error, ystep, x, y;
    register int line_color = color;
    register unsigned int buffer_start;

    if (backbuffer == 1)
        buffer_start = (int)vga_screen_back_buffer;
    else
        buffer_start = (int)vga_screen_front_buffer;

    /* Preprocessing inputs */
    if (steep > 0) {
        // Swap x_0 and y_0
        temp = x_0;
        x_0  = y_0;
        y_0  = temp;

        // Swap x_1 and y_1
        temp = x_1;
        x_1  = y_1;
        y_1  = temp;
    }
    if (x_0 > x_1) {
        // Swap x_0 and x_1
        temp = x_0;
        x_0  = x_1;
        x_1  = temp;

        // Swap y_0 and y_1
        temp = y_0;
        x_0  = y_1;
        x_1  = temp;
    }

    /* Setup local variables */
    deltax = x_1 - x_0;
    deltay = ABS(y_1 - y_0);
    error  = -(deltax / 2);
    y      = y_0;
    if (y_0 < y_1)
        ystep = 1;
    else
        ystep = -1;

    /* Draw a line - either go along the x-axis (steep = 0) or along
     * the y-axis (steep = 1). The code is replicated to be fast on
     * low optimization levels. */
    if (steep == 1) {
        // draw pixel( y,x`)
        size_t i;
        for (i = x_0; i < x_1; ++i) {
            helper_plot_pixel(buffer_start, y, i, color);
            error = error + (deltay / deltax);
            if (error >= 0.5) {
                y     = y + ystep;
                error = error - 1;
            }
        }

    } else {
        // draw pixel( x,y)
        size_t i;
        for (i = x_0; i < x_1; ++i) {
            helper_plot_pixel(buffer_start, i, y, color);
        }
        error = error + (deltay / deltax);
        if (error >= 0.5) {
            y     = y + ystep;
            error = error - 1;
        }
    }
}

int main(void)
{
    clear_screen(0);
    draw_line(0, 0, 150, 150, 0xffff, 0);
    draw_line(150, 150, 319, 0, 0xf81f, 0);
    draw_line(319, 0, 0, 239, 0x8410, 0);
    draw_line(0, 239, 319, 239, 0xf800, 0);
}
