#include "raylib.h"
#include <math.h>

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    int z = 0;

    int frames = 0;

    Image canvas = GenImageColor(600, 400, GREEN);

    

    SetExitKey(KEY_Q);
    while (!WindowShouldClose())
    {
	    frames ++;
	    int mx = GetMouseX();
	    int my = GetMouseY();
	    for (int i = 0; i < 400; i++) {
		    for (int j = 0; j < 600; j++) {
			    if ((i-my ) & (j - mx)) {
				    ImageDrawPixel(&canvas, j, i, WHITE);
			    } else {
				    ImageDrawPixel(&canvas, j, i, GREEN);
			    }
	    
		    }
	    }
	    Texture canvas_tex = LoadTextureFromImage(canvas);
        BeginDrawing();
            ClearBackground(RAYWHITE);
	    DrawTexture(canvas_tex, 0, 0, WHITE);
            DrawText(TextFormat("%f", round(0.0 + frames) / GetTime()), 190, 200, 20, BLACK);
            DrawText(TextFormat("%i", mx), 190, 301, 20, BLACK);
	    DrawRectangle(z, 10, 20, 20, BLUE);


        EndDrawing();
	   UnloadTexture(canvas_tex);

	if (IsKeyDown(KEY_UP)) {
		z += 1;
	}
		
    }

    CloseWindow();

    return 0;
}
