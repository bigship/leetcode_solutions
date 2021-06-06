// 1383. Maximum Performance of a Team
/*
 * You are given two integers n and k and two integer arrays speed and efficiency both of length n.
 * There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.
Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.


Example 1:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60

Explanation:
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7).
That is, performance = (10 + 5) * min(4, 7) = 60.

*/

class Solution {
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    const int mod = 1e9 + 7;
    vector<pair<int, int>> candidates;
    candidates.reserve(n);
    for (int i = 0; i < n; i++) {
      candidates.emplace_back(speed[i], efficiency[i]);
    }

    std::sort(candidates.begin(), candidates.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.second > b.second;
    });

    std::priority_queue<int, vector<int>, std::greater<int>> speedHeap;   // minHeap
    long res = 0, totalSpeed = 0;
    for (auto& p : candidates) {
      int curspeed = p.first;
      int cureffi  = p.second;

      while (speedHeap.size() == k) {
        totalSpeed -= speedHeap.top();
        speedHeap.pop();
      }
      totalSpeed += curspeed;
      speedHeap.push(curspeed);
      res = std::max(res, totalSpeed * cureffi);
    }
    return res;
  }
};
