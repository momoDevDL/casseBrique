#include<iostream>
#include"option.h"
using namespace std;
//les constructeurs de terrain par defaut et paramétré
Option::Option():id(Option::NONE),type(AUCUN),raccourci(""),description("UNKNOWN"){}
Option::Option(Ido identifiant,Type t,string racc,string descr):id(identifiant),type(t),raccourci(racc),description(descr){}

Option& Option::operator=(const Option &opt){
  if(this != &opt){
  description = opt.getdescription();
  id = opt.getId();
  type = opt.getType();
  raccourci = opt.getraccourci();
  }
  return *this;
  
}
//accesseur en lecture 
Option::Ido Option::getId()const{
  return id;
}

string  Option::getraccourci()const{
  return raccourci;
}
string  Option::getdescription()const{
  return description;
}
Option::Type Option::getType()const{
  return type;
}

  //accesseurs en ecriture
void Option::setId(Option::Ido ID){
  id=ID;
}

void Option::setRaccourci(const string &r){
  raccourci=r;
}
void Option::setDescription(const string &d){
  description=d;
}
void Option::setType(Type t){
  type=t;
}

  //afficher l'option
void Option::print()const{
  cout<<ID2String(id)<<": ( "<<raccourci<<" ) "<<Type2String(type)<<" :"<<endl;
  cout<<"----Description----"<<endl;
  cout<<description<<endl;
  cout<<"/=--------------------=/"<<endl;
}


//transformer mon type en string
string Type2String(Option::Type t){
  string type;
  switch(t){
  case Option::ENTIER:
    type="<ENTIER>"; break;
  case Option::CHARACTER:
    type="<CHARACTER>"; break;
  case Option::AUCUN:
    type="<AUCUN>"; break;
  case Option::STRING:
    type="<STRING>"; break; 
  }
  return type;
}

//transformer mon id en
string ID2String(const Option::Ido Id){
  string ID;
  switch(Id){
  case Option::HELP:
    ID="HELP"; break;
  case Option::VERSION:
    ID="VERSION"; break;
  case Option::AUTHORS:
    ID="AUTHORS"; break;
  case Option::NBR_BRICK :
    ID="NBR_BRICK"; break;
  case Option::NONE:
    ID="UKNOWN"; break; 
  }
  return ID;
}
