#include "graphics.hpp"
#include "widget.h"
#include "GameMaster.h"
#include "szamlalo.h"
#include <vector>
#include <iostream>
#include "Window.h"
#include <fstream>
using namespace std;
using namespace genv;

int main()
{
    GameMaster G(600,600);
    G.event_loop();

    /*vector<Widget*> ws;
    Szamlalo * sz1 = new Szamlalo(100,50,50,20,100, -100);
    Szamlalo * sz2 = new Szamlalo(100,100,70,30, 50, -50);
    ws.push_back(sz1);
    ws.push_back(sz2);
    for (Widget * wg : ws) {
        wg->draw();
    }
    gout << refresh;
    event_loop(ws);*/
    return 0;
}
