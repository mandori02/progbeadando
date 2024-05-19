#include "graphics.hpp"
#include "widget.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
using namespace genv;


void gridDrawer(){

    for (int i = 0; i <= 15; ++i) {
        int x = i * 40;
        gout << color(255,255,255) << move_to(x, 0) << line(0, 600);
    }

    for (int i = 0; i <= 15; ++i) {
        int y = i * 40;
        gout << move_to(0, y) << color(255,255,255) << line(600, 0);
    }

}

void matrixToConsole(vector<vector<int>> m)
{
        for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    gout.open(600,600);
    event ev;
    vector<vector<int>> allas(15, vector<int>(15, 0));
    matrixToConsole(allas);




    while (gin >> ev && ev.keycode != key_escape) {
        gridDrawer();

        gout << refresh;
    }
    return 0;
}
