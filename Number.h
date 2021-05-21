//
// Created by Rahul on 2021-05-20.
//

#ifndef NUMBER_H
#define NUMBER_H
#include <SFML/Graphics.hpp>

class Number {
private:


public:
    int num{};
    sf::RectangleShape rect;

    Number(){
        rect.setFillColor(sf::Color::White);
    }

    Number(const Number &n){
        num = n.num;
        rect = n.rect;
    }
    void setNum(int c){
        num = c;
    }

    void setSize(sf::Vector2<float> dimension) {
        rect.setSize(dimension);
    }
};


#endif //NUMBER_H
