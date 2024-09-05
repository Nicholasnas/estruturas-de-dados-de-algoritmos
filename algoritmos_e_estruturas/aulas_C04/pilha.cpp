#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> pilha;
	list<int>::iterator p;
	int valor, ultimo;
	
	for (int i=0;i<4;i++){
		cin >> valor;
		pilha.push_back(valor);
	}
	
	for(p =pilha.end();p != pilha.begin() ;p--){
		cout << *(p) << endl;
		// ultimo = *(p);
		// pilha.pop_back();
		// cout << ultimo << " ";
	}
	return 0;
}