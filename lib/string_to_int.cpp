// lib/string_to_int.cpp
#include "string_to_int.h"

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
