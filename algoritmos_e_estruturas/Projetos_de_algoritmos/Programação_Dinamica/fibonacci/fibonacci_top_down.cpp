#include <iostream>
#define TAM 100

using namespace std;


int fibonacci_memoizacao(int n, int vetor[], int tam){

    if (vetor[n] == -1){
        vetor[n] = fibonacci_memoizacao(n-1, vetor, tam) + fibonacci_memoizacao(n-2, vetor, tam);
    }
    return vetor[n];
}

int main(){
    /*
    Toda vez que um problema é resolvido é salvo no array.
    return 1, se n == 1 ou n == 2
    return Fib(n-1) + Fib(n-2), se n > 2
    */
    int * vetor = new int[TAM];
    vetor[1] = 1;
    vetor[2] = 1;
    
    // Inicializando o array para os valores nao resolvidos
    for(int i=3;i<TAM;i++){
        vetor[i] = -1;
    }
    cout << "Fibonacci de " << 3 << ": "  << fibonacci_memoizacao(3, vetor, TAM) << endl;
    cout << "Fibonacci de " << 4 << ": " << fibonacci_memoizacao(4, vetor, TAM) << endl;
    cout << "Fibonacci de " << 5 << ": " << fibonacci_memoizacao(5, vetor, TAM) << endl;
    cout << "Fibonacci de " << 8 << ": " << fibonacci_memoizacao(8, vetor, TAM) << endl;
    cout << "Fibonacci de " << 9 << ": " << fibonacci_memoizacao(9, vetor, TAM) << endl;

    for(int i=0;i<TAM;i++){
        cout << vetor[i] << " ";
    }

    return 0;
}