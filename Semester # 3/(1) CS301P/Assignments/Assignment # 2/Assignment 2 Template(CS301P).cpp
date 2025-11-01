#include <iostream>
#include <string>
using namespace std;

// -------------------- Book Node Class --------------------
class BookNode {
public:
    int price;
    string title;
    BookNode* left;
    BookNode* right;

    // Constructor
    BookNode(int p, string t) {
        price = p;
        title = t;
        left = right = NULL;
    }
};

// -------------------- Binary Search Tree Class --------------------
class BookBST {
private:
    BookNode* root;

    // Helper: Find node with minimum price
    BookNode* minValueNode(BookNode* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    // TODO 1: Insert Book into BST
    BookNode* addBook(BookNode* node, int price, string title) {
        
        // Write your code here
        
    }

    // TODO 2: Delete Book by price from BST
    BookNode* removeBook(BookNode* node, int price) {
        
        // Write your code here
       
    }

    // TODO 3: In-Order Traversal to print books
    void printInOrder(BookNode* node) {
        
        // Write your code here
    }

    // TODO 4: Search Book by price
    BookNode* findBook(BookNode* node, int price) {
        
        // Write your code here
        
    }

public:
    // Constructor
    BookBST() {
        root = NULL;
    }

    // Wrapper functions to be used in main
    void insert(int price, string title) { root = addBook(root, price, title); }
    void remove(int price) { root = removeBook(root, price); }
    void display() { printInOrder(root); }
    void search(int price) {
        BookNode* found = findBook(root, price);
        if (found)
            cout << "Book Found: " << found->title << " (Rs. " << found->price << ")\n";
        else
            cout << "Book not found.\n";
    }
};

// ----------------------- MAIN FUNCTION -----------------------
int main() {
    BookBST tree;

    // Student own ID (hardcoded)
    string studentId = "BC123456789";     // Replace with your own VU ID
    int lastDigit = studentId[studentId.length() - 1] - '0';
    int customPrice = 500 + lastDigit;
    string customBookName = "CustomBook";

    // Display student info
    cout << "---------------- Book Management System (" << studentId << ") ----------------\n";
    cout << "Extracted Last Digit: " << lastDigit << "\n";
    cout << "Custom Book Price: Rs. " << customPrice << "\n\n";

    // Insert sample books
    tree.insert(520, "C++ Primer");
    tree.insert(580, "Clean Code");
    tree.insert(610, "Algorithms Unlocked");
    tree.insert(695, "Design Patterns");
    tree.insert(750, "Intro to AI");

    // Display before insertion
    cout << "\nIn-order Traversal BEFORE inserting CustomBook:\n";
    tree.display();

    // Insert custom book
    tree.insert(customPrice, customBookName);

    // Display after insertion
    cout << "\nIn-order Traversal AFTER inserting CustomBook:\n";
    tree.display();

    // Search for custom book
    cout << "\nSearching for CustomBook (Rs. " << customPrice << ")...\n";
    tree.search(customPrice);

    // Delete custom book
    tree.remove(customPrice);

    // Display after deletion
    cout << "\nIn-order Traversal AFTER deleting CustomBook:\n";
    tree.display();

    return 0;
}

