#include <iostream>
#include <list>

using namespace std;


bool encontrar(list<int> fila, int x){
	
	list<int>::iterator p;
	for (p = fila.begin();p != fila.end();p++){
		if (x==*(p)){
			return true;
		}
	}
	return false;
}
int main()
{
	list<int> fila;
	bool busca;
	int valor, n;
	
	do{
		cin >> valor;
		fila.push_back(valor);
	}while(valor != 0);
	
	cin >> n;
	busca = encontrar(fila, n);
	if (busca){
		cout << "Encontrado" << endl;
	}
	else{
		cout << "Nao encontrado" << endl;
	}
	
	return 0;
}