#include<iostream>
#include<string>
#include"option.h"
#include"tabOptions.h"


TabOp::TabOp():nb_option(0),tab(NULL){}
TabOp::TabOp(size_t n):nb_option(n),tab(new Option[n]){}
TabOp::TabOp(const TabOp &T){
  nb_option=T.nb_option;
  tab=new Option[nb_option];
  for(size_t i =0;i<nb_option;i++){
    tab[i]=T.tab[i];
  }
}

Option& TabOp::operator[](size_t i){
  return tab[i];
}

TabOp::~TabOp(){delete [] tab; }

Option* TabOp::getTab()const{return tab;}

void TabOp::addOption(const Option &o){
  if(tab==NULL){
    setNBoption(nb_option+1);
    tab=new Option[nb_option];
    tab[0] = o;
  }else{
    setNBoption(nb_option+1);
    TabOp tmp(nb_option);
    for (size_t i=0;i<nb_option-1;i++){
    tmp[i]=tab[i];
    }
    tmp[nb_option-1]= o;
    delete [] tab;
    tab=tmp.getTab();
  }
}
size_t TabOp::getNBoption()const{ return nb_option;}

void TabOp::printTabOp() const{
  for(size_t i =0 ;i<nb_option;++i){
    tab[i].print();
  }
}
Option::Ido TabOp::getId2Case(const Option &o) const{
  return o.getId();
}
bool TabOp::optionHasArgument(const Option &opt) const{
  if( Type2String(opt.getType()) != "AUCUN")
    return true;
  else
    return false;
}
std::string TabOp::optionArgumentType(const Option &opt) const{
  return Type2String(opt.getType());
}

void TabOp::setNBoption(size_t n){
  nb_option=n;
}
