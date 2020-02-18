// SFML_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"


int main()
{
    Game game;

    srand((unsigned)time(nullptr));

    game.Run();
}
