// 1657. Determine if Two Strings Are Close
/*
 * Two strings are considered close if you can attain one from the other using the following operations:

    Operation 1: Swap any two existing characters.
        For example, abcde -> aecdb
    Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
        For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.
Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.


Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"

Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"

Example 4:

Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.

Constraints:

    1 <= word1.length, word2.length <= 105
    word1 and word2 contain only lowercase English letters.
*/
// Solution:
// 长度不相同肯定返回false
// 统计各个字符出现的次数, 如果a中有b中未出现过的字符或者b中有a里没有出现过的字符就返回false
// 如果a中所有字符在b中都出现过, 且b中所有字符也在a中都出现过
// 将字符次数排序, 如果相同就表示满足要求返回true, 否则返回false
// 由于都是小写字母, 使用数组做map可提速
class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length())
      return false;

    vector<int> map1(26, 0);
    vector<int> map2(26, 0);
    for (auto& ch : word1) map1[ch - 'a']++;
    for (auto& ch : word2) map2[ch - 'a']++;
    for (int i = 0; i < 26; i++) {
      if (map1[i] == 0 && map2[i] != 0 || map1[i] != 0 && map2[i] == 0)
        return false;
    }

    std::sort(map1.begin(), map1.end());
    std::sort(map2.begin(), map2.end());
    return map1 == map2;
  }
};


