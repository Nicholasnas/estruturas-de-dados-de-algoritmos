#include <iostream>

using namespace std;
               
int busca_binaria(int vetor[], int inicio, int fim, int alvo){
	int meio = (inicio+fim)/2;
	
    if (inicio <= fim){
        if(vetor[meio] == alvo)
            return meio;
        if(vetor[meio] < alvo){
            return busca_binaria(vetor,meio+1, fim, alvo);
        }
        else{
            return busca_binaria(vetor,inicio, meio-1, alvo);
        }

    }
	
	return -1;
		
}
int main()
{
	int n, alvo;
	
	cin >> n;
	
	int* vetor = new int[n];

	
	for (int i=0;i<n;i++){
		// cout << "Entre com o valor de [" << i+1 << "] :" ;
		cin >> vetor[i];
		// cout << endl;
	}	
	
	cin >> alvo;
	
	cout << busca_binaria(vetor,0, n-1,alvo);
	
	delete [] vetor;
	return 0;
}