

#include "raylib.h"
#define MAX_COLUMNS 20
#define WIDTH 1280
#define HEIGHT 720

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    InitWindow(WIDTH, HEIGHT, "TEste");
    float xpos = WIDTH / 2;
    float ypos = HEIGHT / 2;
    // SetTargetFPS(60);
    int movVelocity = 400;
    int gravity = 300;
    float dt = 0;
    float yVel = 0;
    Vector2 velocity;
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())
    {
        // xpos+= 10;
        dt = GetFrameTime();
        if (ypos < HEIGHT - 30)
        {
            velocity.y = gravity * dt;
            /* code */
        }
        if (IsKeyDown(KEY_W))
        {
            velocity.y = -movVelocity * dt;
        }
        if (IsKeyDown(KEY_A))
        {
            velocity.x = -movVelocity * dt;
        }
        if (IsKeyDown(KEY_D))
        {
            velocity.x = movVelocity * dt;
        }
        xpos = xpos + velocity.x;
        ypos = ypos + velocity.y;

        ClearBackground(WHITE);
        BeginDrawing();

        DrawCircle(xpos, ypos, 30, BLUE);
        EndDrawing();
        velocity.y = 0;
        velocity.x = 0;
    }

    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}