#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


using namespace std;

istream& read_hw(istream& in, vector<double>& hw)
{
  if (in) {
    // remove any previous contents.
    hw.clear();

    // read greades
    double x;
    while (in >> x) {
      hw.push_back(x);
    }

    in.clear();
  }

  return in;
}

double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  if(size == 0){
    throw domain_error("Median of empty vector");
  }

  sort(vec.begin(), vec.end());

  vec_sz mid = size/2;

  // is mid-1 because of 0 indexing...
  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];

}

double grade(double midterm, double final, double homework) 
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{

  if (hw.size() == 0) {
    throw domain_error("Student has done no homework");
  }

  return grade(midterm, final, median(hw));
}


int main(int argc, char* argv[])
{
  cout << "Please enter your first name: ";
  string name;
  cin >> name; 
  cout << "Hello, " << name << "!" <<endl;

  // Ask for midterm and final grades
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // Ask for homework grades
  cout << "Enter all your homework grades, followed by end of file: ";
  vector<double> homework;
  read_hw(cin, homework);
  cout << endl;

  try {
    double final_grade = grade(midterm, final, homework);
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << final_grade << setprecision(prec) << endl;
  } catch (domain_error) {
    cout << endl << "You must enter your grades. Please try again." << endl;
    return 1;
  }

  return 0;
}
