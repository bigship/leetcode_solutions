// 1944. Number Of Visible People in a Queue
/*
 * There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order.
 * You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them.
More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).
Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

*/

// 单调栈 Monotone Stack

class Solution {
public:
  // 单调栈. 反向处理, 维护栈中的元素单调递减
  vector<int> canSeePersonsCount(vector<int>& heights) {
    vector<int> ans(heights.size(), 0);
    stack<int> sk;
    for (int i = heights.size() - 1; i >= 0; i--) {
      int cnt = 0;
      while (!sk.empty() && heights[i] > heights[sk.top()]) {
        cnt++;
        sk.pop();
      }
      if (!sk.empty()) {
        cnt++;
      }
      ans[i] = cnt;
      sk.push(i);
    }
    return ans;
  }
};

