// 323. Number of Connected Components in an Undirected Graph
/*
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
 * write a function to find the number of connected components in an undirected graph.

Example 1:
Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

Output: 2

Example 2:
Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1

Note:
You can assume that no duplicate edges will appear in edges.
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    int ans = 0;
    unordered_set<int> visited;
    for (int i = 0; i < n; i++) {
      if (visited.count(i) == 0) {
        ans++;
        BFS(graph, visited, i);
      }
    }

    return ans;
  }
private:
  void BFS(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int nodeval) {
    queue<int> q;
    q.push(nodeval);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      if (visited.count(node) == 0) {
        visited.insert(node);
      }
      for (int i = 0; i < graph[node].size(); i++) {
        if (visited.count(graph[node][i]) == 0) {
          q.push(graph[node][i]);
        }
      }
    }
    return ;
  }
};

