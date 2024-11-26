#include <iostream>


using namespace std;

int main(){

    int tam;
    cin >> tam;
    
    int vetor[tam];

    int* p;
    int maior;

    for(int i=0;i<tam;i++){
        cin >> vetor[i];
    }

    p = vetor;
    maior = *p;
    for(int i=0;i<tam;i++){
        if(*p > maior){
            maior = *p;
        }
        p++;
    }  

    cout << maior << endl;

    return 0;
}