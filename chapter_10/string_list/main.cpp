#include "String_list.hpp"
#include <iostream>

int main() {

  String_list list;

  std::cout << "Creating list" << std::endl;
  list.print(std::cout);
  
  list.push_back("One");
  list.print(std::cout);
  
  list.push_back("Two");
  list.print(std::cout);
  
  list.push_back("Three");
  list.print(std::cout);

  list.push_back("Four");
  list.push_back("Five");
  list.push_back("Six");
  list.print(std::cout);
 
  return 0;
}
