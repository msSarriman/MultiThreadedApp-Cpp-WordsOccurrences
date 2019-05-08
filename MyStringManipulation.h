#ifndef MYSTRINGMANIPULATION_H
#define MYSTRINGMANIPULATION_H

std::string replaceChar(const std::string& str, char x, char y);
size_t findLeadingChar(std::string str);
size_t findTrailingChar(std::string str);
std::string trim(std::string str);
std::vector<std::string> splitStringToArray(std::string str);
std::string eraseChar(const std::string& str, char x, char y);

#endif /* MYSTRINGMANIPULATION_H */

