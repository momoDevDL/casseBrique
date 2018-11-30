#ifndef __MENU_H
#define __MENU_H
#include"window.h>"


class Menu {

private:
        Window field ; 

 public :
	// constructeur par défaut et parametré de menu
	menu();
	menu(window field);
	//accesseur en lecture
	Color getBKgdColorField()const;
	Color getBordColorField()const; 
	int GetHeightFiled()const;
	int GetWidthField()const;
	int getYField()const;
	int getXField()const;

	// accsseur en ecriture
	void setBkgColorField(Color);
	void setBordColorField(Color);
       	void setHeightField(int H);
	void setWidhtField(int W);
	void setBordureFile(char c);

	//methodes
	
};
