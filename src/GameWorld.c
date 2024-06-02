#include "../include/GameWorld.h"
#include <stdlib.h>
#include <stdio.h> 
#define WIDHT 1280
#define HEIGHT 720
#define PLAYER_GRAVITY 300
#define PLAYERV_X 300
#define PLAYERV_Y 500

float delta;
void managePlayerCollision(GameWorld *gw);

Player *createPlayer()
{
    Player *player = (Player *)malloc(sizeof(Player));

    if (player == NULL)
    {
        printf("Failed to allocate memory for Player\n");
        exit(1);
    }
    Vector2 pos = {300, 300};
    float gravity = PLAYER_GRAVITY;
    Vector2 velocity = {PLAYERV_X, PLAYERV_Y};
    Texture2D texture = LoadTexture("../resources/face.png");
    if (texture.id == 0)
    {
        printf("Failed to load texture\n");
        free(player);
        exit(1); // Exit if texture fails to load
    }
    Rectangle collisionArea = {500, 100, texture.width, texture.height};
    player->texture = texture;
    player->position = pos;
    player->gravity = gravity;
    player->velocity = velocity;
    player->collisionArea = collisionArea;
    return player;
}

GameWorld *createGameWorld()
{
    GameWorld *gw = (GameWorld *)malloc(sizeof(GameWorld));

    if (gw == NULL)
    {
        printf("Failed to allocate memory for GameWorld\n");
        exit(1);
    }

    gw->dummy = 0;
    gw->player = createPlayer();
    Rectangle rec = {100, 100, 50, 50};
    gw->platform = rec;

    return gw;
}

void destroyGameWorld(GameWorld *gw)
{
    UnloadTexture(gw->player->texture); // Free the texture
    free(gw->player);                   // Free the player memory
    free(gw);
}

void inputAndUpdateGameWorld(GameWorld *gw)
{
    delta = GetFrameTime();
    Vector2 oldPosition = {gw->player->position.x, gw->player->position.y};
    if (IsKeyDown(KEY_D))
        gw->player->position.x += gw->player->velocity.x * delta;
    if (IsKeyDown(KEY_A))
        gw->player->position.x -= gw->player->velocity.x * delta;
    if (IsKeyDown(KEY_W))
        gw->player->position.y -= gw->player->velocity.y * delta;
        gw->player->gravity = 0;
    if (IsKeyDown(KEY_S))
        gw->player->position.y += gw->player->velocity.y * delta;

    if (gw->player->position.y >= HEIGHT - gw->player->texture.height)
    {
        gw->player->gravity = 0;
    }
    else
    {
        gw->player->gravity = PLAYER_GRAVITY;
    }
    gw->player->position.y += gw->player->gravity * delta;

    gw->player->collisionArea.x = gw->player->position.x;
    gw->player->collisionArea.y = gw->player->position.y;

    if (CheckCollisionRecs(gw->player->collisionArea, gw->platform))
    {
        managePlayerCollision(gw);
    }
}

void drawGameWorld(GameWorld *gw)
{
    BeginDrawing();
    ClearBackground(WHITE);

    DrawTexture(gw->player->texture, gw->player->position.x, gw->player->position.y, WHITE);
    DrawRectangleRec(gw->platform, BLUE);
    // DrawRectangleRec(gw->player->collisionArea, PINK);
    if (CheckCollisionRecs(gw->player->collisionArea, gw->platform))
    {
        DrawText("COLIDIU", 500, 500, 32, BLACK);
    }
    DrawFPS(20, 20);

    EndDrawing();
}

void managePlayerCollision(GameWorld *gw)
{
    if (gw->player->collisionArea.y <= gw->platform.y)
    {
        gw->player->position.y = gw->platform.y - gw->player->collisionArea.height;
    }
    else if (gw->player->collisionArea.y >= gw->platform.y + gw->player->collisionArea.height)
    {
        gw->player->position.y = gw->platform.y + gw->platform.height;
    }
    else if (gw->player->collisionArea.x >= gw->platform.x)
    {
        gw->player->position.x = gw->platform.x + gw->platform.width;
    }
    else if (gw->player->collisionArea.x <= gw->platform.x)
    {
        gw->player->position.x = gw->platform.x - gw->player->collisionArea.width;
    }
    gw->player->collisionArea.x = gw->player->position.x;
    gw->player->collisionArea.y = gw->player->position.y;
}