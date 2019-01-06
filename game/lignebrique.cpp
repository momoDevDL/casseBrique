#include "terrain.h"
#include "balle.h"
#include "ensemblebrique.h"
#include "lignebrique.h"

LigneBrick::LigneBrick() : _LB(1), _n(1) {
  
  _deb = 2;
  _fin = 2;
  _padding = 2;
  _hauteur = _LB[0].get_H + 1;
  _y=0;
}

LigneBrick::LigneBrick(size_t y, terrain &ter){
  
  _deb = 2;
  _fin = 2;
  _padding = 2;
  _hauteur = 2;
  _y = y;
  
  unsigned int placement = _deb;
  unsigned int nb = 0;
  unsigned int reste = 0;
  
  nb = _padding +(ter.getWidthField()-(_fin)-(_deb))/11;
  reste = _padding +(ter.getWidthField()-(_fin)-(_deb))%11;
  
  _LB = new EnsembleBrick[nb];
  _n = nb;
  
  placement += reste/2;
  
  for(size_t i=0;i<nb;i++){
    _LB[i].setPosY(_y);
    _LB[i].setPosX(placement);
    placement += _LB[i].get_W();
    placement += _padding;
  }
}

LigneBrick::LigneBrick(size_t y, int pad, terrain &ter){
  
  _deb = 2;
  _fin = 2;
  _padding = pad;
  _hauteur = 2;
  _y = y;
  
  unsigned int placement = _deb;
  unsigned int nb = 0;
  unsigned int reste = 0;
  
  nb = _padding +(ter.getWidthField()-(_fin)-(_deb))/11;
  reste = _padding +(ter.getWidthField()-(_fin)-(_deb))%11;
  
  _LB = new EnsembleBrick[nb];
  _n = nb;
  
  placement += reste/2;
  
  for(size_t i=0;i<nb;i++){
    _LB[i].setPosY(_y);
    _LB[i].setPosX(placement);
    placement += _LB[i].get_W();
    placement += _padding;
  }
}


LigneBrick::LigneBrick(size_t y, int pad, int deb, terrain &ter){
  
  _deb = deb;
  _fin = deb;
  _padding = pad;
  _hauteur = 2;
  _y = y;
  
  unsigned int placement = _deb;
  unsigned int nb = 0;
  unsigned int reste = 0;
  
  nb = _padding +(ter.getWidthField()-(_fin)-(_deb))/11;
  reste = _padding +(ter.getWidthField()-(_fin)-(_deb))%11;
  
  _LB = new EnsembleBrick[nb];
  _n = nb;
  
  placement += reste/2;
  
  for(size_t i=0;i<nb;i++){
    _LB[i].setPosY(_y);
    _LB[i].setPosX(placement);
    placement += _LB[i].get_W();
    placement += _padding;
  }
}


LigneBrick::LigneBrick(size_t y, EnsembleBrick& EB,  terrain &ter){

  _deb = 2;
  _fin = 2;
  _padding = 2;
  _hauteur = EB._h + 1;
  _y = y;
  
  unsigned int placement = _deb;
  unsigned int nb = 0;
  unsigned int reste = 0;
  
  nb = _padding +(ter.getWidthField()-(_fin)-(_deb))/11;
  reste = _padding +(ter.getWidthField()-(_fin)-(_deb))%11;
  
  _n = nb;
  _LB = new EnsembleBrick[nb];
  for(size_t k=0;k<nb;k++){
    copy(EB,_LB[k]);
  }
  
  placement += reste/2;
  
  for(size_t i=0;i<nb;i++){
    _LB[i].setPosY(_y);
    _LB[i].setPosX(placement);
    placement += _LB[i].get_W();
    placement += _padding;
  }
}

