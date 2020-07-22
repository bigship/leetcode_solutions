// 310. Minimum Height Trees
/*
 * For an undirected graph with tree characteristics, we can choose any node as the root.
 * The result graph is then a rooted tree. Among all possible rooted trees, those with minimum
 * height are called minimum height trees (MHTs). Given such a graph, write a function
 * to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the
number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected,
[0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1 :

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3

Output: [1]

Example 2 :

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

Output: [3, 4]

Note:

    According to the definition of tree on Wikipedia: “a tree is an undirected graph
    in which any two vertices are connected by exactly one path. In other words,
    any connected graph without simple cycles is a tree.”
    The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n == 1) ans.push_back(0);
        return ans;

        vector<int> degree(n, 0);   // save degrees for graph node (关联该点的边数)
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[i] = vector<int>();
        }

        // 二维数组转换为图的表达形式
        for (auto& edge : edges) {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // keep the node which the degree is 1
        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        // erase the node which has degree of 1,
        // and update the degree for the rest nodes
        // if node's degree becomes 1, add to queue
        while (!q.empty()) {
            vector<int> list;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                list.push_back(cur);
                q.pop();
                for (int v : map[cur]) {
                    degree[v]--;
                    if (degree[v] == 1)
                        q.push(v);
                }
            }
            ans = list;
        }
        return ans;
    }
};

