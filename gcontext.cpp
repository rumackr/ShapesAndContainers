/**
 * @author Reid Rumack
 * @file   gcontext.cpp
 * @date   3/23/2018
 * @project lab 3
 * \see gcontext.h
 */

#define _USE_MATH_DEFINES	// for M_PI
#include <cmath>	// for trig functions
#include "gcontext.h"

/**
 * Destructor - does nothing
 */
GraphicsContext::~GraphicsContext()
{
    // nothing to do
    // here to insure subclasses handle destruction properly
}


/**
 * Draws a line from point (x0,y0) to (x1,y1) using the Bresenham's
 * line algorithm. Only use integer arithmetic.
 * @brief  Draws a line from point (x0,y0) to (x1,y1).
 *
 * @param x0  origin of line
 * @param y0  origin of line
 * @param x1 end of line
 * @param y1 end of line
 */
void GraphicsContext::drawLine(int x0, int y0, int x1, int y1)
{

    // find slope
    int dx = x1-x0;
    int dy = y1-y0;

    // make sure we actually have a line
    if (dx != 0 || dy !=0)
    {
        // slope < 1?
        if (std::abs(dx)>std::abs(dy)) {
            // iterate over x
            //is the reversed
            (dx < 0) ? (drawLineLow(x1, y1, x0, y0)) : (drawLineLow(x0, y0, x1, y1));
            // end of if |slope| < 1
        } else {
            // iterate over y
            // is the slope negative
            (dy < 0) ? (drawLineHigh(x1,y1,x0,y0)) : (drawLineHigh(x0,y0,x1,y1));

        } // end of else |slope| >= 1
    } // end of if it is a real line (dx!=0 || dy !=0)
    return;
}
/**
 * Draws a line with slope less then 1
 * (helper function for drawLine)
 * @param x0  origin of line
 * @param y0  origin of line
 * @param x1 end of line
 * @param y1 end of line
 */
void GraphicsContext::drawLineLow(const int x0, const int y0, const int x1, const int y1) {
    int dx,dy;
    int yIntercept = 1;

    //find slope
    dx = x1 - x0;
    dy = y1 - y0;
    if(dy < 0){	//negative slope
        yIntercept = -1;
        dy = -dy;
    }

    int D = (dy << 1) - dx;
    int y = y0;
    for (int x = x0; x < x1; ++x) {
        setPixel(x,y);
        if (D > 0){
            y+= yIntercept;
            D-= (dx << 1);
        }
        D += (dy << 1);
    }

}
/**
 * Draws a line with slope grater then 1
 * (helper function for drawLine)
 * @param x0  origin of line
 * @param y0  origin of line
 * @param x1 end of line
 * @param y1 end of line
 */
void GraphicsContext::drawLineHigh(const int x0, const int y0, const int x1, const int y1) {
    int dx,dy;
    int xIntercept = 1;

    //find slope
    dx = x1 - x0;
    dy = y1 - y0;

    if(dx < 0){ // reversed line
        xIntercept = -1;
        dx = -dx;
    }

    int D = (dx << 1) - dy;
    int x = x0;
    for (int y = y0; y < y1; ++y) {
        setPixel(x,y);
        if (D > 0){
            x+= xIntercept;
            D-= (dy << 1);
        }
        D += (dx << 1);
    }

}


/**
 * Draws a circle using the mid-point circle algorithm. Uses only
 * integer arithmetic.
 * @brief draws circle
 *
 * 	@param x0 origin/center of circle
 * 	@param y0 origin/center of circle
 *  @param radius radius of circle
 */
void GraphicsContext::drawCircle(int x0, int y0, unsigned int radius)
{
    int x,y;
    int dx,dy;
    //decision parameter
    int D;

    x = radius-1;
    y = 0;
    dy = 1;
    dx = 1;

    //dx - diameter
    D	= dx - (radius << 1);

    while (x >= y){
        //draw lower right of circle
        setPixel(x0 + x, y0 + y);
        setPixel(x0 + y, y0 + x);
        //draw lower left of circle
        setPixel(x0 - x, y0 + y);
        setPixel(x0 - y, y0 + x);
        //draw upper right of circle
        setPixel(x0 + x, y0 - y);
        setPixel(x0 + y, y0 - x);
        //draw upper left of circle
        setPixel(x0 - x, y0 - y);
        setPixel(x0 - y, y0 - x);

        if (D <= 0 ){
            // mid-point is on or inside the perimeter
            y++;
            D += dy;
            dy += 2;
        }else{
            // mid-point is outside the perimeter
            x--;
            dx += 2;
            //dx - diameter
            D += dx - (radius << 1);
        }
    }
}
bfr

void GraphicsContext::endLoop()
{
    run = false;
}

