//
// Created by boris on 06.10.2022.
//

#ifndef MANDELBROT_MANDELBROT_H
#define MANDELBROT_MANDELBROT_H
#include <vector>
using namespace std;

vector<vector<int>> mandelbrot(double x1=-2, double y1=1.12, double x2=0.47, double y2=-1.12, int pixelSize=30);
vector<vector<int>> mandelbrotCentre(double centreX=0, double centreY=0, double dx=3, double dy=3, int pixelSize=30);

#endif //MANDELBROT_MANDELBROT_H