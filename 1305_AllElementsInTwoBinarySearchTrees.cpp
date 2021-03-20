// 1305. All Elements in Two Binary Search Trees
/*
 * Given two binary search trees root1 and root2.
   Return a list containing all the integers from both trees sorted in ascending order.
*/

class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> tree1Nodes = inOrderTraversal(root1);
    vector<int> tree2Nodes = inOrderTraversal(root2);
    return mergeTwoSortedArray(tree1Nodes, tree2Nodes);
  }
private:
  vector<int> inOrderTraversal(TreeNode *root) {
    vector<int> res;
    std::stack<TreeNode *> sk;
    TreeNode *cur = root;
    while (!sk.empty() || cur) {
      while (cur) {
        sk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = sk.top();
      sk.pop();
      if (node) {
        res.push_back(node->val);
        cur = node->right;
      }
    }
    return res;
  }

  vector<int> mergeTwoSortedArray(vector<int>& arr1, vector<int>& arr2) {
    int sz = arr1.size() + arr2.size();
    vector<int> ans(sz, 0);
    int i = 0, j = 0, writePos = 0;
    while (i < arr1.size() && j < arr2.size()) {
      if (arr1[i] < arr2[j]) {
        ans[writePos] = arr1[i];
        writePos++;
        i++;
      } else {
        ans[writePos] = arr2[j];
        writePos++;
        j++;
      }
    }

    while (i < arr1.size()) {
      ans[writePos++] = arr1[i++];
    }
    while (j < arr2.size()) {
      ans[writePos++] = arr2[j++];
    }
    return ans;
  }
};
