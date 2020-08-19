// 384. Shuffle an array
/*
 * Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

class Solution {
public:
  Solution(vector<int>& nums) {
    array = nums;
    original = nums;
    std::rand(std::time(nullptr));
  }

  vector<int> reset() {
    array = original;
    return array;
  }

  // 洗牌算法
  // 基于交换, 随机产生i到nums.size()的下标, 和当前下标的值交换
  vector<int> shuffle() {
    for (int i = 0; i < array.size(); i++) {
      int x = rand() % array.size();
      swap(array[i], array[x]);
    }
    return array;
  }
private:
  vector<int> array;
  vector<int> original;
};
