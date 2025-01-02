#include <iostream>

using namespace std;
struct Node{
	int info;
	Node * left;
	Node * right;
	
};
// ponteiros para outros nos da arvore
// informação no dado da arvore, criar uma struct para data para armazenar  valor na raiz(folha)
void insert(Node *& curr, int new_info){
	   // passar o ponteiro por referencia, curr- ponteiro atual
	   if(curr== NULL){
		   curr = new Node;
		   curr->info = new_info;
		   curr->left = NULL;
		   curr->right = NULL;
	   }
	   else{
		   if(new_info < curr->info){
			   insert(curr->left, new_info);
		   }
		   else{
			   insert(curr->right,new_info);
		   }
	   }
} 

// buscar retornar o ponteiro que apontou para o valor desejado
Node * search(Node * curr, int info){
	// passar o ponteiro por referencia, curr- ponteiro atual
	if(curr== NULL){
		   return NULL;
	   }
	else if(info == curr->info){
		return curr;
	}
	else{
		if(info < curr->info){
			return search(curr->left, info);
		}
		else{
			return search(curr->right, info);
		}
	}

	   
}
int main()
{
    setlocale(LC_ALL, "portuguese");

	
	int tam, info;
	char op;
	
	cin >> tam;
	
	Node * raiz = NULL;
	
	for(int i=0;i<tam;i++){
		cin >> op >> info;
		if(op == 'i')
			insert(raiz,info);
		else if(op=='b'){
			if(search(raiz, info)){
				cout << "Sim" << endl;
			}
			else cout << "Não" << endl;
		}

	}
	
	
	return 0;
}