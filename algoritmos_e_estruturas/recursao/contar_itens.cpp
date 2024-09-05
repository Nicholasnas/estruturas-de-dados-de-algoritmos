#include <iostream>

using namespace std;

// Funcao contar itens de um vetor
int conta_itens(int vetor[], int tam, int i){
    if (i == tam)
        return 0;
    return 1 + conta_itens(vetor, tam, i+1 );
}

int main(){

    int vetor[] = {2, 4, 6, 8};

    cout << "Itens no vetor: " << conta_itens(vetor, 4, 0);

    
    return 0;
}