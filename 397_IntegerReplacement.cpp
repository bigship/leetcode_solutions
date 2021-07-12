// 397. Integer Replacement
/*
 * Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

Example 1:

Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1
*/

// Dynamic programming
class Solution {
public:
  int integerReplacement(int n) {
    std::unordered_map<int, int> mem;
    return helper(static_cast<long>(n), mem);
  }
private:
  int helper(long n, unordered_map<int, int>& mem) {
    if (n == 1) return 0;
    if (mem.count(n)) return mem[n];
    if (n % 2 == 0) return 1 + helper(n/2, mem);
    return mem[n] = 1 + std::min(helper(n + 1, mem), helper(n - 1, mem));
  }
};
