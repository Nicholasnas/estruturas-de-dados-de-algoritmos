#include <iostream>

using namespace std;

int somatorio_fatorial(int n){
    if (n == 1)
        return 1;
    else
        return n + somatorio_fatorial(n-1);
}

int main(){
    int n;

    cout << "Somatorio de qual numero(0->N): ";
    cin >> n;
    
    cout << "O somatorio de " << n << ": " << somatorio_fatorial(n) << endl;

    return 0;
}