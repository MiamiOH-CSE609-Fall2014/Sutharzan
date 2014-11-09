#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include "digramFreqScores.h"

map<string, int> digramFreqScores(string s) {
    map<string, int> diData = {
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
    for (int i = 0; i < (s.length()-1); ++i) {
        ++diData[s.substr(i,2)];
    }
    return diData;
}

