/**
 * 2096 Step-By-Step Directions From a Binary Tree Node to Another
 *
 * You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n.
 * You are also given an integer startValue representing the value of the start node s, and a different integer
 * destValue representing the value of the destination node t.

 * Find the shortest path starting from node s and ending at node t.
 * Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'.
 * Each letter indicates a specific direction:

 * 'L' means to go from a node to its left child node.
 * 'R' means to go from a node to its right child node.
 * 'U' means to go from a node to its parent node.
 * Return the step-by-step directions of the shortest path from node s to node t.
 *
 */

class Solution {
  public:
    string getDirections(TreeNode *root, int startValue, int destValue) {
      TreeNode *lca = findLCA(root, startValue, destValue);
      string leftRoute, rightRoute;
      bool foundLeft = false, foundRight = false;
      encodeRoute(lca, startValue, leftRoute, foundLeft);
      encodeRoute(lca, destValue, rightRoute, foundRight);

      for (auto& ch : leftRoute) {
        if (ch == 'L' || ch == 'R') {
          ch = 'U';
        }
      }

      return leftRoute + rightRoute;
    }

  private:
    TreeNode *findLCA(TreeNode *root, int startValue, int destValue) {
      if (!root) return nullptr;
      if (root->val == startValue || root->val == destValue) {
        return root;
      }

      TreeNode *left = findLCA(root->left, startValue, destValue);
      TreeNode *right = findLCA(root->right, startValue, destValue);
      if (left && right) {
        return root;
      }

      return (left == nullptr) ? right : left;
    }

    void encodeRoute(TreeNode *start, int destValue, string& routeStr, bool& found) {
      if (found == true || start == nullptr) {
        return;
      }

      if (start->val == destValue) {
        found = true;
        return;
      }

      if (start->left && found == false) {
        routeStr.push_back('L');
        encodeRoute(start->left, destValue, routeStr, found);
        if (found == false) {
          routeStr.pop_back();
        }
      }

      if (start->right && found == false) {
        routeStr.push_back('R');
        encodeRoute(start->right, destValue, routeStr, found);
        if (found == false) {
          routeStr.pop_back();
        }
      }

      return ;
    }
};


