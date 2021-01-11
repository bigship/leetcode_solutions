// 1245. Tree Diameter
/*
 * Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.

The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v.
Each node has labels in the set {0, 1, ..., edges.length}.

Input: edges = [[0,1],[0,2]]
Output: 2
Explanation:
A longest path of the tree is the path 1 - 0 - 2.

Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation:
A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.

Constraints:

    0 <= edges.length < 10^4
    edges[i][0] != edges[i][1]
    0 <= edges[i][j] <= edges.length
    The given edges form an undirected tree.
*/

class Solution {
public:
  int treeDiameter(vector<vector<int>>& edges) {
    // build graph as adjacent list
    std::unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
      graph[edge[0]] = edge[1];
      graph[edge[1]] = edge[0];
    }

    // pick any node from graph, here we choose 0 (Each node has labels in the set {0, 1, ...})
    // the furthest node will be the end point node in the longest path.
    vector<int> visited(edges.size() + 1, 0);
    std::queue<int> q;
    q.push(0);
    int furthest = -1;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        int v = q.front();
        q.pop();
        if (visited[v] != 0)
          continue;
        visited[v] = 1;
        furthest = v;
        for (auto& u : graph[v]) {
          if (visited[u] == 0)
            q.push(u);
        }
      }
    }

    // we do a BFS search again, this time pick the furthest node as the starting point
    int longestPathNodeCnt = 0;
    for (auto& v : visited) {
      v = 0;
    }
    q.push(furthest);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        int v = q.front();
        q.pop();
        if (visited[v] != 0)
          continue;
        visited[v] = 1;
        for (auto& u : graph[v]) {
          if (visited[u] == 0)
            q.push(u);
        }
      }
      longestPathNodeCnt++;
    }

    return longestPathNodeCnt - 1;
  }
};

