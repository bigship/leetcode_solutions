// 1361. Validate Binary Tree Nodes
/*
 * You have n binary tree nodes numbered from 0 to n - 1 where node i has two children
 * leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.


Example 1:

Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true

Example 2:

Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false

Example 3:

Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false

Example 4:

Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false


Constraints:

    1 <= n <= 10^4
    leftChild.length == rightChild.length == n
    -1 <= leftChild[i], rightChild[i] <= n - 1
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if (n == 1) return true;
        int left, right;
        unordered_map<int, int> parent;  // key: child node , value: root of the child
        for (int i = 0; i < n; ++i) {
            left = leftChild[i];
            right = rightChild[i];
            if (left != -1) {
                if (parent.count(left) != 0) return false;  // 同一个节点有两个parent, 直接返回false
                else parent[left] = i;
            }
            if (right != -1) {
                if (parent.count(right) != 0) return false; // 同一个节点有两个parent, 直接返回false
                else parent[right] = i;
            }
        }
        int root = 0;
        for (int i = 0; i < n; ++i) {
            // if n > 1, then a valid root should not only have no parent, but also
            // have at least one children
            // 根节点只能有一个(它本身没有根节点), 其他节点只能有一个父节点
            // 根节点至少有一个子节点(n > 1)
            if (!parent.count(i) && (leftChild[i] != -1 || rightChild[i] != -1)) root++;
        }
        if (root == 0 || root > 1) return false;
        return true;
    }
};


