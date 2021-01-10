// 413. Arithmetic Slices
/*
 * A sequence of numbers is called arithmetic if it consists of at least three elements and
 * if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of the array A is called arithmetic if the sequence:
A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

// Solution: 1-D dynamic programming
// 满足条件的子数组必须有 A[i] - A[i - 1] == A[i - 1] - A[i - 2]
// 定义状态dp(i), 表示以索引i结尾的子数组中拥有满足条件的3元子数组的数目
// 整个问题的解就是对dp数组求和
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    const int n = A.size();
    if (n < 3) return 0;    // 至少要有3个元素
    vector<int> dp(n, 0);
    for (int i = 2; i < n; ++i) {
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
        dp[i] = dp[i - 1] + 1;
      }
    }
    return std::accumulate(dp.begin(), dp.end(), 0);
  }

  // 根据上面的解法, 发现dp[i]只和dp[i - 1]有关, 因此可以状态压缩
  // 只使用一个变量来表示即可
  int numberOfArithmeticSlices(vector<int>& A) {
    const int n = A.size();
    if (n < 3) return 0;
    int ans = 0;
    int dp = 0;
    for (int i = 2; i < n; ++i) {
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
        dp = dp + 1;
        ans += dp;
      } else {
        dp = 0;
      }
    }
    return ans;
  }
};

