// 93. Restore IP Addresses
/*
 * Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s.
 * You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros.
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:

Input: s = "1111"
Output: ["1.1.1.1"]

Example 4:

Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]

Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

Constraints:
    0 <= s.length <= 3000
    s consists of digits only.
*/

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    const int len = s.length();

    for (int i = 1; i < 4 && i < len - 2; i++) {
      for (int j = i + 1; j < i + 4 && j < len - 1; j++) {
        for (int k = j + 1; k < j + 4 && k < len; k++) {
          string s1 = string(s.begin(), s.begin() + i);
          string s2 = string(s.begin() + i, s.begin() + j);
          string s3 = string(s.begin() + j, s.begin() + k);
          string s4 = string(s.begin() + k, s.end());
          if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
            ans.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
          }
        }
      }
    }
    return ans;
  }
private:
  bool isValid(string& str) {
    if (str.length() > 3 || str.length() == 0 || (str[0] == '0' && str.length() > 1) ||
       std::stoi(str) > 255)
      return false;
    return true;
  }
};

