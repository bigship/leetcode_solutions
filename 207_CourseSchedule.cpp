// 207. Course Schedule
/*
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Constraints:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
    Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    1 <= numCourses <= 10^5
*/

class Solution {
public:
    // Topological Sort. Time - O(n)
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    graph_ = vector<vector<int>>(numCourses);
    for (const auto& p : prerequisites)
      graph_[p.first].push_back(p.second);

    // states: 0 = unkonwn, 1 = visiting, 2 = visited
    vector<int> v(numCourses, 0);
    for (int i = 0; i < numCourses; ++i)
      if (dfs(i, v)) return false;
    return true;
  }
private:
  vector<vector<int>> graph_;
  bool dfs(int cur, vector<int>& v) {
    if (v[cur] == 1) return true;
    if (v[cur] == 2) return false;

    v[cur] = 1;
    for (const int t : graph_[cur])
      if (dfs(t, v)) return true;

    v[cur] = 2;
    return false;
  }
};

// Topological sort iterative solution
// Can actually get the sequence that meets the requirement
// 1. 先建图并统计所有点的入度
// 2. 把入度为0的节点加入队列中. 如果没有任何节点的入度为0, 返回false
// 3. 依次从队列中取出节点加入到seq中. 每取出一个节点, 在图中将该节点的后继节点入度都减去1
//    如果在更新入度的过程中发现某个节点的入度为0了, 将其加入队列中
// 4. 如果可以上完所有课程, 此时seq的长度应该和课程的数量相等
class Solution2 {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    for (const auto& prerequisite : prerequisites) {
      graph[prerequisite[1]].push_back(prerequisite[0]);
      ++indegree[prerequisite[0]];
    }

    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i) {
      if (indegree[i] == 0)
        q.push(i);
    }
    if (q.empty())
      return false;

    vector<int> seq;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      seq.push_back(u);
      for (auto& v : graph[u]) {
        --indegree[v];
        if (indegree[v] == 0)
          q.push(v);
      }
    }
    return seq.size() == numCourses;
  }
};

