#include "window.h"
#include "menu.h"
#include <string.h>


//constructeurs de menu
Menu::Menu():menu(30,50,74,2,'='){}
Menu::Menu(Window &w):menu(w.getHauteur(),w.getLargeur(),w.getX(),w.getY(),w.getBordure()){

//accesseur en lecture ColorMenu::getBkgdColorMenu()const{
// w.getCouleurFenetre();
menu.setCouleurFenetre(WRED);
}
Color Menu::getBordColorMenu()const{
  return menu.getCouleurBordure();
}
int Menu::getHeightMenu()const{
  return menu.getHauteur();
}
int Menu::getWidthMenu()const{
  return menu.getLargeur();
}
int Menu::getYMenu()const{
  return menu.getY();
}
int  Menu::getXMenu()const{
  return menu.getX();
}


void Menu::printInMenu(float x,float y,char c, Color cl){
  menu.print(x,y,c,cl);
}
//accesseurs en ecriture
void Menu::setBkgdColorMenu(Color couleur){
  menu.setCouleurFenetre(couleur);
}
//methodes

void Menu::printStringInMenu(int x,int y,std::string s){
 menu.print(x,y,s);
}
