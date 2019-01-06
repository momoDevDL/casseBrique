#ifndef __SCORE_H
#define __SCORE_H
#include"window.h"
class Score{
private:
	Window score;
	unsigned int value;
	std::string pseudo;
public:
	//les constructeurs de terrain par defaut et paramétré
	Score();
	Score(int h,int w, int x, int y, char c, unsigned int s, std::string p);

	//accesseur en lecture 
	Color getBkgdColorScore()const;
	Color getBordColorScore()const;
	int getHeightScore()const;
	int getWidthScore()const;
	int getYScore()const;
	int  getXScore()const;
	unsigned int getValueScore() const;
	std::string getPseudo() const;
	
	//accesseurs en ecriture
	void setBkgdColorScore(Color);
	void setBordColorScore(Color);
	void setHeightScore(int H);
	void setWidthScore(int W);
	void setBordureScore(char c);
	void setValueScore(int S);
	void setPseudo(std::string p);

	//methodes
	void clearScore();
	void printStringInScore(int,int,std::string,Color);
	void printCharInScore(int,int,char,Color);
};

#endif
