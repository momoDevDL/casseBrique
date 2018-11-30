#ifndef __MENU_H
#define __MENU_H
#include "window.h"
#include<string>
class menu{
 private:
  Window Menu ;
 public :
  //constructeurs de menu
  menu();
  menu(int h,int w,int x,int y, char bordure);
  
  //accesseur en lecture 
  Color getBkgdColorMenu()const;
  Color getBordColorMenu()const;
  int getHeightMenu()const;
  int getWidthMenu()const;
  int getYMenu()const;
  int  getXMenu()const;
  
  //accesseurs en ecriture
  void setBkgdColorMenu(Color);
  void setBordColorMenu(Color);
  void setHeightMenu(int H);
  void setWidthMenu(int W);
  void setBordureMenu(char c);
  
  //methodes
  void clearMenu();
  void printStringInMenu(int ,int ,std::string,Color);
};

#endif
