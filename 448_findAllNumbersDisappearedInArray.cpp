// 448. Find All numbers disappeared in an array
/*
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the
returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int j = std::abs(nums[i]) - 1;
            nums[j] = std::abs(nums[j]) * -1;
        }
        for (auto& s : nums) {
            cout << s << ", ";
        }
        cout << endl;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution s1;
    vector<int> ans = s1.findDisappearedNumbers(nums);

    return 0;
}



