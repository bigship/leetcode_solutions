// 1136. Parallel Courses
/*
 * You are given an integer n which indicates that we have n courses, labeled from 1 to n.
 * You are also given an array relations where relations[i] = [a, b],
 * representing a prerequisite relationship between course a and course b: course a has to be studied before course b.

In one semester, you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.
Return the minimum number of semesters needed to study all courses. If there is no way to study all the courses, return -1.
*/

class Solution {
public:
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<int> seq;
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> indegrees;

    // Init all nodes indegrees to 0
    for (int i = 1; i <= n; i++) {
      indegrees[i] = 0;
    }

    // Build graph && update indegrees
    for (auto& vec : relations) {
      graph[vec[0]].push_back(vec[1]);
      indegrees[vec[1]]++;
    }

    // enqueue all the nodes with indegrees == 0
    std::queue<int> que;
    for (auto it = indegrees.begin(); it != indegrees.end(); it++) {
      if (it->second == 0) {
        que.push(it->first);
      }
    }

    // pop all the node with 0 indegrees, and update remaining node's indegree
    // If the indegree for any node becomes 0, enqueue it.
    int semesters = 0;
    while (!que.empty()) {
      int n = que.size();
      for (int k = 0; k < n; k++) {
        int node = que.front();
        que.pop();
        seq.push_back(node);
        for (auto& vec : graph[node]) {
          indegrees[vec]--;
          if (indegrees[vec] == 0) {
            que.push(vec);
          }
        }
      }
      semesters++;
    }

    return (seq.size() == n) ? semesters : -1;
  }
};
