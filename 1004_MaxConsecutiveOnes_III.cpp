// 1004. Max Consecutive Ones III
/*
 * Given a binary array nums and an integer k,
 * return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
0 <= k <= nums.length

*/

class Solution {
public:
  // 不减少窗口的大小. 如果包含了多于k的0, 只需要移动left即可
  int longestOnes(vector<int>& nums, int k) {
    int left = 0, right;
    for (right = 0; right < nums.size(); right++) {
      if (nums[right] == 0) {
        k--;
      }
      if (k < 0) {
        if (nums[left] == 0) {
          k++;
        }
        left++;
      }
    }

    return right - left;
  }

  // 标准的滑动窗口. 先移动右端去扩展窗口,
  // 当窗口中包含的0已经超过了k, 此时移动左窗口, 让已经包含过的0移出去
  // 之后右窗口就可以继续扩展了
  int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int maxlen = INT_MIN;
    while (right < nums.size()) {
      // 如果当前是0, 减少k
      if (nums[right] == 0) {
        k--;
      }

      // 已经无法再包含更多的0了, 此时移动左窗口, 将已经包含的0移出去
      while (k < 0) {
        if (nums[left] == 0) {
          k++;
        }
        left++;
      }

      // 更新窗口的最大长度值
      maxlen = std::max(maxlen, right - left + 1);
      right++;
    }

    return maxlen;
  }
};
