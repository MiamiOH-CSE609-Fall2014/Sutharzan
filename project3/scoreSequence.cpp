#include <string>
#include <vector>
#include <map>
#include "scoreSequence.h"
#include "parseScoringFile.h"

using namespace std;

// This function stores sequenence alignments
pair<int, int> scoreSequence(string haystack, string needle, vector<vector<int>> scoring_m) {
    pair<int, int> maxWordScore = {0,0}; // Tuple score the maximum score and position (position is stored first)
    map<char, int> scorePosDict = { // A map to annotated the scoring_m indices
        {'A', 0},
        {'G', 1},
        {'C', 2},
        {'T', 3}
    };
    int score = 0; // Variable to store the score of an alignment
    string word; // String to store a word from haystack
    int wordLength = needle.length(); // Length of needle sequence
    for (int i = 0; i < (haystack.length() - wordLength + 1); ++i) {// Aligning the sequences
        word = haystack.substr(i, wordLength); // Extracting a word from the haystack
        for (int j = 0; j < wordLength; ++j) { // Scoring a word alignment
            score += scoring_m[scorePosDict[word[j]]][scorePosDict[needle[j]]];
        }        
        if(score >= maxWordScore.second){ // Finding a maximum alignment
            maxWordScore.first = i;
            maxWordScore.second = score;
        }
        score = 0;
    }
    return maxWordScore;
}
