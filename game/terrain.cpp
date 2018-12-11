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

//methodes
void terrain::clearField(){
  field.clear();
}
void terrain::printStringInField(int x,int y,string s,Color c){
  field.print(x,y,s,c);
}

void terrain::collision_Ball_field(Ball &b){
  int  H=getHeightField();
  int  L=getWidthField();
  int  Y=getYField()-2;
  int  X=getXField()-2;
  
  // bool collision_Bordure=false;
  // float tmp= 0.1;
  // float timelapseY= b.getVitesseY();
  /* if(b.getposX()<(X+L) && b.getposY()<(Y+H) && b.getposY()>Y && b.getposX()>X){
    printInField(b.getposX(),b.getposY(),' ',col);
    b.move_Ball();
    printInField(b.getposX(),b.getposY(),b.getChar(),col);
  }*/

  
  
  if(b.getposY()==(Y+H)-1 || b.getposY()==Y){
    b.setVitesseY(-1*(b.getVitesseY()));
    //b.setVitesseY(0);
    // cout<<b.getVitesseY();
    //cout<<"fuuuuck";
    // collision_Bordure=true;
    // printInField(b.getposX(),b.getposY(),' ',col);
    //b.move_Ball();
    // printInField(b.getposX(),b.getposY(),b.getChar(),col);
  }
  if(b.getposX()==(X+L)-1|| b.getposX()==X){
    b.setVitesseX(-1*(b.getVitesseX()));
    //  collision_Bordure=true;
    // printInField(b.getposX(),b.getposY(),' ',col);
    //b.move_Ball();
    //  printInField(b.getposX(),b.getposY(),b.getChar(),col);
    }

  if(b.getposX()==X && b.getposY()==Y){
     b.setVitesseX(-1*(b.getVitesseX()));
     b.setVitesseY(-1*(b.getVitesseY()));
  }
  if(b.getposX()==X && b.getposY()==Y){
     b.setVitesseX(-1*(b.getVitesseX()));
     b.setVitesseY(-1*(b.getVitesseY()));
  }
  //return collision_Bordure;
}


