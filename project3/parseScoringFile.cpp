#include <vector>
#include <fstream>
#include <string>
#include "parseScoringFile.h"

using namespace std;

vector<vector<int>> parseScoringFile(string fName) {
    fstream file;
    vector<vector<int>> scoreVec;
    vector<int> tempVec;
    string tempScore;
    file.open(fName, fstream::in);
    while (getline(file, tempScore, ',')) {
        // Filling tempVector
        tempVec.push_back(atoi(tempScore.c_str()));
        getline(file, tempScore, ',');
        tempVec.push_back(atoi(tempScore.c_str()));
        getline(file, tempScore, ',');
        tempVec.push_back(atoi(tempScore.c_str()));
        getline(file, tempScore);
        tempVec.push_back(atoi(tempScore.c_str()));
        // Filling scoreVec
        scoreVec.push_back(tempVec);
        tempVec.clear();    
    }
    file.close();
    return scoreVec;
}

