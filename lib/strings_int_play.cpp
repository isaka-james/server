// lib/string_to_int.cpp
#include "strings_int_play.h"
#include <string>
#include <cstring>

int stringToInt(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handle empty string
    if (str[i] == '\0') {
        throw "Empty string";
    }

    // Check for optional sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Convert each character to the corresponding digit
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            throw "Invalid character in string";
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

// Function to get the length of a string as an integer
int getStringLength(const std::string& str) {
    int length = 0;
    for (char c : str) {
        ++length;
    }
    return length;
}

std::string intToString(int number) {
    if (number == 0) return "0";
    std::string result;
    bool isNegative = number < 0;
    if (isNegative) number = -number;
    
    while (number > 0) {
        result.insert(result.begin(), '0' + number % 10);
        number /= 10;
    }

    if (isNegative) result.insert(result.begin(), '-');
    return result;
}