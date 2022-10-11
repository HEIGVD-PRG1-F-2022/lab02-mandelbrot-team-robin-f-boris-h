/*
 * Fichier : mandelbrot.cpp
 * Autheur : Boris Hutzli, Robin Forestier
 * Date    : 13.10.22
 *
 * But     : La fonction mandelbrot est l'implémentation du pseudo code de wikipedia :
 *           https://en.wikipedia.org/wiki/Mandelbrot_set#Computer_drawings
 */

#include <vector>
using namespace std;

//const int MAX_ITERATIONS = 1000;

/*
 * La fonction mandelbrot est l'implémentation du pseudo code de wikipedia :
 * https://en.wikipedia.org/wiki/Mandelbrot_set#Computer_drawings
 *
 * @param double x1 = 2 : Coordonée X du coin en haut à gauche.
 * @param double y1 = 1.12 : Coordonée Y du coin en haut à gauche.
 * @param double x2 = 0.47 : Coordonée X du coin en bas à droite.
 * @param double y2 = -1.12 : Coordonée Y du coin en bas à droite.
 * @param int nX = 30 : Nombres de pixels horizontal.
 * @param int nY = 30 : Nombres de pixels vertical.
 * @param int maxIterations = 1000 : Nombres d'itération maximum pour le calcul de chaque pixels.
 * @return vector<vector<int>> : Vector 2D contenant les valeurs d'iterations.
 */
vector<vector<int>> mandelbrot(double x1 = -2, double y1 = 1.12, double x2 = 0.47, double y2 = -1.12, int nX = 30,
                               int nY = 30, int maxIterations = 1000) {

    vector<vector<int>> pixelData(nX, vector<int>(nY, 0));

    for (int i = 0; i < nX; i++) {
        double x0 = x1 + ((x2 - x1) / nX) * i;

        for (int j = 0; j < nY; j++) {
            double y0 = y1 + ((y2 -y1) / nY) * j;
            double x = 0;
            double y = 0;

            int iterations = 0;

            while (x*x + y*y <= 2*2 && iterations < maxIterations) {
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

/*
 * Surcharge de la fonction mandelbrot, prenant en paramètre le centre du visuel, la largeur et la hauteur.
 *
 * @param double centreX = 0 : Coordonée X du centre.
 * @param double centreY = 0 : Coordonée Y du centre.
 * @param int nX = 30 : Nombres de pixels horizontal.
 * @param int nY = 30 : Nombres de pixels vertical.
 * @param double dX = 3 : Largeur du visuel.
 * @param double dY = 3 : Hauteur du visuel.
 * @param int maxIterations = 1000 : Nombres d'itération maximum pour le calcul de chaque pixels.
 * @return vector<vector<int>> : Vector 2D contenant les valeurs d'iterations.
 */
vector<vector<int>> mandelbrot(double centreX = 0, double centreY = 0, int nX = 30, int nY = 30, double dX = 3,
                               double dY = 3, int maxIterations = 1000) {

    // calcule des coins par rapport aux centre, la largeur et la hauteur.
    double x1 = centreX - (dX / 2);
    double x2 = centreX + (dX / 2);
    double y1 = centreY + (dY / 2);
    double y2 = centreY - (dY / 2);

    return mandelbrot(x1, y1, x2, y2, nX, nY, maxIterations);
}