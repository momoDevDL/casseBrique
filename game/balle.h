#ifndef __BALLE_H
#define __BALLE_H
#include <string>
class Ball{
private:
	char c ;
	size_t posX ;
	size_t posY;
	int vitesse;
public:
	//les constructeurs de terrain par defaut et paramétré
	Ball();
	Ball(char car,size_t x,size_t y,size_t v);
	//accesseur en lecture 
	size_t getposX()const;
	size_t getposY()const;
	int getVitesse()const;
	char getChar()const;
	//accesseurs en ecriture
	void setposX(size_t);
	void setposY(size_t);
	void setVitesse(int);
	//methodes

	void move_Ball();


};

#endif
