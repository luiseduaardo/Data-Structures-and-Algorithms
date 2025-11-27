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
    Node<int>* n15 = new Node<int>(15);

    Node<int>* n13 = new Node<int>(13, nullptr, n15);

    // nós intermediários
    Node<int>* n5 = new Node<int>(5, n3, n7);
    Node<int>* n11 = new Node<int>(11, nullptr, n13);

    // raiz
    Node<int>* n9 = new Node<int>(9, n5, n11);

    return n9;
}

void visit(Node<int>* root, int level = 0) {
    for (int i = 0; i < level; i++) cout << "    ";
    cout << root->val << endl;
}

void preOrder(Node<int>* root, int level = 0) {
    if (root == nullptr) return;

    visit(root, level);
    preOrder(root->left, level+1);
    preOrder(root->right, level+1);
}

void postOrder(Node<int>* root, int level = 0) {
    if (root == nullptr) return;
    
    postOrder(root->left, level+1);
    postOrder(root->right, level+1);
    visit(root, level);
}

void inOrder(Node<int>* root, int level = 0) {
    if (root == nullptr) return;
    
    inOrder(root->left, level+1);
    visit(root, level);
    inOrder(root->right, level+1);    
}

int height(Node<int>* root) {
    if (root == nullptr) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// diâmetro da árvore (maior distância em aresta entre nós de uma árvore)
    // TA ERRADO MELHORAR ISSO.
int diameter(Node<int>* root, int diameter = 0) {
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight + rightHeight > leftHeight * 2 || leftHeight + rightHeight > rightHeight * 2) {
        return leftHeight + rightHeight;
    } else {
        return(2*max(leftHeight, rightHeight));
    }
}

int countnodes(Node<int>* root) {
    if (root == nullptr) return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}


int main() {

    Node<int>* root = buildExampleBT();
    cout << "[PRE] \n";
    preOrder(root);

    cout << "\n\n";

    cout << "[POS] \n";
    postOrder(root);

    cout << "\n\n";

    cout << "[IN] \n";
    inOrder(root);

    cout << "\n\n";

    cout << "\nThere are " << countnodes(root) << " nodes in this tree" << endl; // expected: 6
    cout << "The height of this tree is " << height(root) << endl;

    cout << "The diameter of this tree is " << diameter(root) << endl;

    return 0;
}