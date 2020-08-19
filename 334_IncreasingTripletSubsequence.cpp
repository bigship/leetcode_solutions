// 334. Increasing Triplet Subsequence
/*
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
   Formally the function should:

    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true

Example 2:

Input: [5,4,3,2,1]
Output: false
*/
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
  // Brute force. TLE !!
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;
    vector<int> cur;
    bool ans = false;
    bool added = false;
    function<void(int)> helper = [&](int idx) {
      if (cur.size() == 3) {
        ans = true;
        return ;
      }
      if (idx == nums.size()) return ;
      for (int i = idx; i < nums.size(); i++) {
        if (cur.size() != 0) {
          if (cur.back() < nums[i]) {
            cur.push_back(nums[i]);
            added = true;
          }
        } else {
          cur.push_back(nums[i]);
          added = true;
        }
        helper(i+1);
        if (added) {
          cur.pop_back();
          added = false;
        }
      }
    };
    helper(0);
    return ans;
  }

  // Time: O(n), Space: O(1)
  // 维护最小的数以及第2小的数
  bool increasingTriplet_iter(vector<int>& nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int cur = nums[i];
      if (cur > min2) return true;  // 找到比第2小的数要大的数了, 返回true
      else if (cur < min1) min1 = cur;  // 找到比最小的数还小的, 更新最小的数
      else if (cur > min1 && cur < min2) min2 = cur;  // 找到比第2小的数要小，但要大于最小的数, 更新第2小的数
    }
    return false;  // 没有找到
  }
};

int main() {
  vector<int> arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  cout << std::boolalpha << Solution().increasingTriplet_iter(arr) << endl;
  return 0;
}


