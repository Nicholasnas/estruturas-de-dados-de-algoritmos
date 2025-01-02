#include <iostream>

using namespace std;

struct Movie{
	string nome, genero;
	int duracao, classificacao, ano;	
};


struct Node{
	Movie info;
	Node * left;
	Node * right;
	
};
// ponteiros para outros nos da arvore
// informação no dado da arvore, criar uma struct para data para armazenar  valor na raiz(folha)

void insert(Node *& curr, Movie new_info){
	   // passar o ponteiro por referencia, curr- ponteiro atual
	   if(curr== NULL){
		   curr = new Node;
		   curr->info = new_info;
		   curr->left = NULL;
		   curr->right = NULL;
	   }
	   else{
		   if(new_info.nome < curr->info.nome){
			   insert(curr->left, new_info);
		   }
		   else{
			   insert(curr->right,new_info);
		   }
	   }
} 

// buscar retornar o ponteiro que apontou para o valor desejado

Node * search(Node * curr, string info){
	// passar o ponteiro por referencia, curr- ponteiro atual
	if(curr== NULL){
		   return NULL;
	   }
	else if(info == curr->info.nome){
		return curr;
	}
	else{
		if(info < curr->info.nome){
			return search(curr->left, info);
		}
		else{
			return search(curr->right, info);
		}
	}

	   
}
int main()
{
	int op;
	string nome;
	Node * raiz = NULL;
	
	while(true){
		cin >> op;
		cin.ignore();

		switch(op)
		{
		case 1:{

			Movie dado;
            getline(cin, dado.nome);
			cin >> dado.genero >> dado.duracao >> dado.classificacao >> dado.ano;
		
			insert(raiz, dado);

            cin.ignore();
			break;
		}
		case 2:
		{
			getline(cin, nome);
			Node *resultado = search(raiz, nome);
			cin.ignore();
			if(resultado != NULL){
				cout << "Nome: " << resultado->info.nome << endl; 
				cout << "Genero: " << resultado->info.genero << endl;
				cout << "Duracao: " << resultado->info.duracao << " mins" <<endl;
				cout << "Classificacao: " << resultado->info.classificacao << endl;
				cout << "Ano: " << resultado->info.ano << endl;
				
			}
			else cout << "Filme nao encontrado" << endl;
			break;
		}
		case 0:
			return 0;
		default:
			cout << "Operacao invalida" << endl;
			break;
		}
		
	}
	
	delete raiz;
    
	return 0;
}