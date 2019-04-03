#include "Student_info.hpp"

using namespace std;

Student_info::Student_info(): midterm(0), finalMark(0) {
  cout << "Student  Constructed" << endl;
}

istream& Student_info::read_hw(istream& in) {

  if (in) {
    
    // reset if this is called again.
    homework.clear();
    double hw;
  
    while(in >> hw) {
      homework.push_back(hw); 
    }
   
    // Resets the error state of the input stream
    // means next set of records can stil be read
    // even if this one was erroneously formatted.
    in.clear();
  }

  return in;
}

istream& Student_info::read(istream& in) {
  
  in >> name >> midterm >> finalMark;
  return read_hw(in);
  
}

ostream& Student_info::print(ostream& os) {

  os << name << " M: " << midterm << " F: " << finalMark << endl;
  return os;
}

