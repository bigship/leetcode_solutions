// 277. Find the Celebrity
/*
 * Suppose you are at a party with n people (labeled from 0 to n - 1), and among them, there may exist one celebrity.
 * The definition of a celebrity is that all the other n - 1 people know him/her, but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one.
The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B.
You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B.
Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party.
Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
*/

// 先找出可能的解. 设candidate初始为0, 从1开始遍历全部的人, 如果candidate认识i,
// 则需要更新candidate为i.
// 再次从0开始遍历所有人, 跳过candidate本身. 如果candidate认识任何其中的人或者其他人并不认识candidate
// 表示没有celebrity存在. 否则遍历结束后candidate就是答案

class Solution {
public:
  int findCelebrity(int n) {
    int candidate = 0;
    for (int i = 1; i < n; i++) {
      if (knows(candidate, i)) {
        candidate = i;
      }
    }

    for (int j = 0; j < n; j++) {
      if (j == candidate) continue;
      if (knows(candidate, j) || !knows(j, candidate)) {
        return -1;
      }
    }
    return candidate;
  }
};
