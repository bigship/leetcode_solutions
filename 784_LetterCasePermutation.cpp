// 784. Letter Case Permutation
/*
 * Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
   Return a list of all possible strings we could create. You can return the output in any order.

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]

Example 3:

Input: S = "12345"
Output: ["12345"]

Example 4:

Input: S = "0"
Output: ["0"]

Constraints:

    S will be a string with length between 1 and 12.
    S will consist only of letters or digits.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cctype>
using namespace std;

// Backtrack TLE !!  O(N^N)
class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    unordered_set<string> ans;
    vector<int> letters;
    for (int i = 0; i < S.length(); i++) {
      if (std::isalpha(S[i])) {
        letters.push_back(i);
      }
    }
    if (letters.size() == 0) {
      return vector<string>(1, S);
    }

    int start = 0;
    backtrack(S, letters, ans, start);
    return vector<string>(ans.begin(), ans.end());
  }
private:
  void backtrack(string& S, vector<int>& letters, unordered_set<string>& ans, int start) {
    for (int i = start; i < letters.size(); i++) {
      char ch = S[letters[i]];   // 先取出原来的字符
      //cout << "ch = " << ch << endl;
      if (ch >= 'a' && ch <= 'z') {
        // 小写转大写
        S[letters[i]] = std::toupper(S[letters[i]]);
        //cout << "upper S[i] " << S[letters[i]] << endl;
      } else {
        // 大写转小写
        S[letters[i]] = std::tolower(S[letters[i]]);
        //cout << "lower S[i] " << S[letters[i]] << endl;
      }
      ans.insert(S);
      backtrack(S, letters, ans, start + 1);
      S[letters[i]] = ch;
      ans.insert(S);
    }
  }
};


class Solution2 {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    backtrack(S, 0, ans);
    return ans;
  }

  void backtrack(string &s, int i, vector<string> &ans) {
    if (i == s.size()) {
      cout << s << endl;
      ans.push_back(s);
      return;
    }
    // save initial value
    char c = s[i];
    cout << "save char: " << c << endl;
    // path1: toggle lower/upper case
    s[i] = islower(c) ? toupper(c) : tolower(c);
    backtrack(s, i + 1, ans);
    // path2: reset back(NOT go to this path if c is digit)
    if (isalpha(c)) {
      cout << "cur s[i] = " << s[i] << ", reset back to : " << c << endl;
      s[i] = c;
      backtrack(s, i + 1, ans);
    }
  }
};


class Solution3 {
public:
  /**
          a1b2   i=0, when it's at a, since it's a letter, we have two branches: a, A
       /        \
     a1b2       A1b2 i=1 when it's at 1, we only have 1 branch which is itself
      |          |
     a1b2       A1b2 i=2 when it's at b, we have two branches: b, B
     /  \        / \
    a1b2 a1B2  A1b2 A1B2 i=3  when it's at 2, we only have one branch.
     |    |     |     |
    a1b2 a1B2  A1b2  A1B2 i=4 = S.length(). End recursion, add permutation to ans.

    During this process, we are changing the S char array itself
  */

  vector<string> letterCasePermutation(string S) {
    vector<string> result;
    backtrace(S, 0, result);
    return result;
  }

private:
  void backtrace(string S, int i, vector<string> &result) {
    if (i == S.length()) {
      result.push_back(S);
      return;
    }
    if ('a' <= S[i] && S[i] <= 'z') { // two branches if a letter
        backtrace(S, i + 1, result);
        S[i] = 'A' + S[i] - 'a';
        backtrace(S, i + 1, result);
    } else if ('A' <= S[i] && S[i] <= 'Z') { // two branch if a letter
        backtrace(S, i + 1, result);
        S[i] = 'a' + S[i] - 'A';
        backtrace(S, i + 1, result);
    } else { // one branch if a digit
        backtrace(S, i + 1, result);
    }
  }
};

int main() {
  vector<string> ans;
  //ans = Solution2().letterCasePermutation("JcTNPT1AsvC");
  ans = Solution2().letterCasePermutation("a1b2");
  cout << "ans size = " << ans.size() << endl;
  return 0;
}

