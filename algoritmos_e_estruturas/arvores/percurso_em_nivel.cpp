
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
int maior_elemento(node *curr)
{
	if(curr != NULL)
	{
		node * atual = curr;
		while(atual->right != NULL)
		{
			atual = atual->right;
		}
		return atual->info;
	}
	return -1;
}
int menor_elemento(node * curr)
{
	if(curr != NULL)
	{
		node * atual = curr;
		while(atual->left != NULL)
		{
			atual = atual->left;
		}
		return atual->info;
	}
	return -1;
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
void in_level(node * curr)
{
	list<node *> visit_queue;
	if(curr != NULL)
	{
		visit_queue.push_back(curr);
		while(!visit_queue.empty())
		{
			node * aux = visit_queue.front();
			visit_queue.pop_front();
			if(aux->left != NULL)
				visit_queue.push_back(aux->left);
			if(aux->right != NULL)
				visit_queue.push_back(aux->right);
			cout << aux->info << endl;
		}
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
        in_level(root);

		return 0;
}


