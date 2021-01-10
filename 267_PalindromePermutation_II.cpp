// 267. Palindrome Permutation II
/*
 * Given a string s, return all the palindromic permutations (without duplicates) of it.
 * Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]

Example 2:

Input: "abc"
Output: []
*/

// Brute force. 检查每一个排列是否为回文
// 产生全排列的复杂度是 O(n!)
class Solution {
public:
  vector<string> generatePalindromes(string s) {
    vector<string> ans;
    std::sort(s.begin(), s.end());
    do {
      if (isPalindrome(s))
        ans.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));
    return ans;
  }
private:
  bool isPalindrome(string& str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
      if (str[left++] != str[right--])
        return false;
    }
    return true;
  }
};

// 有的字符串无论怎么排列也是不可能构成回文的. 可提前先做判断
// 另外, 如果一个字符串是回文, 那么可以只产生其一半长度的全部排列
// 即可. 剩下的一半只需逆序再append即可
// 可把时间复杂度降低到O((n/2)!)
class Solution2 {
public:
  vector<string> generatePalindromes(string s) {
    unordered_map<char, int> cntmap;
    if (!canPermutePalindrome(s, cntmap))
      return vector<string>();

    vector<string> ans;
    vector<char> half(s.length() / 2, 0);
    char ch = 0;
    int k = 0;
    for (auto it = cntmap.begin(); it != cntmap.end(); it++) {
      if (it->second % 2 == 1)
        ch = it->first;
      for (int j = 0; j < it->second / 2; j++) {
        half[k++] = it->first;
      }
    }

    string halfstr = string(half.begin(), half.end());
    std::sort(halfstr.begin(), halfstr.end());
    do {
      string cp = halfstr;
      std::reverse(cp.begin(), cp.end());
      string ret = halfstr + (ch == 0 ? "" : string(1, ch)) + cp;
      ans.push_back(ret);
    } while (std::next_permutation(halfstr.begin(), halfstr.end()));

    return ans;
  }
private:
  bool canPermutePalindrome(string& s, unordered_map<char, int>& cntmap) {
    for (auto& ch : s)
      cntmap[ch]++;

    int oddCnt = 0;
    for (auto it = cntmap.begin(); it != cntmap.end(); it++) {
      if (it->second % 2 == 1)
        oddCnt++;
    }
    return (oddCnt == 0) ? true : (oddCnt == 1);
  }
};


