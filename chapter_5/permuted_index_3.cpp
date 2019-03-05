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


void get_pre_post_text_lines(vector<string>& preLines, vector<string>& postLines, vector<PermutedIndex>& index)
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

  // Get ordered set of sentence parts for before index word, and also for after. 
  vector<string> preLines;
  vector<string> postLines;
  get_pre_post_text_lines(preLines, postLines, index);

  
  preLines = frame_r(preLines);
  postLines = frame_l(postLines);
  
  vector<string> out = hcat(preLines, postLines);

  for(vs_it it=out.begin(); it != out.end(); it++) {
    cout << *it << endl;
  }
  // Write pre amd post text lines to padded, aligned block on a stream
  //frame_right();
  //frame_left();

  // Horizontally concatinate frames
  //h_concat_frames();

  // Print frames to std out

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


