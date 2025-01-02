#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType;
typedef int ValueType;

struct DataType {
	int key;
	float espessura;
	float peso;
	float altura;
	float diametro;
	float valor;
};

struct Node {
	DataType data;
	Node * right;
	Node * left;
};

void insert(Node *& curr, DataType data){	
	if(curr == NULL){
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(data.valor < curr->data.valor){
			insert(curr->left, data);
		} else{
			insert(curr->right, data);
		}		
	}	
}

Node * search(Node * curr, int key){
	if(curr == NULL)
		return NULL;
	if(key == curr->data.key){
		return curr;
	} else {
		if(key < curr->data.key){
			return search(curr->left, key);
		} else{
			return search(curr->right, key);
		}
	}
	return NULL;
}

void show_ordered(Node * curr){
	if(curr != NULL){
		show_ordered(curr->left);
		cout << curr->data.key << ":" << curr->data.valor << endl;
		show_ordered(curr->right);
	}
}

Node * disconnect_lesser(Node *& curr){
	Node * aux = curr;
	if(aux->left == NULL){ 	
		curr = curr->right; 
		return aux;			
	} else {				
		return disconnect_lesser(curr->left);
	}
}


int remove(Node *& curr, KeyType old_key){
	if(curr == NULL){
		return 0;
	}
	Node * aux;
	if(curr->data.key == old_key){
		aux = curr;		
		if(curr->left == NULL){
			curr = aux->right;
		} else if(curr->right == NULL){
			curr = aux->left;
		} else {
			aux = disconnect_lesser(curr->right);
			curr->data = aux->data;
		}		
		delete aux;
		return 1;		
	} else {
		if(old_key > curr->data.key){
			return remove(curr->right, old_key);
		} else if(old_key < curr->data.key) {
			return remove(curr->left, old_key);
		}
	}
	return 0;
}


void destruct(Node *& curr){
	if(curr != NULL){
		destruct(curr->left);
		destruct(curr->right);
		delete curr;
	}
}
int main()
{
	int qtd_tortas;
	
	cin >> qtd_tortas;
	
	Node * root = NULL;
	DataType dado;
	int valor;
	
	for(int i=0;i<qtd_tortas;i++){
		dado.key = i;
		cin >> dado.espessura;
		cin >> dado.peso;
		cin >> dado.altura;
		cin >> dado.diametro;
		valor = (dado.espessura * dado.peso * dado.altura 
		+dado.diametro + dado.altura);
		dado.valor = valor;
		insert(root, dado);
	}
	show_ordered(root);
	destruct(root);
	

	return 0;
}

// ----------------------------------------------------------------------------