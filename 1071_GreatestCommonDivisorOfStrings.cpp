// 1071. Greatest Common Divisor of Strings
/*
 * For two strings s and t, we say "t divides s" if and only if s = t + ... + t
 * (t concatenated with itself 1 or more times)

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""

Example 4:

Input: str1 = "ABCDEF", str2 = "ABC"
Output: ""

Constraints:
    1 <= str1.length <= 1000
    1 <= str2.length <= 1000
    str1 and str2 consist of English uppercase letters.
*/
class Solution {
public:
  int len1 = str1.length();
  int len2 = str2.length();

  int gcdLength = std::gcd(len1, len2);
  string prefix = str2.substr(0, gcdLength);

  int cnt1 = len1 / gcdLength;
  int cnt2 = len2 / gcdLength;
  string t1, t2;
  for (int i = 0; i < len1; i += gcdLength) {
    t1 = string(str1.begin() + i, str1.begin() + i + cl);
    if (t1 == prefix) cnt1--;
  }
  for (int j = 0; j < len2; j += gcdLength) {
    t2 = string(str2.begin() + j, str2.begin() + j + cl);
    if (t2 == prefix) cnt2--;
  }
  if (cnt1 == 0 && cnt2 == 0) return prefix;
  return "";
};


