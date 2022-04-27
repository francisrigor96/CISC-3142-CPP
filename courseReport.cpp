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
void printInput(vector<string> v) {
	for (int j = 1; j < v.size(); j++) 
     printf("%s %s %s %s %s %s\n", v[j].c_str(), v[j].c_str(), v[j].c_str(), v[j].c_str(), v[j].c_str(), v[j].c_str());
}

// This function gets the rate of passing grades in the file
void getPassingRate(set<string> set, vector<string> vGrade, vector<string> vec) {
	double passingGrade = 0;

  // Iterator
  for (string const & seti: set) {
    passingGrade = 0;
    for (int q = 1; q < vec.size(); q++) {
      // Check how many of these total iterated elements have a passing grade
      if (vec[q] == seti && (vGrade[q] == "A" || vGrade[q] == "A+" || vGrade[q] == "A-" || vGrade[q] == "B" || vGrade[q] == "B+" ||
          vGrade[q] == "B-" || vGrade[q] == "C" || vGrade[q] == "C+" || vGrade[q] == "C-" || vGrade[q] == "CR" || vGrade[q] == "P")) 
        passingGrade++;
    } 
    printf("\nPassing rate for %s is %lf%", seti.c_str(), passingGrade / vGrade.size() * 100);
    //cout << "Passing rate for" << seti << " is " <<  passingGrade / vGrade.size() * 100 << "%" << endl;
  } 
}

// This function gets how much of the grade W is in the file
void getRateOfW(set<string> set, vector<string> vGrade, vector<string> vec) {
	double gradeIsW = 0;
  
  // Iterator
  for (string const & seti: set) {
    gradeIsW = 0;
    // Check how many of these total iterated elements have a passing grade
    for (int q = 1; q < vec.size(); q++) {
      if (vec[q] == seti && vGrade[q] == "W") 
        gradeIsW++;
    }
	printf("\nW rate for %s is %lf%", seti.c_str(), gradeIsW / vGrade.size() * 100); 
    //cout << "W rate for " << seti << " is " << gradeIsW / vGrade.size() * 100 << "%" << endl;
  } 
}
