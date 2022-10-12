/*
 * Fichier : display.cpp
 * Autheur : Boris Hutzli, Robin Forestier
 * Date    : 13.10.22
 *
 * But     : Contient des fonctions liées à l'affichage du set de mandelbrot (affichage avec des caractères ascii
 *           ou affichage des itérations)
 */


#include "display.h"
#include <vector>
#include <iostream>
#include <iomanip> // for setw

using namespace std;

//const vector<int> ASCII_DISPLAYS = {'.', 'o', '|', '0', '*', '#'};
//const vector<int> ASCII_DISPLAYS = {'.', ',', ';', '!', 'v', 'l', 'L', 'F', 'E', '$'};
const vector<int> ASCII_DISPLAYS = {' ', '.', ',', '*', '/', '(', '#', '%', '&', '@'};

/*
 * Affichage du set de mandelbrot en utilisant les caractères ASCII définit dans la constante ASCII_DISPLAYS
 *
 * @param vector<vector<int>> iterations : Vecteur contenant les nombres d'itérations pour chaque pixel
 * @param int maxIterations : Nombre d'itérations maximum pour chaque pixel, utilisé pour calculer le char ascii à
 *                            utiliser
 */
void displayAscii(vector<vector<int>> iterations, int maxIterations) {
    string mandelbrotChar = "";
    for (int pY = 0; pY < iterations.size(); pY ++) {
        for (int pX = 0; pX < iterations[pY].size(); pX ++) {
            //int currentIterations = iterations[pX][pY];
            int currentIterations = iterations[pY][pX];
            int asciiIndex = (currentIterations * ASCII_DISPLAYS.size() - 1) / maxIterations;
            char currentAscii = ASCII_DISPLAYS[asciiIndex];
            //cout << currentAscii << " ";
            mandelbrotChar += currentAscii;
        }
        //cout << endl;
        mandelbrotChar += '\n';
    }

    cout << mandelbrotChar;
}

/*
 * Affichage du set de mandelbrot avec les nombre d'itérations
 *
 * @param vector<vector<int>> iterations : Vecteur contenant les nombres d'itérations pour chaque pixel
 * @param int maxIterations : Nombre d'itérations maximum pour chaque pixel, utilisé pour calculer
 */
void displayIterations(vector<vector<int>> iterations, int maxIterations) {

    int maxLenght = 0;

    while (maxIterations > 0) {
        maxLenght ++;
        maxIterations /= 10;
    }

    for (int pY = 0; pY < iterations.size(); pY ++) {
        for (int pX = 0; pX < iterations[pY].size(); pX ++) {
            cout << setw(maxLenght) << iterations[pY][pX] << " ";
        }
        cout << endl;
    }
}
