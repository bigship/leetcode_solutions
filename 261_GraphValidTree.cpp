// 261. Graph Valid Tree
/*
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes),
 * write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false

Note: you can assume that no duplicate edges will appear in edges.
Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/

// 成为树的条件: 没有成环, 且所有的边连起来只有一个独立的连通实体
class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;
    vector<int> visited(n, 0);
    for (auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    unordered_set<int> qset;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      visited[node] = 1;
      auto ret = qset.insert(node);
      if (ret.second == false) {
        return false;
      }
      for (int i = 0; i < graph[node].size(); i++) {
        int nei = graph[node][i];
        // 没有标记为已访问的节点才加入到队列
        if (visited[nei] == 0) {
          q.push(nei);
        }
      }
    }

    // 所有节点都加入到qset中了, 此时才可以保证只有唯一一个独立的连通实体
    return qset.size() == n;
  }
};
