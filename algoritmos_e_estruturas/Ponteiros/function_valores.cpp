#include <iostream>

using namespace std;

void modifica_valor(int * ptr){
    cout << "Endereco recebido pela funcao: " << ptr << endl;
    *ptr = 45; // Modifica o valor da variavel que o ponteiro aponta
}
int main(){
    int a = 10; // Variavel alocada na STACK
    cout << "O endereco de 'a' na main: " << &a << endl;
    modifica_valor(&a);
    cout << "Novo valor apos funcao: " << a << endl;

    return 0;
}