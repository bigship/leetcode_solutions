// 8. String to Integer (atoi)

/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of 
this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str 
is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2**31,  2**31 − 1]. 
If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
*/

// overflow condition
const int maxDiv10 = INT_MAX / 10;
const int lastDigitLimit = INT_MAX % 10;

class Solution {
public:
  int atoi(string str) {
    int len = str.size();
    int i = 0, sign = 1, value = 0, digit = 0;
    while (i < len && isspace(str[i])) i++;
    if (i < len && str[i] == '+') {
      i++;
    } else if (str[i] == '-') {
      sign = -1;
      i++;
    }

    while (i < len && isdigit(str[i])) {
      digit = str[i] - '0';
      if (value > maxDiv10 || digit > lastDigitLimit && value == maxDiv10) {
        return sign == 1 ? INT_MAX : INT_MIN;
      }
      value = value * 10 + digit;
      i++;
    }
    
    return value * sign;
  }
}

