#include<iostream>
#include"window.h"
#include"terrain.h"
#include"balle.h"
void myProgram(){
  Window w(30,70,2,2,'=');
  Ball b('@',5,5,1);
  terrain menu;
  terrain  ter(w,b);
  int ch ;
  char p ='@';
  // ter.printInField(5,10,p);
    while((ch = getch()) != 'q')
    {
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
      case KEY_UP:
	ter.printInField(5,10,' ');
	ter.printInField(10,9,p);
	break;
      }
	ter.collision_Ball_field();
	
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
