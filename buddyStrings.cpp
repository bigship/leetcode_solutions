// 859. Buddy Strings

/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

Example 1:

Input: A = "ab", B = "ba"
Output: true

Example 2:

Input: A = "ab", B = "ab"
Output: false

Example 3:

Input: A = "aa", B = "aa"
Output: true

Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:

Input: A = "", B = "aa"
Output: false

 

Note:

    0 <= A.length <= 20000
    0 <= B.length <= 20000
    A and B consist only of lowercase letters.

*/

// 如果A和B长度都不相等, 显然无法通过只交换一次就得到另一个字符串
// 如果A和B相等, 由于需要交换一次才行, 那么A中必须要有重复的字符才可以. 此时交换相同的字符即可满足
// 如果A和B不相等, 则计算A和B中共有多少个位置的字符不相同. 如果有超过2个不相同的位置, 则无法只通过交换一次来得到对方
// 如果确实只有2个不同的位置, 则还需要判断这两个位置上的字符是否交叉相等. (ab, ba)

class Solution {
  bool buddyStrings(string A, string B) {
    int lenA = A.size();
    int lenB = B.size();
    if (lenA != lenB) return false;
    if (A == B && set<char>(A.begin(), A.end()).size() < lenA) return true;

    vector<int> diff;
    for (int i = 0; i < lenA; i++) {
      if (A[i] != B[i]) diff.push_back(i);
    }
    if (diff.size() != 2) return false;
    return A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
  }
};