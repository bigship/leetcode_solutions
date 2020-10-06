// 1506. Find Root of N-Ary Tree
/*
 * Given all the nodes of an N-ary tree as an array  Node[] tree where each node has a unique value.
   Find and return the root of the N-ary tree.

Follow up:
Could you solve this problem in constant space complexity with a linear time algorithm?

Nary-Tree input serialization is represented in their level order traversal, each group of children is
separated by the null value (See examples).

For example, the above tree is serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

Custom testing:
You should provide the serialization of the input tree.
The Driver code then extracts the nodes from the tree and shuffles them. You shouldn't care how the extracted nodes are shuffled.
The driver code will provide you with an array of the extracted nodes in random order and you need to find the root of the tree out of these nodes.


Example 1:

Input: tree = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
Explanation: The input tree is shown above. The driver code first extracts the nodes so we now have an array of all tree nodes
[Node(1),Node(3),Node(2),Node(4),Node(5),Node(6)], then the array is randomly shuffled,
thus the actual input is [Node(5),Node(4),Node(3),Node(6),Node(2),Node(1)].
The root of the tree is Node(1) and the output is the serialization of the node you return.

Example 2:

Input: tree = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]

Constraints:

    The total number of nodes is between [1, 5 * 10^4].
    Each node has a unique value.
*/
class Solution {
public:
  // Solution: 遍历数组, 如果节点包含子节点, 则把子节点的父节点保存到hashmap
  // 再次遍历数组, 根节点就是没有父节点的那个
  // Time: O(n), Space: O(n)
  Node *findRoot(vector<Node *> tree) {
    unordered_map<Node *, Node *> map;
    for (int i = 0; i < tree.size(); i++) {
      Node *node = tree[i];
      if (node->children.size() != 0) {
        for (auto& child : node->children) {
          map[child] = node;
        }
      }
    }
    for (auto& node : tree) {
      if (map.find(node) == map.end())
        return node;
    }
    return nullptr;
  }

  // Constant Space solution
  // Time: O(n), Space: O(1)
  // 根节点的值为全部所有节点的值减去所有子节点的值
  // 因为根节点不是任何节点的子节点(根节点没有父节点)
  Node *findRoot(vector<Node *> tree) {
    int nodeSum = 0, childrenSum = 0;
    for (int i = 0; i < tree.size(); i++) {
      nodeSum += tree[i]->val;
      if (tree[i]->children.size() != 0) {
        for (int j = 0; j < tree[i]->children.size(); j++) {
          childrenSum += tree[i]->children[j]->val;
        }
      }
    }

    for (auto& node : tree) {
      if (node->val == nodeSum - childrenSum) {
        return node;
      }
    }
    return nullptr;
  }
};

