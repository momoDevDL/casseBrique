#ifndef __TERRAIN_H
#define __TERRAIN_H
#include"window.h"
#include"balle.h"
#include <string>
#include"score.h"

class terrain{
private:
  Window field ;
  Ball b;
  unsigned int life;
public:
  //les constructeurs de terrain par defaut et paramétré
  terrain();
  terrain(Window &field, Ball &b, unsigned int l);
  //accesseur en lecture 
  Color getBkgdColorField()const;
  Color getBordColorField()const;
  int getHeightField()const;
  int getWidthField()const;
  int getYField()const;
  int getXField()const;
  unsigned int getLife()const;
  //accesseurs en ecriture
  void setBkgdColorField(Color);
  void setBordColorField(Color);
  void setHeightField(int H);
  void setWidthField(int W);
  void setBordureField(char c);
  void setLife(unsigned int &l);
  //print un caractere dans la fenetre 
  void printInField(float x,float y,char c,Color col);
  //methodes
  void clearField(); //efface le contenu de la fenetre 
  void printStringInField(int,int,std::string,Color); //print un string dans la fenetre
  void collision_Ball_field(Ball &b, Score &s);
  void remove_Ball(Ball &b);
};

unsigned int heart_Quantity();

#endif
