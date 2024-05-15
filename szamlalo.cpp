#include "graphics.hpp"
#include "szamlalo.h"
#include <iostream>
using namespace std;
using namespace genv;


Szamlalo::Szamlalo(int x, int y, int sx, int sy, int maxh, int minh)
    : Widget(x,y,sx,sy) , _maxh(maxh), _minh(minh)
{
    _szam = 0;
    _plusHitX = _x + _size_x/4*3;
    _plusHitY = _y;
    _hitsizeX = _size_x / 3;
    _hitsizeY = _size_y / 2;
    _minusHitX = _plusHitX;
    _minusHitY = _plusHitY + _hitsizeY;

}

void Szamlalo::draw() {

    //gout << font("LiberationSans-Regular.ttf",_size_y - _size_y/4);
    gout << color(255,255,255) << move_to(_x,_y) << box(_size_x,_size_y);
    gout << color(0,0,0) << move_to(_x + _x/8,_y) << text(std::to_string(_szam));

    //nyilak
    gout << color(128,128,128) << move_to(_plusHitX,_plusHitY) << box(_hitsizeX,_hitsizeY);
    gout << color(0,0,0) << move_to(_plusHitX + _plusHitX/32, _plusHitY - _plusHitY/32) << text("^");

    gout << color(128,128,128) << move_to(_minusHitX,_minusHitY) << box(_hitsizeX,_hitsizeY);
    gout << color(0,0,0) << move_to(_minusHitX + _minusHitX/32, _minusHitY + _minusHitY/32) << text("ˇ");

}

void Szamlalo::handle(event ev) {

    if (ev.keycode == key_pgup)
        _szam += 10;
    else if (ev.keycode == key_pgdn)
        _szam -= 10;
    else if ((ev.button == btn_left && ev.pos_x > _plusHitX &&
             ev.pos_x < _hitsizeX + _plusHitX && ev.pos_y > _plusHitY && ev.pos_y < _plusHitY + _hitsizeY) || ev.keycode == key_up)
        _szam++;
    else if ((ev.button == btn_left && ev.pos_x > _minusHitX &&
             ev.pos_x < _hitsizeX + _minusHitX && ev.pos_y > _minusHitY && ev.pos_y < _minusHitY + _hitsizeY) || ev.keycode == key_down)
        _szam--;

    if (_szam > _maxh)
        _szam = _maxh;
    if (_szam < _minh)
        _szam = _minh;



}


