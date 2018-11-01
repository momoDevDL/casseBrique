#include<iostream>
#include"raquette.h"

//les constructeurs de racket par defaut et paramétré
racket::racket():Surfer(0,0,0,0,'='){}
racket::racket(int h,int w,int x,int y, char bordure):Surfer(h,w,x,y,'='){
  Surfer.setCouleurBordure(WCYAN);
  Surfer.setCouleurFenetre(WRED);
}

//accesseur en lecture 
Color racket::getBkgdColorRacket()const{
  return Surfer.getCouleurFenetre();
}
Color racket::getBordColorRacket()const{
  return Surfer.getCouleurBordure();
}
int racket::getHeightRacket()const{
  return Surfer.getHauteur();
}
int racket::getWidthRacket()const{
return  Surfer.getLargeur();
}
int racket::getYRacket()const{
  return Surfer.getY();
}
int  racket::getXRacket()const{
  return Surfer.getX();
}
//accesseurs en ecriture
void racket::setBkgdColorRacket(Color couleur){
  Surfer.setCouleurFenetre(couleur)
}
void racket::setBordColorRacket(Color couleur){
  Surfer.setCouleurBordure(couleur);
}
void racket::setHeightRacket(int H){
  Surfer.setHauteur(H);
}
void racket::setWidthRacket(int W){
  Surfer.setLargeur(W);
}
void racket::setBordureRacket(char c){
  Surfer.setBordure(c);
}
//methodes
void racket::clearRacket(){
  Surfer.clear();
}
void racket::printStringInRacket(int x,int y,std::string s,Color c){
  Surfer.print(x,y,s,c);
}
