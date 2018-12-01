#include<iostream>
#include"terrain.h"
#include"balle.h"
#include"window.h"
using namespace std;
//les constructeurs de terrain par defaut et paramétré
terrain::terrain():field(22,78,0,0,'+'),b('@',9,5,1,1){}
terrain::terrain(Window &fields,Ball &_b):field(fields.getHauteur(),fields.getLargeur(),fields.getX(),fields.getY(),fields.getBordure()),b(_b.getChar(),_b.getposX(),_b.getposY(),_b.getVitesseX(),_b.getVitesseY()){
 
  fields.setCouleurBordure(WRED);
  fields.setCouleurFenetre(WBLACK);
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
void terrain::printInField(int x,int y,char c,Color col){
  field.print(x,y,c,col);
}
void terrain::setBordureField(char c){
  field.setBordure(c);
}

//methodes
void terrain::clearField(){
  field.clear();
}
void terrain::printStringInField(int x,int y,string s,Color c){
  field.print(x,y,s,c);
}

void terrain::collision_Ball_field(Color col){
  size_t H=getHeightField()-2 ;
  size_t L=getWidthField()-2 ;
  size_t Y=getYField();
  size_t X=getXField();
  while(b.getposX()<(float)(X+L) && b.getposY()<(float)(Y+H) && b.getposY()>(float)Y && b.getposX()>(float)X){
    printInField(b.getposX(),b.getposY(),' ',col);
    b.move_Ball();
    printInField(b.getposX(),b.getposY(),b.getChar(),col);

  }
  if(b.getposY()==(float)(Y+H)|| b.getposY()==(float)Y){
    b.setVitesseY(-1*(b.getVitesseY()));
    printInField(b.getposX(),b.getposY(),' ',col);
    b.move_Ball();
    printInField(b.getposX(),b.getposY(),b.getChar(),col);
  }
  if(b.getposX()==(float)(X+L) || b.getposX()==(float)X){
    b.setVitesseX(-1*(b.getVitesseX()));
    printInField(b.getposX(),b.getposY(),' ',col);
    b.move_Ball();
    printInField(b.getposX(),b.getposY(),b.getChar(),col);
  }
}
