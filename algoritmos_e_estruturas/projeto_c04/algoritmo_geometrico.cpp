#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include <iomanip>
#include <locale>

using namespace std;

// Palavra fictícia, significado e coordenadas no espaço
struct Palavra {
    string palavraFicticia;
    string significado;
    int x, y, z;
};

// Nó para a Árvore Binária
struct Node {
    Palavra palavra;
    Node *left;
    Node *right;
};

// Função para inserir palavras na árvore binária
void insert(Node *&curr, Palavra nova_palavra) {
    if (curr == NULL) {
        curr = new Node;
        curr->palavra = nova_palavra;
        curr->right = NULL;
        curr->left = NULL;
    } else {
        if (nova_palavra.palavraFicticia < curr->palavra.palavraFicticia) {
            insert(curr->left, nova_palavra);
        } else {
            insert(curr->right, nova_palavra);
        }
    }
}

// Realizar a busca na árvore pela palavra fictícia
Node *search(Node *curr, string palavraFicticia) {
    if (curr == NULL) {
        return NULL;
    } else if (palavraFicticia == curr->palavra.palavraFicticia) {
        return curr;
    } else {
        if (palavraFicticia < curr->palavra.palavraFicticia) {
            return search(curr->left, palavraFicticia);
        } else {
            return search(curr->right, palavraFicticia);
        }
    }
}

// Busca em nível de profundidade na árvore
void in_level(Node *curr) {
    list<Node *> visit_queue;
    if (curr != NULL) {
        visit_queue.push_back(curr);
        while (!visit_queue.empty()) {
            Node *aux = visit_queue.front();
            visit_queue.pop_front();
            if (aux->left != NULL)
                visit_queue.push_back(aux->left);
            if (aux->right != NULL)
                visit_queue.push_back(aux->right);

            cout << "Palavra Fictícia: " << aux->palavra.palavraFicticia << endl;
            cout << "Significado: " << aux->palavra.significado << endl;
        }
    }
}

// Mostrar as palavras em ordem alfabética
void arvore_em_ordem(Node *curr) {
    if (curr == NULL) {
        return;
    }
    arvore_em_ordem(curr->left);
    cout << "Palavra Fictícia: " << curr->palavra.palavraFicticia << endl;
    cout << "Significado: " << curr->palavra.significado << endl;
    cout << "Coordenadas: (" << curr->palavra.x << ", ";
    cout << curr->palavra.y << ", " << curr->palavra.z << ")" << endl;
    arvore_em_ordem(curr->right);
}

// Mostrar as palavras em pré-ordem
void arvore_em_pre_ordem(Node *curr) {
    if (curr == NULL) {
        return;
    }
    cout << "Palavra Fictícia: " << curr->palavra.palavraFicticia << endl;
    cout << "Significado: " << curr->palavra.significado << endl;
    cout << "Coordenadas: (" << curr->palavra.x << ", ";
    cout << curr->palavra.y << ", " << curr->palavra.z << ")" << endl;
    arvore_em_pre_ordem(curr->left);
    arvore_em_pre_ordem(curr->right);
}

// Mostrar as palavras em pós-ordem
void arvore_em_pos_ordem(Node *curr) {
    if (curr != NULL) {
        arvore_em_pos_ordem(curr->left);
        arvore_em_pos_ordem(curr->right);
        cout << "Palavra Fictícia: " << curr->palavra.palavraFicticia << endl;
        cout << "Significado: " << curr->palavra.significado << endl;
        cout << "Coordenadas: (" << curr->palavra.x << ", ";
        cout << curr->palavra.y << ", " << curr->palavra.z << ")" << endl;
    }
}

// Destruindo a árvore - removendo os nós
void destruct(Node *&curr) {
    if (curr != NULL) {
        destruct(curr->left);
        destruct(curr->right);
        delete curr;
        curr = NULL;
    }
}

// Encontrar o menor elemento e apontar para a direita dele
Node *PointSmall(Node *&curr) {
    if (curr->left == NULL) {
        Node *temp = curr;
        curr = curr->right;
        return temp;
    }
    return PointSmall(curr->left);
}

