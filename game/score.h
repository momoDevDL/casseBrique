#ifndef __SCORE_H
#define __SCORE_H
#include"window.h"
#include <string>
class Score{
private:
	Window score;
public:
	//les constructeurs de terrain par defaut et paramétré
	score();
	score(int h,int w,int x,int y, char bordure);
	//accesseur en lecture 
	Color getBkgdColorScore()const;
	Color getBordColorScore()const;
	int getHeightScore()const;
	int getWidthScore()const;
	int getYScore()const;
	int  getXScore()const;
	//accesseurs en ecriture
	void setBkgdColorScore(Color);
	void setBordColorScore(Color);
	void setHeightScore(int H);
	void setWidthScore(int W);
	void setBordureScore(char c);
	//methodes
	void clearScore();
	void printStringInScore(int,int,std::string,Color);
	void printCharInScore(int,int,char,Color);

};

#endif
