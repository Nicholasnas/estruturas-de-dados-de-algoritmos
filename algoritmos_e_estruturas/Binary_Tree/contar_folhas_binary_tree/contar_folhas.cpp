// Faça um programa,que dado uma árvore,diga quantas folhas essa árvore possui.

// As folhas devem ser contadas através da função:

// int contaFolhas(treenodeptr arvore)
// Entrada

// Haverá N números a serem inseridos na árvore, até que a entrada seja -1.
// Saída
// A saída deve conter o número de folhas da árvore.

// Exemplo de entrada     
// Exemplo de saída     
// 10 7 15 2 8 12 20 3 -1

// 4

#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int valor)
{
    if (root == NULL)
    {
        root = new Node;
        root->info = valor;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (valor < root->info)
    {
        root->left = insert(root->left, valor);
    }
    else
    {
        root->right = insert(root->right, valor);
    }
    return root;
}
int contar_folhas(Node *arvore)
{
    if (arvore == NULL)
    {
        return 0;
    }
    if (arvore->left == NULL && arvore->right == NULL)
    {
        return 1;
    }
    return contar_folhas(arvore->left) + contar_folhas(arvore->right);
}

int main()
{
    Node *arvore = NULL;
    int dado;
    while (true)
    {
        cin >> dado;
        if (dado == -1)
        {
            break;
        }
        arvore = insert(arvore, dado);
    }
    cout << contar_folhas(arvore) << endl;
    return 0;
}