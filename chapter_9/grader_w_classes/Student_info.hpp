#include <iostream>
#include <vector>
#include <string>

class Student_info {

  private:
    double midterm;
    double finalMark;
    double homework_grade;
    double grade;
    std::string name;
    std::vector<double> homework;

    std::istream& read_hw(std::istream& in);

  public:
    Student_info();
    std::istream& read(std::istream& in);
    std::ostream& print(std::ostream& os);
    void calculate_homework_grade(double grade_fun(std::vector<double>));
    void calculate_grade(double grade_fun(double, double, double));


};
