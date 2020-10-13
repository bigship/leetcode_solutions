// 187. Repeated DNA Sequences
/*
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
 * When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

class Solution {
public:
  vector<string> findRepeatedDNASequences(string s) {
    vector<string> ans;
    unordered_map<string, int> map;
    const int n = s.length();
    for (int i = 0; i <= n - 10; i++)
      map[string(s.begin() + i, s.begin() + i + 10)]++;
    for (auto it = map.begin(); it != map.end(); it++) {
      if (it->second >= 2)
        ans.push_back(it->first);
    }
    return ans;
  }
};

