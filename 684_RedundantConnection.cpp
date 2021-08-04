// 684. Redundant Connection
/*
 * In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added.
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes.
If there are multiple answers, return the answer that occurs last in the input.
*/

// Union Find
// 构建并查集数据结构. 按顺序遍历所有的边并尝试合并节点, 第一个不能合并的边就是答案
class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> ans;
    UnionFind uf(edges.size() + 1);

    for (int i = 0; i < edges.size(); i++) {
      if (!uf.unionGroup(edges[i][0], edges[i][1])) {
        ans.push_back(edges[i][0]);
        ans.push_back(edges[i][1]);
        break;
      }
    }

    return ans;
  }
private:
  class UnionFind {
    vector<int> group;
    vector<int> rank;
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
      int id1 = find(obj1);
      int id2 = find(obj2);
      if (id1 == id2) {
        return false;
      }

      if (rank[id1] < rank[id2]) {
        group[id1] = id2;
      } else if (rank[id1] > rank[id2]) {
        group[id2] = id1;
      } else {
        group[id1] = id2;
        rank[id2] += 1;
      }
      return true;
    }
  };
};
