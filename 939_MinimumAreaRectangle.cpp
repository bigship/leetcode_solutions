// 939. Minimum Area Rectangle
/*
 * Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points,
 * with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4

Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2

Note:

    1 <= points.length <= 500
    0 <= points[i][0] <= 40000
    0 <= points[i][1] <= 40000
    All points are distinct.
*/

class Solution {
public:
  int minAreaRect(vector<vector<int>>& points) {
    unordered_map<int, unordered_set<int>> map;
    for(auto& p : points){
      map[p[0]].insert(p[1]);
    }

    int result = INT_MAX;
    for (int i = 0; i < points.size(); i++){
      for (int j = i + 1; j < points.size(); j++){
        int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
        if (x1 == x2 || y1 == y2) continue;   // 要构成对角线, x1 != x2, y1 != y2

        // 可以构成对角线了, 看另外两个点是否存在, 存在就求面积并更新min值
        if (map[x1].count(y2) && map[x2].count(y1)) {
          result = min(result, abs(x1 - x2) * abs(y1 - y2));
        }
      }
    }
    return result == INT_MAX ? 0 : result;
  }
};


