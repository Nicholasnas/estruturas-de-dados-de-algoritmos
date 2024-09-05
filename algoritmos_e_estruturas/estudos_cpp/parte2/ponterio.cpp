#include <iostream>
#include <cstddef>

using namespace std;

int main(){ 

    int var1;
    int* pont1;

    var1 = 10;

    pont1 = &var1; // o ponteiro armazena o enderoco de var1
    cout << "Valor de var1 pelo nome eh " << var1 << endl;
    cout << "Endereco dentro do ponterio eh " << pont1 << endl;
    cout << "O valor armazenado no endereco de memoria pont1 eh " << *pont1 << endl;

    int var2 = 50;

    //var2 = var1;

    // *pont1 = 30;
    // cout << var1;

    // var2 = 130;

    pont1 = &var2;
    cout << pont1 << endl;
    cout << *pont1 << endl;

    int* pont2;

    pont2 = NULL;
    cout << "novo ponteiro" << endl;
    cout << pont2 << endl;
    
    cout << "ponterio3" << endl;
    
    int* pont3 = new int;
    *pont3 = 35;
    cout << pont3 << endl;
    cout << *pont3 << endl;

    delete pont3;
    
    pont3 = pont1;
    cout << *pont3 << endl;

}