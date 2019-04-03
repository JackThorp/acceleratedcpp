#include <iostream>
#include "Student_info.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    
  Student_info si;
  si.read(cin);
  si.print(cout);
  return 0;
}
