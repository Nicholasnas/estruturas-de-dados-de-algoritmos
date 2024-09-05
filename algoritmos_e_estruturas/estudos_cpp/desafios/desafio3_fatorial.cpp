#include <iostream>

using namespace std;

int fatorial(int n){
    if (n <= 1) {
        return 1;
    }
    else {
        return n * fatorial(n-1);
    }
}

int main(){
    int numero, resultado;


    while(true){
        cout << "Entre com um número: ";
        cin >> numero;
        if (numero < 0){
            cout << "numero negativo!" << endl;
            continue;
        }
        else{
            break;
        }
    }
        
    resultado = fatorial(numero);
    cout << "O fatorial de " << numero << " eh " << resultado << endl;

    return 0;
}