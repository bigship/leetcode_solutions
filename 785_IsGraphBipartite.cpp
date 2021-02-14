// 785. Is Graph Bipartite ?
/*
 * There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1.
 * You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to.
 * More formally, for each v in graph[u], there is an undirected edge between node u and node v.
 * The graph has the following properties:

    There are no self-edges (graph[u] does not contain u).
    There are no parallel edges (graph[u] does not contain duplicate values).
    If v is in graph[u], then u is in graph[v] (the graph is undirected).
    The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B
such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

// 二分图, 染色法. 从初始节点开始染色, 把它的邻居都染成另一种颜色
// 访问到邻居时如果颜色出现冲突则说明不是二分图

class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    if (n == 0) return true;

    vector<int> color(n, 0);   // 初始时都没有染色
    queue<int> q;

    // 遍历所有节点, 将没有染色过的加入队列
    for (int i = 0; i < n; i++) {
      if (!color[i]) {
        q.push(i);
        color[i] = 1;  // 没染色过, 先染成1
      }
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        // 取出当前节点的邻居, 如果没染过色就染上和当前节点不同的颜色(2) 并加入队列
        for (const int& j : graph[node]) {
          if (color[j] == 0) {
            q.push(j);
            color[j] = color[node] == 1 ? 2 : 1;
          } else if (color[node] == color[j])  // 邻居已经染色过了, 且和当前取出的节点颜色一致 此时不是二分图
            return false;
        }
      }
    }
    return true;  // 遍历完所有节点, 此时是二分图
  }
};
