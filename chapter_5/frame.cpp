#include "frame.hpp"
#include <sstream>
#include <iostream>

using namespace std;


vector<string> frame(const vector<string>& words, string align(int, string, string::size_type)) 
{
  vector<string> ret;
  string::size_type maxlength = get_width(words);

  int col_pad = 1;
  int row_length = maxlength + 2 + (2*col_pad);

  string borderTB = string(row_length, '*');
  
  ret.push_back(borderTB);

  vector<string>::const_iterator it = words.begin();
  for(it = words.begin(); it != words.end(); it++)
  {
    ret.push_back(align(col_pad, *it, maxlength - it->size()));
  }
  ret.push_back(borderTB);

  return ret;
}

string align_left(int col_pad, string content, string::size_type content_pad)
{
  return "*" + string(col_pad, ' ') + content + string(content_pad, ' ') + string(col_pad, ' ') + "*";
}

string align_right(int col_pad, string content, string::size_type content_pad)
{
  return "*" + string(col_pad, ' ') + string(content_pad, ' ') + content + string(col_pad, ' ') + "*";
}

vector<string> frame_l(const vector<string>& words)
{
  return frame(words, align_left);
}

vector<string> frame_r(const vector<string>& words)
{
  return frame(words, align_right);
}


string::size_type get_width(const vector<string>& lines) 
{
  
  string::size_type maxlength = 0;
  for(vector<string>::const_iterator it = lines.begin(); it != lines.end(); it++) {
    maxlength = max(it->size(), maxlength);
  }

  return maxlength;

}


vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
  

  vector<string> ret;

  vector<string>::size_type height= max(left.size(), right.size());

  string::size_type width = get_width(left);

  for(vector<string>::size_type i = 0; i < height; i++) {
  
    string s;

    s = i < left.size() ? left[i] : string(width, ' ');

    s += i < right.size() ? right[i] : "";

    ret.push_back(s);
  
  }

  return ret;

}
