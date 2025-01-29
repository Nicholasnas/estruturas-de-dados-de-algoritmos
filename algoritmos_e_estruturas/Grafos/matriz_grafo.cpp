#include <iostream>
#include <list>
#define MAX_VERTICES 10
using namespace std;

// precisa marcar o vertice como visitado
void bfs(int grafo[][MAX_VERTICES], int vertices, int origem){
    // controlar os vertices visitados
    bool visitados[vertices];

    list<int> fila_visitados;
    for(int i=0;i<vertices;i++){
        visitados[i] = false;
    }
    cout << origem << endl;
    visitados[origem] = true;

    // criar uma fila de visitação
    fila_visitados.push_back(origem);
    while(!fila_visitados.empty()){
        int atual = fila_visitados.front();
        fila_visitados.pop_front();

        // varrer os vizinhos do vértice atual
        for(int i=0; i < vertices; i++){
            if(grafo[atual][i] > 0 && !visitados[i]){  // Verifica se há uma aresta
                cout << i << endl;
                visitados[i] = true;
                fila_visitados.push_back(i);
            }
        }
    }
    // entender a topologia
    // verificar se o grafo é conexo pois foi possivel visitar todos os vertices

    // verificar se o grafo é conexo
    bool disconexo = false;
    for(int i = 0; i < vertices; i++){
        if(!visitados[i]){
            cout << "grafo disconexo" << endl;
            disconexo = true;
            break;
        }
    }

    if(!disconexo)
        cout << "grafo conexo" << endl;
}

int main(){
    int vertices, arestas;
    int origem, destino, peso;
    bool ponderado = false;

    cin >> vertices >> arestas;

    // inicializar o grafo com 0 (sem aresta)
    int grafo[vertices][vertices];

    // ler as arestas
    for(int i = 0; i < arestas; i++){
        cin >> origem >> destino >> peso;
        grafo[origem][destino] = peso;
        // Se o grafo for não direcionado
        grafo[destino][origem] = peso; // Verifica se algum peso é diferente de 1, indicando um grafo ponderado
        if (peso != 1) {
            ponderado = true;
        }
    }

    // Mostrar a matriz de adjacência
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }

    // Verificar se o grafo é ponderado ou não
    if (ponderado) {
        cout << "Grafo ponderado" << endl;
    } else {
        cout << "Grafo não ponderado" << endl;
    }

    bfs(grafo, vertices, 5);

    return 0;
}
