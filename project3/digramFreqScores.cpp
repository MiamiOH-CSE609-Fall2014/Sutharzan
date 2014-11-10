#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include "digramFreqScores.h"

// This function creates a map of digram frequencies
map<string, int> digramFreqScores(string s) {
    map<string, int> scores = { // Map to store the digram frequencies
        {"AA", 0},
        {"AG", 0},
        {"AC", 0},
        {"AT", 0},
        {"GA", 0},
        {"GG", 0},
        {"GC", 0},
        {"GT", 0},
        {"CA", 0},
        {"CG", 0},
        {"CC", 0},
        {"CT", 0},
        {"TA", 0},
        {"TG", 0},
        {"TC", 0},
        {"TT", 0}
    };
    for (int i = 0; i < (s.length()-1); ++i) { // Calculating the digram frequencies
        ++scores[s.substr(i,2)];
    }
    return scores;
}

