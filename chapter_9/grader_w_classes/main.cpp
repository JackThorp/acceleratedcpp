#include <iostream>
#include "Student_info.hpp"

using namespace std;

double grade(double midterm, double final, double homework) 
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vec) {

  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  if(!size) {
    throw domain_error("Median of empty vector");
  }

  vec_sz mid = size/2;

  return mid % 2 == 0 ? (vec[mid] + vec[mid-1] / 2) : vec[mid];
}

int main(int argc, char* argv[]) {
    
  Student_info si;
  si.read(cin);
  si.print(cout);

  si.calculate_homework_grade(median);
  si.calculate_grade(grade);

  si.print(cout);

  return 0;
}
