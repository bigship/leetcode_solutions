// 80. Remove Duplicates from Sorted Array II
/*
 * Given a sorted array nums, remove the duplicates in-place such that duplicates
 * appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input
array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.

Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        int pos = 1;
        while (pos < nums.size() - 1) {
            if (nums[pos + 1] == nums[pos - 1]) {
                nums.erase(nums.begin() + pos);
                continue;
            }
            ++pos;
        }
        return nums.size();
    }
};
