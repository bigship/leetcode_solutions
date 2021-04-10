// 953. Verifying an Alien Dictionary
/*
 * In an alien language, surprisingly they also use english lowercase letters,
 * but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet,
return true if and only if the given words are sorted lexicographicaly in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.)
According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅'
is defined as the blank character which is less than any other character (More info).


Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 20
    order.length == 26
    All characters in words[i] and order are English lowercase letters.
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
      int n = words.size();
      unordered_map<char, int> m;
      for (int i = 0; i < order.size(); i++)
        m[order[i]] = i;
      for (int i = 1; i < n; i++) {
        if (!compareTwoWords(words[i-1], words[i], m))
          return false;
      }
      return true;
    }
private:
    bool compareTwoWords(string& s1, string& s2, unordered_map<char, int>& dict) {
      int n1 = s1.size();
      int n2 = s2.size();
      int i, j;
      int ans = -1;
      for (i = 0, j = 0; i < n1 && j < n2; i++, j++) {
        if (s1[i] == s2[j]) continue;
        if (dict[s1[i]] < dict[s2[j]]) {
          ans = 1;
          break;
        } else {
          ans = 0;
          break;
        }
      }

      if (ans == -1) {
        if (n1 == n2) {
          return true;
        }
        return n2 > n1;
      }
      return ans;
    }
};


