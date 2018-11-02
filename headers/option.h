#ifndef __OPTION_H
#define __OPTION_H
#include <string>
class Option{
 public:
enum Ido{
  HELP,
  VERSION,
  AUTHORS,
  NONE,
  NB_IDO
};

enum Type{
  ENTIER,
  CHARACTER,
  STRING,
  AUCUN,
  NB_TYPE
};

 private:
  Ido identifiant;
  Type _type ;
  std::string nom,raccourci,description;
 public:
  //constructeur par defaut
  Option();
  //constructeurs paramétré
  Option(Ido,Type,std::string,std::string,std::string);
  //accesseurs en lecture
  Ido  getId()const;
  std::string  getnom()const;
  std::string  getraccourci()const;
  std::string  getdescrption()const;
  Type getType()const;

  //accesseurs en ecriture
  void setId(Ido);
  void setNom(const &std::string);
  void setRaccourci(const &std::string);
  void setDescription(const &std::string);
  void setType(Type);

  //afficher l'option
  void print() const;
};


//transformer mon type en string
std::string Type2String(Option::Type);
//transformer mon id en string
std::string ID2String(Option::Ido);
