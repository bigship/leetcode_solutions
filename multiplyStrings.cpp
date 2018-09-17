// 43. Multiply Strings

/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

class Solution {
public:
  string multiply(string n1, string n2) {
    int digitValue, carry = 0;
    string tmp = "";
    deque<char> dq;
    vector<string> vec;
    int addZero = 0;
    
    if (n1 == "0" || n2 == "0") return "0";

    for (int i = n1.size() - 1; i >= 0; i--) {
      digitValue = 0;
      for (int j = n2.size() - 1; j >= 0; j--) {
        digitValue = (n1[i] - '0') * (n2[j] - '0') + carry;
        carry = digitValue / 10;
        digitValue %= 10;
        dq.push_front(digitValue + '0');
      }
      if (carry != 0) {
        dq.push_front(carry + '0');
        carry = 0;
      }
      tmp = string(dq.begin(), dq.end());
      for (int i = 0; i < addZero; i++) {
        tmp.push_back('0');
      }
      addZero += 1;
      dq.clear();
      vec.push_back(tmp);
    }

    if (vec.size() == 1) {
      return vec[0];
    } else {
      return std::accumulate(std::next(vec.begin()), vec.end(), vec[0], [](string s1, string s2) {
        deque<char> dq;
        int carry = 0, digit = 0;
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 < len2) {
          for (int i = 0; i < len2 - len1; i++) {
            s1.insert(0, "0");
          }
        } else if (len1 > len2) {
          for (int i = 0; i < len1 - len2; i++) {
            s2.insert(0, "0");
          }
        }

        for (int i = s1.size() - 1; i >= 0; i--) {
          digit = (s1[i] - '0') + (s2[i] - '0') + carry;
          carry = digit / 10;
          digit %= 10;
          dq.push_front(digit + '0');
        }
        if (carry != 0) {
          dq.push_front(carry + '0');
        }
        //cout << s1 << " + " << s2 << " = " << string(dq.begin(), dq.end()) << endl;
        return string(dq.begin(), dq.end());
      });
    }
  }
};


