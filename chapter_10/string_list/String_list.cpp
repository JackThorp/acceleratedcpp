#include "String_list.hpp"
#include <string>
#include <iostream>

using namespace std;

//// Retrieve method returns string of element at index
//string String_list::retrieve(size_t index) {
//  return get_elem(index)->elem;
//};
//
//
//// Returns true if element at given index is succesfully removed
//bool String_list::remove(size_t index) {
//
//  // Get the element before and use it to retrieve the
//  // address of the elements after next.
//  String_list_elem* before_elem;
//  try {
//    before_elem = get_elem(index-1);
//  } catch (exception e) {
//    return false;
//  }
//  String_list_elem* removed_elem = before_elem->nextElem;
//
//  before_elem->nextElem = removed_elem->nextElem;
//  
//  // Free memory of old element and decrement size.
//  delete removed_elem;
//  _size--;
//
//  return true;
//}
//
// Add a string into the list at index
void String_list::push_back(string elem) {

  // Dynamically create a new list element on the heap
  String_list_elem* new_elem = new String_list_elem;
  new_elem->elem = elem;
  new_elem->next = NULL;

  if(head == NULL) {
    head = new_elem;
    tail = new_elem;
    new_elem = NULL;
  } 
  else {
    tail->next = new_elem;
    tail = new_elem;
  }
}


// Private helper function. Returns pointer to elem at index:
// Big question about types here
//String_list_elem* String_list::get_elem(size_t index) {
//  
//  if (index > _size) {
//    throw out_of_range("Index not in range");
//  }
//
//  cerr << "INDEX = " << index << " SIZE: " << _size << endl;
//  String_list_elem* curr = new String_list_elem;
//  curr = start->nextElem;
//  while( index > 0) {
//    curr = curr->nextElem;
//    index--;
//  }
//
//  return curr;
//}
//

void String_list::print(ostream& os) {

  String_list_elem* curr = new String_list_elem;
  curr = head;
  while(curr != NULL) {
    os << "[" << curr->elem << "]->";
    curr = curr->next;
  }
  os << endl;
}

size_t String_list::size() {
  return _size;
}
