#include "brique.h"
#include "terrain.h"
#include "balle.h"
#include <iostream>
using namespace std;
Brick::Brick() : height(1), width(9), posX(30), posY(10), resistance(2),bordure(' '){}
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

void printBrick(Brick &br, terrain &ter,Color col){
  int hauteur = 0;
  int largeur = 0;
  unsigned int resistance = br.getResistance();
  if(resistance > 0){
    
    while(hauteur < br.getHeight()){
      
      while(largeur < br.getWidth()){
	switch(resistance){
	case 1 :
	  ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,br.getBordure(),WRED);
	  break;
	case 2 :
	  ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,br.getBordure(),WBLUE);
	  break;
	case 3 :
	  ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,br.getBordure(),WYELLOW);
	  break;
	case 4 :
	  ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,br.getBordure(),WGREEN);
	  break;
	case 5 :
	  ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,br.getBordure(),WMAGENTA);
	  break;
	default :
	  ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,br.getBordure(),col);
	}
      
	largeur++;
      }
      hauteur++;
      largeur=0;
    }
  }else{
    remove_Brick(br,ter,WBLACK);
  }
}

void remove_Brick(Brick &br,terrain &ter,Color col){
  int hauteur = 0;
  int largeur = 0;
  unsigned int resistance = br.getResistance();
  
  if(resistance == 0){
    
    while(hauteur < br.getHeight()){
      
      while(largeur < br.getWidth()){
	ter.printInField(br.getPosX()+largeur,br.getPosY()+hauteur,' ',col);
	largeur++;
      }
      hauteur++;
      largeur=0;
    }
  }
  
}

void collision_Ball_Brique(Ball &b,Brick &br){   
    float position_ballX= b.getposX();
    float position_ballY= b.getposY();
    float Vitesse_BallX = b.getVitesseX();
    float Vitesse_BallY = b.getVitesseY();
    int   height        = br.getHeight();
    int   width         = br.getWidth();
    int   posX          = br.getPosX();
    int   posY          = br.getPosY();
    unsigned int   resistance    = br.getResistance();
    
    if(resistance >0){
      if( position_ballY == posY+height && (position_ballX >=posX && position_ballX <= (posX+width)) ){
	b.setVitesseY(Vitesse_BallY *-1);
	br.setResistance(resistance-1);
      }
      
      if(position_ballY == posY-1 && (position_ballX >=posX && position_ballX<= (posX+width))){
	b.setVitesseY(Vitesse_BallY *-1);
	br.setResistance(resistance-1);
      }
      if( position_ballX == posX-1 && (position_ballY >= posY-1 && position_ballY <= posY+height)){
	b.setVitesseX(Vitesse_BallX *-1);
	br.setResistance(resistance-1);
      }
      
      if (position_ballX == posX+width+1 && (position_ballY >= posY-1 && position_ballY <= posY+height)){
	b.setVitesseX(Vitesse_BallX *-1);
	br.setResistance(resistance-1);
      }
    
  }
}
  

