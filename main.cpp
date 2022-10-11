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
#include "mandelbrot.h"
#include "display.h"
#include "animation.h"

using namespace std;

const int MAX_ITERATIONS = 1000;

int main() {
    vector<vector<int>> test = mandelbrot(0.0, 0.0, 30, 30, 2.0, 2.0);

    displayAscii(test, MAX_ITERATIONS);
    //displayIterations(test, MAX_ITERATIONS);

    return 0;
}

