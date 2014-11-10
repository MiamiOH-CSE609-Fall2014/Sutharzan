#include <string>
#include <vector>
#include <tuple>
#include "scoreSequence.h"

using namespace std;

// This function finds the highest scoring needle
tuple<int, int, string> findHighScore(string haystack, vector<string> needles, vector<vector<int>> scoring_m) {
    tuple <int, int, string> high_scorer; // Tuple to store the highest scorer
    pair<int, int> score; // A pair to store an alignment results
    
    // Aligning the needeles and finding the highest scorer
    score = scoreSequence(haystack, needles[0], scoring_m); // Performing the initial alignment
    get<0>(high_scorer) = score.first;
    get<1>(high_scorer) = score.second;
    get<2>(high_scorer) = needles[0];
    for (int i = 1; i < needles.size(); ++i) {
        score = scoreSequence(haystack, needles[i], scoring_m); // Performing alignment
        if (score.second > get<1>(high_scorer)) { // Storing the highest scorer
            get<0>(high_scorer) = score.first;
            get<1>(high_scorer) = score.second;
            get<2>(high_scorer) = needles[i];
        }
    }
    return high_scorer;
}
