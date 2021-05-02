// 1628. Design an Expression Tree With Evaluate Function

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Node {
public:
  virtual ~Node () {};
  virtual int evaluate() const = 0;
protected:
  // define your fields here
};


// Stack, OOP


class OperatorNode : public Node {
public:
  OperatorNode(string op, Node *l = nullptr, Node *r = nullptr) : oper(op), left(l), right(r) { }

  int evaluate() const {
    int lhs = left->evaluate();
    int rhs = right->evaluate();
    if (oper == "+") return lhs + rhs;
    else if (oper == "-") return lhs - rhs;
    else if (oper == "*") return lhs * rhs;
    else return lhs / rhs;
  }

  string oper;
  Node *left;
  Node *right;
};

class ValueNode : public Node {
public:
  ValueNode(int value) : val(value) { }

  int evaluate() const {
    return this->val;
  }

  int val;
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
  Node* buildTree(vector<string>& postfix) {
    unordered_set<string> opers{"+", "-", "*",  "/"};
    stack<Node *> sk;
    for (auto& ch : postfix) {
      if (opers.count(ch) == 0) {
        Node *vnode = new ValueNode(stoi(ch));
        sk.push(vnode);
      } else {
        Node *right = sk.top();
        sk.pop();
        Node *left = sk.top();
        sk.pop();
        Node *onode = new OperatorNode(ch, left, right);
        sk.push(onode);
      }
    }
    return sk.top();
  }
};


int main() {
  vector<string> postfix = {"4", "5", "7", "2", "+", "-", "*"};
  TreeBuilder tb = TreeBuilder();
  Node *root = tb.buildTree(postfix);
  cout << root->evaluate() << endl;

  return 0;
}
