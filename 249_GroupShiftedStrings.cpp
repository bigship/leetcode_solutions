// 249. Group Shifted Strings
/*
 * We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

Example 1:

Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
Example 2:

Input: strings = ["a"]
Output: [["a"]]

Constraints:

1 <= strings.length <= 200
1 <= strings[i].length <= 50
strings[i] consists of lowercase English letters.
*/

// Brute force. 为字符串生成它的转换链
// 如果其他字符串出现在这个转换链中, 表示它们应该归为同一组
class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> ans;
    if (strings.size() == 0) return ans;

    int remaining = strings.size();
    vector<bool> grouped(remaining, false);

    for (int i = 0; i < strings.size(); i++) {
      if (!grouped[i]) {
        vector<string> group;
        group.push_back(strings[i]);
        grouped[i] = true;
        auto hs = shiftedString(strings[i]);
        for (int j = 0; j < strings.size(); j++) {
          if (!grouped[j] && hs.count(strings[j]) != 0) {
            group.push_back(strings[j]);
            grouped[j] = true;
          }
        }
        ans.push_back(group);
      }
    }
    return ans;
  }
private:
  unordered_set<string> shiftedString(string str) {
    unordered_set<string> hashset;
    hashset.insert(str);
    while (true) {
      for (auto& ch : str) {
        if (ch == 'z') {
          ch = 'a';
        } else {
          ch = ch + 1;
        }
      }
      if (hashset.count(str) != 0) {
        break;
      }
      hashset.insert(str);
    }
    return hashset;
  }
};

// O(n)的方法. 类似于group anagram
// 将每个字符串都转换为开头字符为a的字符串. 如果它们可以归为一类,
// 则转换后的字符串是相同的. 可以利用hashmap保存所有转换后的分组
class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < strings.size(); i++) {
      string str = strings[i];
      int diff = str[0] - 'a';
      for (auto& ch : str) {
        ch = (ch - diff + 26) % 26;
      }
      map[str].push_back(strings[i]);
    }

    for (auto it = map.begin(); it != map.end(); it++) {
      ans.push_back(it->second);
    }
    return ans;
  }
};
