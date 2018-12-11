#include<iostream>
#include"window.h"
#include"terrain.h"
#include"raquette.h"
#include"balle.h"
#include"menu.h"
using namespace std;
void GlobalPrint(Ball &b,terrain &ter,racket &r){
  ter.clearField();
  ter.printInField(b.getposX(),b.getposY(),b.getChar(),WBLACK);
  printRacket(r,ter);
}
void myProgram(){
  Window w(30,70,2,2,'_');
  Menu menu;
  Ball b('@',20,10,1,1);
  terrain  ter(w,b);
  ter.setBkgdColorField(BWHITE);
  ter.setBordColorField(BWHITE);
  racket r1(8,35,26);
  // printRacket(r1,ter);
  //terrain menu;1
  int ch ;
  // bool collision;
  //char p ='@';
  //ter.printInField(5,10,p,WBLACK);
  // ter.printInField(b.getposX(),b.getposY(),b.getChar(),WCYAN);
 
    while((ch = getch()) != 'q')
      {
	  b.move_Ball();
	  ter.collision_Ball_field(b);
	  GlobalPrint(b,ter,r1);
	  
	switch (ch) {
	case '1':
	  ter.setBkgdColorField(WCYAN);
	  break;
	case '2':
	  ter.setBkgdColorField(WRED);
	  break;
	case '3':
	  ter.setBordureField('X');
	break;
	case '4' :
	  ter.setBkgdColorField(WBLACK);
	  break;
	case KEY_UP:
	
	  break;
	case KEY_LEFT:
	  if (((r1.getXRacket()-(ter.getXField()-2))<=4)){
	    
	    r1.setPosXRacket(ter.getXField()-2);

	  } else if((r1.getXRacket()-(ter.getXField()-2))>4){
	    r1.setPosXRacket(r1.getXRacket()-4);
	  }
	  GlobalPrint(b,ter,r1);
	  break;
	case KEY_RIGHT:
	  if ((( ((ter.getXField()-2) + ter.getWidthField()) ) - (r1.getXRacket()+r1.getWidthRacket())) >= 4 ){
	    
	    r1.setPosXRacket(r1.getXRacket()+4);

	  } else if(((r1.getXRacket()+r1.getWidthRacket())-((ter.getXField()-2)+ter.getWidthField()))<4){
	    r1.setPosXRacket(ter.getXField()+ter.getWidthField()-2);
	  }
	  GlobalPrint(b,ter,r1);
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
