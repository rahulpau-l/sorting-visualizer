//
// Created by Rahul on 2021-05-20.
//

#include "Sort.h"
#include <random>
#include <iostream>
#include <chrono>

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

        selectSort();
        sWindow.clear();
        draw();
        sWindow.display();

    }

    display();


}

void Sort::draw() {
    for(auto &n: arr){
        sWindow.draw(n.rect);
    }
}

void Sort::init() {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution distrib(1, 535);

    int x = 0;
    int y = 540;

    for(auto &it : arr) {
        int num = distrib(generator);
        it.setNum(num);
        it.setSize(sf::Vector2f(10, -1 * num));
        it.rect.setPosition(x, y);
        x += 11;
    }
}

void Sort::bubbleSort() {
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

void Sort::insertionSort() {
    int i;
    for(int j = 1; j < arr.size(); j++){
        Number key = arr[j];
        i = j-1;
        while(i >= 0 && arr[i].num > key.num){
            sWindow.clear();
            arr[i+1].num = arr[i].num;
            arr[i+1].rect.setSize(sf::Vector2f(10, arr[i].rect.getSize().y));
            draw();

            i = i - 1;
        }
        sWindow.clear();
        arr[i+1].num = key.num;
        arr[i+1].rect.setSize(sf::Vector2f(10, key.rect.getSize().y));
        draw();
        sWindow.display();
    }
}

void Sort::selectionSort() {
    for(int i = 0; i < arr.size() - 1; i++){
        auto minIndex = i;
        for(int j = i + 1; j < arr.size(); j++ ){
            if(arr[j].num < arr[minIndex].num){
                    minIndex = j;
            }
            sWindow.clear();
            draw();
        }

        if(minIndex != i){
            sWindow.clear();
            Number temp(arr[i]);
            arr[i].num = arr[minIndex].num;
            arr[i].rect.setSize(sf::Vector2f(10, arr[minIndex].rect.getSize().y));

            arr[minIndex].num = temp.num;
            arr[minIndex].rect.setSize(sf::Vector2f(10, temp.rect.getSize().y));
            draw();
            sWindow.display();
        }

    }
}

void Sort::quickSort(int left, int right) {
    if(left < right){
        int pivotIndex = partition(left, right);
        quickSort(left, pivotIndex - 1);
        quickSort(pivotIndex, right);
    }
}

int Sort::partition(int left, int right){
    int pivotIndex = left + (right - left) / 2;
    Number pivotValue = arr[pivotIndex];
    int i = left, j = right;



    while(i <= j) {
        sWindow.clear();
        draw();
        sWindow.display();

        sWindow.clear();
        draw();
        sWindow.display();

        sWindow.clear();
        draw();
        sWindow.display();

        while(arr[i].num < pivotValue.num) {
            sWindow.clear();
            draw();
            sWindow.display();
            i++;
            sWindow.clear();
            draw();
            sWindow.display();
        }
        while(arr[j].num > pivotValue.num) {
            sWindow.clear();
            draw();
            sWindow.display();
            j--;
            sWindow.clear();
            draw();
            sWindow.display();
        }
        if(i <= j) {
            sWindow.clear();
            Number temp(arr[i]);
            arr[i].num = arr[j].num;
            arr[i].rect.setSize(sf::Vector2f(10, arr[j].rect.getSize().y));
            draw();
            sWindow.display();

            sWindow.clear();
            draw();
            sWindow.display();

            sWindow.clear();
            arr[j].num = temp.num;
            arr[j].rect.setSize(sf::Vector2f(10, temp.rect.getSize().y));
            i++;
            j--;
            draw();
            sWindow.display();

        }
        sWindow.clear();
        draw();
        sWindow.display();


    }
    return i;
}


void Sort::selectSort() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
        init();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        bubbleSort();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        insertionSort();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
        selectionSort();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){
        quickSort(0, arr.size() - 1);
    }
}



void Sort::display() {
    for(auto &n: arr){
        std::cout << n.num << " ";

    }
}
