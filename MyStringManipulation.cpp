#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

std::string replaceChar(const std::string& str, char x, char y);
size_t findLeadingChar(std::string str);
size_t findTrailingChar(std::string str);
std::string trim(std::string str);
std::vector<std::string> splitStringToArray(std::string str);
std::string eraseChar(const std::string& str, char x, char y);


/**
 * replaceChar()
 * This method replaces the char @x with the char @y at the given string @str.
 * @param str
 * @param x
 * @param y
 * @return 
 */
std::string replaceChar(const std::string& str, char x, char y) {
    char* stringToReturn = new char[str.size()];
    for (int i = 0; i < str.length() ; ++i) {
        if (str[i] == x) {
            stringToReturn[i] = y;
        } else {
            stringToReturn[i] = str[i];
        }
    }
    return stringToReturn;
}


/**
 * eraseChar()
 * This function erases all the occurrences of the char @x, at string @str.
 * @param str
 * @param x
 * @return 
 */
std::string eraseChar(const std::string& str, char x) {
    char* stringToReturn = new char[str.size() + 1];
    int counter = 0;
    for (const char& c : str) {
        if (c != x) {
            stringToReturn[counter++] = c;
        }
    }
    stringToReturn[counter] = '\0';
    return stringToReturn;
}


/**
 * trim()
 * This function trims all the leading and trailing whitespaces from @str.
 * @param str
 * @return 
 */
std::string trim(std::string str) {
    size_t startIndex, endIndex;
    int start = findLeadingChar(str);
    int end = findTrailingChar(str);
    if (start != -1) {
        startIndex = start; 
    } else {
        startIndex = 0;
    }
    if (end != -1) {
        endIndex = end;
    } else {
        endIndex = str.size() - 1;
    }
    return str.substr(startIndex, endIndex);
}


/**
 * findTrailingChar()
 * This function finds the index of the last non space character of given @str
 * @param str
 * @return 
 */
size_t findTrailingChar(std::string str) {
    for (int i = str.length() - 1; i <= 0; i--) {
        if(str[i] != ' ')
            return (size_t) i;
    }
    return -1;
}


/**
 * findLeadingChar()
 * This function finds the index of the first non space character of given @str
 * @param str
 * @return 
 */
size_t findLeadingChar(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if(str[i] != ' ')
            return (size_t) i;
    }
    return -1;
}


/**
 * splitStringToArray()
 * This function splits the given string @str, into substrings (space as delimiter)
 * which are all stored into a vector.
 * @param std::str
 * @return std::vector<std::string>
 */
std::vector<std::string> splitStringToArray(std::string str) {
    str = trim(str);
    str = eraseChar(str, '.');
    str = eraseChar(str, ':');
    str = eraseChar(str, ',');
    std::vector<std::string> myVector;
            
    int start = 0;
    int endAfter = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ') {
            myVector.push_back(str.substr(start, endAfter));
            start = i+1;
            endAfter = 0;
        } else {
            endAfter++;
        }
        
    }
    if (start != 0) {
        myVector.push_back(str.substr(start, endAfter));
    }
    return myVector;
}


/**
 * getKey(std::string str)
 * This function return the key, by removing the prefix that corresponds to the 
 * file that the key was present.
 * @param str
 * @return std::string
 */
std::string getKey(std::string str) {
    bool flag = false;
    int index = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '_') {
            flag = true;
        }
        if (flag == true && str[i] != '_') {
            index = i;
            break;
        }
    }
    return str.substr(index, str.size() - index);
}


/*
Depricated
std::string mySubString(std::string str, size_t start, size_t end) {
    char* stringToReturn = new char[start - end + 1];
    int index = 0;
    size_t current = start;
    while (current < end) {
        stringToReturn[index++] = str[current++];
    }
    stringToReturn[index] = '\0';
    return stringToReturn;
}
 */