// 119. Pascal's Triangle II

/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

// formula: for any row: r[i] = r[i-1]*(row - i + 1) / i

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> r;
    r.resize(rowIndex + 1);
    r[0] = r[rowIndex] = 1;
    for (auto i = 1; i < (r.size() + 1) / 2; ++i) {
      r[i] = r[rowIndex - i] = (unsigned long)r[i - 1] * (unsigned long)(rowIndex - i + 1) / i;
    }
    return r;
  }
};
