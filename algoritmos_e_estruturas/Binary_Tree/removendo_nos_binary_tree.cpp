#include<iostream>
#include<list>
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

void tree_ord_cres(node * curr){
	if(curr != NULL){
		tree_ord_cres(curr->left);
		cout << curr ->info << " ";
		tree_ord_cres(curr->right);
	}
}

int main()
{
	node * root = NULL;
	int dado, desejado;
	while(true){
		cin >> dado;
		if(dado == 0){
			break;
		}
		insert(root, dado);
	}
	cin >> desejado;
    while(search(root, desejado)){
	    remove(root, desejado);
    }
	tree_ord_cres(root);
	
	return 0;
}