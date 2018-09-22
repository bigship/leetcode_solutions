// 49. Group Anagrams

/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.
*/

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < strs.size(); i++) {
      string s = strs[i];
      std::sort(s.begin(), s.end());
      if (m.find(s) == m.end()) {
        vector<int> indexs{i};
        m[s] = indexs;
      } else {
        m[s].push_back(i);
      }
    }
    
    vector<vector<string>> ans(m.size(), vector<string>{});
    int rows = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      for (int j = 0; j < it->second.size(); j++) {
        ans[rows].push_back(strs[it->second[j]]);
      }
      rows++;
    }
    return ans;
  }
};