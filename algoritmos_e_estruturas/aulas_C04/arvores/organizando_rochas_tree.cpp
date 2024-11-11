#include <iostream>
using namespace std;

struct Rocha {
    string nome, tipo;
};

struct Node {
    Rocha info;
    Node *left;
    Node *right;
};

void insert(Node *&curr, Rocha new_info) {
    if (curr == NULL) {
        curr = new Node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if (new_info.nome < curr->info.nome) {
            insert(curr->left, new_info);
        } else {
            insert(curr->right, new_info);
        }
    }
}

Node *search(Node *curr, string info) {
    if (curr == NULL) {
        return NULL;
    } else if (info == curr->info.nome) {
        return curr;
    } else {
        if (info < curr->info.nome) {
            return search(curr->left, info);
        } else {
            return search(curr->right, info);
        }
    }
}

// Encontrar o menor elemento e apontar para direita dele
Node * PointSmall(Node *&curr) {
    if (curr->left == NULL) { // Encontrou o menor valor
        Node *temp = curr;
        curr = curr->right;
        return temp;
    }
    return PointSmall(curr->left); // continua procurando na subarvire a esquerda
}

bool Remove(Node *&p, Rocha x) {
    Node *t;
    if (p == NULL) { // arvore vazia
        return false;
    }
    if (x.nome == p->info.nome && x.tipo == p->info.tipo) {
        t = p;
        if (p->left == NULL) { // sem filhos a esquerda
            p = p->right;
        } else if (p->right == NULL) { // sem filhos a direita
            p = p->left;
        } else {
            t = PointSmall(p->right);
            p->info = t->info;
        }
        delete t;
        return true;
    } else if (x.nome < p->info.nome) {
        return Remove(p->left, x);
    } else {
        return Remove(p->right, x);
    }
}

int main() {
    int op;
    string nome, tipo;
    Node *raiz = NULL;

    while (true) {
        cin >> op;
        cin.ignore(); // Ignora nova linha após o número

        switch (op) {
            case 1: {
                Rocha rocha;
                getline(cin, rocha.nome);
                getline(cin, rocha.tipo);
                insert(raiz, rocha);
                break;
            }
            case 2: {
                getline(cin, nome);
                Node *resultado = search(raiz, nome);
                if (resultado != NULL) {
                    cout << "Nome: " << resultado->info.nome << endl;
                    cout << "Tipo: " << resultado->info.tipo << endl;
                } else {
                    cout << "Rocha nao encontrada" << endl;
                }
                break;
            }
            case 3: {
                Rocha pedra;
                getline(cin, pedra.nome);
                getline(cin, pedra.tipo);
                if (Remove(raiz, pedra)) {
                    cout << "Rocha removida com sucesso" << endl;
                } else {
                    cout << "Rocha nao encontrada para remocao" << endl;
                }
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Operacao invalida" << endl;
                break;
        }
    }
    
    return 0;
}
