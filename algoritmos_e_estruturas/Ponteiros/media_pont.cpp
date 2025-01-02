#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int tam;
    cin >> tam;
    
    int vetor[tam];

    int* p;
    float soma = 0;

    for(int i=0;i<tam;i++){
        cin >> vetor[i];
    }

    p = vetor;
    for(int i=0;i<tam;i++){
        soma += *p;
        p++;
    }  

    cout << fixed << setprecision(2);
    cout << soma/tam << endl;

    delete  p;

    return 0;
}