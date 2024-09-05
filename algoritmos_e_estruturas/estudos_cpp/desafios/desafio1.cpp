#include <iostream>
#include <cmath>

using namespace std;

float calcula_funcao(float x){
    float funcao;
    
    funcao =  pow(x,2) - 3*x + 5;
    return funcao;

}

int main(){
    float x;
    float resultado;
    cout << "Entre com o valor de x: " << endl;
    cin >> x;

    // Chama funcao
    resultado = calcula_funcao(x);
    cout << "O resultado da funcao para x = "<< x << " é " << resultado << endl;

    return 0;
}