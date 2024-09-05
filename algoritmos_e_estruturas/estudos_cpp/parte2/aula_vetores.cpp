#include <iostream>

using namespace std;

int main(){

    // Alocação estática
    // int vetor[4]= {1,2};

    // for (int i = 0;i < 4; i++){
    //     cout << vetor[i] << " ";
    // }
    // cout << endl;

    // cout << sizeof(vetor)/sizeof(int) << endl;

    cout << "Alocacao dinamica" << endl;

    int tam;
    cout << "Entre com o tamanho do vetor: ";
    cin >> tam;

    // Um ponteiro que aponta para um vetor
    int* vetor = new int[tam];
    
    for (int i = 0; i < tam; i++){
        cout << "Entre com o elemento " << i + 1 << " do array: ";
        cin >> vetor[i];
    }

    for (int i=0;i < tam;i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Não precisa usar o vetor

    delete [] vetor;





}