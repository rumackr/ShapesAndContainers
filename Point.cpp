//
// Created by rumackr on 4/17/2018.
//

#include "Point.h"

Point::Point(const Color &color, double x, double y) : Shape(color, x, y) {}

Point::Point(const Color &color, const matrix &p0) : Shape(color, p0) {}

Point::Point(const Shape &shape) : Shape(shape) {}

void Point::draw(GraphicsContext *gc) {
    gc->setColor(this->color.rgb24bit);
    gc->setPixel((int)(p0[0][0]) + 0.5,(int) p0[0][1] + 0.5);
}

Point * Point::clone() const {
    return new Point(*this);
}

