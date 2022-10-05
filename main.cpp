/*
 * for each pixel (Px, Py) on the screen do
    x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
    y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))
    x := 0.0
    y := 0.0
    iteration := 0
    max_iteration := 1000
    while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
        xtemp := x*x - y*y + x0
        y := 2*x*y + y0
        x := xtemp
        iteration := iteration + 1

    color := palette[iteration]
    plot(Px, Py, color)
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int PIXELS_Y = 10;
const int PIXELS_X = 10;
const int MAX_ITERATIONS = 10;

vector<vector<int>> mandelbrot() {
    vector<vector<int>> pixelData(PIXELS_X, vector<int>(PIXELS_Y, 0));
    for (int pY = 0; pY < PIXELS_Y; pY++) {
        for (int pX = 0; pX < PIXELS_X; pX++) {
            int x0 = -2.0;
            int y0 = -1;

            int x = 0;
            int y = 0;

            int iterations = 0;

            while (x*x + y*y <= 2*2 && iterations < MAX_ITERATIONS) {
                int xtemp = x*x - y*y + x0;
                y = 2 * x * y + y0;
                x = xtemp;
                iterations++;
            }
            pixelData[pX][pY] = iterations;
        }
    }

    return pixelData;
}

int main() {
    vector<vector<int>> test = mandelbrot();
    return 0;
}

