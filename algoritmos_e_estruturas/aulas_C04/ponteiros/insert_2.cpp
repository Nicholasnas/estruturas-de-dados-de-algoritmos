#include <iostream>

using namespace std;

int main(){

    int tam;
    cin >> tam;

    int vetor[tam];

    int* p;
    p = vetor;

    for(int i=0;i<tam;i++){
        cin >> *p;
        p++;
    }

    p = vetor;
    for(int i=0;i<tam;i++){
        cout << *p << " ";
        p++;
    }  

    delete p;

    return 0;
}