#include <iostream>

using namespace std;



int busca_binaria_rucursao(int vetor[], int target, int baixo, int alto){
    int meio = (alto + baixo) / 2;
    int chute;

    chute = vetor[meio];

    if (baixo > alto)
        return -1;
    
    // caso encontre o target retorna a posição no vetor
    if (chute == target)
        return meio; 
    if (chute > target)
    {
        alto = meio - 1;
        return busca_binaria_rucursao(vetor,target, baixo, alto);
    }
    if (chute < target)
    {
        baixo = meio + 1;
        return busca_binaria_rucursao(vetor,target, baixo, alto);
    }

}

int main(){

    int lista[5] = {2,4,6,8,10};
    int tam = 5;
	cout << "Lista: [ ";
    for (int i=0; i<5; i++){
            cout << lista[i] << " " ;
        }
	cout << "]" << endl;

	cout << busca_binaria_rucursao(lista,10,0,5);

}
