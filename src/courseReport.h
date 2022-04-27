#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <set>
#include <cstdio>
#ifndef COURSEREPORT_H
#define COURSEREPORT_H

using namespace std;

void sayHello();
void printInput(vector<string> v);
void getPassingRate(set<string> set, vector<string> vGrade, vector<string> vInstructor);
void getRateOfW(set<string> set, vector<string> vGrade, vector<string> vInstructor);

#endif


