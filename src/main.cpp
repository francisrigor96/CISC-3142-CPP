#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <set>
#include <cstdio>
#include "courseReport.cpp"

using namespace std;

struct courseReport {
  string emplID;
  string courseNum;
  string instructor;
  string termID;
  string sectionID;
  string grade;
};

int main(int argc, char * argv[]) {
	ifstream in_stream; // Input file
	FILE * oFile;
	oFile = fopen("output/HW3output.txt", "w"); // output to this file
	
  // Loop through the parameter arguments
  for (int i = 1; i < argc; i++) {
    // Creating a struct
    courseReport report;

    // Vector variables
    vector < string > vEmplID;
    vector < string > vCourseNum;
    vector < string > vInstructor;
    vector < string > vTermID;
    vector < string > vSectionID;
    vector < string > vGrade;

    // Sets
    set < string > setInstructor;
    set < string > setCourseNum;
    set < string > setGrade;

    // Files  
    in_stream.open(argv[i]); // opening the input file
    
    // Reading the input file
    if (!in_stream.fail()) { //if the file is open

      string line;

      while (in_stream.peek() != EOF) { //while the end of file is NOT reached    	
        getline(in_stream, report.emplID, ',');
        vEmplID.push_back(report.emplID);

        getline(in_stream, report.courseNum, ',');
        vCourseNum.push_back(report.courseNum);
        setCourseNum.insert(report.courseNum);

        getline(in_stream, report.instructor, ',');
        vInstructor.push_back(report.instructor);
        setInstructor.insert(report.instructor);

        getline(in_stream, report.termID, ',');
        vTermID.push_back(report.termID);

        getline(in_stream, report.sectionID, ',');
        vSectionID.push_back(report.sectionID);

        getline(in_stream, report.grade, '\n');
        vGrade.push_back(report.grade);
        setGrade.insert(report.grade);
      }
      in_stream.close(); //close the file 
    } else {
      printf("Unable to open file");
     
    }

    /************************STEP 1: OUTPUT TOTAL ROWS OF CSV FILE*******************/
    fprintf(oFile, "\nchecking data for course %s\n", report.courseNum.c_str());
    fprintf(oFile,"\ntotal=%d", vEmplID.size());

    /*************************STEP 2: PASS RATE PER INSTRUCTOR AND COURSE NUMBER*********************/

    // Get passing rate per instructor
    getPassingRate(setInstructor, vGrade, vInstructor, oFile);
    fprintf(oFile,"\n");

    // Get passing rate per course number
    getPassingRate(setCourseNum, vGrade, vCourseNum, oFile);
    printf("\n");

    /*************************STEP 3: W RATE PER INSTRUCTOR AND COURSE NUMBER************************/

    // Get W rate per instructor
    getRateOfW(setInstructor, vGrade, vInstructor, oFile);
    fprintf(oFile,"\n");

    // Get W rate per course number
    getRateOfW(setCourseNum, vGrade, vCourseNum, oFile);
    fprintf(oFile,"\n");

    //******************************STEP 4: PASS RATE FOR FALL AND SPRING***************************************
    fprintf(oFile,"\nNow in STEP 4. Checking for fall pass rate.");
    set < string > setFallTerm = {"T04","T08","T12","T16","T20","T23"};
    set < string > setSpringTerm = {"T02","T06","T10","T14","T18","T21"};

    //-----------------Pass rate for fall-------------------------------------------------------------
    getPassingRate(setFallTerm, vGrade, vTermID, oFile);

    //-----------------Pass rate for spring-------------------------------------------------------
    fprintf(oFile,"\nChecking for spring pass rate");
    getPassingRate(setSpringTerm, vGrade, vTermID, oFile);

    fprintf(oFile,"\n--------------------------------------------------------------------");
  }
  cout << "Files have been successfully read" << endl;
  fclose(oFile);
  return 0;
}
