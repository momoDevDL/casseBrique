#include "brique.h"
#include "terrain.h"
#include "balle.h"
Brick::Brick() : height(2), width(9), posX(30), posY(10), resistance(1),bordure(' '){}
Brick::Brick(int h, int w, int x, int y, int res,const char ch) : height(h), width(w), posX(x), posY(y), resistance(res),bordure(ch){}

int Brick::getHeight() const{return height; }

int Brick::getWidth() const{ return width; }

int Brick::getPosX() const{ return posX; }

int Brick::getPosY() const {return posY; }

int Brick::getResistance() const{return resistance;}

char  Brick::getBordure()const {return bordure;}

void Brick::setHeight(int h){ height = h;}

void Brick::setWidth(int w){ width = w;}

void Brick::setPosX(int x){ posX = x;}

void Brick::setPosY(int y){posY = y; }

void Brick::setResistance(int res){ resistance = res;}

void printBrick(Brick &br,terrain &ter){
  int hauteur = 0;
  int largeur = 0;
  
  while(hauteur < br.getHeight()){
    
    while(largeur < br.getWidth()){
      ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,br.getBordure(),WRED);
      largeur++;
    }
    hauteur++;
    largeur=0;
  }
}


void Brick::collision_Ball_Brique(Ball &b){
  float position_ballX= b.getposX();
  float position_ballY= b.getposY();
  float Vitesse_BallX = b.getVitesseX();
  float Vitesse_BallY= b.getVitesseY();

  if( position_ballY == posY+height && (position_ballX >=posX && position_ballX<= (posX+width)) ){
    b.setVitesseY(Vitesse_BallY *-1);
    resistance--;
  }

  if(position_ballY == posY-1 && (position_ballX >=posX && position_ballX<= (posX+width))){
      b.setVitesseY(Vitesse_BallY *-1);
      resistance--;
  }
  if( position_ballX == posX-1 && (position_ballY >= posY && position_ballY <= posY+height)){
    b.setVitesseX(Vitesse_BallX *-1);
    resistance--;
  }
  
  if (position_ballX == posX+width+1 && (position_ballY >= posY && position_ballY <= posY+height)){
    b.setVitesseX(Vitesse_BallX *-1);
    resistance --;
  }
}
