#ifndef __MENU_H
#define __MENU_H
#include "window.h"

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
	int GetHeightMenu()const;
	int GetWidthMenu()const;
	int getYMenu()const;
	int getXMenu()const;

	// accsseur en ecriture
	void setBkgColorMenu(Color);
	void setBordColorMenu(Color);
       	void setHeightMenu(int H);
	void setWidhtMenu(int W);
	void setBordureMenu(char c);

	//methodes

	void printStriingMenu(int x, int y, std::string s);
	
	
};
#endif 
