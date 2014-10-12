/* 
 * File:   project2.cpp
 * Author: sreesks
 *
 * Created on 09 October 2014, 13:24
 */

#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
 * 
 */
float score = 0; // User input score
float ptot = 0; // Total score
float pmean = 0; // Average score
float pstd = 0; // Standard deviation
float stdtemp = 0; // Temporary value for std
float pn = 0; // Number of students
string name; // User input name
string temp; // Temporary string
vector<float> scoreVec; // Score vector
vector<float> thresVec; // Letter grade threshold vector
vector<string> nameVec; // Name vector

void printSingleThres(float pThres) { // Handles cases where the letter grade threshold is not in 0-100 range    
    if (pThres < 0){
    cout << "below ";
        printf("%.1f", 0.0);
    }
    else if (pThres > 100)  {
        cout << "above ";
        printf("%.1f", 100.0);
    }
    else {
        printf("%.1f", pThres);
    } 
}

void printRangeThres(float pUpperThres, float pLowerThres) { //Prints the letter grade ranges
    printSingleThres(pLowerThres);
    cout << "% - ";
    printSingleThres(pUpperThres);
    cout << "%" << endl << endl;
}

void gradeThres() { // Calculates and displays the letter grade ranges
    //Thresholds for grades
    thresVec.push_back((pmean + pstd * 1.5)); // A
    thresVec.push_back((pmean + pstd * 0.5)); // B
    thresVec.push_back((pmean - pstd * 0.5)); // C
    thresVec.push_back((pmean - pstd * 1.5)); // D

    // Printing grading scale
    cout << endl;
    cout << "Grading scale" << endl << endl;
    //A    
    cout << "A above ";
    if (thresVec[0] <= 100) {
        printf("%.1f", thresVec[0]);
    } else {
        printf("%.1f", 100.0);
    }
    cout << "%" << endl << endl;
    //B    
    cout << "B ";
    printRangeThres(thresVec[0],thresVec[1]);
    //C
    cout << "C ";
    printRangeThres(thresVec[1],thresVec[2]);
    //D
    cout << "D ";
    printRangeThres(thresVec[2],thresVec[3]);
    //F
    cout << "F below ";
    if (thresVec[3] >= 0) {
        printf("%.1f", thresVec[3]);
    } else {
        printf("%.1f", 0.0);
    }
    cout << "%" << endl << endl;
}

string curve(float pGrade) { // Mapps the letter grades for the scores
    string sGrade;
    if(pGrade > thresVec[0]){ // A
        sGrade = "A";
    }
    else if ((pGrade <= thresVec[0] && pGrade > thresVec[1]) || (thresVec[0] == thresVec[1]) ){ //B
        sGrade = "B";
    }
    else if (pGrade <= thresVec[1] && pGrade > thresVec[2]){ // C
        sGrade = "C";
    }
    else if (pGrade <= thresVec[2] && pGrade > thresVec[3]){ // D
        sGrade = "D";
    }
    else if (pGrade <= thresVec[3]){ // F
        sGrade = "F";
    }
    return sGrade;
}

int main(int argc, char** argv) { // main method

    // Accepting input
    do {
        do {
            cout << "Please enter a student’s name, or ‘none’ to quit.\n";
            cout << "Name: ";
            getline(cin, name);
        } while (name.empty());
        if (name != "none") { // Accepting input until "none" is typed
            nameVec.push_back(name); // Storing names
            do {
                cout << "Enter score.\n";
                cout << "Score: ";
                getline(cin, temp);
                score = atof(temp.c_str());
                if (temp.empty() || score < 0 || score > 100) { // Checking for valid score range
                    cout << "Score must be in the range of 0-100. Please re enter score.";
                }
            } while (temp.empty() || score < 0 || score > 100);

            scoreVec.push_back(score); // Storing scores
            ptot += score;
        }

    } while (name != "none");

    // Calculating the stats
    if (!nameVec.empty()) {
        pn = float(scoreVec.size());
        if (pn > 0) {
            pmean = ptot / pn; // Calculating mean

            for (int i = 0; i < scoreVec.size(); ++i) { // Calculating standard deviation
                stdtemp += pow((scoreVec[i] - pmean), 2);
            }
            pstd = sqrt(stdtemp / pn);
        }

        // Printing grading scale
        gradeThres();

        // Printing the grades of students
        cout << endl;
        printf("%-30s", "Name");
        printf("%-30s", "Score");
        printf("%-30s", "Grade");
        cout << endl;
        for (int i = 0; i < nameVec.size(); ++i) { // Printing the grade of each student
            printf("%-30s", nameVec[i].c_str());
            printf("%-.1f%%", scoreVec[i]);
            if(scoreVec[i]>99.95)
            printf("%25s",curve(scoreVec[i]).c_str());
            else if (scoreVec[i]>9.95)
                printf("%26s",curve(scoreVec[i]).c_str());
            else
                printf("%27s",curve(scoreVec[i]).c_str());
            cout << endl;
        }
        cout << endl;
        cout << "Class average = "; // Printing class average
        printf("%.2f", pmean);
        cout << "%\n";
        cout << "Standard Deviation = "; // Printing standard deviation
        printf("%.2f", pstd);
        cout << endl;
    } else {
        cout << "No student grade records entered." << endl;
        cout << endl;
    }

    return 0;
}

