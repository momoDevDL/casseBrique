#include<iostream>
#include"balle.h"

//les constructeurs de terrain par defaut et paramétré
Ball::Ball():c('@'),posX(1),posY(1),vitesseX(1),vitesseY(1){}
Ball::Ball(char car,float x,float y,float vx,float vy):c(car),posX(x),posY(y),vitesseX(vx),vitesseY(vy){}
	//accesseur en lecture 
float Ball::getposX()const{
  return posX;
}
float Ball::getposY()const{
  return posY;
}
float Ball::getVitesseX()const{
  return vitesseX;
}
float Ball::getVitesseY()const{
  return vitesseY;
}
char Ball::getChar()const{
  return c;
}
	//accesseurs en ecriture
void Ball::setposX(float x){
  posX=x;
}
void Ball::setposY(float y){
  posY=y;
}
void Ball::setVitesseX(float vx){
  vitesseX=vx;
}
void Ball::setVitesseY(float vy){
  vitesseY=vy;
}

//methodes

void Ball::move_Ball(){
  setposX(posX+getVitesseX());
  setposY(posY+getVitesseY());
}

