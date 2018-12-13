#include<iostream>
#include"window.h"
#include"terrain.h"
#include"raquette.h"
#include"balle.h"
#include"brique.h"
#include"menu.h"
using namespace std;

void GlobalRemove(Ball &b,terrain &ter,racket &r,Brick &br,bool &leftM, bool &rightM){
  ter.remove_Ball(b);
  remove_Racket(r,ter,leftM,rightM);
  // br.remove_Brick(ter);

}

void GlobalPrint(Ball &b,terrain &ter,racket &r,Brick &br){
  printRacket(r,ter);
  printBrick(br,ter);
  ter.printInField(b.getposX(),b.getposY(),b.getChar(),WGREEN);
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

void GlobalCollision(Ball &b, terrain &ter, racket &r,Brick &br){
  r.collision_Ball_racket(b);
  ter.collision_Ball_field(b);
  br.collision_Ball_Brique(b);
}


void myProgram(){
  Window w(45,70,2,2,'_');
  Menu menu;
  Brick br;
  Ball b('@',20,10,1,1);
  terrain  ter(w,b);
  //ter.setBkgdColorField(BWHITE);
  // ter.setBordColorField(BWHITE);
  racket r1(12,35,26);
  int ch ;
  bool leftMouvRacket = false;
  bool rightMouvRacket = false;
  
  printBrick(br,ter);
  while((ch = getch()) != 'q'){

    GlobalRemove(b,ter,r1,br,leftMouvRacket,rightMouvRacket);
    GlobalMove(b,ter,r1,leftMouvRacket, rightMouvRacket);
    GlobalCollision(b,ter,r1,br);
    GlobalPrint(b,ter,r1,br);

   
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
