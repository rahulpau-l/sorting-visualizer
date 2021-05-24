//
// Created by Rahul on 2021-05-20.
//

#ifndef SORT_H
#define SORT_H

#include <vector>
#include "Number.h"

class Sort {
    const int WIDTH = 960;
    const int HEIGHT = 540;
private:
    sf::RenderWindow sWindow{sf::VideoMode(WIDTH, HEIGHT), "Sort!"};
    std::vector<Number> arr{87};
public:
    void run();
private:
    void draw();
    void init();
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void quickSort();
    void mergeSort();
    void selectSort();
    void display();
};


#endif //SORT_H
