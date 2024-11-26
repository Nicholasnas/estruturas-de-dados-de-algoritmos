#include <iostream>
#include <list>
#define MAX_VERTICES 10
using namespace std;


struct Aresta{
    int origem, destino;
};

void dfs_visit(list<Aresta> grafo[], int u, bool visitado[], int &tempo, int distance[], int f[], list<int> fila) {
    visitado[u] = true; 
    distance[u] = tempo + 1;  // Incrementa tempo ao visitar
    list<Aresta>::iterator it;
    for (it = grafo[u].begin(); it != grafo[u].end();it++) {
        int destino = it->destino;
        if (!visitado[destino]) {
            dfs_visit(grafo, destino, visitado, tempo, distance, f, fila);
        }
    }
    f[u] = tempo + 1;    // Incrementa tempo ao terminar o nó
    fila.push_front(u);  // Adiciona o nó à fila na ordem inversa de finalização
}

void dfs(list<Aresta> grafo[], int vertices, int f[], bool visitado[]) {
    int distance[vertices], tempo = 0; 
    list<int> fila; 

    for (int i = 0; i < vertices; i++) {
        if (!visitado[i]) {
            dfs_visit(grafo, i, visitado, tempo, distance, f, fila);
        }
    }

    // Preenche o array f[] com a ordem topológica
    int aux = 0;
    while (!fila.empty()) {
        aux += 1;
        f[aux] = fila.front();
        fila.pop_front();
    }
}

// Função para mostrar a ordenação topológica
void ordenacao_topologica(int f[], int nVertices) {
    for (int i = 0; i < nVertices; i++) {
        cout << f[i] << " ";
    }
    cout << endl;
}

int main() {
    int vertices, orientado;
    int origem, destino;
	
    cin >> vertices >> orientado;

    list<Aresta> grafo[vertices];

    if (orientado == 1) {
        // Grafo orientado
        while(cin >> origem >> destino && origem != -1 && destino != -1) {
            grafo[origem].push_back(destino); // Aresta orientada
        }
    } else {
        // Grafo não orientado
        while(cin >> origem >> destino && origem != -1 && destino != -1) {
            grafo[origem].push_back(destino); // Aresta não orientada
            grafo[destino].push_back(origem); // Adiciona a aresta reversa
        }
    }
	
    int f[vertices]; // Armazena a ordenação topológica
    
    bool visitado[vertices];
    for(int i = 0; i < vertices; i++) {
        visitado[i] = false;
    }
    
    // Executa o DFS para encontrar a ordenação topológica
    dfs(grafo, vertices, f, visitado);

    // Exibe a ordenação topológica
    ordenacao_topologica(f, vertices);

    return 0;
}
