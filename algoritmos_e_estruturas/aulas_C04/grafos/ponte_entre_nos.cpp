#include <list>
#include <iostream>
#define MAX_VERTICES 10
using namespace std;


struct Cidade{
    int origem;
    int destino;
    int peso;
};

void bfs(bool grafo[][MAX_VERTICES], int vertices, int origem){
    // controlar os vertices visitados
    bool visitados[vertices];
    list<int> fila_visitados;
    
    //Inicializar os vertices visitados
    for(int i=0;i<vertices;i++){
        visitados[i] = false;
    }
    // pegar o no de origem e marcar como visitado
    visitados[origem] = true;

    // criar um fila de visitação e adicionar o no de origem
    fila_visitados.push_back(origem);

    while(!fila_visitados.empty()){
        int atual = fila_visitados.front();
        fila_visitados.pop_front();
        // varrer os vizinhos(filhos) e se ele ja foi visitado
        for(int i=0;i<vertices;i++){
            if(grafo[atual][i] && !visitados[i]){
                    visitados[i] = true;
                    fila_visitados.push_back(i);
            }
        }
    }

    for(int i=0;i<vertices;i++){
        if(!visitados[i]){
            cout << i+1 << " ";
        }
    }

}

int main(){
    int cidades, caminhos;
    int origem, destino;
    
    cin >> cidades >> caminhos;

    bool grafo[MAX_VERTICES][MAX_VERTICES];

    // inicializar o grafo 1 -> 4
    for(int i=0;i<cidades;i++){
        for (int j=0;j<cidades;j++){
            grafo[i][j] = false;
        }
    }
    // Entrada de dados para os caminhos entre cidades
    for(int i=0;i<caminhos;i++){
        cin >> origem >> destino;
        grafo[origem-1][destino-1] = true;
        grafo[destino-1][origem-1] = true;
    }

    // removendo o caminho do grafo
    int x, y;
    cin >> x >> y;

    grafo[x-1][y-1] = false;
    grafo[y-1][x-1] = false;


    bfs(grafo, cidades, 0);

 return 0;
}
