#include"pseudo.h"
#include"window.h"
#include<string>

Pseudo::Pseudo():interface(22,78,0,0,'+'),pseudonyme("user"){};
Pseudo::Pseudo(Window &i, std::string p):interface(i.getHauteur(),i.getLargeur(),i.getX(),i.getY(),i.getBordure()),pseudonyme(p){};

//Accesseurs en lecture
Color Pseudo::getBkgdColorPseudo()const{
  return interface.getCouleurFenetre();
}
Color Pseudo::getBordColorPseudo()const{
  return interface.getCouleurBordure();
}
int Pseudo::getHeightPseudo()const{
  return interface.getHauteur();
}
int Pseudo::getWidthPseudo()const{
  return interface.getLargeur();
}
int Pseudo::getXPseudo()const{
  return interface.getX();
}
int Pseudo::getYPseudo()const{
  return interface.getY();
}
std::string Pseudo::getPseudonyme()const{
    return pseudonyme;
}

//Accesseurs en écriture
void Pseudo::setBkgdColorPseudo(Color couleur){
    interface.setCouleurFenetre(couleur);
}
void Pseudo::setBordColorPseudo(Color couleur){
    interface.setCouleurBordure(couleur);
}
void Pseudo::setBordurePseudo(char c){
    interface.setBordure(c);
}
void Pseudo::setPseudonyme(std::string p){
    pseudonyme = p;
}

void Pseudo::printInPseudo(float x,float y,char c,Color col){
    interface.print(x,y,c,col);
}
void Pseudo::printStringInPseudo(int x,int y,std::string p,Color col){
    interface.print(x,y,p,col);
}
void Pseudo::clearField(){
    interface.clear();
}
