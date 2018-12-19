#ifndef __BALLE_H
#define __BALLE_H
#include <string>

class Ball{
private:
  char c ;
  float posX ;
  float posY;
  float vitesseX;
  float vitesseY;
  unsigned int deplacement;
public:
  //les constructeurs de terrain par defaut et paramétré
  Ball();
  Ball(char car,float x,float y,float vx,float vy,unsigned int d);
  //accesseur en lecture 
  float getposX()const;
  float getposY()const;
  float getVitesseX()const;
  float getVitesseY()const;
  char getChar()const;
  unsigned int getDeplacement()const;
  //accesseurs en ecriture
  void setposX(float);
  void setposY(float);
  void setVitesseX(float);
  void setVitesseY(float);
  void setDeplacement(int);
  //methodes
  
  void move_Ball();
  void remove_Ball();
  
  //void printBall(terrain &ter);
  
  
};


#endif
