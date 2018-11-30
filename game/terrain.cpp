#include<iostream>
#include"terrain.h"
#include"balle.h"
#include"window.h"
using namespace std;
//les constructeurs de terrain par defaut et paramétré
terrain::terrain():field(10,10,55,10,'+'),b('@',9,5,1){}
terrain::terrain(Window &fields,Ball &_b):field(fields.getHauteur(),fields.getLargeur(),fields.getX(),fields.getY(),fields.getBordure()),b('@',_b.getposX(),_b.getposY(),_b.getVitesse()){
 
  fields.setCouleurBordure(WRED);
  fields.setCouleurFenetre(WBLACK);
  fields.print(_b.getposX(),_b.getposY(),'@');
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
void terrain::printInField(int x,int y,char c){
  field.print(x,y,c);
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

void terrain::collision_Ball_field(){
  size_t H=getHeightField() ;
  size_t L=getWidthField() ;
  size_t Y=getYField();
  size_t X=getXField();
  while((b.getposX()>X && b.getposY()>Y) || (b.getposX()<X+L && b.getposY()<Y+H) ){
    printInField(b.getposX(),b.getposY(),' ');
    b.move_Ball();
    printInField(b.getposX(),b.getposY(),'@');
  }
  b.setVitesse(-1*(b.getVitesse()));
}
