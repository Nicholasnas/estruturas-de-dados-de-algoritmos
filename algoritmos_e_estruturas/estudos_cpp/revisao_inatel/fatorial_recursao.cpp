#include <iostream>

using namespace std;


int fatorial(int n){
    if (n <= 1){
        return 1;
    }
    else{
        return n * fatorial(n-1);
    }
}

int main(){
    int n;

    while(true){
        cout << "Entre com o valor a ser calculado: " << endl;
        cin >> n;

        if (n <= -1){
            cout << "Entrada invalida, volte sempre!" << endl;
            break;
        }
        cout << "Fatorial de " << n << " eh: " << fatorial(n) << endl; 

    }

}