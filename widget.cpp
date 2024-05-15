#include "widget.h"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy, Window * w) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{
    gout << font("LiberationSans-Regular.ttf",_size_y - _size_y/4);
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
        return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}






