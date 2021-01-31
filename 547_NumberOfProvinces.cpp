// 547. Number of Provinces
/*
 * There are n cities. Some of them are connected, while some are not.
 * If city a is connected directly with city b, and city b is connected directly with city c,
 * then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
*/

// DFS
class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    vector<int> visited(isConnected.size(), 0);
    int ans = 0;
    for (int i = 0; i < isConnected.size(); i++) {
      if (visited[i] == 0) {
        dfs(isConnected, visited, i);
        ans++;
      }
    }
    return ans;
  }
private:
  void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int i) {
    for (int j = 0; j < isConnected.size(); j++) {
      if (isConnected[i][j] == 1 && !visited[j]) {
        visited[j] = 1;
        dfs(isConnected, visited, j);
      }
    }
  }
};

// BFS
class Solution2 {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    vector<int> visited(isConnected.size(), 0);
    int ans = 0;
    std::queue<int> q;
    for (int i = 0; i < isConnected.size(); i++) {
      if (visited[i] == 0) {
        q.push(i);
        while (!q.empty()) {
          int s = q.front();
          q.pop();
          visited[s] = 1;
          for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[s][j] == 1 && !visited[j]) {
              q.push(j);
            }
          }
        }
        ans++;
      }
    }
    return ans;
  }
};
