
// Exemplo de entrada
// 10 7 15 2 8 12 20 3 -1
// Exemplo de saída
// 20 15 12 10 8 7 3 2

// Faça um programa que insira vários números em uma árvore,
// e depois verifique qual a média dos elementos da árvore.
//
// A média deve ser calculada através de uma função, com o seguinte cabeçalho:
// float media(treenodeptr arvore)
// Entrada
// Na primeira linha da entrada serão fornecidos vários números,
// que deverão ser inseridos na lista até que seja lido o número -1.
//
// Saída
// O programa deve informar a média com 2 casas de precisão.
// Exemplo de entrada
// Exemplo de saída
// 8 3 10 14 6 4 13 7 1 -1
//
// Media: 7.33

#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

struct node
{
    int info;
    node *left, *right;
};

void insert(node *&curr, int new_info)
{
    if (curr == NULL)
    {
        curr = new node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
    }
    else
    {
        if (new_info < curr->info)
        {
            insert(curr->left, new_info);
        }
        else
        {
            insert(curr->right, new_info);
        }
    }
}
int maior_elemento(node *curr){
    if(curr != NULL){
        maior_elemento(curr->left);
    }
    return curr->info;
}

    node *search(node *curr, int searched_info)
{
    if (curr == NULL)
        return NULL;
    if (curr->info == searched_info)
        return curr;
    if (searched_info < curr->info)
    {
        return search(curr->left, searched_info);
    }
    else
    {
        return search(curr->right, searched_info);
    }
}

node *point_smaller(node *&curr)
{
    if (curr->left == NULL)
    {
        node *aux = curr;
        curr = curr->right;
        return aux;
    }
    else
    {
        return point_smaller(curr->left);
    }
}

bool remove(node *&curr, int removing_info)
{
    if (curr == NULL)
        return false;
    if (curr->info == removing_info)
    {
        node *aux = curr;
        if (curr->left == NULL)
            curr = curr->right;
        else if (curr->right == NULL)
            curr = curr->left;
        else
        {
            aux = point_smaller(curr->right);
            curr->info = aux->info;
        }
        delete aux;
        return true;
    }
    else if (removing_info < curr->info)
    {
        return remove(curr->left, removing_info);
    }
    else
    {
        return remove(curr->right, removing_info);
    }
}

void ord_decrescente(node *curr)
{
    if (curr != NULL)
    {
        ord_decrescente(curr->right);
        cout << curr->info << " ";
        ord_decrescente(curr->left);
    }
}

int main()
{
    node *root = NULL;
    int dado;

    while (true)
    {
        cin >> dado;
        if (dado == -1)
        {
            break;
        }
        insert(root, dado);
    }
    cout << maior_elemento(root) << endl;

    return 0;
}