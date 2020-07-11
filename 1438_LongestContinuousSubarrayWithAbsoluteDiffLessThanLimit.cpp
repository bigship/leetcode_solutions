// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
/*
 * Given an array of integers nums and an integer limit, return the size of the
 * longest non-empty subarray such that the absolute difference between any two
 * elements of this subarray is less than or equal to limit.



Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are:
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4.
Therefore, the size of the longest subarray is 2.

Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3



Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
    0 <= limit <= 10^9
*/

class Solution {
public:
    // use multiset, O(nlog(n))
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;   // binary tree
        int l = 0, ans = 0;
        for (int r = 0; r < nums.size(); ++r) {
            s.insert(nums[r]);
            while (*rbegin(s) - *begin(s) > limit)
                s.erase(s.equal_range(nums[l++]).first);
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }

    int longesetSubarray(vector<int>& nums, int limit) {
        deque<int> max_q; // keep track of the max element
        deque<int> min_q; // keep track of the min element
        int ans = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (!min_q.empty() && nums[r] < min_q.back())
                min_q.pop_back();
            while (!max_q.empty() && nums[r] > max_q.back())
                max_q.pop_back();
            min_q.push_back(nums[r]);
            max_q.push_back(nums[r]);
            while (max_q.front() - min_q.front() > limit) {
                if (max_q.front() == nums[l]) max_q.pop_front();
                if (min_q.front() == nums[l]) min_q.pop_front();
                ++l;
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};

