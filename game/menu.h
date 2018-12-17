#ifndef __MENU_H
#define __MENU_H
#include "window.h"
#include<string.h>

class Menu {

private:
          Window menu;  

 public :

	// constructeur par défaut et parametré de menu
	Menu();

	Menu(Window &w);
	//accesseur en lecture
	Color getBKgdColorMenu()const;
	Color getBordColorMenu()const; 
	int getHeightMenu()const;
	int getWidthMenu()const;
	int getYMenu()const;
	int getXMenu()const;

	// accsseur en ecriture
	void setBkgdColorMenu(Color);
	void setBordColorMenu(Color);
       	//void setHeightMenu(int H);
	//	void setWidthMenu(int W);
	void setBordureMenu(char c);

	// print un carcatere dans le menu 
	void printInMenu(float x,float y, char c,Color cl); 

	//methodes

	void printStringInMenu(int x, int y,std::string);
	
	
};
#endif 
