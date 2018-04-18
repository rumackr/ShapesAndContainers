//
// Created by rumackr on 4/18/2018.
//

#include "Line.h"
#include "gcontext.h"

Line::Line(const Shape &shape) : Shape(shape),p1(1,4) {
}

Line::Line(const Color &color, double x0, double y0, double x1, double y1): p1(1,4){
    this->color = color;
    p0[0][0] = x0;
    p0[0][1] = y0;

    p1[0][0] = x1;
    p1[0][1] = y1;

}

Line::Line(const Color &color, const matrix &p0, const matrix &p1) : Shape(color, p0), p1(p1) {

}

void Line::draw(GraphicsContext *gc) {
    if(gc!= nullptr) {
        gc->setColor(color.rgb24bit);
        gc->drawLine((int)p0[0][0] + 0.5, (int) p0[0][1] + 0.5,
                     (int) p1[0][0] + 0.5, (int) p1[0][1] + 0.5);
    }

}

Shape *Line::clone() const {
    return new Line(*this);
}

double Line::getSlope() const {
    return slope;
}




