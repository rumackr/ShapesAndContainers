//
// Created by rumackr on 4/17/2018.
//

#include "Shape.h"
Shape::Shape(Color color, double x, double y): color(color),p0(1,4){
    p0[0][0] = x;
    p0[0][1] = y;
}

Shape::Shape(const Color &color, const matrix &p0) : color(color), p0(p0) {}

Shape::Shape(const Shape& shape): color(shape.color), p0(1,4){
    p0 = shape.p0;
}
Shape::~Shape(){

}
Shape& Shape::operator=(const Shape& rhs){
    color = rhs.color;
    p0 = rhs.p0;
    return *this;
}
void Shape::draw(GraphicsContext* gc){

}
//Todo  virtual out();
//TODO  virtual in();
Shape* Shape::clone() const {

}

Shape::Shape(){

}

