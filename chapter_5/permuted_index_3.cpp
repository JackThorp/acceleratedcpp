#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
/* Permuted index takes a list of sentences and outputs a list where 
 * all premutations of every sentence split is indexed by one half but
 * ordered alphabetically by the value (not the key)
 */

using namespace std;
typedef vector<string>::iterator vs_it;

istream& read_lines(istream& in, vector<string>& lines)
{
  string line;
  while (getline(in, line)) {
    lines.push_back(line);
  }
  return in;
}

vector<string> read_words(string line)
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

struct PermutedIndex {

  vector<string> permutation;
  vector<string> original;
  string rotatedLine;
  int rotation;
};

string string_from_vec_string(vector<string>& stringVec)
{
  string result;
  for(vs_it it = stringVec.begin(); it != stringVec.end(); it++){
    result += *it + " ";
  }
  return result;
}

void build_index(vector<string>& lines, vector<PermutedIndex>& index)
{

  // Loop over each line of the article.
  for(vs_it it_line = lines.begin(); it_line != lines.end(); it_line++) {
    
    vector<string> sentence = read_words(*it_line);

    int rotation = 0;

    // Make a permutation by iterating through line
    for(vs_it it_word = sentence.begin(); it_word != sentence.end(); it_word++) {
    
      vector<string> rotated_words;

      // Push all words from here to end of original line
      for(vs_it it_rest = it_word; it_rest != sentence.end(); it_rest++) {
        rotated_words.push_back(*it_rest);
      }
      
      // Then append words from begining upto current iteration.
      for(vs_it it_rest = sentence.begin(); it_rest != it_word; it_rest++) {
        rotated_words.push_back(*it_rest);
      }
     
      PermutedIndex pi;
      pi.original = sentence;
      pi.permutation = rotated_words;
      pi.rotatedLine = string_from_vec_string(rotated_words);
      pi.rotation = rotation;
      index.push_back(pi);

      rotation++;
    }
  }
}

bool comp_permutations(PermutedIndex& a, PermutedIndex& b)
{
  string a_l = string(a.rotatedLine);
  string b_l = string(b.rotatedLine);
  transform(a.rotatedLine.begin(), a.rotatedLine.end(), a_l.begin(), ::tolower);
  transform(b.rotatedLine.begin(), b.rotatedLine.end(), b_l.begin(), ::tolower);
  return a_l < b_l;
}

void sort_index(vector<PermutedIndex>& index)
{
    sort(index.begin(), index.end(), comp_permutations);
}

void print_index(vector<PermutedIndex>& index) 
{
  for(vector<PermutedIndex>::iterator it = index.begin(); it != index.end(); it++) {
    cout << it->rotatedLine << endl;
  }
}

int main(int argc, char* argv[]) {

  // Splt input by line
  vector<string> lines;
  read_lines(cin, lines);

  //  
  vector<PermutedIndex> index; 
  build_index(lines, index);

  // Sort permuted indicies
  sort_index(index);

  print_index(index);
/*
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
*/
  return 0;
} 


