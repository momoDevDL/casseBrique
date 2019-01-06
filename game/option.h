#ifndef __OPTION_H
#define __OPTION_H
#include <string>
class Option{
  
 public:
enum Ido{
  HELP,
  VERSION,
  AUTHORS,
  NBR_BRICK,
  CONFIG,
  NONE
};

enum Type{
  ENTIER,
  CHARACTER,
  STRING,
  AUCUN
};

 private:
  Ido id;
  Type type ;
  std::string raccourci;
  std::string description;
 public:
  //constructeur par defaut
  Option();
  //constructeurs paramétré
  Option(Ido,Type,std::string,std::string);

  Option& operator=(const Option &o);
  //accesseurs en lecture
  Option::Ido  getId()const;
  std::string  getraccourci()const;
  std::string getdescription()const;
  Type getType()const;

  //accesseurs en ecriture
  void setId(Ido);
  void setRaccourci(const std::string &s);
  void setDescription(const std::string &s);
  void setType(Type);

  //afficher l'option
  void print() const;
};


//transformer mon type en string
std::string Type2String(Option::Type);

//transformer mon id en string
std::string ID2String( Option::Ido);
#endif
