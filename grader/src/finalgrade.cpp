#include "student.hpp"
#include "grade.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char* argv[])
{

  cout << "YOOOO" << endl;
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // Read and store all records. Find longest name.
  while(read(cin, record))
  {
    students.push_back(record);
    maxlen = max(maxlen, record.name.size());
  }

  //Alphabetise the records
  sort(students.begin(), students.end(), compare);
  
  //Print each students grade
  for(vector<Student_info>::size_type i = 0; i != students.size(); i++)
  {
    Student_info student = students[i];

    cout << student.name << string(maxlen - student.name.size() + 1, ' ');

    try {
      double final_grade = grade(student);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }

    cout << endl;
  
  }

  return 0;
}
