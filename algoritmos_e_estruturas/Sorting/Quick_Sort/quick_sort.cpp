#include <iostream>


using namespace std;
int partition(int vetor[], int left, int right){
   int pivo = vetor[right]; // Pivo ultimo elemento
   int i = left -1; // Index - apontando para o vazio
   int temp; // variavel temporaria p/ troca

   for (int j=left;j<right;j++){
        if (vetor[j] <= pivo){
            i++;
            temp = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = temp;
         }

   }
   // Colocor o pivo no lugar correto
   temp = vetor[i+1];
   vetor[i+1] = vetor[right];
   vetor[right] = temp;

   return i +1;
}

void quicksort(int vetor[], int left, int right) {
    int pivo;
    if (left < right)
    {
        pivo = partition(vetor, left, right);
        quicksort(vetor, left, pivo-1);
        quicksort(vetor,pivo+1,right);
    }
  
}

int main() {
    int vetor[] = {10, 15, 1, 5, 20, 7}; // um array de 6 elementos
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Array Desordenado: " << endl << "[ ";
    for (int i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << "]" << endl;


    quicksort(vetor, 0, tam - 1);

    cout << "Array ordenado: " << endl << "[ ";
    for (int i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}
