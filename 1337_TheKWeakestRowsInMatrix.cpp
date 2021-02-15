// 1337. The K Weakest Rows in a Matrix
/*
 * Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians),
 * return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j,
or they have the same number of soldiers but i is less than j.
Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

Example 1:

Input: mat =
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]],
k = 3
Output: [2,0,3]
Explanation:
The number of soldiers for each row is:
row 0 -> 2
row 1 -> 4
row 2 -> 1
row 3 -> 2
row 4 -> 5
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
*/

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> ans;

    auto cmp = [&](pair<int, int>& p1, pair<int, int>& p2) {
      if (p1.first == p2.first)
        return p1.second > p2.second;
      return p1.first > p2.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    for (int i = 0; i < mat.size(); i++) {
      int cntOne = 0;
      auto it = std::lower_bound(mat[i].rbegin(), mat[i].rend(), 1);
      if (it == mat[i].rend())
        cntOne = 0;
      else
        cntOne = abs(distance(rend(mat[i]), it));
      q.push({cntOne, i});
    }

    while (!q.empty() && ans.size() < k) {
      auto p = q.top();
      q.pop();
      ans.push_back(p.second);
    }
    return ans;
  }
};
