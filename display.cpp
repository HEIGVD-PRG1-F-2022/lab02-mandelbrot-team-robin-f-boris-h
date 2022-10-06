#include "display.h"
#include <vector>
#include <iostream>

using namespace std;

const vector<int> asciiDisplays = {'.', 'o', '|', '0', '*', '#'};

void displayAscii(vector<vector<int>> iterations, int maxIterations) {
    for (int pY = 0; pY < iterations.size(); pY ++)
    {
        for (int pX = 0; pX < iterations[pY].size(); pX ++)
        {
            int currentIterations = iterations[pX][pY];
            int asciiIndex = (currentIterations * asciiDisplays.size() - 1) / maxIterations;
            char currentAscii = asciiDisplays[asciiIndex];
            cout << currentAscii << " ";
        }
        cout << endl;
    }
}

void displayIterations(vector<vector<int>> iterations, int maxIterations) {
    for (int pY = 0; pY < iterations.size(); pY ++)
    {
        for (int pX = 0; pX < iterations[pY].size(); pX ++)
        {
            cout << iterations[pX][pY] << " "; // TODO : tostring to get length
        }
        cout << endl;
    }
}
