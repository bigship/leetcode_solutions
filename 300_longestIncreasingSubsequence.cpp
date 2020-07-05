// 300. Longest Increasing Subsequence
/*
 * Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Note:

    There may be more than one LIS combination, it is only necessary for you to return the length.
    Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*
*/

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            int cur = (nums[i] > nums[j]) ? dp[j] + 1 : 1;
            dp[i] = std::max(dp[i], cur);
        }
    }
    return *(std::max_element(dp.begin(), dp.end()));
}

