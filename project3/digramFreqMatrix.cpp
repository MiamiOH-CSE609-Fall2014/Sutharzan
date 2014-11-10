#include <string>
#include <vector>
#include <map>
#include "digramFreqMatrix.h"
#include <iostream>
using namespace std;

// This function conrverts a map of digram frequencies to matrix form
vector<vector<int>> digramFreqMatrix(map<string, int> d) {

    // Vectorizing the map
    vector<int> diVec;
    for (const pair<string, int> &ind : d) {
        diVec.push_back(ind.second);
    }    
    vector<vector <int> > m; // Matrix to store the digram frequencies
    vector<int> tempVec; // A temporary vector to store intermediate results
    int pos = 0; // Indicating the position of diVec
    for (int i = 0; i < 4; ++i) { // Generating the matrix
        for (int j = 0; j < 4; ++j) {
            tempVec.push_back(diVec.at(pos));
            ++pos;
        }
        m.push_back(tempVec);
        tempVec.clear();
    }
    
    // Reordering matrix
    int temp;
    for (int i = 0; i < 4; i++) { 
        temp = m[i][1];
        m[i][1] = m[i][2];
        m[i][2] = temp;
    }
    tempVec = m[1];
    m[1] = m[2];
    m[2] = tempVec;
    return m;
}
