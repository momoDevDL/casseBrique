#include<iostream>
#include"raquette.h"

//les constructeurs de racket par defaut et paramétré
racket::racket():height(2),width(8),posX(35),posY(20),bordureUP("_"),bordure1Side(","),bordure2Side("'"){}
racket::racket(int h,int w,int x,int y):height(h),width(w),posX(x),posY(y),bordureUP("_"),bordure1Side(","),bordure2Side("'"){
}

//accesseur en lecture 
int racket::getHeightRacket()const{
  return height;
}
int racket::getWidthRacket()const{
return width();
}
int  racket::getXRacket()const{
  return posX;
}
int  racket::getYRacket()const{
  return posY;
}

//accesseurs en ecriture
void racket::setHeightRacket(int H){
  height = H;
}
void racket::setWidthRacket(int W){
  width = W;
}
void racket::setPosXRacket(int X){
  posX = X;
}
void racket::setPosYRacket(int Y){
  posY = Y;
}

