#include <iostream>
#include <list>
using namespace std;

struct node {
    int info;
    node *left, *right;
};

// Função para inserir nós na árvore binária de busca
void insert(node *&curr, int new_info) {
    if (curr == NULL) {
        curr = new node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
        cout << "Inserido: " << new_info << endl; // Depuração
    } else {
        if (new_info < curr->info) {
            insert(curr->left, new_info);
        } else {
            insert(curr->right, new_info);
        }
    }
}

// Função para exibir a árvore em níveis
void in_level(node *curr) {
    if (curr == NULL) {
        cout << "A árvore está vazia!" << endl; // Depuração
        return;
    }

    list<node *> visit_queue;
    visit_queue.push_back(curr);
    cout << "Nível iniciado com o nó raiz: " << curr->info << endl; // Depuração

    while (!visit_queue.empty()) {
        int level_size = visit_queue.size();
        cout << "Nó(s) no nível: " << level_size << endl; // Depuração

        for (int i = 0; i < level_size; i++) {
            node *aux = visit_queue.front();
            visit_queue.pop_front();
            cout << aux->info << " ";

            if (aux->left != NULL) {
                cout << "(Esquerda: " << aux->left->info << ") "; // Depuração
                visit_queue.push_back(aux->left);
            }
            if (aux->right != NULL) {
                cout << "(Direita: " << aux->right->info << ") "; // Depuração
                visit_queue.push_back(aux->right);
            }
        }
        cout << endl;
    }
}

int main() {
    node *root = NULL;
    int dado;

    cout << "Digite os valores para inserir na árvore (-1 para encerrar):" << endl;
    while (true) {
        cin >> dado;
        if (dado == -1) {
            break;
        }
        insert(root, dado);
    }

    cout << "Árvore exibida por níveis:" << endl;
    in_level(root);

    return 0;
}
