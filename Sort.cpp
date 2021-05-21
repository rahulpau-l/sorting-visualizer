//
// Created by Rahul on 2021-05-20.
//

#include "Sort.h"
#include <random>
#include <iostream>

void Sort::run(){

    init();

    while (sWindow.isOpen())
    {
        sf::Event event{};
        while (sWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sWindow.close();
        }

        sWindow.clear();
        draw();
        sort();
    }
}

void Sort::draw() {
    for(auto &n: arr){
        sWindow.draw(n.rect);
    }
}


void Sort::init() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution distrib(1, 510);


    int x = 0;
    int y = 530;

    for(auto &it : arr) {
        int num = distrib(gen);
        it.setNum(num);
        it.setSize(sf::Vector2f(10, -1 * num));
        it.rect.setPosition(x, y);
        x += 11;
    }


}

void Sort::sort() {

    for(int j = 0; j < arr.size(); j++){
        for(int i = 0; i < arr.size() -1; i++){
            if(arr[i].num > arr[i+1].num){
                sWindow.clear();

                Number temp(arr[i]);
                arr[i].num = arr[i+1].num;
                arr[i].rect.setSize(sf::Vector2f(10, arr[i+1].rect.getSize().y));


                arr[i+1].num = temp.num;
                arr[i+1].rect.setSize(sf::Vector2f(10, temp.rect.getSize().y));


                draw();
                sWindow.display();
            }

        }

    }

}

void Sort::display() {
    for(auto &n: arr){
        std::cout << n.num << " ";

    }
}
