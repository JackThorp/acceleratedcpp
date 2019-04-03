#include <iostream>
#include <vector>
#include <string>

class Student_info {

  private:
    double midterm;
    double finalMark;
    std::string name;
    std::vector<double> homework;

    std::istream& read_hw(std::istream& in);

  public:
    Student_info();
    std::istream& read(std::istream& in);
    std::ostream& print(std::ostream& os);


};
