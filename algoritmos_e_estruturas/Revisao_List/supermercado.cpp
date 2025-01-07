#include <iostream>
#include <list>

using namespace std;


int main()
{
	list<int> estoque;
	list<int> venda;
	list<int>::iterator p;
	int n; // operacoes
	int operacao, codigo; /// operação e codigo do produto
	int primeiro;
	
	cin >> n;
	
	for (int i=0;i<n;i++){
		cin >> operacao >> codigo;
		if(operacao == 1){
			estoque.push_back(codigo);
		}
		else if(operacao == 2){
			primeiro = estoque.front();
			estoque.pop_front();
			venda.push_back(primeiro);
		}
		
	}	
	cout << "Estoque: ";
	for (p = estoque.begin();p != estoque.end();p++){
		cout << *(p) << " ";
	}
	cout << endl;
	
	cout << "Venda: ";
	for (p = venda.begin();p != venda.end();p++){
		cout << *(p) << " ";
	}
	cout << endl;
	
	return 0;
}