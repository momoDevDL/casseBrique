#include<iostream>
#include"window.h"
#include"terrain.h"
#include"raquette.h"
#include"balle.h"
#include<stdlib.h>
#include<time.h>
#include"brique.h"
#include"menu.h"
using namespace std;
void GlobalRemove(Ball &b,terrain &ter,racket &r,bool &leftM, bool &rightM){
  ter.remove_Ball(b);
  remove_Racket(r,ter,leftM,rightM);
  // remove_Brick(br,ter,WCYAN);

}

void GlobalPrint(Ball &b,terrain &ter,racket &r,Brick *br,unsigned int nbrBrick){
  printRacket(r,ter);
  if ((b.getDeplacement()==1)||(b.getDeplacement()==2)){
    ter.printInField(b.getposX(),b.getposY(),b.getChar(),WBLACK);
  }
  unsigned int nbr= 0;
  while(nbr < nbrBrick){
    printBrick(br[nbr],ter,BWHITE);
    nbr++;
  }
}

void GlobalMove(Ball &b, terrain &ter, racket &r, bool &leftM, bool &rightM){
  
  if (b.getDeplacement()==2){
    b.move_Ball();
  }
  
  if (leftM) {

    if (((r.getXRacket()-(ter.getXField()-2))<=4)){
	
	r.setPosXRacket(ter.getXField()-2);
	
      } else if((r.getXRacket()-(ter.getXField()-2))>4){
	r.setPosXRacket(r.getXRacket()-2);
      }
  } else if (rightM) {

    if ((( ((ter.getXField()-2) + ter.getWidthField()) ) - (r.getXRacket()+r.getWidthRacket())) > 4 ){
	
	r.setPosXRacket(r.getXRacket()+2);
	
      } else if((((ter.getXField()-2)+ter.getWidthField())-(r.getXRacket()+r.getWidthRacket()))<=4){
	
	r.setPosXRacket((ter.getXField() + ter.getWidthField())-(r.getWidthRacket()+3));
      }
  }
  if (b.getDeplacement()==1){
    b.setposX((r.getXRacket())+(0.5*r.getWidthRacket()));
  }
}

void GlobalCollision(Ball &b, terrain &ter, racket &r,Brick* br,unsigned int nbrBrick){
  if (b.getDeplacement()==2){
    r.collision_Ball_racket(b);
    ter.collision_Ball_field(b);
  }
  unsigned int nbr =0 ;
  while( nbr < nbrBrick ){
    collision_Ball_Brique(b,br[nbr]);
    nbr++;
  }
}

void initTabBrick(Brick * br,unsigned int taille ,int posXDebut,int posYDebut ,terrain &ter){
  br[0].setPosX(posXDebut);
  br[0].setPosY(posYDebut);
  srand (time(NULL));
  unsigned int i=1 ;
  unsigned int resistance_generator= rand()%10+1;
  while(i < taille){
      resistance_generator= rand()%10+1;
    if( ter.getWidthField() - (br[i-1].getWidth() +  br[i-1].getPosX()) > br[i-1].getWidth() + 1 ){
      br[i].setPosX( br[i-1].getPosX() + br[i-1].getWidth() + 1 );
      br[i].setPosY(br[i-1].getPosY());
      br[i].setResistance(resistance_generator);
      i++;
    }else{
      br[i].setPosY( br[i-1].getPosY() + br[i-1].getHeight() + 2);
      br[i].setPosX(posXDebut);
      br[i].setResistance(resistance_generator);
      i++;
    }
  }
}

void Game_Launch(){
  
  Window w(40,70,2,2,'_');
  unsigned int nbrBrick = 40;
  Ball b('@',35,27,0,0,1);
  terrain  ter(w,b);
  Brick tab[nbrBrick];
  initTabBrick(tab,nbrBrick, 4 ,4 ,ter);
  racket r1(12,30,36,b);
  int ch ;
  bool leftMouvRacket = false;
  bool rightMouvRacket = false;

  //GlobalPrint(b,ter,r1,tab,5); 
  while((ch = getch()) != 'q'){
    
    GlobalRemove(b,ter,r1,leftMouvRacket,rightMouvRacket);
    GlobalMove(b,ter,r1,leftMouvRacket, rightMouvRacket);
    GlobalCollision(b,ter,r1,tab,nbrBrick);
    GlobalPrint(b,ter,r1,tab,nbrBrick);
    
    
    switch (ch) {
    case '1':
      ter.setBkgdColorField(WMAGENTA);
      break;
    case '2':
      ter.setBkgdColorField(WYELLOW);
      break;
    case '3':
      ter.setBordureField('X');
      break;
    case '4' :
      ter.setBkgdColorField(WBLACK);
      break;
    case KEY_LEFT:
      if (leftMouvRacket==false){
	leftMouvRacket=true;
      } else if (leftMouvRacket==true){
	leftMouvRacket=false;
      }
      rightMouvRacket=false;
      break;
    case KEY_RIGHT:
      if (rightMouvRacket==false){
	rightMouvRacket=true;
      } else if (rightMouvRacket==true){
	rightMouvRacket=false;
      }
      leftMouvRacket=false;
      break;
    case ' ':
      if (b.getDeplacement()==1){
	b.setDeplacement(2);
	b.setVitesseX(0);
	b.setVitesseY(-1);
      }
      break;
   
    }
  }    
  
}

void myProgram(){

  Window w(20,30,50,20,' ');
  Menu menu(w);
  int ch;
  string Choix[]={
    "Lancer un nouveau Jeu",
    "Lancer une sauvegarde",
    "TUTORIEL",
    "Quitter",
  };
  int choix =1;
  int posX2Choix = 2;
  int posY2Choix= 2;
  int indice2Choix=-1;
  Color Highlight=WRED;
  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[0],WBLACK);
  menu.printStringInMenu(posX2Choix,posY2Choix+2,Choix[1],WBLACK);
  menu.printStringInMenu(posX2Choix,posY2Choix+4,Choix[2],WBLACK);
  menu.printStringInMenu(posX2Choix,posY2Choix+6,Choix[3],WBLACK);
  
  while(choix!=0 ){
    ch = getch();
    switch (ch) {
      
    case KEY_DOWN:
      if(indice2Choix==-1){
	menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix+1],Highlight);
       	indice2Choix++;
	//	posY2Choix+=2;
      }else{
	menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],WBLACK);
	indice2Choix++;
	posY2Choix+=2;
	choix++;
	menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],Highlight);
	
      }
      //menu.printStringInMenu(2,4,Choix[1],WRED);
      break;
    case KEY_UP:
      menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],WBLACK);
      posY2Choix-=2;
      indice2Choix--;
      choix--;
      menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],Highlight);
      // menu.printStringInMenu(2,2,Choix[0],WRED);
      //menu.printStringInMenu(2,4,Choix[1],WBLACK);
      break;
    case 10 :
      choix=0;
      break;
  
    }
  }
  
 switch(indice2Choix){
 case 3:
   break;
 case 0 :
   Game_Launch();
   break;
  }
}

int main(){
  startProgramX();
  myProgram();
  stopProgramX();
 
  return 0;
}
