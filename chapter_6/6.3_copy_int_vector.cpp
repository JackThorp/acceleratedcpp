#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  
  cout << "Hello Jack" << endl;

  vector<int> u(10, 100);
  vector<int> v;
  copy(u.begin(), u.end(), back_inserter(v));

  ostream_iterator<int> out_it (cout, ", ");
  copy(v.begin(), v.end(), out_it);
  
  cout << endl;

  return 0;
}
