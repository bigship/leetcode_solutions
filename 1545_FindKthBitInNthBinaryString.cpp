// 1545. Find Kth Bit in Nth Binary String
/*
 * Given two positive integers n and k, the binary string  Sn is formed as follows:

    S1 = "0"
    Si = Si-1 + "1" + reverse(invert(Si-1)) for i > 1

Where + denotes the concatenation operation, reverse(x) returns the reversed string x,
and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first 4 strings in the above sequence are:

    S1 = "0"
    S2 = "011"
    S3 = "0111001"
    S4 = "011100110110001"

Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001". The first bit is "0".

Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001". The 11th bit is "1".

Example 3:

Input: n = 1, k = 1
Output: "0"

Example 4:

Input: n = 2, k = 3
Output: "1"

Constraints:

    1 <= n <= 20
    1 <= k <= 2n - 1
*/

class Solution {
public:
  // 直接根据要求生成字符串, 取第k - 1 (从1开始)位
  // Time: O(n), 212 ms
  char findKthBit(int n, int k) {
    string kth = kthS(n);
    return kth[k-1];
  }

  // 递归解法
  // 字符串长度为2^n - 1
  // 如果k刚好在中间, 则根据规则一定是加上的那个'1'
  // 如果在左半部分, 则和n - 1的解一样
  // 如果在右半部, 则递归求解n - 1, 但逆序过的解, 再翻转就是答案
  char findKthBit_recursive(int n, int k) {
    if (n == 1) return '0';
    int len = pow(2, n) - 1;
    if (k - 1 == len / 2) return '1';
    if (k - 1 < len / 2) return findKthBit_recursive(n - 1, k);
    return findKthBit_recursive(n - 1, len - k + 1) == '0' ? '1' : '0';
  }

private:
  string kthS(int n) {
    if (n == 1) return "0";
    string str = kthS(n - 1);
    return str + "1" + reverse(invert(str));
  }

  string invert(string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](char c) -> char {
      if (c == '0') return '1';
      return '0';
    });
    return s;
  }

  string reverse(string s) {
    std::reverse(s.begin(), s.end());
    return s;
  }
};

