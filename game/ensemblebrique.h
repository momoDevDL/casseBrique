#ifndef __ENSEMBLEBRIQUE_H
#define __ENSEMBLEBRIQUE_H
#include "brique.h"
#include "terrain.h"

class EnsembleBrick {
  
 private:
  
  Brick *_EB;
  size_t _n;
  int _h;
  int _w;
  
 public:

  EnsembleBrick();
  EnsembleBrick(size_t);
  EnsembleBrick(const EnsembleBrick&);
  ~EnsembleBrick();

  void addX(int);
  void addY(int);
  void setPosX(int);
  void setPosY(int);
  void setResistance(int);
  void set_H(int);
  void set_W(int);
  void print(terrain t,color c);
  
  size_t size()const;
  int get_H()const;
  int get_W()const;
 
};

void copy(const EnsembleBrick& E1, EnsembleBrick& E2);
#endif
