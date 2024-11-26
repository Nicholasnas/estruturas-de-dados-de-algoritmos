#include <iostream>
#include <list>
using namespace std;

int main(){
    int cidades, caminhos;
    int origem, destino;

    cin >> cidades >> caminhos;

    // inicializar o grafo com 0 (sem aresta)
    int grafo[cidades][cidades];

    for(int i=0;i<cidades;i++){
        for(int j=0;j<cidades;j++){
            grafo[i][j] = 0;
        }
    }

    for(int i = 0; i < caminhos; i++){
        cin >> origem >> destino;
        grafo[origem-1][destino-1] = 1;
        grafo[destino-1][origem-1] = 1;

    }

    // Mostrar a matriz de adjacência
    for (int i = 0; i < cidades; i++) {
        for (int j = 0; j < cidades; j++) {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
