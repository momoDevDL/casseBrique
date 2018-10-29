#include<iostream>
#include"terrain.h"
#include"window.h"
using namespace std;
//les constructeurs de terrain par defaut et paramétré
terrain::terrain():field(0,0,0,0,'+'){}
terrain::terrain(int h,int w,int x,int y, char bordure):field(h,w,x,y,'+'){
  field.setCouleurBordure(WRED);
  field.setCouleurFenetre(WBLACK);
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
  field.setHauteur(H);
}
void terrain::setWidthField(int W){
  field.setLargeur(W);
}
void terrain::setBordureField(char c){
  field.setBordure(c);
}
//methodes
void terrain::clearField(){
  this->field.clear();
}
void terrain::printStringInField(int x,int y,string s,Color c){
  this->field.print(x,y,s,c);
}
