//
// Created by rumackr on 4/17/2018.
//

#ifndef LAB4_COLOR_H
#define LAB4_COLOR_H


class Color {
    public:
        unsigned char R;
        unsigned char G;
        unsigned char B;
        unsigned int  rgb24bit;
        Color::Color(unsigned char R, unsigned char G, unsigned char B);
        Color::Color(unsigned rgb24bit);


};


#endif //LAB4_COLOR_H
