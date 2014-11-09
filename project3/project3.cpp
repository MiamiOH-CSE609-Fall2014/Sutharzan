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

    //Printing the matrix
    cout << "[";
    for (int i = 0; i < 4; ++i) {
        cout << "[";
        for (int j = 0; j < 4; ++j) {
            cout << diVecData[i][j];
            if (j < 3) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < 3) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << endl;

    // Calling parseScoringFile
    vector<vector<int>> scoreVecData = parseScoringFile(scoreFilePath);

    // Getting the list of string from the user
    cout << "How many sequences would you like to score?";
    string tmpStr;
    getline(cin, tmpStr);
    vector<string> seqs;
    int num_seq = atoi(tmpStr.c_str());
    for (int i = 0; i < num_seq; ++i) {
        cout << "Enter string No." << i << ": ";
        getline(cin,tmpStr);
        seqs.push_back(tmpStr);
    }
    cout << endl;
    
    //Calling findHighScore
    tuple<int,int,string> highScorerTup = findHighScore(seq,seqs,scoreVecData);
    cout <<"("<<get<0>(highScorerTup)<<", "<<get<1>(highScorerTup)<<", "<<get<2>(highScorerTup)<<")"<<endl;     

    return 0;
}

