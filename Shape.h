//
// Created by rumackr on 4/17/2018.
//

#ifndef LAB4_SHAPE_H
#define LAB4_SHAPE_H

#include "Color.h"
#include "Matrix.h"
#include "x11context.h"


class Shape {
    protected:
        Color color;
        matrix origin;
    public:
        Shape(Color color, double x, double y);
        Shape(const Shape& shape);
        virtual ~Shape();
        virtual Shape& operator=(const Shape& rhs);
        virtual void draw(GraphicsContext* gc) = 0;
      //Todo  virtual out();
      //TODO  virtual in();
        virtual Shape* clone() const = 0;


};


#endif //LAB4_SHAPE_H
