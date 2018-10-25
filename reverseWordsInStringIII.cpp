// 557. Reverse Words in a String III

/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and 
initial word order.

Example 1:

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string. 
*/

class Solution {
public:
  string reverseWords(string s) {
    s += " ";
    for (int i = 0, j = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        reverseWord(s, j, i-1);
        j = i + 1;
      } 
    }
    return s.substr(0, s.size() - 1);
  }
private:
  void reverseWord(string& word, int start, int end) {
    while (start < end) {
      swap(word[start++], word[end--]);
    }
  }
};
