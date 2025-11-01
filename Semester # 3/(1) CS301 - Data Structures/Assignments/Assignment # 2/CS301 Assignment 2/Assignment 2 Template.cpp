#include <iostream>
#include <cstddef>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

class AVL {
private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }
    int getBalance(Node* node) {
        return height(node->left) - height(node->right);
    }
    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right)); 
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        updateHeight(y);
        updateHeight(x);

        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        updateHeight(x);
        updateHeight(y);

        return y;
    }
    Node* minValueNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

public:
    AVL() : root(NULL) {}

	/************** To be implemented by Student ***************/
	/*
	1. Implement insertNode() method
	2. Implement deleteNode() method
	3. Implement inOrder() method
	*/
	/**********************************************************/
	
	// TODO 1: Implement insertNode Method
    Node* insertNode(Node* node, int key) {
        // Write your code here
    }
    
    // TODO 2: Implement deleteNode Method
    Node* deleteNode(Node* root, int key) {
        // Write your code here
    }
    
    // TODO 3: Implement inOrder Method
    void inOrder(Node* root) {
        // Write your code here
    }
 
    // Helper to call from main()
    void insert(int key) { root = insertNode(root, key); }
    void deleteKey(int key) { root = deleteNode(root, key); }
    void inOrder() { inOrder(root); cout << endl; }
};

int main(){	
	// A) Hard-code the student ID
    string studentID = "BC123456789"; // Replace BC123456789 with your VUID

    // Extract digits and combine                     
    int idLastDigit  = studentID[studentID.size()-1] - '0';

    // Display header & extract id last digit
    cout << "---------------- XYZ Company System ("
         << studentID << ")---------------" << endl;
    cout << "Extracted Last Digits is:\n"
         << idLastDigit << "\n\n";

    AVL tree;
    int arr[] = {10, 20, 30, 40, 50};
    // Creating AVL tree with initial nodes
    for(int i = 0; i < 5; i++) {
        tree.insert(arr[i]);
    }
    
    cout << "Inorder Traversal before Insertion:";
    tree.inOrder();
	cout<<endl;
	
	// Inserting digit to AVL
    cout << "Inserting " << idLastDigit << " into AVL." << endl;
    tree.insert(idLastDigit);
    cout << "Inorder Traversal after Insertion: ";
    tree.inOrder();
	cout<<endl;
    
    // Removing digit form AVL
	cout << "Deleting " << idLastDigit << " from AVL." << endl;
    tree.deleteKey(idLastDigit);
    cout << "Inorder AVL after deletion:        ";
	tree.inOrder();

    return 0;
}
