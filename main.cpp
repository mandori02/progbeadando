#include "graphics.hpp"
#include "widget.h"
#include "szamlalo.h"
#include "legordulo.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
using namespace genv;

    const int XX = 600;
    const int YY = 600;


void event_loop(vector<Widget*>& widgets) {

    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if(ev.keycode == key_enter)
        {
            cout << ":(" << endl;
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << move_to(10, YY - 30) << color(255,255,255) << text("Press enter to save") << refresh;

    }
}

int main()
{
    gout.open(XX,YY);
    ofstream of;
    of.open("Data.txt");
    vector<Widget*> ws;
    Szamlalo * sz1 = new Szamlalo(100,50,50,20,100, -100);
    Szamlalo * sz2 = new Szamlalo(100,100,70,30, 50, -50);
    ws.push_back(sz1);
    ws.push_back(sz2);
    for (Widget * wg : ws) {
        wg->draw();
    }
    gout << refresh;
    event_loop(ws);
    of.close();
    return 0;
}
