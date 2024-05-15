#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "Window.h"

class Window;

class Widget{
protected:
    Window*_w;
    int _x, _y, _size_x, _size_y;
public:
    Widget(int x, int y, int sx, int sy, Window * w);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
};


#endif // WIDGET_HPP_INCLUDED
