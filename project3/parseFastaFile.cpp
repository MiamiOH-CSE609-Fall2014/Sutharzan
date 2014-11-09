#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include "parseFastaFile.h"

using namespace std;

tuple<string,vector<string>,string> parseFastaFile(string filename) {
    fstream file;
    string line;
    string header;
    string sequence = "";
    vector<string> comment;
    file.open(filename,fstream::in);
    while (getline(file, line)) {
        if (line.at(0) == '>') {
            header = line;
        } else if (line.at(0) == ';') {
            comment.push_back(line);
        } else {
            sequence += line;
        }
    }
    file.close();
    tuple<string,vector<string>,string> fastaData {header,comment,sequence};
    return fastaData;
}
