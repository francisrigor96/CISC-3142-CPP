#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <set>
#include <cstdio>
#include "courseReport.h"

using namespace std;

// This function prints out the contents of the file
void printInput(vector < string > v, FILE * oFile) {
  for (int j = 1; j < v.size(); j++)
    fprintf(oFile, "%s %s %s %s %s %s\n", v[j].c_str(), v[j].c_str(), v[j].c_str(), v[j].c_str(), v[j].c_str(), v[j].c_str());
}

// This function gets the rate of passing grades in the file
void getPassingRate(set < string > set, vector < string > vGrade, vector < string > vec, FILE * oFile) {
  int classSize;
  double passingGrade;

  // Iterator
  for (string const & seti: set) {
    classSize = 0;
    passingGrade = 0;
    cout << seti << endl;
    for (int q = 1; q < vec.size(); q++) {
      // Check how many of these total iterated elements have a passing grade
      if (vec[q] == seti) {
        if ((vGrade[q] == "A" || vGrade[q] == "A+" || vGrade[q] == "A-" || vGrade[q] == "B" || vGrade[q] == "B+" ||
            vGrade[q] == "B-" || vGrade[q] == "C" || vGrade[q] == "C+" || vGrade[q] == "C-" || vGrade[q] == "CR" || vGrade[q] == "P")) {
          passingGrade++;
        }
        classSize++;
      }
    }
    fprintf(oFile, "\nPassing rate for %s is %lf%", seti.c_str(), passingGrade / classSize * 100);
    //cout << "Passing rate for" << seti << " is " <<  passingGrade / vGrade.size() * 100 << "%" << endl;
  }
}

// This function gets how much of the grade W is in the file
void getRateOfW(set < string > set, vector < string > vGrade, vector < string > vec, FILE * oFile) {
  double gradeIsW;
  int classSize;
  
  // Iterator
  for (string const & seti: set) {
    gradeIsW = 0;
    classSize = 0;
    // Check how many of these total iterated elements have a passing grade
    for (int q = 1; q < vec.size(); q++) {
      if (vec[q] == seti) {
        if (vGrade[q] == "W") {
          gradeIsW++;
        }
        classSize++;
      }
    }
    fprintf(oFile, "\nW rate for %s is %lf%", seti.c_str(), gradeIsW / classSize * 100);
    //cout << "W rate for " << seti << " is " << gradeIsW / vGrade.size() * 100 << "%" << endl;
  }
}
