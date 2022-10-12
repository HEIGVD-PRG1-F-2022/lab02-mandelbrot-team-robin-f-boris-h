/*
 * Fichier : animation.cpp
 * Autheur : Boris Hutzli, Robin Forestier
 * Date    : 13.10.22
 *
 * But     : Contient la fonction permettant de faire des animations sur le mandelbrot set (zoom chaque x secondes)
 */


#include <chrono>
#include <thread>
#include "mandelbrot.h"
#include "display.h"

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

const int MAX_ITERATIONS = 1000;    // Nombre d'itérations

/*
 * Permet de faire des zoom dans le set de mandelbrot
 *
 * @param int delay = 3000 : Temps en secondes entre chaque zoom
 * @param int animationCount = 10 : Nombre de zooms à faire
 * @param double centreX = 0 : Coordonée X du centre.
 * @param double centreY = 0 : Coordonée Y du centre.
 * @param double dX = 3 : Largeur du visuel.
 * @param double dY = 3 : Hauteur du visuel.
 * @param int nX = 30 : Nombres de pixels horizontal.
 * @param int nY = 30 : Nombres de pixels vertical.
 * @param double zoomFactor = 1.9 : Le diviseur pour faire l'effet de zoom
 */
void zoom (int delay = 3000, int animationCount = 10, double centreX = 0, double centreY = 0, double dx = 3,
           double dy = 3, int nX = 60, int nY = 60, double zoomFactor = 1.9) {

    for (int i = 0; i < animationCount; i++) {
        vector<vector<int>> generatedData = mandelbrot(centreX, centreY,  nX, nY, dx, dy, MAX_ITERATIONS);
        displayAscii(generatedData, MAX_ITERATIONS);
        sleep_for(chrono::milliseconds (delay));
        dx /= zoomFactor;
        dy /= zoomFactor;
    }
}