#include<iostream>
#include"terrain.h"
#include"window.h"
//les constructeurs de terrain par defaut et paramétré
terrain::terrain():field(0,0,0,0,'+'){};
terrain::terrain(int h,int w,int x,int y, char bordure):field(h,w,x,y,'+'){
  field.colorwin=WRED;
  field.colorframe=WBLACK;
  field.frame=newwin(h+2,w+2,y,x);
  field.win=subwin(field.frame,h,w,y+1,x+1);
  wbkgd(field.frame,COLOR_PAIR(field.colorwin));
  wbkgd(field.win,COLOR_PAIR(field.colorframe));
  wborder(field.frame, c,c,c,c,c,c,c,c);
  wattron(field.win,COLOR_PAIR(field.colorwin));
  wattron(field.frame,COLOR_PAIR(field.colorframe));
  field.update();
}
//accesseur en lecture 
Color terrain::getBkgdColorField()const{
  return this->field.getCouleurFenetre();
}
Color terrain::getBordColorField()const{
  return this->field.getCouleurBordure();
}
int terrain::getHeightField()const{
  return this->field.getHauteur();
}
int terrain::getWidthField()const{
  return this->field.getLargeur();
}
int terrain::getXField()const{
  return this->field.getX();
}
int terrain::getYField()const{
  return this->field.getY();
}
//accesseurs en ecriture
void terrain::setBkgdColorField(Color couleur){
  this->field.setCouleurFenetre(couleur);
}
void terrain::setBordColorField(Color couleur){
  this->field.setCouleurBordure(couleur);
}
void terrain::setHeightField(int H){
  field.height=H;
}
void terrain::setWidthField(int W){
  field.width=W;
}
void terrain::setBordureField(char c){
  field.bord=c;
}
//methodes
void terrain::clearField(){
  this->field.clear();
}
//void terrain::printStringInField()
//void terrain::updateField();

