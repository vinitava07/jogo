#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "raylib.h"
#include "Player.h"

typedef struct GameWorld
{
    int dummy;
    Player *player;
    Rectangle platform;
} GameWorld;

GameWorld *createGameWorld();
void destroyGameWorld(GameWorld *gw);
void inputAndUpdateGameWorld(GameWorld *gw);
void drawGameWorld(GameWorld *gw);

#endif // GAMEWORLD_H
