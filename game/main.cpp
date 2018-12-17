#include<iostream>
#include"window.h"
#include"terrain.h"
#include"raquette.h"
#include"balle.h"
#include"brique.h"
#include"menu.h"
using namespace std;

void GlobalRemove(Ball &b,terrain &ter,racket &r,bool &leftM, bool &rightM){
  ter.remove_Ball(b);
  remove_Racket(r,ter,leftM,rightM);
  // remove_Brick(br,ter,WCYAN);

}

void GlobalPrint(Ball &b,terrain &ter,racket &r,Brick *br,unsigned int nbrBrick){
  ter.printInField(b.getposX(),b.getposY(),b.getChar(),WGREEN);
  printRacket(r,ter);
  unsigned int nbr= 0;
  while(nbr < nbrBrick){
    printBrick(br[nbr],ter,BWHITE);
    nbr++;
  }
}

void GlobalMove(Ball &b, terrain &ter, racket &r, bool &leftM, bool &rightM){
  
  b.move_Ball();
  
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
}

void GlobalCollision(Ball &b, terrain &ter, racket &r,Brick* br,unsigned int nbrBrick){
  r.collision_Ball_racket(b);
  ter.collision_Ball_field(b);
  unsigned int nbr =0 ;
  while( nbr < nbrBrick ){
    collision_Ball_Brique(b,br[nbr]);
    nbr++;
  }
}

void initTabBrick(Brick * br,unsigned int taille ,int posXDebut,int posYDebut ,terrain &ter){
  br[0].setPosX(posXDebut);
  br[0].setPosY(posYDebut);
  unsigned int i=1 ;
  while(i < taille){
    if( ter.getWidthField() - (br[i-1].getWidth() +  br[i-1].getPosX()) > br[i-1].getWidth() + 5 ){
      br[i].setPosX( br[i-1].getPosX() + br[i-1].getWidth() + 5 );
      br[i].setPosY(br[i-1].getPosY());
      br[i].setResistance(2);
      i++;
    }else{
      br[i].setPosY( br[i-1].getPosY() + br[i-1].getHeight() + 2);
      br[i].setPosX(posXDebut);
      br[i].setResistance(2);
      i++;
    }
  }
}



void myProgram(){
  Window w(45,70,2,2,'_');
  unsigned int nbrBrick = 31;
  Menu menu;
  Ball b('@',35,35,1,1);
  terrain  ter(w,b);
  Brick tab[nbrBrick];
  initTabBrick(tab,nbrBrick, 4 ,4 ,ter);
  //  Brick br;
  //ter.setBkgdColorField(BWHITE);
  // ter.setBordColorField(BWHITE);
  racket r1(12,35,40);
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
      leftMouvRacket=false;
      rightMouvRacket=false;
      break;
   
    }
  }    
}

int main(){
  startProgramX();
  myProgram();
  stopProgramX();
 
  return 0;
}
