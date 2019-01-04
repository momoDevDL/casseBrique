#ifndef __TABOPTION_H
#define __TABOPTION_H

#include "option.h"
#include<string>

class TabOp{
 private :
  size_t nb_option ;
  Option *tab;

 public :
  TabOp();
  TabOp(size_t);
  TabOp(const TabOp  &t);
  ~TabOp();
  Option& operator[](size_t i);
  void addOption(const Option &o);
  size_t getNBoption()const;
  Option* getTab()const;
  void printTabOp() const;
  Option::Ido getId2Case(const Option &o) const;
  bool optionHasArgument(const Option &opt) const;
  std::string optionArgumentType(const Option &opt) const;

  void setNBoption(size_t);

  

};
#endif 
