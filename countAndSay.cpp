// 38. Count and Say

/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"

Example 2:

Input: 4
Output: "1211"
*/

class Solution {
public:
  string countAndSay(int n) {
    if (n == 1) return "1";
    if (n == 2) return "11";
    return say(countAndSay(n-1));
  }
private:
  string say(string s) {
    int i = 0, j = 0, cnt = 1;
    string ans = "";
    while (i < s.size()) {
      j = i+1;
      if (j == s.size()) {
        ans += std::to_string(cnt) + s[i];
        break;
      }
      if (s[i] == s[j]) {
        cnt++;
        i++;
      } else {
        ans += std::to_string(cnt) + s[i];
        cnt = 1;
        i++;
      }
    }
    return ans;
  }
};
