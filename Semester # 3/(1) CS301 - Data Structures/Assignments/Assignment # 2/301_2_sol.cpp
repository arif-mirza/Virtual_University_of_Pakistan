#include <iostream>
#include <cstddef>
using namespace std;

class Node
{
public:
  int key;
  Node *left;
  Node *right;
  int height;

  Node(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

class AVL
{
private:
  Node *root;

  int height(Node *node)
  {
    return node ? node->height : 0;
  }

  int getBalance(Node *node)
  {
    return height(node->left) - height(node->right);
  }

  void updateHeight(Node *node)
  {
    node->height = 1 + max(height(node->left), height(node->right));
  }

  Node *rightRotate(Node *y)
  {
    Node *x = y->left;
    Node *T = x->right;

    x->right = y;
    y->left = T;

    updateHeight(y);
    updateHeight(x);

    return x;
  }

  Node *leftRotate(Node *x)
  {
    Node *y = x->right;
    Node *T = y->left;

    y->left = x;
    x->right = T;

    updateHeight(x);
    updateHeight(y);

    return y;
  }

  Node *minValueNode(Node *node)
  {
    while (node->left)
      node = node->left;
    return node;
  }

public:
  AVL() : root(NULL) {}

  Node *insertNode(Node *node, int key)
  {
    if (!node)
      return new Node(key);

    if (key < node->key)
      node->left = insertNode(node->left, key);
    else if (key > node->key)
      node->right = insertNode(node->right, key);
    else
      return node; // Duplicate not allowed

    updateHeight(node);
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key)
      return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->key)
      return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->key)
    {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key)
    {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
  }

  Node *deleteNode(Node *root, int key)
  {
    if (!root)
      return root;

    if (key < root->key)
      root->left = deleteNode(root->left, key);
    else if (key > root->key)
      root->right = deleteNode(root->right, key);
    else
    {
      if (!root->left || !root->right)
      {
        Node *temp = root->left ? root->left : root->right;
        if (!temp)
        {
          temp = root;
          root = NULL;
        }
        else
          *root = *temp;
        delete temp;
      }
      else
      {
        Node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
      }
    }

    if (!root)
      return root;

    updateHeight(root);
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
      return rightRotate(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0)
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
      return leftRotate(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0)
    {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }

    return root;
  }

  void inOrder(Node *root)
  {
    if (!root)
      return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
  }

  void insert(int key) { root = insertNode(root, key); }
  void deleteKey(int key) { root = deleteNode(root, key); }
  void inOrder()
  {
    inOrder(root);
    cout << endl;
  }
};

int main()
{
  // Hard-coded Student ID
  string studentID = "BC240205517";

  int idLastDigit = studentID[studentID.size() - 1] - '0';

  cout << "---------------- XYZ Company System (" << studentID << ")---------------" << endl;
  cout << "Extracted Last Digits is:\n"
       << idLastDigit << "\n"
       << endl;

  AVL tree;
  int arr[] = {10, 20, 30, 40, 50};

  for (int i = 0; i < 5; i++)
  {
    tree.insert(arr[i]);
  }

  cout << "Inorder Traversal before Insertion: ";
  tree.inOrder();
  cout << endl;

  cout << "Inserting " << idLastDigit << " into AVL." << endl;
  tree.insert(idLastDigit);

  cout << "Inorder Traversal after Insertion: ";
  tree.inOrder();
  cout << endl;

  cout << "Deleting " << idLastDigit << " from AVL." << endl;
  tree.deleteKey(idLastDigit);

  cout << "Inorder AVL after deletion:        ";
  tree.inOrder();

  return 0;
}
