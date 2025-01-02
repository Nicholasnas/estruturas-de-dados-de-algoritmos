#include <iostream>


using namespace std;

int main(){

    int tam;
    cin >> tam;
    
    int vetor[tam];

    int* p;
    int qtd_pares_positivos=0;

    for(int i=0;i<tam;i++){
        cin >> vetor[i];
    }

    p = vetor;
    for(int i=0;i<tam;i++){
        if(*p>0 && *p%2==0){
            qtd_pares_positivos++;
        }
        p++;
    }  

    cout << qtd_pares_positivos << endl;

    return 0;
}