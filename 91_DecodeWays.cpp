// 91. Decode Ways
/*
 * A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways).
For example, "11106" can be mapped into:

    "AAJF" with the grouping (1 1 10 6)
    "KJF" with the grouping (11 10 6)

Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
Given a string s containing only digits, return the number of ways to decode it.
The answer is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
  int numDecodings(string s) {
    if (s.length() == 0)
      return 0;
    return ways(s, 0, s.length() - 1);
  }
private:
  unordered_map<int, int> mem;
  int ways(const string& s, int l, int r) {
    if (mem.count(l)) return mem[l];
    if (s[l] == '0') return 0;
    if (l >= r) return 1;

    int w = ways(s, l + 1, r);
    const int prefix = (s[l] - '0') * 10 + (s[l + 1] - '0');
    if (prefix <= 26)
      w += ways(s, l + 2, r);
    return mem[l] = w;
  }
};

