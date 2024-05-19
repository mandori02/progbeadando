#include "graphics.hpp"
#include "widget.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
using namespace genv;

struct Tile{

    int x,y,sx,sy;
    int isMarked = -1;

};

struct Board{

    int noszlop = 15;
    int nsor = 15;
    vector<vector<Tile>> allas;

};

void gridDrawer(){

    for (int i = 0; i <= 15; ++i) {
        int x = i * 40;
        gout << move_to(x, 0) << line(0, 600);
    }

    for (int i = 0; i <= 15; ++i) {
        int y = i * 40;
        gout << move_to(0, y) << line(600, 0);
    }

    gout << refresh;

}

int main()
{
    gout.open(600,600);
    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        gridDrawer();

    }
    return 0;
}
