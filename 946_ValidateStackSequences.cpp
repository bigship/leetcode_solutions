// 946. Validate Stack Sequences
/*
 * Given two sequences pushed and popped with distinct values,
 * return true if and only if this could have been the result of a sequence of
 * push and pop operations on an initially empty stack.

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.

Constraints:

    0 <= pushed.length == popped.length <= 1000
    0 <= pushed[i], popped[i] < 1000
    pushed is a permutation of popped.
    pushed and popped have distinct values.
*/

// 依次push到栈中. 如果当前栈顶和popped[idx]的值相同, 表示我们
// 必须要pop掉栈顶. 否则后续的push会修改栈顶元素, 那样就没法按popped
// 的顺序得到弹出的值了
// 最后检查idx是否和popped的长度相同, 表示是否可以全部pop出去.
class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    std::stack<int> sk;

    int j = 0;
    for (auto& val : pushed) {
      sk.push(val);
      while (!sk.empty() && j < n && sk.top() == popped[j]) {
        sk.pop();
        j++;
      }
    }
    return j == n;
  }
};

