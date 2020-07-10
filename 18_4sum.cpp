// 18. 4 Sum
/*
 * Given an array nums of n integers and an integer target, are there
 * elements a, b, c, and d in nums such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <unordered_set>

using namespace std;

// 基本思路就是排序后双指针前后夹击. 最后记得要去重
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    sort(nums.begin(), nums.end());

    auto last = nums.end();
    for (auto a = nums.begin(); a < prev(last, 3); ++a) {
        for (auto b = next(a); b < prev(last, 2); ++b) {
            auto c = next(b);
            auto d = prev(last);
            while (c < d) {
                if (*a + *b + *c + *d < target) {
                    ++c;
                } else if (*a + *b + *c + *d > target) {
                    --d;
                } else {
                    res.push_back({*a, *b, *c, *d});
                    ++c;
                    --d;
                }
            }
        }
    }

    // remove duplicate
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main() {
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<vector<int>> ans = fourSum(nums, 0);
    for (auto& v : ans) {
        for (auto& val : v) {
            cout << val << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

