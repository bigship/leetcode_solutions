// 739. Daily Temperatures
/*
 *  Given a list of daily temperatures T, return a list such that, for each day in the input,
 *  tells you how many days you would have to wait until a warmer temperature.
 *  If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73],
your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000].
Each temperature will be an integer in the range [30, 100].
*/

class Solution {
public:
  // Solution: Monotone stack
  // 用栈逆向保存元素的索引值
  // 如果栈为空表示没有任何一个数比当前的值要大, 此时该位置的结果就是0
  // 如果栈不为空, 且栈顶元素的值比当前的值要大, 表示栈顶元素就是下一个更大的值
  // 此时结果就是栈顶元素的值减去当前值的索引
  // 如果栈不为空, 且当前元素比栈顶还要大, 那么栈顶元素不是下一个更大的值, 为了寻找下一个
  // 更大的值需要一直pop栈顶元素, 直到发现下一个栈顶元素的值比当前的值要大.
  vector<int> dailyTemparetures(vector<int>& T) {
    std::stack<int> sk;
    const int n = T.size();
    vector<int> ans(n, 0);

    for (int i = n - 1; i >= 0; i--) {
      while (!sk.empty() && T[sk.top()] <= T[i]) {
        sk.pop();
      }
      if (sk.empty()) {
        ans[i] = 0;
      } else {
        ans[i] = sk.top() - i;
      }
      sk.push(i);
    }
    return ans;
  }
};
