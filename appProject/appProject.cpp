#include "Game.h"
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;

    Game game{ screenWidth,screenHeight,"Rondo" };
 
    while (!game.GameShouldClose())
    {
        game.Tick();
    }
    
    return 0;
}