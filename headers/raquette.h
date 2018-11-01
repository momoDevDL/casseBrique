#ifndef __RAQUETTE_h
#define __RAQUETTE_h
#include"window.h"
#include<string>
class racket{
 private:
  Window Surfer;
 public :
	//les constructeurs de racket par defaut et paramétré
	racket();
	racket(int h,int w,int x,int y, char bordure);
	//accesseur en lecture 
	Color getBkgdColorRacket()const;
	Color getBordColorRacket()const;
	int getHeightRacket()const;
	int getWidthRacket()const;
	int getYRacket()const;
	int  getXRacket()const;
	//accesseurs en ecriture
	void setBkgdColorRacket(Color);
	void setBordColorRacket(Color);
	void setHeightRacket(int H);
	void setWidthRacket(int W);
	void setBordureRacket(char c);
	//methodes
	void clearRacket();
	void printStringInRacket(int,int,std::string,Color);

};

#endif

