#ifndef __BRIQUE_H
#define __BRIQUE_H
#include"terrain.h"
#include"balle.h"
#include"score.h"
class Brick{

    private:
        // attributs
        int height;
        int width;
        int posX;
        int posY;
        unsigned int resistance;
	char bordure ;

    public:
        // Constructeurs 
        Brick(); 
        Brick(int h, int w, int x, int y, int res,const char c);

        // accesseur en lecture
        int getHeight() const;
        int getWidth() const;
        int getPosX() const;
        int getPosY() const;
        int getResistance() const;
	char getBordure() const ;

        // accesseur en écriture
        void setHeight(int);
        void setWidth(int);
        void setPosX(int);
        void setPosY(int);
        void setResistance(int);
	


       
};
void collision_Ball_Brique(Ball &b,Brick &br,Score &s);
void remove_Brick(Brick &br, terrain &ter,Color col);
void printBrick(Brick &br,terrain &ter,Color col);
#endif
