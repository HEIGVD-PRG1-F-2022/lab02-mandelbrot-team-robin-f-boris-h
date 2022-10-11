//
// Created by boris on 06.10.2022.
//

#ifndef MANDELBROT_MANDELBROT_H
#define MANDELBROT_MANDELBROT_H

#include <vector>

using namespace std;

vector<vector<int>> mandelbrot(double x1 = -2, double y1 = 1.12, double x2 = 0.47, double y2 = -1.12, int nX = 30,
                               int nY = 30, int maxIterations = 1000);

vector<vector<int>> mandelbrot(double centreX = 0, double centreY = 0, int nX = 30, int nY = 30, double dx = 3,
                               double dy = 3, int maxIterations = 1000);

#endif //MANDELBROT_MANDELBROT_H
