#include <iostream>

using namespace std;

int main(){

    int tam;
    cin >> tam;
    int* p  = new int[tam];

    for(int i=0;i<tam;i++){
        cin >> p[i];
    }
    for(int i=0;i<tam;i++){
        cout << p[i] << " ";
    }

    delete [] p;

    return 0;
}