#ifndef __TERRAIN_H
#define __TERRAIN_H
#include"window.h"

class terrain{
private:
	Window field ;
public:
	//les constructeurs de terrain par defaut et paramétré
	terrain();
	terrain(int h,int w,int x,int y, char bordure);
	//accesseur en lecture 
	Color getBkgdColorField()const;
	Color getBordColorField()const;
	int getHeightField()const;
	int getWidthField()const;
	int getYField()const;
	int  getXField()const;
	//accesseurs en ecriture
	void setBkgdColorField(Color);
	void setBordColorField(Color);
	void setHeightField(int H);
	void setWidthField(int W);
	void setBordureField(char c);
	//methodes
	void clearField();
	void printStringInField();
	void updateField();


};

#endif
