#include "frame.hpp"
#include <sstream>
#include <iostream>

using namespace std;


void frame(const vector<string>& words) 
{
  vector<string>::const_iterator it = words.begin();
  string::size_type maxlength = it->size();

  for( ; it != words.end(); it++) {
    maxlength = max(it->size(), maxlength);
  }

  int col_pad = 1;
  int row_length = maxlength + 2 + (2*col_pad);

  string borderTB = string(row_length, '*');
  
  cout << borderTB << endl;
  for(it = words.begin(); it != words.end(); it++)
  {
    cout << "*" << string(col_pad, ' ') << *it << string(maxlength - it->size(), ' ') << string(col_pad, ' ') << "*" << endl;
  }
  cout << borderTB << endl;

}

/*
int main(int argc, char* argv[])
{

  // Read sentence from input
  string line;
  getline(cin, line);
  
  istringstream iss(line);
  string word;
  vector<string> words;
  while( iss >> word) {
    words.push_back(word);
  }

  frame(words);

}
*/
