#include<iostream>
#include"terrain.h"
#include"balle.h"
#include"window.h"
#include"fstream"
#include"sstream"
#include<vector>
#include"triTabString.h"
#include"posPseudo.h"

struct Classement{
    std::string pseudo;
    std::string position;

};

//les constructeurs de terrain par defaut et paramétré
terrain::terrain():field(22,78,0,0,'+'),b('@',9,5,1,1,0),life(0){}
terrain::terrain(Window &fields,Ball &_b, unsigned int l):field(fields.getHauteur(),fields.getLargeur(),fields.getX(),fields.getY(),fields.getBordure()),b(_b.getChar(),_b.getposX(),_b.getposY(),_b.getVitesseX(),_b.getVitesseY(),_b.getDeplacement()),life(l){
 
  //fields.setCouleurBordure(WRED);
  //fields.setCouleurFenetre(BWHITE);
  //fields.print(_b.getposX(),_b.getposY(),_b.getChar());
}
//accesseur en lecture 
Color terrain::getBkgdColorField()const{
  return field.getCouleurFenetre();
}
Color terrain::getBordColorField()const{
  return field.getCouleurBordure();
}
int terrain::getHeightField()const{
  return field.getHauteur();
}
int terrain::getWidthField()const{
  return field.getLargeur();
}
int terrain::getXField()const{
  return field.getX();
}
int terrain::getYField()const{
  return field.getY();
}
unsigned int terrain::getLife()const{
  return life;
}
//accesseurs en ecriture
void terrain::setBkgdColorField(Color couleur){
  field.setCouleurFenetre(couleur);
}
void terrain::setBordColorField(Color couleur){
  field.setCouleurBordure(couleur);
}
void terrain::printInField(float x,float y,char c,Color col){
  field.print(x,y,c,col);
}
void terrain::setBordureField(char c){
  field.setBordure(c);
}

void terrain::setLife(unsigned int &l){
  this->life=l;
}

void terrain::clearField(){
  field.clear();
}
void terrain::printStringInField(int x,int y,std::string s,Color c){
  field.print(x,y,s,c);
}

void terrain::remove_Ball(Ball &b){
  printInField(b.getposX(),b.getposY(),' ',WBLACK);
}


void terrain::collision_Ball_field(Ball &b, Score &s){
  int  H=getHeightField();
  int  L=getWidthField();
  int  Y=getYField()-2;
  int  X=getXField()-2;

  if(b.getposY()==(Y+H)-2 || b.getposY()==Y){
    b.setVitesseY(-1*(b.getVitesseY()));
  

    if(b.getposY()==(Y+H)-2){
      life--;
      b.setposX(37);
      b.setposY(36);
      b.setDeplacement(1);
    }


    if(life==0){

      s.printStringInScore(0,6,"Classement des 30 meilleurs joueurs\n",BGREEN);

      /* OUVERTURE FLUX DE ECRITURE */
      std::ofstream myout;
      myout.seekp(0,std::ios::beg);
      myout.open("leaderboard.txt",std::ios::app);
      std::ostringstream n;
      n << s.getValueScore();
      std::string score = n.str();
      std::string pseudo = s.getPseudo() + " - Score : " + score + "\n";
      myout << pseudo;
      myout.close();  
      /* OUVERTURE FLUX DE ECRITURE */

      /* CLASSEMENT */
    std::ifstream myin2;
    myin2.open("leaderboard.txt");
    int i=0;
    std::string ligne;
    while(getline(myin2,ligne)){
        i++;
    }

    std::vector<Classement> c1(i);
    myin2.clear();
    myin2.seekg(0,std::ios::beg);

    std::string score2;

    for(int j=0; j<=i-1; j++){
        
        std::string pseudonyme;
        std::string rang;

        bool apres_egale = false;

        getline(myin2,ligne);

        unsigned int k=0;
        while(ligne[k]!=' '){
            pseudonyme += ligne[k];
            k++;
        }

        c1[j].pseudo = pseudonyme;

        k=0;
      
        while(k<=ligne.length()-1){

            if(ligne[k]==':'){
                apres_egale=true;
                k++;
            }

            if(apres_egale)
                rang += ligne[k];

            if(k==ligne.length()-1)
                c1[j].position = rang;

            k++;
        }
      
    }
    myin2.close();
    /* CLASSEMENT */

      printStringInField(field.getLargeur()/2 - 3,field.getHauteur()/2,"GAME OVER",WYELLOW);
      b.setDeplacement(0); 

      /* AFFICHAGE SCORE */
      std::string tab1[i];
      std::string tab2[i];

      for(int k2=0; k2<=i-1; k2++){
        tab1[k2]=c1[k2].position;
        tab2[k2]=c1[k2].pseudo;
      }

      triTab(tab1,tab2,i);

      int i2=7;
      int i3=0;
      int cpt=0;

      while(cpt<=i-1 && i3<30){

        std::stringstream i2s;
        i2s << i3+1;
        std::string i3bis = i2s.str();

        if(cpt==posPseudo(tab2,i,s)){
          s.printStringInScore(0,i2,i3bis+"."+tab2[cpt]+" - Score : "+tab1[cpt],BBLUE);
          i2++;
          i3++;
          cpt++;
        }
        else{
          s.printStringInScore(0,i2,i3bis+"."+tab2[cpt]+" - Score : "+tab1[cpt],BGREEN);
          i2++;
          cpt++;
          i3++;
        }
      }
      /* AFFICHAGE SCORE */
         
    }
  }

  if(b.getposX()==(X+L)-1|| b.getposX()==X){
    b.setVitesseX(-1*(b.getVitesseX()));
  }

  if(b.getposX()==X-1 && b.getposY()==Y-1){
     b.setVitesseX(-1*(b.getVitesseX()));
     b.setVitesseY(-1*(b.getVitesseY()));
  }
  if(b.getposX()==X+L && b.getposY()==Y+H){
     b.setVitesseX(-1*(b.getVitesseX()));
     b.setVitesseY(-1*(b.getVitesseY()));
  }
}








