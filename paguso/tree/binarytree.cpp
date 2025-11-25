#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T val;
    Node* left;
    Node* right;

    Node(int v, Node* l = nullptr, Node* r = nullptr) : val{v}, left{l}, right{r} {}
};

Node<int>* buildExampleBT() {
    // folhas
    Node<int>* n3 = new Node<int>(3);
    Node<int>* n7 = new Node<int>(7);
    Node<int>* n13 = new Node<int>(13);

    // nós intermediários
    Node<int>* n5 = new Node<int>(5, n3, n7);
    Node<int>* n11 = new Node<int>(11, nullptr, n13);

    // raiz
    Node<int>* n9 = new Node<int>(9, n5, n11);

    return n9;
}

void preorder(Node<int>* root) {
    if (root == nullptr) return;

    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

int countnodes(Node<int>* root) {
    if (root == nullptr) return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}

int main() {

    Node<int>* root = buildExampleBT();
    preorder(root);
    cout << "\nThere are " << countnodes(root) << " nodes in this tree" << endl; // expected: 6

    /*
    9
        5
            3
            7
        11
            -
            13
    
    */

    return 0;
}