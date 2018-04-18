//
// Created by rumackr on 4/17/2018.
//

#include "Point.h"

Point::Point(const Color &color, double x, double y) : Shape(color, x, y) {}

Point::Point(const Shape &shape) : Shape(shape) {}

void Point::draw(GraphicsContext *gc) {

}

Point * Point::clone() const {
    return new Point(*this);
}
