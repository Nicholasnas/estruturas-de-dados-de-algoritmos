#include <iostream>

using namespace std;

void trocar_ponteiros(int *&p1, int *&p2){
    int pont;

    pont = *p1;
    *p1 = *p2;
    *p2 = pont;
 
}
int main(){

    int *pont1 = new int;
    int *pont2 = new int;

    *pont1 = 10;
    *pont2 = 5;
    cout << "endereco p1: " << pont1 << endl;
    cout << "endereco p2: " << pont2 << endl;

    trocar_ponteiros(pont1, pont2);
    cout << "p1 " << pont1 << " valor "  << *pont1 << endl;
    cout << "p2 "  << pont2 << " valor " << *pont2 << endl;

    return 0;
}