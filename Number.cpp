//
// Created by Rahul on 2021-05-20.
//

#include "Number.h"

Number::Number() {
    rect.setFillColor(sf::Color::White);
}

Number::Number(const Number &n): num(n.num), rect(n.rect) {

}

void Number::setNum(int c) {
    num = c;
}

void Number::setSize(sf::Vector2<float> &&dimension)  {
    rect.setSize(dimension);
}




