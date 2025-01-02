#include <iostream>

using namespace std;


void selection_sort(int vetor[], int tam){

    int menor_index, temp; // menor index e variavel temporaria para inverter os valores

    for (int i=0; i<tam; i++){
        menor_index = i;
        for (int j=i+1;j<tam; j++){
            if (vetor[j] < vetor[menor_index])
                menor_index = j;
        }
        temp = vetor[i];
        vetor[i] = vetor[menor_index];
        vetor[menor_index] = temp;
    }
}

int main(){
    int vetor_int[] = {15, 12, 14, 13, 8, 9, 7, 5, 2, 1, 0};
    int tam = sizeof(vetor_int) / sizeof(vetor_int[0]);

    selection_sort(vetor_int, tam);

    cout << "Vector sort: [ ";
    for (int i=0;i<tam;i++){
        cout << vetor_int[i] << " ";
    }
    cout << "]";

    return 0;

}