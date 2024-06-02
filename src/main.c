#include "raylib.h"
#include "GameWorld.h"
#define WIDHT 1280
#define HEIGHT 720

int main(void)
{
    // Initialize the window
    InitWindow(WIDHT, HEIGHT, "Game Window");

    // Initialize the game world
    GameWorld *gameWorld = createGameWorld();

    Rectangle playerArea = {80, 80, 50, 50};
    Rectangle rect1 = {100, 100, 50, 50};
    SetTargetFPS(60);
    // Main game loop
    while (!WindowShouldClose())
    {
        
        inputAndUpdateGameWorld(gameWorld);
        drawGameWorld(gameWorld);
    }

    // Deinitialize the game world
    destroyGameWorld(gameWorld);

    // Close the window and OpenGL context
    CloseWindow();

    return 0;
}
