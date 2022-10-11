/*
 * Fichier : main.cpp
 * Autheur : Boris Hutzli, Robin Forestier
 * Date    : 13.10.22
 *
 * But     : Le but de ce deuxième laboratoire est de réaliser une visualisation d'une fractale de Mandelbrot.
 *           Et de l'afficher de différente manière.
 */

#include <iostream>
#include <vector>
#include "mandelbrot.h"
#include "display.h"
#include "animation.h"

using namespace std;

const int MAX_ITERATIONS = 1000;

int main() {
    zoom(1, 100, 0.38, -0.1);
    //vector<vector<int>> test = mandelbrot(0.0, 0.0, 30, 30, 2.0, 2.0);

    //displayAscii(test, MAX_ITERATIONS);
    //displayIterations(test, MAX_ITERATIONS);

    return 0;
}

