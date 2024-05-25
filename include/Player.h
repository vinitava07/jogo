#ifndef PLAYER_H
#define PLAYER_H


#include "raylib.h"

typedef struct Player
{
    Vector2 position;
    float gravity;
    Vector2 velocity;
    Texture2D texture;
    Rectangle collisionArea;

}Player;

#endif // PLAYER_H
