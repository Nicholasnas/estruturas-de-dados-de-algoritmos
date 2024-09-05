#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float nota[5], soma = 0;
	int i = 0;
	float maior;
	
	
	while(i < 5){
		cout << "Entre com a idade do aluno [" << i + 1 << "]:" << endl;
		cin >> nota[i];
		soma += nota[i];
		i++;
	}
	
	cout << "A media das notas dos alunos eh " << soma/5 << setprecision(5) << endl;
	
	maior = nota[0];
	for (i=0; i<5; i++){
		if (nota[i] > maior){
			maior = nota[i];
		}
	}
	
	cout << "A maior nota dos alunos eh " << maior << endl;
	
	return 0;
}