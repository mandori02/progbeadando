#ifndef SZAMLALO_HPP_INCLUDED
#define SZAMLALO_HPP_INCLUDED
#include "graphics.hpp"
#include "widget.h"

class Szamlalo : public Widget {
protected:
    int _maxh, _minh;
public:
    Szamlalo(int x, int y, int sx, int sy, int maxh, int minh);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    int _szam;

private:
    int _plusHitX, _plusHitY, _minusHitX, _minusHitY, _hitsizeX, _hitsizeY;

};


#endif // SZAMLALO_HPP_INCLUDED
