// 916. Word Subsets
/*
 * We are given two arrays A and B of words.  Each word is a string of lowercase letters.
   Now, say that word b is a subset of word a if every letter in b occurs in a,
   including multiplicity. For example, "wrr" is a subset of "warrior",
   but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a.
Return a list of all universal words in A.  You can return the words in any order.

Example 1:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]

Example 3:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]

Example 4:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]

Example 5:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]

Note:

    1 <= A.length, B.length <= 10000
    1 <= A[i].length, B[i].length <= 10
    A[i] and B[i] consist only of lowercase letters.
    All words in A[i] are unique: there isn't i != j with A[i] == A[j].
*/
class Solution {
public:
  // Solution: 针对B的所有单词, 统计所有字符出现最多的次数并加入到hashmap中
  // 再遍历A中的单词并统计字符出现的频率, 和之前统计的hashmap对比判断
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<string> ans;
    if (A.size() == 0 || B.size() == 0) return ans;
    unordered_map<char, int> map;
    string w1 = B[0];
    for (auto& ch : w1) {
      map[ch]++;
    }
    for (int i = 1; i < B.size(); i++) {
      unordered_map<char, int> m;
      for (auto& ch : B[i]) {
        m[ch]++;
      }
      for (auto it = m.begin(); it != m.end(); it++) {
        if (map.find(it->first) != map.end()) {
          if (map[it->first] < it->second) {
            map[it->first] = it->second;
          }
        } else {
          map[it->first] = it->second;
        }
      }
    }

    for (int i = 0; i < A.size(); i++) {
      unordered_map<char, int> ma;
      for (auto& ch : A[i]) {
        ma[ch]++;
      }
      bool found = true;
      for (auto it = map.begin()l it != map.end(); it++) {
        if (ma.find(it->first) == ma.end() || ma[it->first] < it->second) {
          found = false;
          break;
        }
      }
      if (found) {
        ans.push_back(A[i]);
      }
    }
    return ans;
  }

  // Solution: 因为全部是小写字符, 用vector替代unordered_map
  // 遍历vector数组时不受数据规模影响, 降低复杂度为O(n), n为A或B的数组长度
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    string empty = "";
    vector<int> bmax = count(empty);
    vector<string> ans;
    for (auto& word : B) {
      vector<int> c = count(word);
      for (int i = 0; i < 26; i++) {
        bmax[i] = std::max(bmax[i], c[i]);
      }
    }

    for (auto& word : A) {
      vector<int> c = count(word);
      bool found = true;
      for (int i = 0; i < 26; i++) {
        if (c[i] < bmax[i]) {
          found = false;
          break;
        }
      }
      if (found) {
        ans.push_back(word);
      }
    }

    return ans;
  }
private:
  vector<int> count(string& str) {
    vector<int> cnt(26, 0);
    for (auto& ch : str) {
      cnt[ch - 'a']++;
    }
    return cnt;
  }
};

