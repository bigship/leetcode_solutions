// 1128. Number Of Equivalent Domino Pairs
/*
 * Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d]
 * if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

Constraints:

    1 <= dominoes.length <= 40000
    1 <= dominoes[i][j] <= 9
*/
class Solution {
public:
  // Solution: 用hashmap保存pair出现的次数
  // 结果就是每个出现超过2次的pair中作组合, 累加组合数即可
  int numEquivDominoPairs(<vector<vector<int>>& dominoes) {
    int ans = 0;
    unordered_map<int, int> map;
    for (auto& dom: dominoes) {
      if (dom[0] > dom[1]) std::swap(dom[0], dom[1]);
      int key = dom[0] * 10 + dom[1];
      map[key]++;
    }
    for (auto &kv : map) {
      if (kv.second > 1) {
        ans += kv.second * (kv.second - 1) / 2;
      }
    }
    return ans;
  }
};
