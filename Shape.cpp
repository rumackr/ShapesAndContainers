//
// Created by rumackr on 4/17/2018.
//

#include "Shape.h"
Shape::Shape(Color color, double x, double y): color(color),origin(1,4){
    origin[0][0] = x;
    origin[0][1] = y;
}
Shape::Shape(const Shape& shape): color(shape.color), origin(1,4){
    origin = shape.origin;
}
Shape::~Shape(){

}
Shape& Shape::operator=(const Shape& rhs){
    color = rhs.color;
    origin = rhs.origin;
    return *this;
}
void Shape::draw(GraphicsContext* gc){

}
//Todo  virtual out();
//TODO  virtual in();
Shape* Shape::clone() const {

}
