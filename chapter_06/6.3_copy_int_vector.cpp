#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  
  cout << "Hello Jack" << endl;

  vector<int> u(10, 100);
  vector<int> v;
  vector<int> w;
  // As v is uninitialised we cannot pass v.begin() to copy
  // as copy will try to write to an unreserved location
  
  // Option 1
  copy(u.begin(), u.end(), back_inserter(v));

  // Resize works but reserve does not
  // maybe as reserve doesn't change vector size so can't be accessed. !
  // Option 2 is probably preferable here if we know how big w
  // will grow by as it reduces the number of allocate calls to resize
  // that might occur from back_insertion.

  // Option 2
  w.resize(10);
  copy(u.begin(), u.end(), w.begin());

  // Print option 1
  ostream_iterator<int> out_it (cout, ", ");
  copy(v.begin(), v.end(), out_it);
  
  cout << endl;

  // Print option 2
  copy(w.begin(), w.end(), out_it);
  
  cout << endl;

  return 0;
}
