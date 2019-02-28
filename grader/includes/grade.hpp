#ifndef GRADE_HPP
#define GRADE_HPP

#include "student.hpp"
#include <vector>

double grade(double midterm, double final, double homework);

double grade(double midterm, double final, const std::vector<double>& hw);

double grade(const Student_info& student);

#endif
