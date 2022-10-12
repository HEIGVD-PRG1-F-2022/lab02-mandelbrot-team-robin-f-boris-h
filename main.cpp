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
    // Pour windows, on met le terminal en plein écran.
    #ifdef _LINUX_
    system("mode 650");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    const int largeur_ecran = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    const int hauteur_ecran = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

    // Pour les autres system on utilise des ces valeurs.
    #else
    const int largeur_ecran = 50;
    const int hauteur_ecran = 25;
    #endif

    cout << "Que voulez-vous voir ?\n1. mandelbrot iteration \n2. mandelbrot ascii\n3. mandelbrot zoom \n";
    int whatToDo = 0;
    cin >> whatToDo;

    vector<vector<int>> test;

    switch (whatToDo) {
        case 2:
            test = mandelbrot(1.5, 0.0, largeur_ecran, hauteur_ecran, 6.5, 2.5);
            displayAscii(test, MAX_ITERATIONS);
            break;
        case 3:
            zoom(5, 100, -0.7465, -0.075, 3, 3, largeur_ecran, hauteur_ecran, 2.4);
            break;
        default:
            test = mandelbrot(1.5, 0.0, largeur_ecran, hauteur_ecran, 6.5, 2.5);
            displayIterations(test, MAX_ITERATIONS);
            break;
    }



    //zoom(5, 100, -0.7465, -0.075, 3, 3, largeur_ecran, hauteur_ecran, 2.4);
    //vector<vector<int>> test = mandelbrot(1.5, 0.0, largeur_ecran, hauteur_ecran, 6.5, 2.5);

    //displayAscii(test, MAX_ITERATIONS);
    //displayIterations(test, MAX_ITERATIONS);

    return 0;
}

