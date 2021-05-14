// 1054. Distant Barcodes
/*
 * In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
   Rearrange the barcodes so that no two adjacent barcodes are equal.
   You may return any answer, and it is guaranteed an answer exists.

Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]

Constraints:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
*/

class Solution {
public:
  vector<int> reArrangeBarCodes(vector<int>& barcodes) {
    unordered_map<int, int> cntmap;
    for (int v : barcodes)
      cntmap[v]++;

    auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
      if (p1.second == p2.second)
        return p1.first < p2.first;
      return p1.second < p2.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    for (auto it = cntmap.begin(); it != cntmap.end(); it++) {
      q.push({it->first, it->second});
    }

    vector<int> ans(barcodes.size(), 0);
    int idx = 0;
    while (idx < ans.size()) {
      if (!q.empty()) {
        auto p1 = q.top();
        q.pop();
        ans[idx++] = p1.first;
        p1.second--;

        if (!q.empty()) {
          auto p2 = q.top();
          q.pop();
          ans[idx++] = p2.first;
          p2.second--;
          if (p2.second > 0)
            q.push(p2);
        }
        if (p1.second > 0)
          q.push(p1);
      }
    }
    return ans;
  }
};
