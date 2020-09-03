// 260. Single Number III
/*
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
 * Find the two elements that appear only once. You can return the answer in any order.

Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]

Constraints:
    1 <= nums.length <= 30000
     Each integer in nums will appear twice, only two integers will appear once.
*/
class Solution {
public:
    // Solution: 利用异或, 第一次遍历求得只出现一次的两个数的异或值
    // 将数组分成两组, 其中每一组包含所求的其中一个值. 针对每一组再次求异或即为所求的值
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans = {0, 0};
        int xorsum = 0;
        for (auto& val : nums)
            xorsum ^= val;
        xorsum &= -xorsum;    // hightest 1 bit, 以此区分开所要求的两个值
        for (auto& val : nums) {
            if (xorsum & val == 0) {
                ans[0] ^= val;
            } else {
                ans[1] ^= val;
            }
        }
        return ans;
    }
};
