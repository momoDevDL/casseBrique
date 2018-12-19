#include<iostream>
#include"balle.h"

//les constructeurs de terrain par defaut et paramétré
Ball::Ball():c('@'),posX(1),posY(1),vitesseX(0),vitesseY(0),deplacement(0){}
Ball::Ball(char car,float x,float y,float vx,float vy,unsigned int d):c(car),posX(x),posY(y),vitesseX(vx),vitesseY(vy),deplacement(d){}
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
unsigned int Ball::getDeplacement()const{
  return deplacement;
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
void Ball::setDeplacement(int d){
  deplacement = d;
}

//methodes

void Ball::move_Ball(){
  setposX(posX+getVitesseX());
  setposY(posY+getVitesseY());
}

