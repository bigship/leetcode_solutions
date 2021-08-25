// 1743. Restore the Array From Adjacent Pairs
/*
 * There is an integer array nums that consists of n unique elements, but you have forgotten it.
 * However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that
the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs,
either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

*/

class Solution {
public:
  // 转化成图的问题, dfs遍历
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> ans;
    unordered_map<int, unordered_set<int>> graph;
    for (auto& pairs : adjacentPairs) {
      graph[pairs[0]].insert(pairs[1]);
      graph[pairs[1]].insert(pairs[0]);
    }

    // 选择起始点. 起始点的要求就是它的邻居只能有一个
    int startingPoint = INT_MAX;
    for (auto it = graph.begin(); it != graph.end(); it++) {
      if (it->second.size() == 1) {
        startingPoint = it->first;
        break;
      }
    }

    unordered_set<int> visited;
    dfs(graph, startingPoint, ans, visited);
    return ans;
  }
private:
  void dfs(unordered_map<int, unordered_set<int>>& graph, int current,
             vector<int>& ans, unordered_set<int>& visited) {
    if (ans.size() == graph.size()) {
      return ;
    }

    ans.push_back(current);
    visited.insert(current);
    for (auto nei : graph[current]) {
      if (visited.count(nei) == 0) {
        dfs(graph, nei, ans, visited);
      }
    }
  }
};

