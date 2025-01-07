#include <iostream>

using namespace std;

int busca_binaria_recursao(int vetor[], int target, int baixo, int alto){
    // caso base - nao encontrou o elemento
    if (baixo > alto)
        return -1;
    
    int meio = (alto + baixo) / 2; // calcular o meio do array
    int chute = vetor[meio];

    // Caso base - elemento encontrado
    if (chute == target)
        return meio; 

    if (chute > target)
    {
        alto = meio - 1;
        return busca_binaria_recursao(vetor,target, baixo, alto);
    }
    if (chute < target)
    {
        baixo = meio + 1;
        return busca_binaria_recursao(vetor,target, baixo, alto);
    }

}

void print_array(int array[], int tam){
    for (int i = 0; i < tam; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main(){
    int tam;
    
    while(true){
        cout << "Entre com o tamanho do vetor (-1 para sair): ";
        cin >> tam;
        if (tam == -1)
            break;
        
        if (tam <= 0){
            cout << "Tamanho inválido" << endl;
            continue;
        }

        int * array = new int[tam];
        int valor;
        int contador = 0;

        while (contador < tam){
            cout << "Entre com o valor: ";
            cin >> valor;

            array[contador] = valor;
            contador++;
        }
        int target;

        cout << "Entre com o elemento a ser procurado: ";
        cin >> target;

        int resultado = busca_binaria_recursao(array, target, 0, tam-1);
        if (resultado == -1)
            cout << "Elemento não encontrado" << endl;
        else{
            cout << "Elemento encontrado na posição " << resultado << endl;
        }
        print_array(array, tam);

        delete[] array;
    }
    return 0;
}
