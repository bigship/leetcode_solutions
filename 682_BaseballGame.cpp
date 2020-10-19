// 682. Baseball Game
/*
 * You are keeping score for a baseball game with strange rules.
 * The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops,
where ops[i] is the ith operation you must apply to the record and is one of the following:

    An integer x - Record a new score of x.
    "+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
    "D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
    "C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.

Return the sum of all the scores on the record.

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.

Example 3:

Input: ops = ["1"]
Output: 1

Constraints:
    1 <= ops.length <= 1000
    ops[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
    For operation "+", there will always be at least two previous scores on the record.
    For operations "C" and "D", there will always be at least one previous score on the record.
*/

class Solution {
public:
  int calPoints(vector<string>& ops) {
    vector<int> points;
    for (int i = 0; i < ops.size(); i++) {
      if (ops[i] == "C") {
        points.pop_back();
      } else if (ops[i] == "D") {
        int v = points.back();
        points.push_back(2 * v);
      } else if (ops[i] == "+") {
        int a = points.back();
        int b = points[points.size() - 2];
        points.push_back(a+b);
      } else {
        int v = retriveNumber(ops[i]);
        points.push_back(v);
      }
    }
    return std::accumulate(points.begin(), points.end(), 0);
  }
private:
  int retriveNumber(string& str) {
    int sign = 1;
    int ret = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '-') {
        sign = -1;
        continue;
      }
      ret = ret * 10 + (str[i] - '0');
    }
    return ret * sign;
  }
};


