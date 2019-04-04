#include <iostream>
#include <vector>
#include <algorithm>

int main (int argc, char* argv[]) {

  using namespace std;

  vector<string> words;
  string word;

  while(cin >> word) {
    words.push_back(word);
  }

  cout << "Number of words inputted = " << words.size() << endl;

  // Concatenate all the words into one string
  // accumulate works through overloading + but is bad efficiency atm
  // copy doesnt work when trying to use vector<string> iterators. I think this is because
  // a string is a collection of char to which char can be added. Iterating through a vector<string>
  // and trying to back insert strings is not compatible 
  string out;
  for (const auto &elem : words ) {
    out += elem + " ";
  }

  cout << out << endl;
}
