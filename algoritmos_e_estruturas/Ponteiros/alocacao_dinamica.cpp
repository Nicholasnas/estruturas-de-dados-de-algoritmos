#include <iostream>

using namespace std;

void modifica_valor(int * ptr){
    cout << "Endereco recebido pela funcao: " << ptr << endl;
    // Modificando o valor na heap
    *ptr = 45; // Modifica o valor da variavel que o ponteiro aponta        
}

int main(){
    int *b = new int(20); // ponteiro na stack e valor na heap
    cout << "O endereco do ponteiro na stack: " << &b << endl;
    cout << "O endereco alocado na heap: " << b << endl;
    modifica_valor(b);

    cout << "novo valor na heap: " << *b << endl;

    delete b; // liberando a memoria alocada na heap

    return 0;
}