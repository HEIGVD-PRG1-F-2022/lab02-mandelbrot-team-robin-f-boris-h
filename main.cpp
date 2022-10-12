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
#include <windows.h>
#include "mandelbrot.h"
#include "display.h"
#include "animation.h"

using namespace std;

const int MAX_ITERATIONS = 1000;

int main() {

    system("mode 650");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int largeur_ecran = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    int hauteur_ecran = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

    //zoom(1, 100, 0.38, -0.1);
    vector<vector<int>> test = mandelbrot(1.5, 0.0, largeur_ecran, hauteur_ecran, 6.5, 2.5);
    // TODO: ERREUR vérifier x / y dans mandelbrot et display (invertion) !
    displayAscii(test, MAX_ITERATIONS);
    //displayIterations(test, MAX_ITERATIONS);

    cin >> hauteur_ecran;

    return 0;
}

