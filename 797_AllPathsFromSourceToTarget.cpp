// 797. All Paths from Source to Target
/*
 * Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1,
 * find all possible paths from node 0 to node n - 1, and return them in any order.
 * The graph is given as follows: graph[i] is a list of all nodes you can visit from node i
 * (i.e., there is a directed edge from node i to node graph[i][j]).
 */

// 先构建出图, 使用邻接表表示. 然后就是标准的DFS + Backtracking
// 每次先把起点加入到当前路径中, 去邻接表找出当前节点的下一个可能位置, 更新起点递归调用dfs
// 如果发现当前起点和终点相同, 表示我们找到了一条路径此时要加入到答案中
// dfs调用返回后需要backtracking, 即将上一次添加到路径中的节点pop出来, 然后才能继续尝试其他路径
class Solution {
public:
  vector<vector<int>> allPathsSourceToTarget(vector<vector<int>>& grid) {
    unordered_map<int, vector<int>> m;
    buildGraph(graph, m);
    vector<vector<int>> ans;
    int start = 0;
    vector<int> cur;
    dfs(m, cur, ans, start, graph.size() - 1);
    return ans;
  }
private:
  void buildGraph(vector<vector<int>>& grid, unordered_map<int, vector<int>>& graph) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        graph[i].push_back(grid[i][j]);
      }
    }
  }

  void dfs(unordered_map<int, vector<int>>& graph, vector<int>& cur, vector<vector<int>>& ans, int start, int dest) {
    if (start == dest) {
      cur.push_back(dest);
      ans.push_back(cur);
      return ;
    }

    cur.push_back(start);
    for (auto& next : graph[start]) {
      dfs(graph, cur, ans, next, dest);
      cur.pop_back();
    }
  }
};
