// 377. Combination Sum IV
/*
 * Given an integer array with all positive numbers and no duplicates,
 * find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

// Backtracking, TLE !!
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    int ans = 0;
    int start = 0;
    vector<int> cur;
    std::sort(nums.begin(), nums.end());
    backtrack(nums, cur, start, target, ans);
    return ans;
  }
private:
  void backtrack(vector<int>& nums, vector<int>& cur, int start, int left, int& ans) {
    if (left == 0) {
      ans++;
      return ;
    }
    for (int i = start; i < nums.size(); i++) {
      if (left < nums[i]) return ;
      cur.push_back(nums[i]);
      backtrack(nums, cur, start, left - nums[i], ans);
      cur.pop_back();
    }
  }
};

// 由于只要求数量而不是每一组解, 因此考虑动态规划的方法
// 和硬币找零一样, 以每个数i作为组合的结尾, 因此可以递归求解 combo(target - i, nums)
// 采用记忆化递归的方法, 通过hashmap记录已经求解过的答案
class Solution2 {
public:
  int combinationSum4(vector<int>& nums, int target) {
    unordered_map<int, int> memo;   // 记录凑出和target一共可以有多少种方法
    return combos(nums, target, memo);
  }
private:
  int combos(vector<int>& nums, int target, unordered_map<int, int>& memo) {
    if (target == 0)  // target == 0 表示我们不需要取任何元素就可以凑出和为0的解, 只有一种方法(都不取)
      return 1;
    if (memo.find(target) != memo.end())
      return memo[target];

    int res = 0;
    // 以每个元素作为组合中的最后一个值, 累加所有的结果数
    for (int num : nums) {
      if (target - num >= 0) {
        res += combos(nums, target - num, memo);
      }
    }
    memo[target] =  res;
    return res;
  }
};


