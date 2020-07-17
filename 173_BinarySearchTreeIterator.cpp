// 173. Binary Search Tree Iterator
/*
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.



Example:

BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false



Note:

    next() and hasNext() should run in average O(1) time and uses O(h) memory,
    where h is the height of the tree.
    You may assume that next() call will always be valid, that is, there will be
    at least a next smallest number in the BST when next() is called.
*/

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *cur = root;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode *node = s.top();
            s.pop();
            q.push_back(node->val);
            cur = node->right;
        }
    }

    int next() {
        if (hasNext())
            return q[idx++];
        else return -1;
    }

    bool hasNext() {
        return idx < q.size();
    }
private:
    vector<int> q;
    stack<TreeNode *> s;
    int idx = 0;
};


