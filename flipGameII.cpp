// 294. Flip Game II

/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example:

Input: s = "++++"
Output: true 
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
*/

class Solution {
public:
  bool canWin(string s) {
    unordered_map<string, bool> m;
    return helper(m, s);
  }

  bool canWin_noMemoization(string s) {
    for (int i = 1; i < s.size(); i++) {
      if ((s[i] == s[i-1]) && s[i] == '+') {
        s[i] = s[i-1] = '-';
        bool oppoent = canWin_noMemoization(s);
        s[i] = s[i-1] = '+';
        if (!oppoent) return true;
      }
    }
    return false;
  }
private:
  bool helper(unordered_map<string, bool>& m, string s) {
    if (m.find(s) != m.end()) return m[s];
    for (int i = 1; i < s.size(); i++) {
      if ((s[i] == s[i-1]) && s[i] == '+') {
        s[i] = s[i-1] = '-';
        bool oppoent = helper(m, s);
        s[i] = s[i-1] = '+';
        if (!oppoent) {
          m[s] = true;
          return true;
        }
      }
    }

    m[s] = false;
    return false;
  }
};