#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class NTree {
private:
    struct Node {
        T val;
        Node* firstChild;
        Node* sibiling;

        // retorna o n-ésimo filho desse nó ou nullptr se o nó não existe
        Node* chld(int n) { 
            Node* ret = firstChild;
            for (int i = 0; ret && i < n; i++) { // percorre enquanto tiver filho
                ret = ret->sibiling;
            }
            return ret;
        }

        // adiciona novo nó filho com valor v
        void addChd(T v) {
            if (!firstChild) {
                firstChild = new Node{v, nullptr, nullptr};
                return;
            }

            Node* cur = firstChild;
            while (cur->sibiling) {
                cur = cur->sibiling;
            }
            cur->sibiling = new Node{v, nullptr, nullptr};
        }

        void printNode(int level=0) {
            for (int i = 0; i < level; i++) {
                cout << "   ";
            }
            cout << this->val << endl;

            for (Node* cur = firstChild; cur; cur = cur->sibiling) {
                cur->printNode(level+1);
            }
        }
    };

public:

    Node* root;

    NTree() {
        root = new Node{0, nullptr, nullptr};
        root->addChd(1);
        root->addChd(2);

        Node* n1 = root->chld(0);
        n1->addChd(3);
        n1->addChd(4);
        n1->addChd(5);

        Node* n2 = root->chld(1);
        n2->addChd(6);
    }

    // percurso em profundidade (Depth-First Search - DFS)
    void print() {
        if (root) root->printNode;
    }

    // percurso em largura (Breadth-First Search - BFS)
    void bfs() {
        queue<Node*> q;
        if (root) q.push(root);

        // coloca a raiz na fila, tira da fila, imprime o valor e coloca todos os filhos na fila enquanto a fila não estiver vazia
        while (q.size()) {
            Node* n = q.front();
            q.pop();
            cout << n->val << " ";
            for (Node* cur = n->firstChild; cur; cur = cur->sibiling) {
                q.push(cur);
            }
        }
        cout << endl;
    }
};



int main() {
    NTree<int> t;
    t.print();

    t.bfs();

    return 0;
}