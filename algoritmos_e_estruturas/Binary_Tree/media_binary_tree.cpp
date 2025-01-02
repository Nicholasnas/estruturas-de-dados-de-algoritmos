
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

#include<iostream>
#include<list>
#include <iomanip>
using namespace std;

struct node {
	   int info;
	   node * left, * right;	
};

void insert(node * & curr, int new_info){
	if(curr == NULL){
		curr = new node;
		curr->info = new_info;
		curr->left = NULL;
		curr->right = NULL;
	} else {
		if(new_info < curr->info){
			insert(curr->left, new_info);
		} else{
			insert(curr->right, new_info);
		}
		
	}
}

node * search(node * curr, int searched_info){
	if(curr == NULL)
		return NULL;
	if(curr->info == searched_info)
		return curr;
	if(searched_info < curr->info){
		return search(curr->left, searched_info);
	} else {
		return search(curr->right, searched_info);
	}	
}

node * point_smaller(node * &curr){
	if(curr->left == NULL){
		node * aux = curr;
		curr = curr->right;
		return aux;
	} else {
		return point_smaller(curr->left);
	}	
}

bool remove(node * &curr, int removing_info){
	if(curr == NULL)
		return false;
	if(curr->info == removing_info){
		node * aux = curr;
		if(curr->left == NULL)
			curr = curr->right;
		else if(curr->right == NULL)
			curr = curr->left;
		else {
			aux = point_smaller(curr->right);
			curr->info = aux->info;
		}
		delete aux;
		return  true;
	} else if(removing_info < curr->info){
		return remove(curr->left, removing_info);
	} else {
		return remove(curr->right, removing_info);
	}	
}

void tree_ord_cres(node * curr, list<int> &arvore){
	if(curr != NULL){
		tree_ord_cres(curr->left, arvore);
        arvore.push_back(curr->info);
		tree_ord_cres(curr->right, arvore);
	}
}

int main()
{
	node * root = NULL;
	int dado;
    float soma =0;

	while(true){
		cin >> dado;
		if(dado == -1){
			break;
		}
		insert(root, dado);
	}

    list<int> arvore;
    list<int>::iterator it;
	int cont_nos = 0;
    tree_ord_cres(root, arvore);

    for(it = arvore.begin();it!= arvore.end();it++){
        soma += *(it);
		cont_nos++;
    }
    cout << fixed << setprecision(2);
    cout << "Media: " << soma/arvore.size() << endl;    
    cout << "Media: " << soma/float(cont_nos)<< endl;    

	return 0;
}