#include "window.h"
#include "menu.h"
#include <string>


//constructeurs de menu
Menu::Menu():menu(0,0,0,0,'_'){}
Menu::Menu(Window &w):menu(w.getHauteur(),w.getLargeur(),w.getX(),w.getY(),w.getBordure()){}

//accesseur en lecture ColorMenu::getBkgdColorMenu()const{
  return w.getCouleurFenetre();
}
Color Menu::getBordColorMenu()const{
  return w.getCouleurBordure();
}
int Menu::getHeightMenu()const{
  return w.getHauteur();
}
int Menu::getWidthMenu()const{
  return w.getLargeur();
}
int Menu::getYMenu()const{
  return w.getY();
}
int  Menu::getXMenu()const{
  return w.getX();
}

//accesseurs en ecriture
void Menu::setBkgdColorMenu(Color couleur){
  w.setCouleurFenetre(couleur);
}
void Menu::setBordColorMenu(Color couleur){
  w.setCouleurBordure(couleur);
}
void Menu::setHeightMenu(int H){
  w.setHauteur(H);
}
void Menu::setWidthMenu(int W){
  w.setLargeur(W);
}
void Menu::setBordureMenu(char c){
  w.setBordure(c);
}

//methodes
}
void Menu::printStringInMenu(int x,int y,string s){
  w.print(x,y,s,c);
}
