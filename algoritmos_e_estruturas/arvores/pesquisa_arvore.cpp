#include <iostream>

using namespace std;

struct Node{
	int info;
	Node * left;
	Node * right;
	
};


void insert(Node *& curr, int new_info){
	   // passar o ponteiro por referencia, curr- ponteiro atual
	   if(curr== NULL){ // inserir na raiz
		   curr = new Node;
		   curr->info = new_info;
		   curr->left = NULL;
		   curr->right = NULL;
	   }
	   else{
		   if(new_info < curr->info){ // inserir a esquerda da arvore
			   insert(curr->left, new_info);
		   }
		   else{ // inserir a direita da arvore
			   insert(curr->right,new_info);
		   }
	   }
} 

// buscar retornar o ponteiro que apontou para o valor desejado
Node * search(Node * curr, int info){
	// passar o ponteiro por referencia, curr- ponteiro atual
	if(curr== NULL){
		return NULL; // valor nao esta na lista ou lista vazia
	   }
	else if(info == curr->info){
		return curr; // valor encontrado
	}
	else{
		if(info < curr->info){
			return search(curr->left, info); // procurar na sub arvore a esquerda
		}
		else{ // procurar na sub arvore a direita
			return search(curr->right, info);
		}
	}

	   
}
int main()
{
	int tam_arvore;
	int desejado;
	int data;
	
	cin >> tam_arvore;
	
	Node * raiz = NULL;
	
	for(int i=0;i<tam_arvore;i++){
		cin >> data;
		insert(raiz, data);
	}
	
	cin >> desejado;
	
	if(search(raiz, desejado) == NULL){
		cout << "Nao encontrado" << endl;
	}
	else{
		cout << "Encontrado" << endl;
	}
	
	return 0;
}