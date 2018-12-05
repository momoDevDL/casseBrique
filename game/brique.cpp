#include "brique.h"


Brique::Brique() : height(0), width(0), posX(2), posY(2), resistance(1) {};
Brique::Brique(size_t h, size_t w, size_t x, size_t y, size_t res) : height(h), width(w), posX(x), posY(y), resistance(res) {};

size_t Brique::getHeight() const{

    return height;
}

size_t Brique::getWidth() const{

    return width;
}

size_t Brique::getPosX() const{

    return posX;
}

size_t Brique::getPosY() const{

    return posY;
}

size_t Brique::getResistance() const{

    return resistance;
}

void Brique::setHeight(size_t &h){

    height = h;
}

void Brique::setWidth(size_t &w){

    width = w;
}

void Brique::setPosX(size_t &x){

    posX = x;
}

void Brique::setPosY(size_t &y){

    posY = y;
}

void Brique::setResistance(size_t &res){

    resistance = res;
}