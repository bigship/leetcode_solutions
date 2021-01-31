// 31. Next Permutation
/*
 * Implement next permutation, which rearranges numbers into the lexicographically
 * next greater permutation of numbers.
   If such arrangement is not possible, it must rearrange it as the lowest possible
   order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
  // Just call library function
  void nextPermutation(vector<int>& nums) {
    std::next_permutation(nums.begin(), nums.end());
    return ;
  }

  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;

    // 从右向左找出不再递增的位置
    while (i >= 0 && nums[i + 1] <= nums[i]) {
      i--;
    }

    // 如果是全递增的, 说明本身就是最大的permutation了, 逆序得到最小的排列
    if (i < 0) {
      std::reverse(nums.begin(), nums.end());
      return ;
    }

    // 从i的右边找到刚好比nums[i]要大的位置
    int j = nums.size() - 1;
    while (j >= 0 && nums[j] <= nums[i]) {
      j--;
    }
    std::swap(nums[i], nums[j]);   // 交换i, j位置上的值
    std::reverse(nums.begin() + i + 1, nums.end());  // 逆序从i+1到结尾的全部元素
    return ;
  }
};

