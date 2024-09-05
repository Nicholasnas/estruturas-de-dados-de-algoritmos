#include <iostream>

using namespace std;

int main()
{
	int numero;
	int contador = 0;
	
	cout << "Entre com os numeros: " << endl;
	while (true){
		cin >> numero;	
		if (numero == -1){
			break;
		}
		contador += numero;
		cout << "Entre com um numero: " << endl;
	}
	
	cout << "Resultado: " << contador << endl;
	
		
	return 0;
}