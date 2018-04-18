/* This is an abstract base class representing a generic graphics
 * context.  Most implementation specifics will need to be provided by
 * a concrete implementation.  See header file for specifics. */

#define _USE_MATH_DEFINES	// for M_PI
#include <cmath>	// for trig functions
#include "gcontext.h"

/*
 * Destructor - does nothing
 */
GraphicsContext::~GraphicsContext()
{
    // nothing to do
    // here to insure subclasses handle destruction properly
}


/* This is a naive implementation that uses floating-point math
 * and "setPixel" which will need to be provided by the concrete
 * implementation.
 *
 * Parameters:
 * 	x0, y0 - origin of line
 *  x1, y1 - end of line
 *
 * Returns: void
 */
//Based on pseudocode from Wikipedia
void drawShallowLine(int x0, int x1, int y0, int y1);
void drawSteepLine(int x0, int x1, int y0, int y1);
void GraphicsContext::drawLine(int x0, int y0, int x1, int y1)
{

    if (std::abs(y1-y0)<std::abs(x1-x0)) {
        if (x0>x1) {
            drawShallowLine(x1, y1, x0, y0);
        }
        else {
            drawShallowLine(x0, y0, x1, y1);
        }
    }
    else {
        if (y0>y1) {
            drawSteepLine(x1, y1, x0, y0);
        }
        else {
            drawSteepLine(x0, y0, x1, y1);
        }
    }
}
void GraphicsContext::drawShallowLine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy<0) {
        yi = -1;
        dy = -dy;
    }
    int D = 2*dy - dx;
    int y = y0;

    for (int x = x0; x<=x1; x++) {
        setPixel(x, y);
        if (D>0) {
            y+=yi;
            D-=2*dx;
        }
        D+=2*dy;
    }
}
void GraphicsContext::drawSteepLine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if (dx<0) {
        xi = -1;
        dx = -dx;
    }
    int D = 2*dx - dy;
    int x = x0;

    for (int y = y0; y<=y1; y++) {
        setPixel(x, y);
        if (D>0) {
            x+=xi;
            D-=2*dy;
        }
        D+=2*dx;
    }
}



/* This is a naive implementation that uses floating-point math
 * and "setPixel" which will need to be provided by the concrete
 * implementation.
 *
 * Parameters:
 * 	x0, y0 - origin/center of circle
 *  radius - radius of circle
 *
 * Returns: void
 */
//Based on code from Wikipedia
void GraphicsContext::drawCircle(int x0, int y0, unsigned int radius)
{
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - 2*radius;

    while (x>=y) {
        setPixel(x0 + x, y0 + y);
        setPixel(x0 + x, y0 - y);
        setPixel(x0 - x, y0 + y);
        setPixel(x0 - x, y0 - y);
        setPixel(x0 + y, y0 + x);
        setPixel(x0 + y, y0 - x);
        setPixel(x0 - y, y0 + x);
        setPixel(x0 - y, y0 - x);

        if (err<=0) {
            y++;
            err+=dy;
            dy+=2;
        }

        if (err>0) {
            x--;
            dx+=2;
            err += dx - 2*radius;
        }
    }
}

void GraphicsContext::endLoop()
{
    run = false;
}

