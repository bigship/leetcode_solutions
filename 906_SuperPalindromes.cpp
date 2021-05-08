// 906. Super Palindromes
/*
 * Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

Example 1:

Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
Example 2:

Input: left = "1", right = "2"
Output: 1


Constraints:

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 10^18].
left is less than or equal to right.
*/
// 由于right最大到10^18, 如果A^2要组成回文, 则A < 10^9.
// 而A本身也需要是回文, 因此把A分成2半, 每一半的上限就是10^5
// 我们只需要回文的前一半即可, 后半部分可以根据前半部分构建
// 注意, 需要考虑回文串是奇数和偶数的情况
class Solution {
public:
  int superPalindromeInRange(string left, string right) {
    int ans = 0;
    long long low = stoll(left);
    long long high = stoll(right);

    for (int k = 1; k < 100000; k++) {
      string s = to_string(k);
      for (int i = s.length() - 2; i >= 0; i--)
        s.push_back(s[i]);
      long v = stol(s);
      v *= v;
      if (v > high) break;
      if (v >= low && isPalindrome(v))
        ans++;
    }

    for (int k = 1; k < 100000; k++) {
      string s = to_string(k);
      for (int i = s.length() - 1; i >= 0; i--)
        s.push_back(s[i]);
      long v = stol(s);
      v *= v;
      if (v > high) break;
      if (v >= low && isPalindrome(v))
        ans++;
    }
    return ans;
  }
private:
  bool isPalindrome(long x) {
    return x == reverse(x);
  }

  long reverse(long x) {
    long res = 0;
    while (x > 0) {
      res = 10 * res + x % 10;
      x /= 10;
    }
    return res;
  }
};
