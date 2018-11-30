#include<iostream>
#include"balle.h"

//les constructeurs de terrain par defaut et paramétré
Ball::Ball():c('@'),posX(1),posY(1),vitesse(1){}
Ball::Ball(char car,size_t x,size_t y,size_t v):c(car),posX(x),posY(y),vitesse(v){}
	//accesseur en lecture 
size_t Ball::getposX()const{
  return posX;
}
size_t Ball::getposY()const{
  return posY;
}
int Ball::getVitesse()const{
  return vitesse;
}
	//accesseurs en ecriture
void Ball::setposX(size_t x){
  posX=x;
}
void Ball::setposY(size_t y){
  posY=y;
}void Ball::setVitesse(int v){
  vitesse=v;
}

//methodes

void Ball::move_Ball(){
  setposX(posX+vitesse);
  setposY(posY+vitesse);
}

