//
// Created by rumackr on 4/17/2018.
//

#ifndef LAB4_POINT_H
#define LAB4_POINT_H


#include "Shape.h"

class Point: public Shape {
    public:
        Point(const Color &color, double x, double y);

        Point(const Color &color, const matrix &p0);

        Point(const Shape &shape);


        void draw(GraphicsContext *gc) override;

        Point *clone() const override;
};


#endif //LAB4_POINT_H
