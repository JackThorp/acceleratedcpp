#include <iostream>
#include <sstream>
#include <vector>
#include <string>
/* Permuted index takes a list of sentences and outputs a list where 
 * all premutations of every sentence split is indexed by one half but
 * ordered alphabetically by the value (not the key)
 */

using namespace std;

string::size_type readLines(istream& in, vector<string>& lines)
{
  string line;
  string::size_type max_line = 0;

  while (getline(in, line)) {
    lines.push_back(line);
    max_line = max(line.size(), max_line); 
  }
  return max_line;
}

vector<string> readWords(string line)
{
  vector<string> words;
  string word;
  istringstream ss(line);
  while( ss >> word)
  {
    words.push_back(word);
  }
  return words;
}

bool compSentences(const vector<string>& s1, const vector<string>& s2)
{
  return s1[0] < s2[0];
}

int main(int argc, char* argv[]) {

  cout << "Working" << endl;
  vector<string> lines;

  // Read lines into a vector
  string::size_type max_line = readLines(cin, lines);

  vector< vector<string> > dict;
  // Parse each line into it's words
  for(vector<string>::iterator it_line = lines.begin(); it_line != lines.end(); it_line++) {
    vector<string> sentence = readWords(*it_line);


    // Make a perm reference pair for each perm in the setence
    for(vector<string>::iterator it_word = sentence.begin(); it_word != sentence.end(); it_word++) {
    

      vector<string> rotation;
      for(vector<string>::iterator it_rest = it_word; it_rest != sentence.end(); it_rest++) {
        rotation.push_back(*it_rest);
      }
      // Insert word start marker
      rotation.push_back("^");
      for(vector<string>::iterator it_rest = sentence.begin(); it_rest != it_word; it_rest++) {
        rotation.push_back(*it_rest);
      }
      
      dict.push_back(rotation);
    }


  }

  // Sort rotations
  sort(dict.begin(), dict.end(), compSentences);

  // Print out again
  for(vector<vector<string> >::iterator it = dict.begin(); it != dict.end(); it++) {
    
    bool start_passed = false;
    
    vector<string>::iterator it_word = it->begin();
    vector<string>::iterator it_word_b = it->begin();
    
    while(*it_word != "^" && it_word != it->end()) {
      it_word++;
      it_word_b++;
    }

    while(it_word != it->end()) {
      it_word++;
      cout << *it_word << " ";
    }

    cout << " ";
    
    it_word = it->begin();
    while(it_word != it_word_b) {
      cout << *it_word << " ";
      it_word++;
    }

    cout << endl;
  }

  return 0;
} 

