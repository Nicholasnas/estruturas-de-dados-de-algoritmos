#include <iostream>

using namespace std;

int calcular_fatorial(int n){

    if (n == 1 || n == 0)
        return 1;
    else
        return n * calcular_fatorial(n-1);
}

int main(){
    int n;

    cout << "Entre com numero que deve ser calculado: ";
    cin >> n;

    cout << "O Fatorial de " << n << "!: " << calcular_fatorial(n) << endl;

    return 0;
}