//
// Created by rumackr on 4/17/2018.
//

#include "Color.h"



Color::Color(unsigned char R, unsigned char G, unsigned char B): R(R),G(G),B(B){
    unsigned int colorInt = R & 0xff;
    colorInt = (colorInt<<8) | (G & 0xff);
    colorInt = (colorInt<<8) | (B & 0xff);
    rgb24bit = colorInt;

}

Color::Color(unsigned rgb24bit): rgb24bit(rgb24bit){
}


