// 679. 24 Game
/*
 * You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9].
 * You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/']
 * and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
You cannot concatenate numbers together
For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
Return true if you can get such expression that evaluates to 24, and false otherwise.

Example 1:

Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24
Example 2:

Input: cards = [1,2,1,2]
Output: false

Constraints:

cards.length == 4
1 <= cards[i] <= 9
*/

// 每一轮选取两个数, 这两个数可以进行加减乘除运算, 一共可以得到6种计算结果
// 选出每一种计算结果, 和剩余的数组合在一起, 下一轮递归时重复这个操作 (每一次递归数组长度都会减少1)
// 当数组中只有一个值时, 判断这个值是否等于24.0
class Solution {
public:
  bool judge24Points(vector<int>& cards) {
    vector<double> deck(cards.size());
    for (int i = 0; i < cards.size(); i++) {
      deck[i] = static_cast<double>(cards[i]);
    }
    return helper(deck);
  }
private:
  bool helper(vector<double>& deck) {
    if (deck.size() == 1) {
      return abs(deck[0] - 24.0) <= 0.0001;
    }

    for (int i = 0; i < deck.size(); i++) {
      for (int j = i + 1; j < deck.size(); j++) {
        vector<double> next(deck.size() - 1);
        int idx = 0;
        for (int k = 0; k < deck.size(); k++) {
          if (k != i && k != j) {
            next[idx++] = deck[k];
          }
        }

        for (double d : compute(deck[i], deck[j])) {
          next[next.size() - 1] = d;
          if (helper(next)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  vector<double> compute(double a, double b) {
    return {a+b, a-b, b-a, a*b, a/b, b/a};
  }
};
