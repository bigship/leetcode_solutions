// 1135. Connecting Cities With Minimum Cost
/*
 * There are n cities labeled from 1 to n.
 * You are given the integer n and an array connections where connections[i] = [xi, yi, costi]
 * indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities.
If it is impossible to connect all the n cities, return -1,

The cost is the sum of the connections' costs used.
*/

// 最小生成树. Kruskal algorithm
// Same with 1584, 1168
int minimumCost(int n, vector<vector<int>>& connections) {
  std::sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
  });

  int connected = 0;
  int ans = 0;
  UnionFind UF(n);

  for (int i = 0; i < connections.size(); i++) {
    if (UF.unionGroup(connections[i][0], connections[i][1])) {
      connected++;
      ans += connections[i][2];
    }
  }

  if (connected != n - 1) {
    return -1;
  }
  return ans;
}

class UnionFind {
  vector<int> group;
  vector<int> rank;
public:
  UnionFind(int size) {
    group = vector<int>(size + 1);
    rank = vector<int>(size + 1, 0);

    for (int i = 0; i < size + 1; i++) {
      group[i] = i;
    }
  }

  int find(int id) {
    if (group[id] != id) {
      group[id] = find(group[id]);
    }
    return group[id];
  }

  bool unionGroup(int id1, int id2) {
    int g1 = find(id1);
    int g2 = find(id2);
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



