/*
 * Labo 2 Mandelbrot set
 *
 * Boris Hutzli, Robin Forestier
 * 05.10.2022 - .10.2022
 * But:
 *
 */

#include <iostream>
#include <vector>
#include "display.h"

using namespace std;

const int MAX_ITERATIONS = 1000;

/*
 * mandelbrot
 *
 * @param
 */
vector<vector<int>> mandelbrot(double centreX=0, double centreY=0, double dx=3, double dy=3, int pixelSize=30)
{
    double x1 = centreX - (dx / 2);
    double x2 = centreX + (dx / 2);
    double y1 = centreY - (dy / 2);
    double y2 = centreY + (dy / 2);

    mandlebrot(x1, y1, x2, y2, pixelSize);
}
vector<vector<int>> mandelbrot(double x1=-2, double y1=1.12, double x2=0.47, double y2=-1.12, int pixelSize=30)
{
    // x1;y1 coordonée en haut a gauche de notre graph
    // x2;y2 coordonée en bas a droite de notre graph

    vector<vector<int>> pixelData(pixelSize, vector<int>(pixelSize, 0));

    for (int i = 0; i < pixelSize; i++)
    {
        double x0 = x1 + ((x2 - x1) / pixelSize) * i;

        for (int j = 0; j < pixelSize; j++)
        {
            double y0 = y1 + ((y2 -y1) / pixelSize) * j;
            double x = 0;
            double y = 0;

            int iterations = 0;

            while (x*x + y*y <= 2*2 && iterations < MAX_ITERATIONS) {
                double xtemp = x*x - y*y + x0;
                y = 2 * x * y + y0;
                x = xtemp;
                iterations++;
            }
            pixelData[i][j] = iterations;
        }
    }
    return pixelData;
}


int main() {
    vector<vector<int>> test = mandelbrot();

    display(test, MAX_ITERATIONS);

    return 0;
}

