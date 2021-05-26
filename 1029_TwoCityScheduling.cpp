// 1029. Two City Scheduling
/*
 * A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti],
 * the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
Example 2:

Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859
Example 3:

Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086

Constraints:

2 * n == costs.length
2 <= costs.length <= 100
costs.length is even.
1 <= aCosti, bCosti <= 1000
*/

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int res = 0;

    // sort the array by the absolute difference of a_cost - b_cost decreasingly
    std::sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
      return abs(a[0] - a[1]) > abs(b[0] - b[1]);   // max diff first
    });

    int n = costs.size();
    int acnt = 0, bcnt = 0;
    for (int i = 0; i < costs.size() / 2; i++) {
      if (costs[i][0] < costs[i][1]) {
        acnt++;
        res += costs[i][0];
      } else {
        bcnt++;
        res += costs[i][1];
      }
    }

    for (int i = costs.size() / 2; i < costs.size(); i++) {
      if (acnt == n / 2) {
        res += costs[i][1];      // always choose b
      } else if (bcnt == n / 2) {
        res += costs[i][0];      // always choose a
      } else {
        if (costs[i][0] < costs[i][1]) {
          acnt++;
          res += costs[i][0];
        } else {
          bcnt++;
          res += costs[i][1];
        }
      }
    }
    return res;
  }
};
