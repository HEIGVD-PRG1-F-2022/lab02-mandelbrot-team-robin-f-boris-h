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
#include "animation.h"

using namespace std;

int main() {
    vector<vector<int>> test = mandelbrotCentre(0, 0, 2, 2);

    displayAscii(test, MAX_ITERATIONS);
    //displayIterations(test, MAX_ITERATIONS);

    return 0;
}

