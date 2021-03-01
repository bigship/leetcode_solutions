// 273. Integer to English Words
/*
 * Convert a non-negative integer num to its English words representation.

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Example 4:

Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

Constraints:

    0 <= num <= 2^31 - 1
*/

class Solution {
public:
  vector<string> in_twenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                              "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                              "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  vector<string> in_hundred = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                               "Sixty", "Seventy", "Eighty", "Ninety"};
  vector<string> over_thousand = {"","Thousand", "Million", "Billion"};

  string numberToWords(int num) {
    if (num == 0) return "Zero";
    int i = 0;
    string ans;
    while (num) {
      string pre = helper(num % 1000);
      if (pre != "") ans = pre + " " + over_thousand[i] + " " + ans;
      num /= 1000;
      ++i;
    }
    return trim(ans);
  }

  string helper(int num) {
    if (num < 20) return trim(in_twenty[num]);
    if (num < 100) return trim(in_hundred[num / 10] + " " + in_twenty[num % 10]);
    return trim(in_twenty[num / 100] + " " + "Hundred " + helper(num % 100));
  }

  string trim(string s) {
    if (s == "") return s;
    int first = s.find_first_not_of(' ');
    int last = s.find_last_not_of(' ');
    return s.substr(first, (last-first+1));
  }
};

