#include <iostream>
#include <iomanip>
#include <list>
#include <math.h>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType;
typedef int ValueType;

struct DataType {
	int key;
	int valor;
};

struct Node {
	DataType data;
	Node * right;
	Node * left;
};

struct Ponto{
    int x,y;
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

void show_ordered(Node * curr, int pfmin, int pfmax){
	if(curr != NULL){
		show_ordered(curr->left, pfmin, pfmax);
        if(curr->data.valor >= pfmin && curr->data.valor <= pfmax)
		    cout << curr->data.key << ":" << curr->data.valor << endl;
		show_ordered(curr->right, pfmin, pfmax);
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
int distancia(Ponto a, Ponto b){

    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
    
}


int main()
{
	int qtd_tortas;
	
	cin >> qtd_tortas;
	
	Node * root = NULL;
	DataType dado;
    Ponto a,b,c,d;
	int valor;
    int espessura, peso, altura, diametro;
    int pfmin, pfmax;

	
	for(int i=0;i<qtd_tortas;i++){
		dado.key = i;
        cin >>a.x >> a.y;
        cin >>b.x >> b.y;
        cin >>c.x >> c.y;
        cin >>d.x >> d.y;
        cin >> peso;
        espessura = distancia(a,b);
        altura = distancia(a,c);
        diametro = distancia(c,d);

		valor = (espessura * peso * altura 
		+diametro + altura);
		dado.valor = valor;
		insert(root, dado);
	}

    cin >> pfmin >> pfmax;
    // mostrar na ordem crescendo seguindo os criterios de pfmin e pfmax
    show_ordered(root, pfmin, pfmax);
    // destruido arvore
	destruct(root);

	return 0;
}
