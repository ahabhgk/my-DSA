#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <string>
using namespace std;

template <typename T>
struct Node {
  T value;
  int left;
  int right;
};

const vector<Node<char> > v1 = {
  Node<char>{'A', 1, 2},
  Node<char>{'B', 3, 4},
  Node<char>{'C', 5, -1},
  Node<char>{'D', -1, -1},
  Node<char>{'E', 6, -1},
  Node<char>{'G', 7, -1},
  Node<char>{'F', -1, -1},
  Node<char>{'H', -1, -1},
};

const vector<Node<char> > v2 = {
  Node<char>{'G', -1, 4},
  Node<char>{'B', 7, 6},
  Node<char>{'F', -1, -1},
  Node<char>{'A', 5, 1},
  Node<char>{'H', -1, -1},
  Node<char>{'C', 0, -1},
  Node<char>{'D', -1, -1},
  Node<char>{'E', 2, -1},
};

const vector<Node<int> > v3 = {
  Node<int>{30, 1, 2},
  Node<int>{15, -1, -1},
  Node<int>{41, 3, 4},
  Node<int>{33, -1, -1},
  Node<int>{50, -1, -1},
};

template <typename T>
struct TreeNode {
  T value;
  TreeNode* left;
  TreeNode* right;
};

template <class T>
class BinTree {
private:
  TreeNode<T>* root;
  // vector<TreeNode<T> > TreeV;

public:
  BinTree() :root(nullptr) {};
  ~BinTree() { clear(); };
  // BinTree(vector<Node<T> > v) :TreeV(v.size() * 2) {
  //   int rootNum = 0;
  //   for (int i = 0; i < v.size(); i++) {
  //     TreeV[i] = TreeNode<T>{v[i].value, nullptr, nullptr};
  //     rootNum += i;
  //   }
  //   for (int i = 0; i < v.size(); i++) {
  //     int leftNum = v[i].left;
  //     int rightNum = v[i].right;
  //     if (leftNum != -1) {
  //       TreeV[i].left = &TreeV[leftNum];
  //       rootNum -= leftNum;
  //     }
  //     if (rightNum != -1) {
  //       TreeV[i].right = &TreeV[rightNum];
  //       rootNum -= rightNum;
  //     }
  //   }
  //   root = &TreeV[rootNum];
  // }

  void inOrderTraversal(TreeNode<T>* root, function<void (T)> const &f) {
    if (root != nullptr) {
      inOrderTraversal(root->left, f);
      f(root->value);
      inOrderTraversal(root->right, f);
    }
  }

  void inOrderTraversal(function<void (T)> const &f) {
    inOrderTraversal(root, f);
  }

  void preOrderTraversal(TreeNode<T>* root, function<void (T)> const &f) {
    if (root != nullptr) {
      f(root->value);
      preOrderTraversal(root->left, f);
      preOrderTraversal(root->right, f);
    }
  }

  void preOrderTraversal(function<void (T)> const &f) {
    preOrderTraversal(root, f);
  }

  void postOrderTraversal(TreeNode<T>* root, function<void (T)> const &f) {
    if (root != nullptr) {
      postOrderTraversal(root->left, f);
      postOrderTraversal(root->right, f);
      f(root->value);
    }
  }

  void postOrderTraversal(function<void (T)> const &f) {
    postOrderTraversal(root, f);
  }

  void levelOrderTraversal(TreeNode<T>* root, function<void (T)> const &f) {
    queue<TreeNode<T> > q;

    if (root == nullptr) return;
    q.push(*root);

    while (!q.empty()) {
      TreeNode<T>* t = &q.front();
      q.pop();
      f(t->value);
      if (t->left != nullptr) q.push(*t->left);
      if (t->right != nullptr) q.push(*t->right);
    }
  }

  void levelOrderTraversal(function<void (T)> const &f) {
    levelOrderTraversal(root, f);
  }

  int height(TreeNode<T>* root) {
    if (root == nullptr) return 0;
    int lh = height(root->left);
    int lr = height(root->right);
    return lh > lr ? lh + 1 : lr + 1;
  }

  int height() {
    return height(root);
  }

  TreeNode<T>* find(TreeNode<T>* root, T val) {
    if (val == root->value) return root;
    else if (val < root->value) return find(root->left, val);
    else if (val > root->value) return find(root->right, val);
    else return nullptr;
  }

  TreeNode<T>* find(T val) {
    return find(root, val);
  }

  TreeNode<T>* iterFind(TreeNode<T>* root, T val) {
    while (root != nullptr) {
      if (val == root->value) return root;
      else if (val < root->value) root = root->left;
      else if (val > root->value) root = root->right;
    }
    return nullptr;
  }

  TreeNode<T>* iterFind(T val) {
    return iterFind(root, val);
  }

  TreeNode<T>* findMin(TreeNode<T>* root) {
    if (root->left == nullptr) return root;
    else return findMin(root->left);
  }

