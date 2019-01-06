#include "brique.h"
#include "ensemblebrique.h"
#include "terrain.h"


EnsembleBrick::EnsembleBrick() : _EB(1), _n(1) {
  set_H();
  set_W();
}

EnsembleBrick::EnsembleBrick(size_t n) : _EB(new Brick[n]), _n(n) {
  set_H;
  set_W;
}

EnsembleBrick::EnsembleBrick(const EnsembleBrick& E) : _EB(new Brick[E._n]), _n(E._n) {
  for(size_t i=0;i<_n;i++){
    _EB[i]=E._EB[i];
    _EB[i].set_H(E._EB[i].get_H());
    _EB[i].set_W(E._EB[i].get_W());
  }
}

EnsembleBrick::~EnsembleBrick(){ delete[] _EB;}

void EnsembleBrick::copy(const EnsembleBrick& E1, EnsembleBrick& E2){
  for(size_t i=0;i<_n;i++){
    _EB[i].setPosX((_EB[i].getPosX()) + x);
  }
}

void EnsembleBrick::addX(int x){
  for(size_t i=0;i<_n;i++){
    _EB[i].setPosX((_EB[i].getPosX()) + x);
  }
}

void EnsembleBrick::addY(int y){
  for(size_t i=0;i<_n;i++){
    _EB[i].setPosY((_EB[i].getPosY()) + y);
  }
}

void EnsembleBrick::setPosX(int x){
  
  for(size_t i=1;i<_n;i++){
    _EB[i].setPosX((_EB[0].getPosX()) - (_EB[i].getPosX()));
  }
  
  _EB[0].setPosX(x);
  
  for(size_t j=1;j<_n;j++){
    _EB[j].setPosX((_EB[0].getPosX()) - (_EB[j].getPosX()));
  }
  
}

void EnsembleBrick::setPosY(int y){
  
  for(size_t i=1;i<_n;i++){
    _EB[i].setPosY((_EB[0].getPosY()) - (_EB[i].getPosY()));
  }
  
  _EB[0].setPosY(y);
  
  for(size_t j=1;j<_n;j++){
    _EB[j].setPosY((_EB[0].getPosY()) - (_EB[j].getPosY()));
  }
  
}

void EnsembleBrick::setResistance(int r){
  for(size_t i=0;i<_n;i++){
    _EB[i].setResistance(r);
  }
}

void EnsembleBrick::set_H(){
  unsigned int mini;
  unsigned int maxi;
  
  for(size_t i=0;i<_n;i++){
    maxi=max((_EB[i].getPosY()),maxi);
    mini=min((_EB[i].getPosY()),mini);
  }
  _h= maxi - mini;
}

void EnsembleBrick::set_W(){
  unsigned int mini;
  unsigned int maxi;
  
  for(size_t i=0;i<_n;i++){
    maxi=max((_EB[i].getPosX()),maxi);
    mini=min((_EB[i].getPosX()),mini);
  }
  _w= maxi - mini;
}

void EnsembleBrick::print(terrain t, color c){
  for(size_t i=0;i<_n;i++){
    _EB[i].printBrick(_EB[i],t,c)
  }
}

size_t EnsembleBrick::size()const {return _n;}

int EnsembleBrick::get_H()const{
  
  return _h;
}

int EnsembleBrick::get_W()const{
  
  return _w;
}

void copy(const EnsembleBrick& E1, EnsembleBrick& E2){
  ~EnsembleBrick() E2;
  EnsembleBrick E2(E1);
  }
}
