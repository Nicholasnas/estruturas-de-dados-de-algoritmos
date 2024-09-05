#include <iostream>

using namespace std;

int main()
{

	float nota;
	
	do {
		cout << "Entre com a Nota: ";
		cin >> nota;
		if (nota >= 60){
			cout << "Passou" << endl;
		}
		else{
			cout << "Nao passou" << endl;
		}
	}while(nota >= 0);
	
	return 0;
}