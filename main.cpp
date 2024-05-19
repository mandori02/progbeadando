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
    gout << refresh;

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

int getMouseRow(int posY)
{
    return posY/40;
}

int getMouseCol(int posX)
{
    return posX/40;

}

void tableDrawer(vector<vector<int>> m)
{
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            if(m[i][j] == 1)
            {
                gout << move_to(j*40+15,i*40+15) << color(240,50,0) << text("O");
            }
            if(m[i][j] == 2)
            {
                gout << move_to(j*40+15,i*40+15) << color(240,50,0) << text("X");
            }
        }
    }
}

bool isWinner(bool ki, vector<vector<int>> m)
{
    int player = ki ? 2 : 1; // Az aktuális játékos jelölése

    // Sorok ellenõrzése
    for (int i = 0; i < 15; ++i) {
        int count = 0;
        for (int j = 0; j < 15; ++j) {
            if (m[i][j] == player) {
                count++;
                if (count == 5) return true;
            } else {
                count = 0;
            }
        }
    }

    // Oszlopok ellenõrzése
    for (int j = 0; j < 15; ++j) {
        int count = 0;
        for (int i = 0; i < 15; ++i) {
            if (m[i][j] == player) {
                count++;
                if (count == 5) return true;
            } else {
                count = 0;
            }
        }
    }

    // Átlók ellenõrzése

    // Fõátló
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            if (m[i][j] == player && m[i+1][j+1] == player && m[i+2][j+2] == player && m[i+3][j+3] == player && m[i+4][j+4] == player)
                return true;
        }
    }
    // Mellékátló
    for (int i = 0; i <= 10; ++i) {
        for (int j = 4; j < 15; ++j) {
            if (m[i][j] == player && m[i+1][j-1] == player && m[i+2][j-2] == player && m[i+3][j-3] == player && m[i+4][j-4] == player)
                return true;
        }
    }

    return false;
}


int main()
{
    gout.open(600,600);
    event ev;
    bool kijon = false; // ha false O (1), ha true X (2)
    vector<vector<int>> allas(15, vector<int>(15, 0));
    //matrixToConsole(allas);


    while (gin >> ev && ev.keycode != key_escape) {
        if(!isWinner(kijon, allas))
        {
            tableDrawer(allas);
            gridDrawer();
            if(ev.button == btn_left)
            {
                int oszlop = getMouseCol(ev.pos_x);
                int sor = getMouseRow(ev.pos_y);
                if(allas[sor][oszlop] == 0)
                {
                    if(kijon)
                    {
                        allas[sor][oszlop] = 2;
                    }
                    else
                    {
                        allas[sor][oszlop] = 1;
                    }
                    kijon = !kijon;
                }
            }
            /*if(ev.keycode == key_enter)
                matrixToConsole(allas);*/
        }
        else{

            gout << move_to(0,0) << color(0,0,0) << box(600,600);
            if(kijon)
                gout << move_to(100,100) << color(255,255,255) << text("X nyert! Nyomj Esc-et a kilépéshez");
            else
                gout << move_to(100,100) << color(255,255,255) << text("O nyert! Nyomj Esc-et a kilépéshez");
            gout << refresh;
        }

    }
    return 0;
}
