//
// Created by rumackr on 4/18/2018.
//

#ifndef LAB4_LINE_H
#define LAB4_LINE_H


#include "Shape.h"

class Line: public Shape {
    private:
        /// xy-slope
        double slope;
     //   matrix midpoint;
    protected:
        matrix p1;
    public:
        Line(const Color &color, double x0, double y0, double x1, double y1);

        Line(const Color &color, const matrix &p0, const matrix &p1);

        Line(const Shape &shape);

        double getSlope() const;

        const matrix &getMidpoint() const;

        void draw(GraphicsContext *gc) override;

        Shape *clone() const override;


};


#endif //LAB4_LINE_H
