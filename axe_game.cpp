#include "raylib.h"

int main()
{
    // window dimensions
    int width = 1350;
    int height = 1100;
    int radius = 50;
    InitWindow(width, height, "Jeromy's Window");

    // circle coords
    int circle_x{300};
    int circle_y{400};

    // circle edge
    int l_circle_x{circle_x - radius};
    int r_circle_x{circle_x + radius};
    int u_circle_y{circle_y - radius};
    int b_circle_y{circle_y + radius};

    //axe coords
    int axe_x{675};
    int axe_y{0};
    int axe_width{100};
    int axe_height{100};

    int axe_direction{10};

    // axe edge
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_height};
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_width};

    // axe collision w/circle
    bool collision = 
                (b_axe_y >= u_circle_y) && 
                (u_axe_y <= b_circle_y) && 
                (r_axe_x >= l_circle_x) && 
                (l_axe_x <= r_circle_x);

    
    /*Collision math note: 
    
    *lower edge of axe (bl_axe_y) must be greater than
    *the upper edge of the circle (tr_circle_y). 
    *Same for the bottom edge of circle and upper edge of the axe.

    *Case #1:
    *"bl_axe_y >= tr_circle_y" <-- Bottom axe / Top circle

    *Case #2:
    *"tl_axe_y <= br_circle_y" <-- Top axe / Bottom circle

    *Case #3:
    *"bl_axe_x <= tr_circle_x" <-- Left axe / Right circle

    *Case 4:
    *"br_axe_x >= bl_circle_x" <-- Right axe / Left circle
    */

  
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
       BeginDrawing();
       ClearBackground(WHITE);

        if (collision)
        {
                DrawText("Game Over!", 490, 520, 80, RED);
            }
            else
            {
                    // Game logic begins

                    // update circle edge pos
                    l_circle_x = circle_x - radius;
                    r_circle_x = circle_x + radius;
                    u_circle_y = circle_y - radius;
                    b_circle_y = circle_y + radius;

                    // update axe edge pos
                    l_axe_x = axe_x;
                    r_axe_x = axe_x + axe_width;
                    u_axe_y = axe_y;
                    b_axe_y = axe_y + axe_height;
                    
                    // update collision
                    collision = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (r_axe_x >= l_circle_x) && 
                    (l_axe_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_width, axe_height, RED);

            // move the axe
            axe_y += axe_direction;
            
            if (axe_y < 0 || axe_y > 1000)
            {
                axe_direction = -axe_direction;
            }

            // Controls
            if (IsKeyDown(KEY_D) && circle_x < width)
        {
                circle_x += 10;
        }
        else if (IsKeyDown(KEY_A) && circle_x > 0)
        {
                circle_x -= 10;
        }
        else if (IsKeyDown(KEY_W) && circle_y > 0)
        {
                circle_y -= 10;
        }
        else if (IsKeyDown(KEY_S) && circle_y < height)
        {
                circle_y += 10;
            }
        }
        // Game logic ends
        EndDrawing();
        }
    }