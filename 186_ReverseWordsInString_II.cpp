// 186. Reverse Words in a String II
/* Given an input string , reverse the string word by word.

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

Note:

    A word is defined as a sequence of non-space characters.
    The input string does not contain leading or trailing spaces.
    The words are always separated by a single space.

Follow up: Could you do it in-place without allocating extra space?
*/

class Solution {
public:
  void reverseWords(vector<char>& s) {
    std::reverse(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < s.size() && j < s.size()) {
      while (j < s.size() && s[j] != ' ')
        j++;
      if (i >= 0 && i < s.size() && j - 1 >= 0 && j - 1 < s.size())
        reverseWord(s, i, j - 1);
      j++;
      i = j;
    }
    return ;
  }
private:
  void reverseWord(vector<char>& s, int begin, int end) {
    while (begin < end) {
      std::swap(s[begin++], s[end--]);
    }
    return ;
  }
};

