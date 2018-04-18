//
// Created by rumackr on 4/18/2018.
//

#ifndef LAB4_TRIANGLE_H
#define LAB4_TRIANGLE_H


#include "Shape.h"

class Triangle: public Shape {
    private:
        double angle0,angle1,angle2 = 0;
    protected:
        matrix p1 = matrix(1,4);
        matrix p2 = matrix(1,4);
    public:
        Triangle(const Color &color, const matrix &p0, const matrix &p1, const matrix &p2);
        Triangle::Triangle(const Color &color, double x0, double y0, double x1, double y1, double x2, double y2);

    void draw(GraphicsContext *gc) override;

    Shape *clone() const override;

};


#endif //LAB4_TRIANGLE_H
