#include <string>
#include <vector>
#include <map>
#include "digramFreqMatrix.h"
#include <iostream>
using namespace std;

vector<vector<int>> digramFreqMatrix(map<string, int> d) {

    // Vectorizing the map
    vector<int> diVec;
    for (const pair<string, int> &ind : d) {
        diVec.push_back(ind.second);
    }

    // Generating the matrix
    vector<vector <int> > diMat;
    vector<int> tempVec;

    int pos = 0; // Indicating the position of diVec
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {

            tempVec.push_back(diVec.at(pos));
            ++pos;
        }
        diMat.push_back(tempVec);
        tempVec.clear();
    }
    int temp;
    for (int i = 0; i < 4; i++) {
        temp = diMat[i][1];
        diMat[i][1] = diMat[i][2];
        diMat[i][2] = temp;
    }
    tempVec = diMat[1];
    diMat[1] = diMat[2];
    diMat[2] = tempVec;
    return diMat;
}
