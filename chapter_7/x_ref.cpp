#include <map>
#include <vector>
#include <istream>
#include <iostream>

using namespace std;

bool space(char c) {
  return isspace(c);
}

bool not_space(char c) {
  return !isspace(c);
}

// Turn a string line of words into a vector
vector<string> split(const string& line) {
 
  typedef string::const_iterator iter;
  vector<string> ret;

  iter i = line.begin();
  while (i != line.end()) {

    // Search to first non space char
    i = find_if(i, line.end(), not_space);
    
    // Search to find end of first char seq
    iter j = find_if(i, line.end(), space);

    // Add word and set start point to space found.
    if( i != line.end()) {
      ret.push_back(string(i, j));
    }
    
    i = j;
  }
  return ret;
}

// Produces the line numbers on which each word in thre input occurs.
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split) {

  string line;
  int line_number = 0;
  map<string, vector<int> > ret;

  while( getline(in, line)) {
    ++line_number;

    vector<string> words = find_words(line);

    for(vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
      ret[*it].push_back(line_number);
    }
  }

  return ret;
}

int main() {

  // get cross refe and use default split
  map<string, vector<int> > ret = xref(cin);

  //
  for(map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
    
    // print the word
    cout << it->first << " appears on line(s): " ;

    vector<int>::const_iterator line_it = it->second.begin();
    cout << *line_it;
    ++line_it;

    // followed by line numbers
    while(line_it != it->second.end()) {
      cout << ", " << *line_it;
      ++line_it;
    }

    cout << endl;
  }

}


