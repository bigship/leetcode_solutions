// 611. Valid Triangle Number
/*
 * Given an array consists of non-negative integers, your task is to count the
 * number of triplets chosen from the array that can make triangles if we take
 * them as side lengths of a triangle.

Example 1:

Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Note:

    The length of the given array won't exceed 1000.
    The integers in the given array are in the range of [0, 1000].
*/

class Solution {
public:
  // 从大到小排序后双指针前后夹
  // 最小的值加第二大的值如果大于最大值, 则是合法三角形
  int triangleNumber(vector<int>& nums) {
    const int n = nums.size();
    if (n < 3) return 0;
    int ans = 0;
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    // std::sort(nums.rbegin(), nums.rend()) 倒序排也可以
    for (int a = 0; a < n - 2; a++) {
      int b = a + 1;  // 第2大
      int c = n - 1;  // 最小
      while (b < c) {
        if (nums[c] + nums[b] > nums[a]) {
          ans += (c - b);
          ++b;
        } else {
          --c;
        }
      }
    }
    return ans;
  }
};

