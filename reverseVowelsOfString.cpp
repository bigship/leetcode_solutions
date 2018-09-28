// 345. Reverse Vowels of a String

/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"

Example 2:

Input: "leetcode"
Output: "leotcede"

Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
  string reverseVowels(string s) {
    unordered_map<char, int> m {
      {'a',1}, {'A',1}, {'e',1}, {'E',1}, {'i',1}, 
      {'I',1}, {'o',1}, {'O',1}, {'u',1}, {'U',1}
    };
    
    int i = 0, j = s.size() - 1;
    int ldx = -1, rdx = -1;
    while (i < j) {
      if (m.find(s[i]) != m.end()) {
        ldx = i;
        if (rdx != -1) {
          swap(s[ldx], s[rdx]);
          ldx = rdx = -1;
          i++;
          j--;
        }
      } else {
        i++;
      }

      if (m.find(s[j]) != m.end()) {
        rdx = j;
        if (ldx != -1) {
          swap(s[ldx], s[rdx]);
          ldx = rdx = -1;
          i++;
          j--;
        } 
      } else {
        j--;
      }
    }
    return s;
  }
};