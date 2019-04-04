#include <map>
#include <iostream>

int main() {

  using namespace std;

  string s;
  map<string, int> counters;

  // counters is value initiliased so result of counters[s] will be 0 if
  // word not already seen.
  while (cin >> s) {
    ++counters[s];
  }

  // container elements are pairs and key/value accessible through first and second.
  for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
    cout << it->first << "\t" << it->second << endl;
  }

  return 0;

}
