// 1498. Number of Subsequence that satisfy the given sum condition
/*
 * Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target.
Since the answer may be too large, return it modulo 109 + 7.

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

*/

// 排序后双指针往中间移动
// 如果确定了最大值和最小值的位置, 此时对于区间中间部分的所有元素都可以有取和不取两种选择
// 因此总的subsequence的数量是pow(2, j - i)个
// 由于题目数据规模较大, 计算pow时会超出整数范围. 可以提前计算好pow的值并取模
// 最大值的边界也可以利用二分查找的方法来确定. 假设最小值索引为i, 最大值的迭代器为prev(upper_bound(target - i))即可
class Soultion {
public:
  int numberSubseq(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    long MOD = 1e9 + 7;

    // precompute the power of 2
    vector<long> power(n + 1, 1);
    for (int i = 1; i <= n; i++)
      power[i] = power[i - 1] * 2 % MOD;

    long res = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
      while (j >= i && nums[i] + nums[j] > target)
        j--;
      if (j < i) break;
      res = (res + power[j - i]) % MOD;
    }
    return res;
  }
};

