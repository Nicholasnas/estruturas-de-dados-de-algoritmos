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
// Encontrar o menor elemento e apontar para direita dele
// Retorna um ponteiro que aponta para Node
Node * PointSmall(Node *& curr){
    Node * temp = curr;
    if(curr->left == NULL){ // Encontrar o menor valor
        curr = curr->right;
        return temp;
    }
    return PointSmall(curr->left); // continua procurando na subarvore a esquerda
}

bool Remove(Node *& p, int x){
    Node * t;
    if(p==NULL){ // arvore vazia
        return false;
    }
    if(x == p->info){
        t = p;
        if(p->left == NULL){ // sem filhos a esquerda
            p = p->right;
        }
        else if(p->right == NULL){ // sem filhos a direita
            p = p->left;
        }
        else{ // raiz tem ambos os filhos
            t = PointSmall(p->right);
            p->info = t->info;
        }

        delete t;

        return true;
    }
    else if(x < p->info){
        return Remove(p->left, x);
    }
    else{
        return Remove(p->right, x);
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
		if(op == 'i'){
			insert(raiz,info);
		}
		else if(op == 'b'){
			if(search(raiz, info)){
				cout << "Sim" << endl;
			}
			else cout << "Não" << endl;
		}
        else if(op=='r'){
            if(Remove(raiz, info)){
                cout << "Sim" << endl;
            }
            else{
                cout << "Não" << endl;
            }
        }

	}
	
	
	return 0;
}