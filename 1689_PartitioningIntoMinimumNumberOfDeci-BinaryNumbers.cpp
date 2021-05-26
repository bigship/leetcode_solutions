// 1689. PartitioningIntoMinimumNumberOfDeci-BinaryNumbers.cpp
/*
 * A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros.
 * For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number
of positive deci-binary numbers needed so that they sum up to n.

Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
Example 2:

Input: n = "82734"
Output: 8
*/
// 如果n只有一位数, 则只能通过不断累加1来得到
// 如果是多位数, 则每一位都需要通过累加1来得到
// 因此答案就是n中数值最大的那一位需要的1
class Solution {
public:
  int minPartitions(string n) {
    char res = '0';
    for (auto c : n) {
      if (res < c) {
        res = c;
      }
    }
    return res - '0';
  }
};
