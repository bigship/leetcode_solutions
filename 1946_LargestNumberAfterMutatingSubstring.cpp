// 1946. Largest Number After Mutating Substring
/*
 * You are given a string num, which represents a large integer.
 * You are also given a 0-indexed integer array change of length 10 that maps each digit 0-9 to another digit.
 * More formally, digit d maps to digit change[d].

You may choose to mutate any substring of num.
To mutate a substring, replace each digit num[i] with the digit it maps to in change (i.e. replace num[i] with change[num[i]]).

Return a string representing the largest possible integer after mutating (or choosing not to) any substring of num.
A substring is a contiguous sequence of characters within the string.

Example 1:

Input: num = "132", change = [9,8,5,0,3,6,4,2,6,8]
Output: "832"
Explanation: Replace the substring "1":
- 1 maps to change[1] = 8.
Thus, "132" becomes "832".
"832" is the largest number that can be created, so return it.
*/

// Greedy
//
class Solution {
public:
  // largest possible.
  // d - change[d]
  // nums[i] - change[nums[i]]
  // 贪心思路. 从最高位开始替换, 因为是替换子数组, 因此一旦开始替换了中间就不能留空
  // 如果出现替换前后结果相同, 此时应该继续往下替换. 因为后面还有可能出现替换出更大值的情况
  // 如果出现替换后结果比替换前要小, 此时要看是否已经开始替换了, 如果已经开始替换了那么就说明
  // 到这里就可以停止替换了. 如果都还没有开始替换, 那么就继续往后搜索可以开始替换的点,
  string maximumNumber(string num, vector<int>& change) {
    bool found = false;
    for (int i = 0; i < num.length(); i++) {
      if (num[i] < change[num[i] - '0'] + '0') {
        found = true;
        num[i] = change[num[i] - '0'] + '0';
      } else {
        if (num[i] == change[num[i] - '0'] + '0') {
          continue;
        } else {
          if (found)
            break;
        }
      }
    }
    return num;
  }
};
