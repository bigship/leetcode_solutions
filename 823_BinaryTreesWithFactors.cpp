// 823. Binary Trees With Factors
/*
 * Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times.
Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

Constraints:
    1 <= arr.length <= 1000
    2 <= arr[i] <= 109
*/
// Solution:
// 数组中最大的值肯定是作为根节点
// 考虑左右子树, 那么原问题可以分解为计算左右子树分别可以有多少种方式构成,
// 那么对于根节点来说, 总的构成方式就是左子树的构成方式乘以右子树的构成方式
//
// 先对数组排序, 依次取数组中的元素来作为根节点, 然后尝试得到其左右子树的解
// 采用动态规划的思想, 设状态dp[i]表示以第i个元素作为根节点一共有多少种方法可以构成符合要求的二叉树
// 答案就是sum(dp[0 ... i])
class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& A) {
    int MOD = 1000000007;
    int N = A.size();
    std::sort(A.begin(), A.end());
    vector<long> dp(N, 1);  // 定义dp状态数组, 初始化为1. 按题意每个单独的元素都可以构成一个合法的二叉树

    unordered_map<int, int> idxmap;  // 用hashmap记录下数组元素对应的下标, 方便我们快速判断某个值是否存在于数组中
    for (int i = 0; i < N; i++) {
      idxmap[A[i]] = i;
    }

    // 外层循环遍历根节点的可能值
    for (int i = 0; i < N; i++) {
      // 内层循环遍历左子树的可能值
      // 符合条件的右子树的值需要满足A[i] % A[j] == 0
      // 此时判断该右子树的值是否存在于原数组中
      for (int j = 0; j < i; j++) {
        if (A[i] % A[j] == 0) {  // A[j] is left child
          int right = A[i] / A[j];
          if (idxmap.count(right) != 0) {
            dp[i] = (dp[i] + dp[j] * dp[idxmap[right]]);
          }
        }
      }
    }
    long ans = 0;
    for (long x : dp) {
      ans += x;
    }

    return (int) ( ans % MOD);
  }
};

