// 1002. Find Common Characters
/*
 * Given an array A of strings made only from lowercase letters,
 * return a list of all characters that show up in all strings within the list (including duplicates).
 * For example, if a character occurs 3 times in all strings but not 4 times,
 * you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]

Note:
    1 <= A.length <= 100
    1 <= A[i].length <= 100
    A[i][j] is a lowercase letter
*/

class Solution {
public:
  vector<string> commonChars(vector<string>& A) {
    vector<int> m(26, 0);
    for (auto& ch : A[0])
      m[ch - 'a']++;

    const int len = A.size();
    for (int i = 1; i < len; i++) {
      vector<int> n(26, 0);
      for (auto& ch : A[i]) {
        if (m[ch - 'a'] == 0)
          continue;
        n[ch - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        m[i] = std::min(m[i], n[i]);
      }
    }

    vector<string> ans;
    for (int i = 0; i < 26; i++) {
      while (m[i]) {
        char c = i + 'a';
        ans.push_back(string(1, c));
        m[i]--;
      }
    }
    return ans;
  }
};


