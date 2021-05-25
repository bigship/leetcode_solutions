// 150. Evaluate Reverse Polish Notation
/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    vector<int> cur;
    int res = 0;
    unordered_set<string> ops = {"+", "-", "*", "/"};

    for (int i = 0; i < tokens.size(); i++) {
      if (ops.count(tokens[i]) == 0) {
        cur.push_back(std::stoi(tokens[i]));
      } else {
        int val1 = cur.back();
        cur.pop_back();
        int val2 = cur.back();
        cur.pop_back();

        int res = 0;
        if (tokens[i] == "+") {
          res = val2 + val1;
        } else if (tokens[i] == "-") {
          res = val2 - val1;
        } else if (tokens[i] == "*") {
          res = val2 * val1;
        } else {
          res = val2 / val1;
        }

        cur.push_back(res);
      }
    }
    return cur.back();
  }
};


