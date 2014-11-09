#include <string>
#include <vector>
#include <tuple>
#include "scoreSequence.h"


using namespace std;

tuple<int, int, string> findHighScore(string haystack, vector<string> needles, vector<vector<int>> scoring_m) {
    tuple <int, int, string> high_scorer;
    pair<int, int> score;
    score = scoreSequence(haystack, needles[0], scoring_m);
    get<0>(high_scorer) = score.first;
    get<1>(high_scorer) = score.second;
    get<2>(high_scorer) = needles[0];
    for (int i = 1; i < needles.size(); ++i) {
        score = scoreSequence(haystack, needles[i], scoring_m);
        if (score.second > get<1>(high_scorer)) {
            get<0>(high_scorer) = score.first;
            get<1>(high_scorer) = score.second;
            get<2>(high_scorer) = needles[i];
        }
    }
    return high_scorer;
}
