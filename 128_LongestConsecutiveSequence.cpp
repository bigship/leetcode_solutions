// 128. Longest Consecutive Sequence
/*
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
    0 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
*/
// Solution: 先找到最大和最小值
// 将所有元素加入hashset
// 从最小值开始累加直到最大值, 如果在hashset中就统计长度并更新最长的长度
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    const int n = nums.size();
    int maxlen = 0;
    auto [minval, maxval] = std::minmax_element(nums.begin(), nums.end());
    unordered_set<int> s;
    for (auto num : nums) {
      s.insert(num);
    }
    if (s.empty())
      return 0;

    int start = *minval, end = *maxval;
    while (start <= end) {
      int curlen = 0;
      while (s.count(start) != 0) {
        curlen++;
        if (maxlen < curlen) {
          maxlen = curlen;
        }
        start++;
      }
      start++;
    }

    return maxlen;
  }
};

// Solution: 还是先把所有元素加入到hashset中.
// 遍历hashset, 找起始元素. 即判断num - 1是否存在hashset中
// 如果num - 1不存在, 则从num开始递增, 判断num + 1是否依然存在hashset中
// 开始统计长度并更新maxlen
//
// 这里的思路就是如果num - 1存在, 则应该从num - 1开始计数, 这样才可能有更长的解
// 所以如果num - 1不存在于hashset中, 则num可以作为可能的起始点来开始统计
class Solution2 {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    for (auto num : nums) {
      s.insert(num);
    }
    if (s.empty()) return 0;

    int maxlen = 0;
    for (auto num : s) {
      if (s.count(num - 1) == 0) {
        int curnum = num;
        int curlen = 1;
        while (s.count(curnum + 1) != 0) {
          curlen++;
          curnum++;
        }
        if (maxlen < curlen) {
          maxlen = curlen;
        }
      }
    }
    return maxlen;
  }
};

