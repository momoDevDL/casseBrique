#include<iostream>
#include"score.h"
#include"window.h"
using namespace std;
//les constructeurs de Score par defaut et paramétré
Score::score():score(0,0,0,0,'+'){}
Score::score(int h,int w,int x,int y, char bordure):score(h,w,x,y,'+'){
  score.setCouleurBordure(WRED);
  score.setCouleurFenetre(WBLACK);
}
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
//accesseurs en ecriture
void Score::setBkgdColorScore(Color couleur){
  this->score.setCouleurFenetre(couleur);
}
void Score::setBordColorScore(Color couleur){
  this->score.setCouleurBordure(couleur);
}
void Score::setHeightScore(int H){
  score.setHauteur(H);
}
void Score::setWidthScore(int W){
  score.setLargeur(W);
}
void Score::setBordureScore(char c){
  score.setBordure(c);
}
//methodes
void Score::clearScore(){
  this->score.clear();
}
void Score::printStringInScore(int x,int y,string s,Color c){
  this->score.print(x,y,s,c);
}
void Score::PrintCharInScore(int x,int y,char s, Color c){
  this->score.print(x,y,s,c)
}
