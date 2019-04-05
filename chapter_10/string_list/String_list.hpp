#ifndef STRING_LIST_HPP
#define STRING_LIST_HPP

#include <string>
#include <ostream>

// Struct to hold each element of the linked list
struct String_list_elem {
  std::string elem;
  String_list_elem* next;
};

// A simple and basic linked list for strings
class String_list {

  private:
    String_list_elem *head, *tail;  // Pointer to start of array
    size_t _size;              // Tracking size saves computing it. Is size_t the right type?

    String_list_elem* get_elem(size_t index); // Helper function returns pointer to element at given index

  public:

    String_list() {
      head = NULL;
      tail = NULL;
    };

    // Traverse list to get list item at index. 
    std::string retrieve(size_t index);

    // Insert an element at this index.
    bool insert(std::string elem, size_t index);

    void push_back(std::string elem);

    // Removes an element from the list
    bool remove(size_t index);

    // Get the size of the list
    size_t size();

    // Print the list
    void print(std::ostream& os);
};

#endif
