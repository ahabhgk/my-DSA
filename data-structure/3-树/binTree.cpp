#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

struct Node {
  char value;
  int left;
  int right;
};

const vector<Node> v1 = {
  Node{'A', 1, 2},
  Node{'B', 3, 4},
  Node{'C', 5, -1},
  Node{'D', -1, -1},
  Node{'E', 6, -1},
  Node{'G', 7, -1},
  Node{'F', -1, -1},
  Node{'H', -1, -1},
};

const vector<Node> v2 = {
  Node{'G', -1, 4},
  Node{'B', 7, 6},
  Node{'F', -1, -1},
  Node{'A', 5, 1},
  Node{'H', -1, -1},
  Node{'C', 0, -1},
  Node{'D', -1, -1},
  Node{'E', 2, -1},
};

struct TreeNode {
  char value;
  TreeNode* left;
  TreeNode* right;
};

class BinTree {
public:
  BinTree(vector<Node> v) :TreeV(v.size()) {
    int rootNum = 0;
    for (int i = 0; i < v.size(); i++) {
      TreeV[i] = TreeNode{v[i].value, nullptr, nullptr};
      rootNum += i;
    }
    for (int i = 0; i < v.size(); i++) {
      int leftNum = v[i].left;
      int rightNum = v[i].right;
      if (leftNum != -1) {
        TreeV[i].left = &TreeV[leftNum];
        rootNum -= leftNum;
      }
      if (rightNum != -1) {
        TreeV[i].right = &TreeV[rightNum];
        rootNum -= rightNum;
      }
    }
    root = &TreeV[rootNum];
  }

  void inOrderTraversal(TreeNode* root, function<void (char)> const &f) {
    if (root != nullptr) {
      inOrderTraversal(root->left, f);
      f(root->value);
      inOrderTraversal(root->right, f);
    }
  }

  void inOrderTraversal(function<void (char)> const &f) {
    inOrderTraversal(root, f);
  }

  void preOrderTraversal(TreeNode* root, function<void (char)> const &f) {
    if (root != nullptr) {
      f(root->value);
      preOrderTraversal(root->left, f);
      preOrderTraversal(root->right, f);
    }
  }

  void preOrderTraversal(function<void (char)> const &f) {
    preOrderTraversal(root, f);
  }

  void postOrderTraversal(TreeNode* root, function<void (char)> const &f) {
    if (root != nullptr) {
      postOrderTraversal(root->left, f);
      postOrderTraversal(root->right, f);
      f(root->value);
    }
  }

  void postOrderTraversal(function<void (char)> const &f) {
    postOrderTraversal(root, f);
  }

  void levelOrderTraversal(TreeNode* root, function<void (char)> const &f) {
    queue<TreeNode> q;

    if (root == nullptr) return;
    q.push(*root);

    while (!q.empty()) {
      TreeNode* t = &q.front();
      q.pop();
      f(t->value);
      if (t->left != nullptr) q.push(*t->left);
      if (t->right != nullptr) q.push(*t->right);
    }
  }

  void levelOrderTraversal(function<void (char)> const &f) {
    levelOrderTraversal(root, f);
  }

  int height(TreeNode* root) {
    if (root == nullptr) return 0;
    int lh = height(root->left);
    int lr = height(root->right);
    return lh > lr ? lh + 1 : lr + 1;
  }

  int height() {
    return height(root);
  }

private:
  TreeNode* root;
  vector<TreeNode> TreeV;
};

int main() {
  BinTree tree(v1);

  cout << "preOrderTraversal: " << endl;
  tree.preOrderTraversal([](char c) { cout << c << endl; });

  cout << "inOrderTraversal: " << endl;
  tree.inOrderTraversal([](char c) { cout << c << endl; });

  cout << "postOrderTraversal: " << endl;
  tree.postOrderTraversal([](char c) { cout << c << endl; });

  cout << "levelOrderTraversal: " << endl;
  tree.levelOrderTraversal([](char c) { cout << c << endl; });

  cout << "height: " << tree.height() << endl;
}
