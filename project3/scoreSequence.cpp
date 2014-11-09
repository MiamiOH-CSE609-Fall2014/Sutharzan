#include <string>
#include <vector>
#include <map>
#include "scoreSequence.h"
#include "parseScoringFile.h"

using namespace std;

pair<int, int> scoreSequence(string haystack, string needle, vector<vector<int>> scoring_m) {
    pair<int, int> maxWordScore = {0,0};
    map<char, int> scorePosDict = {
        {'A', 0},
        {'G', 1},
        {'C', 2},
        {'D', 3}
    };
    int score = 0;
    string word;
    int wordLength = needle.length();

    for (int i = 0; i < (haystack.length() - wordLength + 1); ++i) {
        word = haystack.substr(i, wordLength);
        for (int j = 0; j < wordLength; ++j) {
            score += scoring_m[scorePosDict[word[j]]][scorePosDict[needle[j]]];
        }
        
        if(score >= maxWordScore.second){
            maxWordScore.first = i;
            maxWordScore.second = score;
        }
        score = 0;
    }
    return maxWordScore;
}
