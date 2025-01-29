#include <iostream>
#define TAM 100

using namespace std;


int fibonacci_button_up(int n){
    /*Fibonacci iterativo, comecando de um subproblema menor até o maior*/

   int vetor[TAM];
   for (int i= 0; i<TAM;i++){
    vetor[i] = -1;
   }

   vetor[0] = 0;
   vetor[1] = 1;
   vetor[2] = 1;

   for (int i=3;i <=n ;i++){
        vetor[i] = vetor[i-1] + vetor[i-2];
   }
   return vetor[n];
}

int main(){
    /*
    Toda vez que um problema é resolvido é salvo no array.
    return 1, se n == 1 ou n == 2
    return Fib(n-1) + Fib(n-2), se n > 2
    */
   cout << "Fibonacci de " << 6 << ": " << fibonacci_button_up(6) << endl;
   cout << "Fibonacci de " << 7 << ": " << fibonacci_button_up(7) << endl;   
   cout << "Fibonacci de " << 8 << ": " << fibonacci_button_up(8) << endl;   

  
    return 0;
}