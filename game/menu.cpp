#ifndef __MENU_H
#define __MENU_H
#include "window.h"

//constructeurs de menu
menu::menu():Menu(0,0,0,0,'_'){}
menu::menu(int h,int w,int x,int y, char bordure):Menu(h,w,x,y,bordure){}

//accesseur en lecture 
Color menu::getBkgdColorMenu()const{
  return Menu.getCouleurFenetre();
}
Color menu::getBordColorMenu()const{
  return Menu.getCouleurBordure();
}
int menu::getHeightMenu()const{
  return Menu.getHauteur();
}
int menu::getWidthMenu()const{
  return Menu.getLaegeur();
}
int menu::getYMenu()const{
  return Menu.getY();
}
int  menu::getXMenu()const{
  return Menu.getX();
}

//accesseurs en ecriture
void menu::setBkgdColorMenu(Color couleur){
  Menu.setCouleurFenetre(couleur);
}
void menu::setBordColorMenu(Color couleur){
  Menu.setCouleurBordure(couleur);
}
void menu::setHeightMenu(int H){
  Menu.setHauteur(H);
}
void menu::setWidthMenu(int W){
  Menu.setLargeur(W);
}
void menu::setBordureMenu(char c){
  Menu.setBordure(c);
}

//methodes
void menu::clearMenu(){
  Menu.clear();
}
void menu::printStringInMenu(int x,int y,string s,Color c){
  Menu.print(x,y,s,c);
}
