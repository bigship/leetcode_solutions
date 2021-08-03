// 1584. Min Cost to Connect All points
/*
 * You are given an array points representing integer coordinates of some points on a 2D-plane,
 * where points[i] = [xi, yi].
   The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance
   between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected.
All points are connected if there is exactly one simple path between any two points.
*/

// 并查集, 最小生成树
// 利用并查集生成一颗最小生成树
class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    vector<std::tuple<int, int, int>> costs;
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        costs.push_back({i, j, distance(points[i], points[j])});
      }
    }

    // sort by cost in ascending order 把边按照权重(这里就是花费)排序
    std::sort(costs.begin(), costs.end(), [](const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) {
      return std::get<2>(t1) < std::get<2>(t2);
    });

    UnionFind UF(costs.size());
    int ans = 0;
    for (int i = 0; i < costs.size(); i++) {
      int id1 = std::get<0>(costs[i]);
      int id2 = std::get<1>(costs[i]);
      int cost = std::get<2>(costs[i]);
      if (UF.unionGroup(id1, id2)) {
        ans += cost;
      }
    }
    return ans;
  }
private:
  int distance(const vector<int>& p1, const vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }

  class UnionFind {
    vector<int> group;
    vector<int> rank;   // 路径压缩
  public:
    UnionFind(int size) {
      group = vector<int>(size + 1);
      rank = vector<int>(size + 1);
      for (int i = 0; i < size + 1; i++) {
        group[i] = i;
        rank[i] = 0;
      }
    }

    int find(int obj) {
      if (group[obj] != obj) {
        group[obj] = find(group[obj]);
      }
      return group[obj];
    }

    bool unionGroup(int obj1, int obj2) {
      int g1 = find(obj1);
      int g2 = find(obj2);
      if (g1 == g2) {
        return false;
      }

      if (rank[g1] > rank[g2]) {
        group[g2] = g1;
      } else if (rank[g1] < rank[g2]) {
        group[g1] = g2;
      } else {
        group[g1] = g2;
        rank[g2] += 1;
      }
      return true;
    }
  };
};
