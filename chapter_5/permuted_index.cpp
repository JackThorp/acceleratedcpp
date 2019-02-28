#include <iostream>
#include <sstream>
#include <vector>
#include <string>
/* Permuted index takes a list of sentences and outputs a list where 
 * all premutations of every sentence split is indexed by one half but
 * ordered alphabetically by the value (not the key)
 */

using namespace std;

istream& readLines(istream& in, vector<string>& lines)
{
  string line;
  while (getline(in, line)) {
    lines.push_back(line);
  }
  return in;
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

struct Perm {
  vector<string>::const_iterator start;
  vector<string>::const_iterator index;
} ;

int main(int argc, char* argv[]) {

  cout << "Working" << endl;
  vector<string> lines;

  // Read lines into a vector
  readLines(cin, lines);

  vector<Perm> dict;
  // Parse each line into it's words
  for(vector<string>::iterator it_line = lines.begin(); it_line != lines.end(); it_line++) {
    vector<string> sentence = readWords(*it_line);

    // Make a perm reference pair for each perm in the setence
    for(vector<string>::iterator it_words = sentence.begin(); it_words != sentence.end(); it_words++) {
      Perm p;
      p.start = sentence.begin();
      p.index = it_words;
      dict.push_back(p);
    }

  }

  // Sort ductionary based on the index iterators value;
  for(vector<Perm>::iterator it_dict = dict.begin(); it_dict != dict.end(); it_dict++) {
    cout << *((*it_dict).index) << endl;
  }

  return 0;
} 

