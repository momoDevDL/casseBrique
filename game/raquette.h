#ifndef __RAQUETTE_h
#define __RAQUETTE_h
#include "terrain.h"
#include <string>
class racket{
 private:
 unsigned int height;
 unsigned int width;
 unsigned int posX;
 unsigned int posY;
 char bordureUP;
 char bordure1Side;
 char bordure2Side;
  
 public :
  //les constructeurs de racket par defaut et paramétré
  racket();
  racket(unsigned int w,unsigned int x,unsigned int y);
  
  //accesseur en lecture 
  unsigned int getHeightRacket()const;
  unsigned int getWidthRacket()const;
  unsigned int getYRacket()const;
  unsigned int getXRacket()const;
  char getbordureUP()const;
  char getbordure1Side()const;
  char getbordure2Side()const;
  
  //accesseurs en ecriture
  void setHeightRacket(unsigned int H);
  void setWidthRacket(unsigned int W);
  void setPosXRacket(unsigned int X);
  void setPosYRacket(unsigned int Y);
  void setBordureUP(char BU);
  void setBordure1Side(char B1S);
  void setBordure2Side(char B2S);

  // methodes
  
};

void printRacket(racket &r,terrain &t);
#endif

