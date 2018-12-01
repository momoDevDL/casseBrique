#ifndef __BRIQUE_H
#define __BRIQUE_H


class Brique{

    private:
        // attributs
        size_t height;
        size_t width;
        size_t posX;
        size_t posY;
        size_t resistance;

    public:
        // Constructeurs 
        Brique(); 
        Brique(size_t h, size_t w, size_t x, size_t y, size_t res);

        // accesseur en lecture
        size_t getHeight() const;
        size_t getWidth() const;
        size_t getPosX() const;
        size_t getPosY() const;
        size_t getResistance() const;

        // accesseur en écriture
        void setHeight(size_t &h);
        void setWidth(size_t &w);
        void setPosX(size_t &x);
        void setPosY(size_t &y);
        void setResistance(size_t &res);
};

#endif