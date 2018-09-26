// 438. Find All Anagrams in a String

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

// Sliding window + hashmap  time complexity O(n)

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int sl = s.size(), pl = p.size();
    vector<int> ms(26, 0);
    vector<int> mp(26, 0);
    for (const auto& c : p) ++ms[c - 'a'];
    for (int i = 0; i < sl; i++) {
      if (i >= pl) 
        --mp[s[i-pl]-'a'];     // remove head
      ++mp[s[i]-'a'];          // add tail
      if (ms == mp)
        ans.push_back(i+1-pl);
    }
    return ans;
  }
};






