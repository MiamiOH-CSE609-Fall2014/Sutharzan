/* 
 * File:   project3.cpp
 * Author: manager
 *
 * Created on 04 November 2014, 02:31
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include "parseFastaFile.h"
#include "digramFreqScores.h"
#include "digramFreqMatrix.h"
#include "parseScoringFile.h"
#include "scoreSequence.h"
#include "findHighScore.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string fileName = argv[1];
    string scoreFilePath = argv[2];

    // Calling parseFastaFile
    tuple<string, vector<string>, string> fastaData = parseFastaFile(fileName);
    string seq = get<2>(fastaData); // Sequence

    // Calling digramFreqScore
    map<string, int> diData = digramFreqScores(seq);
    vector<vector<int>> diVecData = digramFreqMatrix(diData); // Generating digram matrix

    //Printing the digram frequency matrix
    cout << endl;
    cout << "Digram Frequency Matrix:" << endl;
    string row = "AGTC";
    cout << "  A G T C" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << row[i] << " ";
        for (int j = 0; j < 4; ++j) {
            cout << diVecData[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Calling parseScoringFile
    vector<vector<int>> scoreVecData = parseScoringFile(scoreFilePath);
    
    // Printing the scoring frequency matrix
    cout << "Scoring Matrix:" << endl;   
    cout << "  A G T C" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << row[i] << " ";
        for (int j = 0; j < 4; ++j) {
            cout << scoreVecData[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Getting the list of string from the user
    cout << "How many sequences would you like to score? ";
    string tmpStr;
    getline(cin, tmpStr);
    cout << endl;
    vector<string> seqs;
    int num_seq = atoi(tmpStr.c_str());
    for (int i = 0; i < num_seq; ++i) {
        cout << "Enter sequence #" << i + 1 << " in a single line." << endl;
        getline(cin, tmpStr);
        seqs.push_back(tmpStr); 
    }
    cout << endl;

    //Calling findHighScore
    tuple<int, int, string> highScorerTup = findHighScore(seq, seqs, scoreVecData);
    cout << "Sequence:" << endl << get<2>(highScorerTup) << endl
            << "Score: " << get<1>(highScorerTup) << " at position " << get<0>(highScorerTup) << endl <<endl;

    return 0;
}

