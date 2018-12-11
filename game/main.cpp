#include<iostream>
#include"window.h"
#include"terrain.h"
#include"raquette.h"
#include"balle.h"
#include"menu.h"
using namespace std;
void myProgram(){
  Window w(30,70,2,2,'=');
  Menu menu;
  Ball b('@',20,10,1,1);
  terrain  ter(w,b);
  racket r1(8,35,26);
  printRacket(r1,ter);
  //terrain menu;1
  int ch ;
  bool collision;
  //char p ='@';
  //ter.printInField(5,10,p,WBLACK);
  ter.printInField(b.getposX(),b.getposY(),b.getChar(),WCYAN);
    while((ch = getch()) != 'q')
      {
	//ter.printInField(b.getposX(),b.getposY(),b.getChar(),WCYAN);
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
	  b.move_Ball();
	  ter.collision_Ball_field(b,WCYAN);
	  ter.clearField();
	  ter.printInField(b.getposX(),b.getposY(),b.getChar(),WBLACK);
	  break;
	case KEY_LEFT:
	  r1.setPosXRacket(r1.getXRacket()-4);
	  ter.clearField();
	  printRacket(r1,ter);
	  break;
	case KEY_RIGHT:
	  r1.setPosXRacket(r1.getXRacket()+4);
	  ter.clearField();
	  printRacket(r1,ter);	
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
