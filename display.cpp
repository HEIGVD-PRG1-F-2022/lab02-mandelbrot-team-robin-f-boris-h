#include "display.h"
#include <vector>
#include <iostream>
# include <string>
#include <iomanip> // for setw

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

    int maxLenght = 0;
    while (maxIterations > 0)
    {
        maxLenght ++;
        maxIterations /= 10;
    }

    for (int pY = 0; pY < iterations.size(); pY ++)
    {
        for (int pX = 0; pX < iterations[pY].size(); pX ++)
        {
            cout << setw(maxLenght) << iterations[pX][pY] << " "; // setw(size(to_string(maxIterations)))
        }
        cout << endl;
    }
}
