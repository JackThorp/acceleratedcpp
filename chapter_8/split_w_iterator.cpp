#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


bool not_space(char c) {
  return !isspace(c);
}

bool space(char c) {
  return isspace(c);
}

template <class Out>
void split (const string& str, Out os) {
  
  typedef string::const_iterator iter;
  
  iter i = str.begin();
  while (i != str.end()) {
    
    // trim leading white space
    i = find_if(i, str.end(), not_space);
    
    // Find end of next word
    iter j = find_if(i, str.end(), space);

    // copy characters from [i,j)
    if (i != str.end()) {
      *os++ = string(i, j);
    }

    i = j;
  }
}

// Program that reads lines of input from std in and writes
// the indiviual words back out on new lines. Purpose is to 
// test split function written with templates to accept any 
// output iterator.
int main()
{
  string s;
  while(getline(cin, s))
  {
    split(s, ostream_iterator<string>(cout, "\n"));
  }
  return 0;
}
