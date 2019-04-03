#include "Student_info.hpp"

using namespace std;

Student_info::Student_info(): midterm(0), finalMark(0), grade(0), homework_grade(0) {
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

  os << name << " M: " << midterm << " F: " << finalMark;
  os << " H: " << homework_grade << " G: " << grade << endl;
  return os;
}

void Student_info::calculate_homework_grade(double grade_fun(vector<double>)) {
  homework_grade = grade_fun(homework);
}

void Student_info::calculate_grade(double grade_fun(double, double, double)) {
  grade = grade_fun(midterm, finalMark, homework_grade);
}