// Remover palavra da árvore
bool remove_palavra(Node *&curr, string palavra) {
    if (curr == NULL) {
        return false;
    }
    if (curr->palavra.palavraFicticia == palavra) {
        Node *aux = curr;
        if (curr->left == NULL) {
            curr = curr->right;
        } else if (curr->right == NULL) {
            curr = curr->left;
        } else {
            aux = PointSmall(curr->right);
            curr->palavra = aux->palavra;
        }
        delete aux;
        return true;
    } else if (palavra < curr->palavra.palavraFicticia) {
        return remove_palavra(curr->left, palavra);
    } else {
        return remove_palavra(curr->right, palavra);
    }
}

// Função para criar uma nova palavra fictícia
Palavra nova_palavra() {
    Palavra palavra;

    cout << "Entre com a palavra fictícia: ";
    cin.ignore();
    getline(cin, palavra.palavraFicticia);
    cout << "Significado: ";
    getline(cin, palavra.significado);
    
    cout << "Entre com as coordenadas (x, y, z): " << endl;
    cout << "Coordenada x: ";
    cin >> palavra.x;
    cout << "Coordenada y: ";
    cin >> palavra.y;    
    cout << "Coordenada z: ";
    cin >> palavra.z;

    return palavra;
}

// Função para calcular a distância entre duas palavras
double calcularDistancia(Palavra p1, Palavra p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main() {
    // Configurando o locale para português
    setlocale(LC_ALL, "portuguese");

    list<Palavra> palavras;
    Node *root = NULL;
    int opcao;

    while (true) {
        cout << "======== Sistema de Vocabulário Fictício =========" << endl;
        cout << "1 - Adicionar nova palavra na árvore: "  << endl;
        cout << "2 - Listar palavras em pré-ordem alfabética: " << endl;
        cout << "3 - Listar palavras em ordem alfabética: " << endl;
        cout << "4 - Listar palavras em pós-ordem alfabética: " << endl;
        cout << "5 - Varredura em largura (nível): " << endl;
        cout << "6 - Busca na árvore: " << endl;
        cout << "7 - Remover palavra da árvore: " << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        
        cin >> opcao;

        switch (opcao) {
            case 0:
                destruct(root);
                cout << "Encerrando o programa!" << endl;
                return 0;
            case 1:
                insert(root, nova_palavra());
                cout << "Palavra adicionada com sucesso!" << endl;
                break;
            case 2:
                cout << "Palavras em pré-ordem alfabética:" << endl;
                arvore_em_pre_ordem(root);
                break;
            case 3:
                cout << "Palavras em ordem alfabética:" << endl;
                arvore_em_ordem(root);
                break;
            case 4:
                cout << "Palavras em pós-ordem alfabética:" << endl;
                arvore_em_pos_ordem(root);
                break;
            case 5: {
                cout << "Palavras em nível: " << endl;
                in_level(root);
                break;
            }
            case 6: {
                string busca;
                cout << "Digite a palavra fictícia para buscar: ";
                cin.ignore();
                getline(cin, busca);
                Node *resultado = search(root, busca);
                if (resultado != NULL) {
                    cout << "Palavra encontrada!" << endl;
                    cout << "Palavra: " << resultado->palavra.palavraFicticia << endl;
                    cout << "Significado: " << resultado->palavra.significado << endl;
                    cout << "Coordenadas: (" << resultado->palavra.x << ", ";
                    cout << resultado->palavra.y << ", " << resultado->palavra.z << ")" << endl;
                } else {
                    cout << "Palavra não encontrada!" << endl;
                }
                break;
            }
            case 7: {
                string palavra_remover;
                cout << "Digite a palavra fictícia para remover: ";
                cin.ignore();
                getline(cin, palavra_remover);
                if (remove_palavra(root, palavra_remover)) {
                    cout << "Palavra removida com sucesso!" << endl;
                } else {
                    cout << "Palavra não encontrada para remoção!" << endl;
                }
                break;
            }
            default:
                cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}