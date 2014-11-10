#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include "parseFastaFile.h"

using namespace std;

// This function reads the fasta file data into a tuple
tuple<string,vector<string>,string> parseFastaFile(string filepath) {
    fstream file; // Input file stream
    string line; // Variable hold a line 
    string header; // Variable to hold a header
    string sequence = ""; // Variable to store the sequence
    vector<string> comment; // Vector to store the comments
    file.open(filepath,fstream::in); // Opening the file
    while (getline(file, line)) { // Reading the fasta file data
        if (line.at(0) == '>') {
            header = line;
        } else if (line.at(0) == ';') {
            comment.push_back(line);
        } else {
            sequence += line;
        }
    }
    file.close(); // Closing the file
    tuple<string,vector<string>,string> fastaData {header,comment,sequence}; // Creating the tuple containing the fasta file data
    return fastaData;
}
