// 1059. All paths from source lead to destination
/*
 * Given the edges of a directed graph where edges[i] = [ai, bi] indicates there is an edge between nodes ai and bi,
 * and two nodes source and destination of this graph, determine whether or not all paths starting from source eventually, end at destination,
 * that is:

    At least one path exists from the source node to the destination node
    If a path exists from the source node to a node with no outgoing edges, then that node is equal to destination.
    The number of possible paths from source to destination is a finite number.

Return true if and only if all roads from source lead to destination.
*/

class Solution {
public:
  bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
    unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
    }
    vector<int> color(n, 0);   // 0 - white, 1 - gray, 2 - black
    return dfs(graph, source, destination, color);
  }
private:
  bool dfs(unordered_map<int, vector<int>>& graph, int start, int end, vector<int>& color) {
    // 没有邻居节点了, 看是否到达终点. 如果不是终点, 表示有一条路是无法到达终点的
    if (graph[start].size() == 0) {
      return start == end;
    }

    // 如果已经染色过了, 看是否是黑色. 黑色表示存在环
    if (color[start] != 0) {
      return color[start] == 2;
    }

    // 没有染色过, 将起点标记为灰色. 表示正在处理中
    color[start] = 1; // mark as grey, we are processing this node

    // DFS递归执行当前节点的所有邻居
    for (auto& nei : graph[start]) {
      if (!dfs(graph, nei, end, color))
        return false;
    }

    // Recursive processing done for the start, mark it black
    // 递归执行完毕, 此时该路径上的所有点已经处理好了, 将起点标记为黑色表示已经处理完毕
    color[start] = 2;
    return true;
  }
};