  TreeNode<T>* findMin() {
    return findMin(root);
  }

  TreeNode<T>* findMax(TreeNode<T>* root) {
    if (root->right == nullptr) return root;
    else return findMax(root->right);
  }

  TreeNode<T>* findMax() {
    return findMax(root);
  }

  TreeNode<T>* iterFindMin(TreeNode<T>* root) {
    while (root->left != nullptr) {
      root = root->left;
    }
    return root;
  }

  TreeNode<T>* iterFindMin() {
    return iterFindMin(root);
  }

  TreeNode<T>* iterFindMax(TreeNode<T>* root) {
    while (root->right != nullptr) {
      root = root->right;
    }
    return root;
  }

  TreeNode<T>* iterFindMax() {
    return iterFindMax(root);
  }

  void insert(TreeNode<T>*& root, T val) {
    if (root == nullptr) {
      TreeNode<T>* node = new TreeNode<T>{val, nullptr, nullptr};
      root = node;
    }
    else if (val < root->value) insert(root->left, val);
    else if (val > root->value) insert(root->right, val);
  }

  BinTree& insert(T val) {
    insert(root, val);
    return *this;
  }

  void del(TreeNode<T>*& root, T val) {
    if (root == nullptr) cout << "The element to be deleted was not found..." << endl;
    else if (val == root->value) {
      if (root->left != nullptr && root->right != nullptr) {
        // 取右子树中最小的元素替代 or 取左子树中最大的元素替代
        TreeNode<T>* rightMin = findMin(root->right);
        root->value = rightMin->value;
        del(root->right, root->value);
      } else {
        TreeNode<T>* tmp = root;
        if (!root->left) root = root->right;
        else if (!root->right) root = root->left;
        delete tmp;
      }
    }
    else if (val < root->value) del(root->left, val);
    else if (val > root->value) del(root->right, val);
  }

  BinTree& del(T val) {
    del(root, val);
    return *this;
  }

  void clear(TreeNode<T>*& root) {
    if (root == nullptr) return;
    clear(root->left);
    clear(root->right);
    delete root;
    root = nullptr;
  }

  BinTree& clear() {
    clear(root);
    return *this;
  }
};

int main() {
  // BinTree tree(v2);

  // cout << "preOrderTraversal: " << endl;
  // tree.preOrderTraversal([](auto c) { cout << c << endl; });

  // cout << "inOrderTraversal: " << endl;
  // tree.inOrderTraversal([](auto c) { cout << c << endl; });

  // cout << "postOrderTraversal: " << endl;
  // tree.postOrderTraversal([](auto c) { cout << c << endl; });

  // cout << "levelOrderTraversal: " << endl;
  // tree.levelOrderTraversal([](auto c) { cout << c << endl; });

  // cout << "height: " << tree.height() << endl;

  // BinTree searchTree(v3);

  // cout << "preOrderTraversal: " << endl;
  // searchTree.preOrderTraversal([](auto c) { cout << c << endl; });

  // cout << "inOrderTraversal: " << endl;
  // searchTree.inOrderTraversal([](auto c) { cout << c << endl; });

  // cout << "postOrderTraversal: " << endl;
  // searchTree.postOrderTraversal([](auto c) { cout << c << endl; });

  // cout << "levelOrderTraversal: " << endl;
  // searchTree.levelOrderTraversal([](auto c) { cout << c << endl; });

  // cout << "height: " << searchTree.height() << endl;

  // TreeNode<int>* val30Node = searchTree.find(30);
  // cout << "find 30 &: " << val30Node << endl;
  // cout << "find 30 value: " << val30Node->value << endl;

  // TreeNode<int>* val15Node = searchTree.iterFind(15);
  // cout << "iterFind 15 &: " << val15Node << endl;
  // cout << "iterFind 15 value: " << val15Node->value << endl;

  // TreeNode<int>* maxNode = searchTree.findMax();
  // cout << "find max &: " << maxNode << endl;
  // cout << "find max value: " << maxNode->value << endl;

  // TreeNode<int>* minNode = searchTree.iterFindMin();
  // cout << "find min &: " << minNode << endl;
  // cout << "find min value: " << minNode->value << endl;

  BinTree<string> st;
  st
    .insert("Jan")
    .insert("Feb")
    .insert("Mar")
    .insert("Apr")
    .insert("May")
    .insert("Jun")
    .insert("July")
    .insert("Aug")
    .insert("Sep")
    .insert("Oct")
    .insert("Nov")
    .insert("Dec")
    .del("Mar");
  //        Jan                      Jan
  //    Fab    Mar(X)            Fab     May
  // Apr     Jun May     =>    Apr     Jun   Sep
  //  Aug  July    Sep          Aug  July  Oct
  //   Dec        Oct            Dec      Nov
  //             Nov
  st.levelOrderTraversal([](auto c) { cout << c << endl; });
  cout << st.height() << endl;
  

  // BinTree st();
}
