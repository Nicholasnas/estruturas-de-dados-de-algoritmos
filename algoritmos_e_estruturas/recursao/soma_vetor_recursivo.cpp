#include <iostream>

using namespace std;


int soma(int vetor[], int tam, int n){
    if (n == tam) 
        return 0;
    else 
        return vetor[n] + soma(vetor, tam, n+1);

}

int main()
{

    int vetor[] = {2, 4, 6, 8};

    cout << "A soma dos elementos do vetor eh: " << soma(vetor, 4, 0);

    return 0;
}