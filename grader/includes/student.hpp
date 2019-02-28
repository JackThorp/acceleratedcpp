#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <vector>
#include <string>
#include <iostream>

struct Student_info {
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

std::istream& read_hw(std::istream& in, std::vector<double>& hw);

std::istream& read(std::istream& is, Student_info& s);

bool compare(const Student_info&, const Student_info&);

#endif
