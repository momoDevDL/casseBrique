#include<iostream>
#include"terrain.h"
#include"balle.h"
#include"window.h"
using namespace std;
//les constructeurs de terrain par defaut et paramétré
terrain::terrain():field(22,78,0,0,'+'),b('@',9,5,1,1){}
terrain::terrain(Window &fields,Ball &_b):field(fields.getHauteur(),fields.getLargeur(),fields.getX(),fields.getY(),fields.getBordure()),b(_b.getChar(),_b.getposX(),_b.getposY(),_b.getVitesseX(),_b.getVitesseY()){
 
  //fields.setCouleurBordure(WRED);
  //fields.setCouleurFenetre(BWHITE);
  //fields.print(_b.getposX(),_b.getposY(),_b.getChar());
}
//accesseur en lecture 
Color terrain::getBkgdColorField()const{
  return field.getCouleurFenetre();
}
Color terrain::getBordColorField()const{
  return field.getCouleurBordure();
}
int terrain::getHeightField()const{
  return field.getHauteur();
}
int terrain::getWidthField()const{
  return field.getLargeur();
}
int terrain::getXField()const{
  return field.getX();
}
int terrain::getYField()const{
  return field.getY();
}
//accesseurs en ecriture
void terrain::setBkgdColorField(Color couleur){
  field.setCouleurFenetre(couleur);
}
void terrain::setBordColorField(Color couleur){
  field.setCouleurBordure(couleur);
}
void terrain::printInField(float x,float y,char c,Color col){
  field.print(x,y,c,col);
}
void terrain::setBordureField(char c){
  field.setBordure(c);
}

void terrain::clearField(){
  field.clear();
}
void terrain::printStringInField(int x,int y,string s,Color c){
  field.print(x,y,s,c);
}

void terrain::remove_Ball(Ball &b){
  printInField(b.getposX(),b.getposY(),' ',WBLACK);
}


void terrain::collision_Ball_field(Ball &b){
  int  H=getHeightField();
  int  L=getWidthField();
  int  Y=getYField()-2;
  int  X=getXField()-2;
  
  if(b.getposY()==(Y+H)-2 || b.getposY()==Y){
    b.setVitesseY(-1*(b.getVitesseY()));
    if(b.getposY()==(Y+H)-2){
      b.setVitesseX(0);
      b.setVitesseY(0);
      printStringInField(field.getLargeur()/2 - 3,field.getHauteur()/2,"GAME OVER",WYELLOW);
      }
  }
  if(b.getposX()==(X+L)-1|| b.getposX()==X){
    b.setVitesseX(-1*(b.getVitesseX()));
  }

  if(b.getposX()==X-1 && b.getposY()==Y-1){
     b.setVitesseX(-1*(b.getVitesseX()));
     b.setVitesseY(-1*(b.getVitesseY()));
  }
  if(b.getposX()==X+L && b.getposY()==Y+H){
     b.setVitesseX(-1*(b.getVitesseX()));
     b.setVitesseY(-1*(b.getVitesseY()));
  }
}




