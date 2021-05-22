//
// Created by Rahul on 2021-05-20.
//

#ifndef NUMBER_H
#define NUMBER_H
#include <SFML/Graphics.hpp>

class Number {
public:
    int num{};
    sf::RectangleShape rect;

    Number();
    Number(const Number &n);
    void setNum(int c);
    void setSize(sf::Vector2<float> dimension);
};


#endif //NUMBER_H
