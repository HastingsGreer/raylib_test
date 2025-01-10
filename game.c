#include "raylib.h"
#include <math.h>


int mandelbrot(float x, float y) {
	float r = 0;
	float i = 0;
	float n = 0;
	while (r * r + i * i < 4) {
		if (n > 256) {
			return 0;
		}
		n += 1;
		float ra = r * r - i * i + x;
		i = 2 * r * i + y;
		r = ra;
	}
	return n;

}
int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    SetTargetFPS(60);

    int z = 0;

    int frames = 0;

    Image canvas = GenImageColor(600, 400, GREEN);

    float lx = 0;
    float ly = 0;
    float oldx = 0;
    float oldy = 0;

    

    SetExitKey(KEY_Q);
    while (!WindowShouldClose())
    {
	    frames ++;
	    int mx = GetMouseX();
	    int my = GetMouseY();
	    lx = lx + mx;
	    ly = ly + my;
	    SetMousePosition(0, 0);
	    for (int i = 0; i < 400; i++) {
		    for (int j = 0; j < 600; j++) {
			    float a = (i - ly) / 25000.;
			    float b = (j - lx) / 25000.;
			    int count = 9 * mandelbrot(a, b);
			    Color c = {count, count, count, count};

			    if (count) {
				    ImageDrawPixel(&canvas, j, i, c);
			    } else {
				    ImageDrawPixel(&canvas, j, i, BLACK);
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
