//
// Created by rumackr on 4/18/2018.
//

#include "Triangle.h"

Triangle::Triangle(const Color &color,
                   const matrix &p0,
                   const matrix &p1,
                   const matrix &p2) : Shape(color, p0), p1(p1), p2(p2) {


}

Triangle::Triangle(const Color &color,
                   double x0, double y0,
                   double x1, double y1,
                   double x2, double y2): Color(color), p1(1,4), p2(1,4){

    p0[0][0] = x0;
    p0[0][1] = y0;

    p1[0][0] = x1;
    p1[0][1] = y1;

    p2[0][0] = x2;
    p2[0][1] = y2;

}

void Triangle::draw(GraphicsContext *gc) {
    if(gc!= nullptr) {
        gc->setColor(color.rgb24bit);
        int x0,x1,x2;
        int y0,y1,y2;
        // rounding points
        x0 = (int)p0[0][0] + 0.5;
        y0 = (int)p0[0][1] + 0.5;

        x1 = (int)p1[0][0] + 0.5;
        y1 = (int)p1[0][1] + 0.5;

        x2 = (int)p2[0][0] + 0.5;
        y2 = (int)p2[0][1] + 0.5;
        //draw lines to form triangle
        gc->drawLine(x0, y0, x1, y1);
        gc->drawLine(x1, y1, x2, y2);
        gc->drawLine(x0, y0, x2, y2);
    }

}

Shape *Triangle::clone() const {
    return nullptr;
}
