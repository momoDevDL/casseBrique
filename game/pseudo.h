#ifndef __PSEUDO_H_
#define __PSEUDO_H_
#include"window.h"
#include<string>

class Pseudo{

 private:
    //Attribut
    Window interface;
    std::string pseudonyme;

 public:
    //Constructeurs
    Pseudo();
    Pseudo(Window &i, std::string p);
    //Accesseurs en lecture
    Color getBkgdColorPseudo()const;
    Color getBordColorPseudo()const;
    int getHeightPseudo()const;
    int getWidthPseudo()const;
    int getYPseudo()const;
    int getXPseudo()const;
    std::string getPseudonyme()const;

    //Accesseurs en écriture
    void setBkgdColorPseudo(Color);
    void setBordColorPseudo(Color);
    void setHeightPseudo(int H);
    void setWidthPseudo(int W);
    void setBordurePseudo(char c);
    void setPseudonyme(std::string p);

    //Efface le contenu de la fenetre
    void clearField();
    //Print un caractere dans la fenetre 
    void printInPseudo(float x,float y,char c,Color col);
    //Print une chaine de charactere dans la fenetre
    void printStringInPseudo(int x,int y,std::string p,Color col);

};

#endif
