#include "frame.hpp"
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


/* read_line: Reads lines of string from an inputstream
 */
istream& read_lines(istream& in, vector<string>& lines)
{
  string line;
  while (getline(in, line)) {
    lines.push_back(line);
  }
  return in;
}


/* read_words: Splits line into sequence of words.
 */
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


/* PermutedIndex: struct to hold all the index information
 */
struct PermutedIndex {

  vector<string> permutation;
  vector<string> original;
  string rotatedLine;
  int lineNum;
  int rotation;
};


/* Helper function to concatenate and unify all strings in a vector
 */
string string_from_vec_string(vector<string>& stringVec)
{
  string result;
  for(vs_it it = stringVec.begin(); it != stringVec.end(); it++){
    result += *it + " ";
  }
  return result;
}


/* Rotates each line of input up to the line size and creates an index instance
 * for each such permutation storing relavent meta info. 
 */
void build_index(vector<string>& lines, vector<PermutedIndex>& index)
{

  // The line of input this index is for.
  int line = 1;
  
  // Loop over each line of the input.
  for(vs_it it_line = lines.begin(); it_line != lines.end(); it_line++) {
    
    
    int rotation = 0;
    vector<string> sentence = read_words(*it_line);

    // Make permutations for each word or index into the sentence
    for(vs_it it_word = sentence.begin(); it_word != sentence.end(); it_word++) {
    
      vector<string> rotated_words;

      // Push all words from the index word to end of line
      for(vs_it it_rest = it_word; it_rest != sentence.end(); it_rest++) {
        rotated_words.push_back(*it_rest);
      }
      
      // Append the words from begining up to index word.
      for(vs_it it_rest = sentence.begin(); it_rest != it_word; it_rest++) {
        rotated_words.push_back(*it_rest);
      }
     
      PermutedIndex pi;
      pi.original     = sentence;
      pi.permutation  = rotated_words;
      pi.rotatedLine  = string_from_vec_string(rotated_words);
      pi.rotation     = rotation;
      pi.lineNum      = line;
      index.push_back(pi);

      // We could use it-lines.begin() if we wanted to drop the rotation counter
      rotation++;
    }

    // As for rotation...
    line++;
  }
}


/* Helper function for sorting the index alphabetically. 
 * Compares two instances of a permuted index
 */
bool comp_permutations(PermutedIndex& a, PermutedIndex& b)
{
  // Create a new copy of each index line
  string a_l = string(a.rotatedLine);
  string b_l = string(b.rotatedLine);
 
  // convert sentence to lower case so capitals do not affect ordering
  transform(a.rotatedLine.begin(), a.rotatedLine.end(), a_l.begin(), ::tolower);
  transform(b.rotatedLine.begin(), b.rotatedLine.end(), b_l.begin(), ::tolower);
  
  return a_l < b_l;
}


/* Sort index alphabetically
 */
void sort_index(vector<PermutedIndex>& index)
{
    sort(index.begin(), index.end(), comp_permutations);
}


/* Helper function to print rotated lines
 */
void print_index(vector<PermutedIndex>& index) 
{
  for(vector<PermutedIndex>::iterator it = index.begin(); it != index.end(); it++) {
    cout << it->rotatedLine << endl;
  }
}


/* Uses rotation count to returns pre index text 
 */
void get_index_info(vector<string>& preLines, vector<string>& postLines, vector<string>& wordNums, vector<string>& lineNums, vector<PermutedIndex>& index)
{

  for(vector<PermutedIndex>::iterator it = index.begin(); it != index.end(); it++) {
    
    string preBuild;
    string postBuild;
    int rot = 0;
    for(vs_it it_s = it->original.begin(); it_s != it->original.end(); it_s++) {
      
      if(rot < it->rotation) {
        preBuild += *it_s + " ";
      } else {
        postBuild += *it_s + " ";
      }
      rot++;
    }
    preLines.push_back(preBuild);
    postLines.push_back(postBuild);
    lineNums.push_back(to_string(it->lineNum));
    wordNums.push_back(to_string(it->rotation + 1));
  }
}

int main(int argc, char* argv[]) {

  // Splt input by line
  vector<string> lines;
  read_lines(cin, lines);

  // Build the index
  vector<PermutedIndex> index; 
  build_index(lines, index);

  // Sort index alphabetically
  sort_index(index);

  // Get ordered set of pre-index text, post-index text, line and word numbers. 
  vector<string> preLines, postLines, wordNums, lineNums;
  get_index_info(preLines, postLines, wordNums, lineNums, index);

  // Frame output sections with appropriate alignment
  preLines = frame_r(preLines);
  postLines = frame_l(postLines);
  wordNums = frame_l(wordNums);
  lineNums = frame_l(lineNums);
  
  // Print index
  vector<string> out = hcat(hcat(preLines, postLines), hcat(lineNums, wordNums));
  for(vs_it it=out.begin(); it != out.end(); it++) {
    cout << *it << endl;
  }

  return 0;
} 


