#include<iostream>
#include"window.h"
#include"terrain.h"
#include"balle.h"
#include"menu.h"
using namespace std;
void myProgram(){
  Window w(30,70,2,2,'=');
  Menu menu;
  Ball b('@',20,10,1,1);
  terrain  ter(w,b);
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
	  //cout<<b.getVitesseY()<<" ("<<b.getposX()<<","<<b.getposY()<<")";
	  ter.printInField(b.getposX(),b.getposY(),b.getChar(),WBLACK);
	  // std::cout<<collision<<" ";
	  /*if(!collision){
	   
	    }*/
	  // ter.clearField();
	  //       	ter.collision_Ball_field(WCYAN);
	  // 	ter.printInField(b.getposX(),b.getposY(),' ',WRED);
	  //	b.setposX(b.getposX()+1);
	  //b.setposY(b.getposY()+1);
	  //	b.move_Ball();
	  //ter.printInField(b.getposX(),b.getposY(),b.getChar(),WRED);

	  break;
      }
	
	
    }
	
	/*case KEY_DOWN:
	ter.print(5,10,' ');
	ter.print(x,++y,p);
	break;
      case KEY_LEFT:
	ter.print(x,y,' ');
	ter.print(--x,y,p,col);
	break;
      case KEY_RIGHT:
	ter.print(x,y,' ');
	ter.print(++x,y,p,col);
	ter.setCouleurBordure(WYELLOW);
	break;
      case '\n':
	x=w/2,y=h/2;
	ter.print(x,y,p,col);
	break;
      case '\t':
	Color tmp= menu.getCouleurBordure();
	menu.setCouleurBordure(ter.getCouleurBordure());
	ter.setCouleurBordure(tmp);
	break;*/
}

int main(){
  startProgramX();
  myProgram();
  stopProgramX();
 
  return 0;
}
