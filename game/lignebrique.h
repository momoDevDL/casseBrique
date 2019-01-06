#ifndef __LIGNEBRIQUE_H
#define __LIGNEBRIQUE_H
#include "terrain.h"
#include "balle.h"
#include "ensemblebrique.h"

class LigneBrick{
  
 private:
  
  EnsembleBrick *_LB;
  size_t _n;
  int _deb;
  int _padding;
  int _fin;
  int _hauteur;
  int _y

 public:

  LigneBrick();
  LigneBrick(size_t y, terrain &ter);
  LigneBrick(size_t y, int pad, terrain &ter);
  LigneBrick(size_t y, int pad, int deb, terrain &ter);
  LigneBrick(size_t y, EnsembleBrick& EB, terrain &ter);
  LigneBrick(size_t y, int pad, EnsembleBrick& EB, terrain &ter);
  LigneBrick(size_t y, int pad, int deb, EnsembleBrick& EB, terrain &ter);
  LigneBrick(const LigneBrick&);
  LigneBrick(const LigneBrick&, size_t y);
  ~LigneBrick();

  void addY(int);
  void set_Y(int);
  void setResistance(int);
  void set_Deb(int);
  void set_Padding(int);
  void set_Fin(int);
  void set_Hauteur(int);
  void printLigne(terrain t, color c)

  int get_Deb()const;
  int get_Padding()const;
  int get_Fin()const;
  int get_Hauteur()const;
  int get_Y()const;
  
  size_t size()const;

  
};
#endif
