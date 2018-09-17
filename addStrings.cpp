// 415. Add Strings

/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

// Trick: use deque can improve overall performance significantly
// No need to reverse the result.

class Solution {
public:
  string addStrings(string num1, string num2) {
    int i = num1.size();
    int j = num2.size();
    int carry = 0
    deque<char> dq;

    while (i >= 0 || j >= 0 || carry) {
      int sum = 0;
      if (i >= 0) {
        sum += (num1[i] - '0');
        i--;
      }
      if (j >= 0) {
        sum += (num2[j] - '0');
        j--;
      }

      sum += carry;
      carry = sum / 10;
      sum %= 10;
      dq.push_front(sum + '0');
    }
    return string(dq.begin(), dq.end());
  }
};