#include <iostream>
#include "Game.h"
#include <time.h>

int main()
{
    srand(time(0));
    Game* joc = new Game();
    joc->run();

 //Legenda:
 // @ - robot
 // $ - destinatie
 // T - teleportator
 // * - CoVid
 // + - HealthBooster
 // # - Thistle/Spine
 // X - Bomb
 // < - Obligates you to make one step back
 // . - nothing

}
