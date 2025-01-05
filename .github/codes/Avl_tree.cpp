#include <iostream>
#include <string>
using namespace std;

struct Node {
    int current_level;
    int threshold;
    string name1;
    Node* left;
    Node* right;
    int height;

    Node(int c, int t, string name) : current_level(c), threshold(t), name1(name), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node);
    int balancef(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* addNode(Node* node, int current_level, int threshold, string name1);
    void checkFloodRisk(Node* node);

public:
    AVLTree();
    void addNode(int current_level, int threshold, string name1);
    void checkFloodRisk();
};

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}
int AVLTree::balancef(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}
Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVLTree::addNode(Node* node, int current_level, int threshold, string name1) {
    if (!node) return new Node(current_level, threshold, name1);

    if (current_level < node->current_level)
        node->left = addNode(node->left, current_level, threshold, name1);
    else if (current_level > node->current_level)
        node->right = addNode(node->right, current_level, threshold, name1);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = balancef(node);

    if (balance > 1 && current_level < node->left->current_level)
        return rotateRight(node);

    if (balance < -1 && current_level > node->right->current_level)
        return rotateLeft(node);

    if (balance > 1 && current_level > node->left->current_level) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && current_level < node->right->current_level) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::checkFloodRisk(Node* node) {
    if (!node) return;

    if (node->current_level >= node->threshold)
        cout << "Reservoir " << node->name1 << " is at risk of flooding (Current Level: " << node->current_level << ", Threshold: " << node->threshold << ")." << endl;

    checkFloodRisk(node->left);
    checkFloodRisk(node->right);
}


void AVLTree::addNode(int current_level, int threshold, string name1) {
    root = addNode(root, current_level, threshold, name1);
}

void AVLTree::checkFloodRisk() {
    checkFloodRisk(root);
}

int main() {
    AVLTree tree;

    tree.addNode(50, 60, "R1");
    tree.addNode(70, 65, "R2");
    tree.addNode(30, 40, "R3");
    tree.addNode(80, 75, "R4");
    tree.addNode(45, 50, "R5");
    tree.addNode(40, 80, "R6");
    tree.addNode(75, 50, "R7");

    cout << "Flood Risk Analysis:" << endl;
    tree.checkFloodRisk();

    return 0;
}
