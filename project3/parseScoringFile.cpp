#include <vector>
#include <fstream>
#include <string>
#include "parseScoringFile.h"

using namespace std;

// This function reads the score containing csv file into a matrix
vector<vector<int>> parseScoringFile(string fName) {
    fstream file; // Input file stream
    vector<vector<int>> scoreVec; // Score matrix
    vector<int> tempVec;
    string tempScore;
    file.open(fName, fstream::in); // Opening the file
    while (getline(file, tempScore, ',')) { // Reading the file into the matrix
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
    file.close(); // Closing the file
    return scoreVec;
}