LigneBrick::LigneBrick(size_t y, int pad, EnsembleBrick& EB,  terrain &ter){

  _deb = 2;
  _fin = 2;
  _padding = pad;
  _hauteur = EB._h + 1;
  _y = y;
  
  unsigned int placement = _deb;
  unsigned int nb = 0;
  unsigned int reste = 0;
  
  nb = _padding +(ter.getWidthField()-(_fin)-(_deb))/11;
  reste = _padding +(ter.getWidthField()-(_fin)-(_deb))%11;
  
  _n = nb;
  _LB = new EnsembleBrick[nb];
  for(size_t k=0;k<nb;k++){
    copy(EB,_LB[k]);
  }
  
  placement += reste/2;
  
  for(size_t i=0;i<nb;i++){
    _LB[i].setPosY(_y);
    _LB[i].setPosX(placement);
    placement += _LB[i].get_W();
    placement += _padding;
  }
}

LigneBrick::LigneBrick(size_t y, int pad, int deb,  EnsembleBrick& EB,  terrain &ter){

  _deb = deb;
  _fin = deb;
  _padding = pad;
  _hauteur = EB._h + 1;
  _y = y;
  
  unsigned int placement = _deb;
  unsigned int nb = 0;
  unsigned int reste = 0;
  
  nb = _padding +(ter.getWidthField()-(_fin)-(_deb))/11;
  reste = _padding +(ter.getWidthField()-(_fin)-(_deb))%11;
  
  _n = nb;
  _LB = new EnsembleBrick[nb];
  for(size_t k=0;k<nb;k++){
    copy(EB,_LB[k]);
  }
  
  placement += reste/2;
  
  for(size_t i=0;i<nb;i++){
    _LB[i].setPosY(_y);
    _LB[i].setPosX(placement);
    placement += _LB[i].get_W();
    placement += _padding;
  }
}

LigneBrick::LigneBrick(const LigneBrick& E) : _LB(new Brick[E._n]), _n(E._n) {
  for(size_t i=0;i<_n;i++){
    copy(E._LB[i],_LB[i]);
    _LB[i]._deb = E._LB[i]._deb;
    _LB[i]._padding = E._LB[i]._padding;
    _LB[i]._fin = E._LB[i]._fin;
    _LB[i]._hauteur = E._LB[i]._hauteur;
    _LB[i]._y = E._LB[i]._y;
  }
}

LigneBrick::LigneBrick(const LigneBrick& E, size_t y) : _LB(new Brick[E._n]), _n(E._n) {
  for(size_t i=0;i<_n;i++){
    copy(E._LB[i],_LB[i]);
    _LB[i]._deb = E._LB[i]._deb;
    _LB[i]._padding = E._LB[i]._padding;
    _LB[i]._fin = E._LB[i]._fin;
    _LB[i]._hauteur = E._LB[i]._hauteur;
    _LB[i]._y = y;
  }
}

LigneBrick::~LigneBrick(){ delete[] _LB;}


void LigneBrick::addY(int y){
  for(size_t i=0;i<_n;i++){
    _LB[i].addY(y);
  }

}

void LigneBrick::set_Y(int y){
  for(size_t i=0;i<_n;i++){
    _LB[i].set_Y(y);
  }
 
}

void LigneBrick::setResistance(int r){
  for(size_t i=0;i<_n;i++){
    _LB[i].setResistance(r);
  }
}

void LigneBrick::set_Deb(int d){
  _deb = d;
}

void LigneBrick::set_Padding(int p){
  _padding = p;
}

void LigneBrick::set_Fin(int f){
  _fin = f;
}

void LigneBrick::set_Hauteur(int h){
  _hauteur = h;
}

void LigneBrick::printLigne(terrain t, color c){
  
  for(size_t i=0;i<_n;i++){
    _LB[i].print(t,c)
  }
}

int LigneBrick::get_Deb()const {return _deb;}

int LigneBrick::get_Padding()const {return _padding;}

int LigneBrick::get_Fin()const {return _fin;}

int LigneBrick::get_Hauteur()const {return _hauteur;}

int LigneBrick::get_Y()const {return _y;}

size_t LigneBrick::size()const {return _n;}

  
