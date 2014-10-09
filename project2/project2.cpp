/* 
 * File:   project1.cpp
 * Author: sreesks
 *
 * Created on 09 October 2014, 13:24
 */

#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
float score = 0;
string name;
string temp;
vector<float> scoreVec;
vector<string> nameVec;

int main(int argc, char** argv) {

    do {
        cout << "Please enter a student’s name, or ‘none’ to quit.\n";
        cout << "Name: ";
        getline(cin, name);
        nameVec.push_back(name);
        if (name != "none") {
            
            do{
            cout << "Enter score.\n";
            cout << "Score: ";
            getline(cin, temp);
            score = atof(temp.c_str());
            if(score < 0 || score > 100){
                cout << "Score must be in the range of 0-100. Please re enter score."; 
            }
            }
            while(score < 0 || score > 100);
            
            scoreVec.push_back(score);
        }

    } while (name != "none");
    return 0;
}

