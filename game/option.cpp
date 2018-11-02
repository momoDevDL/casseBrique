#include<iostream>
#include"option.h"
using namespace std;
//les constructeurs de terrain par defaut et paramétré
Option::Option():identifiant(Option::NONE),_type(AUCUN),nom(""),raccourci(""),description("UKNOWN"){}
  Option::Option(Ido identifiant,Type type,string _nom,string racc,string descr):identifiant(identifiant),_type(type),nom(_nom),raccourci(racc),description(descr){}

//accesseur en lecture 
Ido Option::getId(){
  return Ido;
}const
string  Option::getnom(){
  return nom;
}const
string  Option::getraccourci(){
  return raccourci;
}const
string  Option::getdescrption(){
  return description;
}const
Type Option::getType(){
  return Type;
}const

  //accesseurs en ecriture
void Option::setId(Ido id){
  this->Ido=id;
}
void Option::setNom(const &s){
  this-nom=s;
}
void Option::setRaccourci(const string &r){
  this->raccourci=r;
}
void Option::setDescription(const string &d){
  this->description=d;
}
void Option::setType(Type t){
  this->type=t;
}

  //afficher l'option
void Option::print(){
  cout<<ID2String(Ido)<<" ( "<<raccourci<<" ) "<<Type2String(_type)<<" :"<<endl;
  cout<<"----"<<descrption<<"----"<<endl;
}const


//transformer mon type en string
string Type2String(Option::Type t){
  string t_ype;
  switch(t){
  case Option::ENTIER:
    t_ype="<ENTIER>"; break;
  case Option::CHARACTER:
    t_ype="<CHARACTER>"; break;
  case Option::AUCUN:
    t_ype="<AUCUN>"; break;
  case Option::STRING:
    t_ype="<STRING>"; break; 
  }
  return t_ype;
}

//transformer mon id en
string ID2String(Option::Ido Id){
  string ID;
   switch(Id){
  case Option::HELP:
   ID="HELP"; break;
  case Option::VERSION:
    ID="VERSION"; break;
  case Option::AUTHORS:
    ID="AUTHORS"; break;
  case Option::NONE:
    ID="UKNOWN"; break; 
  }
  return ID;
}
