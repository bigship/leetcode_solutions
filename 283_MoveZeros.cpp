// 283. Move Zeros
/*
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
*/

class Solution {
public:
    // 先把所有不为0的数按顺序从左往右填充, 剩下的0只需要往尾部填入即可
    // Time - O(n), Mem - O(1)
    void moveZeros(vector<int>& nums) {
        int insertIndex = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[insertIndex++] = nums[i];
            }
        }

        int zeroCnt = n - insertIndex;
        int fillZeroIndex = n - 1;
        while (zeroCnt != 0) {
            nums[fillZeroIndex--] = 0;
            zeroCnt--;
        }
        return ;
    }

    // 基于交换的思想
    // Time: O(n^2)
    void moveZeros2(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                for (int j = i+1; j < n; ++j) {
                    if (nums[j] != 0) {
                        std::swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
        return ;
    }
};
