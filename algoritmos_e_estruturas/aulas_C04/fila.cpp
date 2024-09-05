#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> fila;
	list<int>::iterator p;
	int valor, ultimo;
	
	
	for (int i=0;i<4;i++){
		cin >> valor;
		fila.push_back(valor);
	}	
	for (p = fila.begin();p != fila.end();p++){
		cout << *(p) << " ";
	}
	
	
	return 0;
}