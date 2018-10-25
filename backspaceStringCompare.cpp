// 844. Backspace String Compare

/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. 
# means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.

Follow up:

    Can you solve it in O(N) time and O(1) space?
*/

// Solution 1. two stacks. time complexcity: O(n), space complexcity: O(m + n)
// Solution 2. modify string in-place time complexcity: O(n), space complexcity: O(1) 

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    stack<char> st1;
    stack<char> st2;
    for (auto& s : S) {
      if (s != '#') {
        st1.push(s);
      } else {
        if (!st1.empty()) st1.pop();
      }
    }
    for (auto& t : T) {
      if (t != '#') {
        st2.push(t);
      } else {
        if (!st2.empty()) st2.pop();
      }
    }
    
    return st1 == st2;
  }

  bool backspaceCompare2(string S, string T) {
    if (S.size() == 1 && T.size() == 1) return S == T;
    transformString(S);
    transformString(T);
    return S == T;
  }
private:
  void transformString(string& str) {
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '#') {
        str.erase(str.begin() + i);
        i--;
        if (i >= 0) {
          str.erase(str.begin()+i);
          i--;
        }
      }
    }
  }
};

