// 1525. Number of Good Ways to Split a String
/*
 * You are given a string s, a split is called good if you can split s into
 * 2 non-empty strings p and q where its concatenation is equal to s and
 * the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.

*/

class Solution {
public:
  int numSplits(string s) {
    int ans = 0;
    vector<int> cntmap1(26, 0);
    vector<int> cntmap2(26, 0);
    for (auto& ch : s) {
      cntmap1[ch - 'a']++;
    }

    for (int i = 0; i < s.length(); i++) {
      cntmap2[s[i] - 'a']++;
      cntmap1[s[i] - 'a']--;
      if (countDistinct(cntmap1) == countDistinct(cntmap2)) {
        ans++;
      }
    }

    return ans;
  }
private:
  int countDistinct(vector<int>& arr) {
    int cnt = 0;
    for (auto& val : arr) {
      if (val != 0) {
        cnt++;
      }
    }
    return cnt;
  }
};
