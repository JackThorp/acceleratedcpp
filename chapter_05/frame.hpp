#ifndef FRAME_HPP
#define FRAME_HPP

#include <vector>
#include <string>

std::vector<std::string> frame(const std::vector<std::string>& words, std::string align(int, std::string, std::string::size_type));

std::string::size_type get_width(const std::vector<std::string>&);

std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right);

std::vector<std::string> frame_l(const std::vector<std::string>& words);
std::vector<std::string> frame_r(const std::vector<std::string>& words);

#endif

