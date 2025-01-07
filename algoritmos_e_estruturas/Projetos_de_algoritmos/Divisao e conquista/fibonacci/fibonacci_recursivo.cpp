#include <iostream>

using namespace std;

// 1 2 3 4 5 6 7  8  9 10 11 12
// 0 1 1 2 3 5 8 13 21 34 55 89 

int fibonacci(int n){
    if (n == 1)
        return 0;
    else{
        if (n==2)
            return 1;
        else
            return fibonacci(n-1) + fibonacci(n-2);
    }
}


int main(){
    int n;
    
    cout << "Entre com o valor a ser calculado: ";
    cin >> n;
    
    cout << "Fibonacci: " << n << ": " << fibonacci(n) << endl;

    return 0;
}