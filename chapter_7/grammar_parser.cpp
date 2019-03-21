#include <vector>
#include <cctype>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> RuleSet;
typedef map<string, RuleSet> Grammar;


bool space(char c) {
  return isspace(c);
}

bool not_space(char c) {
  return !isspace(c);
}

// Split a line into its constituent words
vector<string> split(const string& line) {

  typedef string::const_iterator iter;
  vector<string> ret;
  iter i = line.begin();

  while(i != line.end()) {
    
    i = find_if(i, line.end(), not_space);
 
    iter j = find_if(i, line.end(), space);

    if(i != line.end()) {
      ret.push_back(string(i, j));
    }
    i = j;
  }

  return ret;
}

// Takes a stream to a set of grammer rules
Grammar generate_grammar(istream& in) {
  
  Grammar ret;
  string line;
  while(getline(in, line)) {
   
    vector<string> words = split(line);

    // Handle empty lines of input
    if (!words.empty()) {
      // Frst word is key, remainder is a rule part.
      ret[words[0]].push_back(Rule(words.begin() + 1, words.end()));
    }
  }

  return ret;

}

bool has_brackets(string input) {

  if (input.empty()) return false;
  return *input.begin() == '<' && *(input.end()-1) == '>';
}

void generate_grammar(Grammar& grammar, string rule, ostream& os) {
  
  RuleSet ruleSet = grammar.find(rule)->second;

  typedef vector<string>::size_type vsz;
  // generate random index to choose grammar rule
  int index = nrand(ruleSet.size());

  vector<string> recipe = ruleSet[index];

  for(vector<string>::const_iterator it = recipe.begin(); it != recipe.end(); ++it) {
    
    if(has_brackets(*it)) {
      generate_grammar(grammar, *it, os);
    } else {
      os << *it << " ";
    }
  }
}

int main(int argc, char* argv[]) {

  // open grammar file
  ifstream grammarFile;
  grammarFile.open(argv[1]);
  Grammar grammar = generate_grammar(grammarFile);
  grammarFile.close();

  generate_grammar(grammar, "<sentence>", cout);
  
  cout << endl;

}
