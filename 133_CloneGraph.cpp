// 133. Clone Graph
/*
 * Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.
Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

*/

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node) return nullptr;
    unordered_map<Node *, Node *> nodeMap;
    unordered_set<Node *> visited;

    cloneNodes(node, nodeMap, visited);  // copy all the nodes
    visited.clear();
    cloneEdges(node, nodeMap, visited);  // copy all the edges
    return nodeMap[node];
  }
private:
  void cloneEdges(Node *node, unordered_map<Node *, Node*>& nodeMap, unordered_set<Node *>& visited) {
    if (visited.count(node) != 0)
      return;
    visited.insert(node);
    for (int i = 0; i < node->neighbors.size(); i++) {
      nodeMap[node]->neighbors.push_back(nodeMap[node->neighbors[i]]);
      cloneEdges(node->neighbors[i], nodeMap, visited);
    }
  }

  void cloneNodes(Node *node, unordered_map<Node *, Node *>& nodeMap, unordered_set<Node *>& visited) {
    if (!node) return;
    if (visited.count(node) != 0)
      return;
    visited.insert(node);
    Node *cloneNode = new Node(node->val);
    nodeMap[node] = cloneNode;
    for (int i = 0; i < node->neighbors[i].size(); i++) {
      if (visited.count(node->neighbors[i]) == 0)
        cloneNodes(node->neighbors[i], nodeMap, visited);
    }
    return ;
  }
};

