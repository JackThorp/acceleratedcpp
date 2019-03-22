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
  
    // trim leading spaces by finding first non space
    i = find_if(i, line.end(), not_space);
 
    // find next space character in front
    iter j = find_if(i, line.end(), space);

    if(i != line.end()) {
      ret.push_back(string(i, j));
    }
    i = j;
  }

  return ret;
}

// Takes a stream and tries to read a set of grammer rules
Grammar read_grammar(istream& in) {
  
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

int nrand(int n) {
  // rand produces pseudo random numbers. When the quotients are small integers the remainders are
  // often not very random and therefore neither is the result of rand() % n; where n = 2,3,4 etc
  
  // second issues is that taking the modulo is only fair if n goes into RAND MAX a whole number of times. 
  // if it doesn't then there will not be an equal probability for numbers in [0,n) once the modulo has been taken
  // e.g. ran_max = 32767, n = 20000. rand = 10000 and rand = 30000 give rand % n = 10000. but only rand = 15000 
  // results in rand % n = 15000
  
  if ( n <= 0 || n > RAND_MAX) {
    throw domain_error("Argument to nrand is out of range");
  }

  // max ranges of n that fit into RAND_MAX 
  const int buckets = RAND_MAX / n;
  int r;

  // if rand is between n * buckets and RAND_MAX (and therefore wouldn't % fairly) don't use it
  // otherwise rand is 
  do r = rand() / buckets;
  while (r >= n);

  return r;
}

// Helper function to decide if word is a literal or rule
bool has_brackets(string input) {

  if (input.empty()) return false;
  return *input.begin() == '<' && *(input.end()-1) == '>';
}

// Build a random sentence from grammar rules
void generate_grammar(Grammar& grammar, string rule, ostream& os) {
 
  // use find because [] access would default value initialise an entry
  Grammar::const_iterator it_g = grammar.find(rule);

  if(it_g == grammar.end()) {
    throw logic_error("Empty rule");
  }

  RuleSet ruleSet = it_g->second;
  
  // generate random index to choose grammar rule
  vector<string> recipe = ruleSet[nrand(ruleSet.size())];

  for(vector<string>::const_iterator it = recipe.begin(); it != recipe.end(); ++it) {
    
    if(has_brackets(*it)) {
      generate_grammar(grammar, *it, os);
    } else {
      os << *it << " ";
    }
  }
}

int main(int argc, char* argv[]) {

  // initialise random numbers
  srand(time(0));

  // open grammar file
  ifstream grammarFile;
  grammarFile.open(argv[1]);
  Grammar grammar = read_grammar(grammarFile);
  grammarFile.close();

  generate_grammar(grammar, "<sentence>", cout);
  
  cout << endl;

}
