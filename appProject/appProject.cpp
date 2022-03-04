﻿#include "Game.h"
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game{ screenWidth,screenHeight,"Rondo123" };

    while (!game.GameShouldClose())
    {
        game.Tick();

    }
    
    return 0;
}
