//
// Created by boris on 06.10.2022.
//

#include <chrono>
#include <thread>
#include "mandelbrot.h"
#include "display.h"

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

const int MAX_ITERATIONS = 1000;
const double ZOOM_FACTOR = 1.1;

void zoom (int delay = 3, int animationCount = 10, double centreX = 0, double centreY = 0, double dx = 3, double dy = 3, int nX = 120, int nY = 60) {
    for (int i = 0; i < animationCount; i++) {
        vector<vector<int>> generatedData = mandelbrot(centreX, centreY,  nX, nY, dx, dy, MAX_ITERATIONS);
        displayAscii(generatedData, MAX_ITERATIONS);
        sleep_for(chrono::seconds(delay));
        dx /= ZOOM_FACTOR;
        dy /= ZOOM_FACTOR;
    }
}