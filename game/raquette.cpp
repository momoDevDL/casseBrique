#include<iostream>
#include"raquette.h"
#include"window.h"

//les constructeurs de racket par defaut et paramétré

racket::racket():height(2),width(8),posX(35),posY(20){
  setBordureUP('-'),setBordure1Side(','),setBordure2Side('\'');}

racket::racket(unsigned int w,unsigned int x,unsigned int y ):width(w),posX(x),posY(y){
  setHeightRacket(2),setBordureUP('-'),setBordure1Side(','),setBordure2Side('\'');}

//accesseur en lecture 
unsigned int racket::getHeightRacket()const{
  return height;
}
unsigned int racket::getWidthRacket()const{
  return width;
}
unsigned int racket::getXRacket()const{
  return posX;
}
unsigned int racket::getYRacket()const{
  return posY;
}

char racket::getbordureUP()const{
  return bordureUP;
}
char racket::getbordure1Side()const{
  return bordure1Side;
}
char racket::getbordure2Side()const{
  return bordure2Side;
}

//accesseurs en ecriture
void racket::setHeightRacket(unsigned int H){
  height = H;
}
void racket::setWidthRacket(unsigned int W){
  width = W;
}
void racket::setPosXRacket(unsigned int X){
  posX = X;
}
void racket::setPosYRacket(unsigned int Y){
  posY = Y;
}
void racket::setBordureUP(char BU){
  bordureUP = BU;
}
void racket::setBordure1Side(char B1S){
  bordure1Side = B1S;
}
void racket::setBordure2Side(char B2S){
  bordure2Side = B2S;
}



//methodes

void printRacket(racket &r,terrain &t){
  unsigned int hauteur = 0;
  unsigned int longueur = 0;
  
  while (hauteur < r.getHeightRacket()){
    
    if (hauteur == 0){
      t.printInField(r.getXRacket()+longueur,r.getYRacket()+hauteur,r.getbordure1Side(),WBLACK);
      longueur++;
    }else if (hauteur == 1){
      t.printInField(r.getXRacket()+longueur,r.getYRacket()+hauteur,r.getbordure2Side(),WBLACK);
      longueur++;
    }
    while (longueur <r.getWidthRacket()){
      t.printInField(r.getXRacket()+longueur,r.getYRacket()+hauteur,r.getbordureUP(),WBLACK);
      longueur++;
    }
    if (hauteur == 0){
      t.printInField(r.getXRacket()+longueur,r.getYRacket()+hauteur,r.getbordure1Side(),WBLACK);
    }else if (hauteur == 1){
      t.printInField(r.getXRacket()+longueur,r.getYRacket()+hauteur,r.getbordure2Side(),WBLACK);
    }
    hauteur++;
    longueur=0;
  }
}



