// 524. Longest Word in Dictionary through Deleting
/*
 *  Given a string and a string dictionary, find the longest string in the dictionary
 *  that can be formed by deleting some characters of the given string.
 *  If there are more than one possible results, return the longest word with the
 *  smallest lexicographical order.
 *  If there is no possible result, return the empty string.

Example 1:

Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"

Example 2:

Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"

Note:
    All the strings in the input will only contain lower-case letters.
    The size of the dictionary won't exceed 1,000.
    The length of all the strings in the input won't exceed 1,000.
*/

// s可以通过删除一些字符来得到字典中的单词, 说明字典中的单词一定需要是
// s的子序列. 因此遍历字典, 判断每个单词是否是s的子序列. 如果是则更新最大长度
// 以及ans. 如果最大长度相同, 此时看字符串的大小. 按字典序最小的作为结果

class Solution {
public:
  string findLongestWord(string s, vector<string>& d) {
    string ans;
    int maxlen = 0;
    for (auto& word : d) {
      if (isSubsequence(word, s)) {
        if (maxlen <= word.length()) {
          if (maxlen == word.length()) {
            if (ans > word) {
              ans = word;
            }
          } else {
            maxlen = word.length();
            ans = word;
          }
        }
      }
    }
    return ans;
  }
private:
  bool isSubsequence(string& str, string& target) {
    int n = str.length();
    int m = target.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (str[i] == target[j]) {
        i++;
        j++;
      } else {
        j++;
      }
    }
    return i == n;
  }
};

