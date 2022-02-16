/*
	Code modified by Francis Rigor
*/

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <set>
#include <numeric>

using namespace std;

int main() {

  // define variables
  string sku, brand, category, year, price;

  // Vector variables
  vector <int> vSKU;
  vector <string> vBrand;
  vector <string> vCategory;
  vector <int> vYear;
  vector <float> vPrice;

  // Set
  set < int > setYear;

  // Files
  ifstream in_stream; // Input file
  in_stream.open("data.csv"); //opening the input file.
  ofstream oFile;
  oFile.open("HW1output.txt");

  if (!in_stream.fail()) { //if the file is open

    string line;

    while (in_stream.peek() != EOF) { //while the end of file is NOT reached    	

      getline(in_stream, sku, ',');
      stringstream ssku(sku);
      int iSKU = 0;
      ssku >> iSKU;
      vSKU.push_back(iSKU);

      getline(in_stream, brand, ',');
      vBrand.push_back(brand);

      getline(in_stream, category, ',');
      vCategory.push_back(category);

      getline(in_stream, year, ',');
      stringstream syear(year);
      int iYear;
      syear >> iYear;
      vYear.push_back(iYear);
      setYear.insert(iYear);

      getline(in_stream, price, '\n');
      stringstream sprice(price);
      float fPrice;
      sprice >> fPrice;
      vPrice.push_back(fPrice);
    }
    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;
  } else {
    cout << "Unable to open file";
  }

  /************************STEP 1: OUTPUT CONTENTS OF CSV FILE*******************/
  oFile << "SKU" << "\t" << "Brand" << "\t" << "Category" << "Year" << "\t" << "Price" << endl;

  for (int j = 1; j < vSKU.size(); j++) {
    oFile << vSKU[j] << "\t" << vBrand[j] << "\t" << vCategory[j] << "\t" << vYear[j] << "\t" << vPrice[j] << endl;
  }

  cout << endl;
  /************************STEP 2: GET AVERAGE OF ALL BRANDS AND CATEGORY***********************/
  // Get Average of brand ABC
  float sumBrandABC = 0;
  int count = 0;
  for (int a = 0; a < vBrand.size(); a++) {
    if (vBrand.at(a) == "ABC") {
      sumBrandABC += vPrice.at(a);
      count++;
    }
  }
  oFile << "\nAverage of brand ABC = " << sumBrandABC / count << endl;

  // Get Average of brand XYZ
  float sumBrandXYZ = 0;
  count = 0;
  for (int b = 0; b < vBrand.size(); b++) {
    if (vBrand.at(b) == "XYZ") {
      sumBrandXYZ += vPrice.at(b);
      count++;
    }
  }
  oFile << "Average of brand XYZ = " << sumBrandXYZ / count << endl;

  // Get Average of category A
  float sumCatA = 0;
  count = 0;
  for (int c = 0; c < vCategory.size(); c++) {
    if (vCategory.at(c) == "A") {
      sumCatA += vPrice.at(c);
      count++;
    }
  }
  oFile << "Average of category A = " << sumCatA / count << endl;

  // Get Average of category B
  float sumCatB = 0;
  count = 0;
  for (int d = 0; d < vCategory.size(); d++) {
    if (vCategory.at(d) == "B") {
      sumCatB += vPrice.at(d);
      count++;
    }
  }
  oFile << "Average of category B = " << sumCatB / count << endl;

  // Get Average of category C
  float sumCatC = 0;
  count = 0;
  for (int e = 0; e < vCategory.size(); e++) {
    if (vCategory.at(e) == "C") {
      sumCatC += vPrice.at(e);
      count++;
    }
  }
  oFile << "Average of category C = " << sumCatC / count << endl;

  /************************STEP 3: LIST OUT UNIQUE YEARS AND SKU************************************/
  // Creating a iterator pointing to start of set
  set < int > ::iterator it = setYear.begin();
  // Iterate till the end of set
  while (it != setYear.end()) {
    int SKUcount = 0;
    oFile << "\n" << ( * it) << ": ";
    for (int f = 1; f < vYear.size(); f++) {
      if (vYear.at(f) == ( * it)) {
        oFile << vSKU.at(f) << " ";
        SKUcount++;
      }
    }
    oFile << "| SKU count: " << SKUcount;

    //Increment the iterator
    it++;
  }
  oFile << "\n\nProgram modifications by Francis Rigor" << endl;
  oFile.close();
  return 0;
} // END OF PROGRAM
