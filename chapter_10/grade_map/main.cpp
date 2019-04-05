#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool space(char c) {
  return isspace(c);
}

bool not_space(char c) {
  return !isspace(c);
}

void split (const string& str, vector<string>& words) {
 
  typedef string::const_iterator iter;
  
  iter it = str.begin();
  
  while(it != str.end()) {

    // Find start of first non space character
    it = find_if(it, str.end(), not_space);

    // Find end of first non space sequence
    iter jt = find_if(it, str.end(), space);
    
    if(it != str.end()) {
      // If there was a non space sequence make a new string
      // and save
      words.push_back(string(it, jt));
    }

    // reset start iterator to end of added sequence 
    it = jt;
  }
}

string grade(double mark) {
 
  // These arrays are statically allocated and persist accross invocations of grade
  static const double numbers[] = { 97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };
  static const char* const letters[] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };

  // calculate number of elements inside.
  size_t numLevels = sizeof(numbers) / sizeof(*numbers);

  // Find grade string
  for(size_t i = 0; i < numLevels; ++i) {
    if(mark >= numbers[i]) {
      return letters[i];
    }
  }

  // c++ programs should not contain two or more consecutive question marks
  return "?\?\?";
}

int main(int argc, char* argv[]) {

  //Read input file of grades from standard input
  if (argc < 2) {
    cerr << "No path for grades file supplied" << endl;
    return 1;
  }

  // Create an input stream to file. 
  ifstream ifile(argv[1]);

  // Exit with error if we were unable to open the text file
  if(ifile.fail()) {
    cerr << "unable to open file: " << argv[1] << endl;
    return 1;
  }

  string s;
  while(getline(ifile, s)) {
    
    // Split the file line into a collection of individual grade strings.
    vector<string> grades;
    split(s, grades);
    
    // Print the mark and associated grade to standard out
    for(vector<string>::const_iterator it = grades.begin(); it != grades.end(); ++it) {
      cout << *it << ": " << grade(stod(*it)) << " " << endl;
    }
  }



  //char* gradeFile = 
  cout << "Successfully passed argument" << endl;
  return 0;
}
