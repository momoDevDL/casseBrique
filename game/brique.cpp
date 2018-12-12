#include "brique.h"
#include "terrain.h"

Brick::Brick() : height(0), width(5), posX(20), posY(20), resistance(1),bordure(' '){}
Brick::Brick(int h, int w, int x, int y, int res,const char ch) : height(h), width(w), posX(x), posY(y), resistance(res),bordure(ch){}

int Brick::getHeight() const{

    return height;
}

int Brick::getWidth() const{

    return width;
}

int Brick::getPosX() const{

    return posX;
}

int Brick::getPosY() const{

    return posY;
}

int Brick::getResistance() const{

    return resistance;
}



void Brick::setHeight(int h){

    height = h;
}

void Brick::setWidth(int w){

    width = w;
}

void Brick::setPosX(int x){

    posX = x;
}

void Brick::setPosY(int y){

    posY = y;
}

void Brick::setResistance(int res){

    resistance = res;
}

char  Brick::getBordure()const {
  return bordure;
}

void printBrick(Brick &br,terrain &ter){
  int hauteur = 0;
  int largeur = 0;
  
  while(hauteur <= br.getHeight()){

    while(largeur <= br.getWidth()){
      ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,br.getBordure(),BWHITE);
      largeur++;
    }
    hauteur++;
    largeur=0;
  }
}
