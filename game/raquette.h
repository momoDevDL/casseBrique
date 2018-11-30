#ifndef __RAQUETTE_h
#define __RAQUETTE_h
#include<string>
class racket{
 private:
  int height;
  int width;
  int posX;
  int posY;
  char bordureUP;
  char bordure1Side;
  char bordure2Side;
  
 public :
  //les constructeurs de racket par defaut et paramétré
  racket();
  racket(int h,int w,int x,int y);
  //accesseur en lecture 
  int getHeightRacket()const;
  int getWidthRacket()const;
  int getYRacket()const;
  int getXRacket()const;
  //accesseurs en ecriture
  void setHeightRacket(int H);
  void setWidthRacket(int W);
  void setPosXRacket(int X);
  void setPosYRacket(int Y);

  
};

#endif

