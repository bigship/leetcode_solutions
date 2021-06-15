// 1182. Shortest Distance to Target Color
/*
 * You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries.
Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c.
If there is no solution return -1.

*/

class Solution {
public:
  vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
    vector<int> ans;
    unordered_map<int, vector<int>> colorIdxMap;
    for (int i = 0; i < colors.size(); i++) {
      colorIdxMap[colors[i]].push_back(i);
    }

    for (int i = 0; i < queries.size(); i++) {
      int idx = queries[i][0];
      int color = queries[i][1];

      if (colorIdxMap.count(color) == 0) {
        ans.push_back(-1);
      } else {
        auto low = std::lower_bound(colorIdxMap[color].begin(), colorIdxMap[color].end(), idx);
        if (low == colorIdxMap[color].end()) {
          ans.push_back(idx - colorIdxMap[color].back());
        } else {
          if (low == colorIdxMap[color].begin()) {
            ans.push_back(abs(*low - idx));
          } else {
            auto pre = std::prev(low);
            ans.push_back(std::min(abs(*pre - idx), abs(*low - idx)));
          }
        }
      }
    }
    return ans;
  }
};


