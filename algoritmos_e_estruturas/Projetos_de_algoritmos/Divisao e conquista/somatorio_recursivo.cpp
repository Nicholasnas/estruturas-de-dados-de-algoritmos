#include <iostream>

using namespace std;

int somatorio_recursivo(int n){
    if (n == 1)
        return 1;
    else
        return n + somatorio_recursivo(n-1);
}

int main(){
    int n;

    cout << "Somatorio de qual numero(0->N): ";
    cin >> n;
    
    cout << "O somatorio de " << n << ": " << somatorio_recursivo(n) << endl;

    return 0;
}