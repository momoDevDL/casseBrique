#include<iostream>
#include"score.h"
#include"window.h"
#include<fstream>
using namespace std;
//les constructeurs de Score par defaut et paramétré
Score::Score():score(0,0,0,0,' '), value(0), pseudo("Invité"){}
Score::Score(int h,int w, int x, int y, char c, unsigned int s, string p) : score(h,w,x,y,c), value(0), pseudo(p){}


//accesseur en lecture 
Color Score::getBkgdColorScore()const{
  return this->score.getCouleurFenetre();
}
Color Score::getBordColorScore()const{
  return this->score.getCouleurBordure();
}
int Score::getHeightScore()const{
  return this->score.getHauteur();
}
int Score::getWidthScore()const{
  return this->score.getLargeur();
}
int Score::getXScore()const{
  return this->score.getX();
}
int Score::getYScore()const{
  return this->score.getY();
}
unsigned int Score::getValueScore()const{
  return this->value;
}
string Score::getPseudo()const{
  return this->pseudo;
}



//accesseurs en ecriture
void Score::setBkgdColorScore(Color couleur){
  this->score.setCouleurFenetre(couleur);
}
void Score::setBordColorScore(Color couleur){
  this->score.setCouleurBordure(couleur);
}
/*
void Score::setHeightScore(int H){
  score.setHauteur(H);
}
void Score::setWidthScore(int W){
  score.setLargeur(W);
}
*/
void Score::setBordureScore(char c){
  score.setBordure(c);
}
void Score::setValueScore(int s){
  this->value += s;
}
void Score::setPseudo(std::string p){
  this->pseudo = p;
}

//methodes
void Score::clearScore(){
  this->score.clear();
}
void Score::printStringInScore(int x, int y, string p, Color c){
  this->score.print(x,y,p,c);
}
void Score::printCharInScore(int x,int y,char s, Color c){
  this->score.print(x,y,s,c);
}


