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
    Window w(600,600);
    w.event_loop();
    return 0;
}
