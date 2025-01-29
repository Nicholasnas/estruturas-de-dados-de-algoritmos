#include <iostream>

using namespace std;


int main(){
    int linhas = 4;
    int colunas = 3;
    /*
    Cria um array de ponteiros para as linhas
    cada linha sera um array de inteiros
    */
    int ** matriz = new int *[linhas];
    
    for (int i=0;i < linhas;i++){
        matriz[i] = new int[colunas];
    }

    // Preenche a matriz com valores
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = 0; // Exemplo de inicialização
        }
    }
    cout << "Matriz preenchida:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}