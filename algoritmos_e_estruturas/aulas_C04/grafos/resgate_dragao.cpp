#include <iostream>
#include <list>
#define MAX_VERTICES 10
#define INT_MAX 99999
using namespace std;

struct No{
    int origem;  // origem da aresta
    int destino;
    int peso; // caso a grafo seja ponderado

};

// precisa marcar o vertice como visitado
int bfs(list<No>grafo[], int vertices, int origem, int end){
    // controlar os vertices visitados
    bool visitados[vertices];
    list<No>::iterator it;
    list<int> fila_visitados;
    int distancia[vertices];

    // Inicializando os vetores de controle
    for(int i=0;i<vertices;i++){
        visitados[i] = false;
        distancia[i] = INT_MAX;
    }

    // Atribuindo os valores dos vertices de origem
    visitados[origem] = true;
    distancia[origem] = 0;

    // criar um fila de visitação
    fila_visitados.push_back(origem);

    while(!fila_visitados.empty()){
        int atual = fila_visitados.front();
        fila_visitados.pop_front();

        // varrer as salas vizinhas
        for(it=grafo[atual].begin();it != grafo[atual].end();it++){
            int dest = it->destino;
            if(!visitados[dest] && distancia[dest]==INT_MAX){
                // atualizar a distancia e marcar o vertice como visitado
                distancia[dest] = distancia[atual] + 1;
				visitados[dest] = true;
				fila_visitados.push_back(dest);
            }
        }
    }
    return distancia[end];
}


void mostrar_grafo(list<No> grafo[MAX_VERTICES], int vertices){
    list<No>::iterator it;

    for (int i=0;i<vertices;i++){
        for (it = grafo[i].begin();it!=grafo[i].end();it++){
            cout << it->origem  << " " << it->destino << " " << it->peso << endl;
        }   
    }
    
}
int main(){
    int salas, caminhos;
    int origem, destino, peso;
    int entrada, dragao;

    cin >> salas >> caminhos;

    list<No> grafo[salas];
    list<No>::iterator it;

    for(int i=0;i<caminhos;i++){
        cin >> origem >> destino;
        grafo[origem-1].push_back({origem-1,destino-1,0});
        grafo[destino-1].push_back({destino-1,origem-1,0});
    }
    cin >> entrada >> dragao;

    // mostrar_grafo(grafo, salas);
    int menor = bfs(grafo,salas, entrada-1, dragao-1);
    if(menor == INT_MAX){
        cout << "IMPOSSIVEL" << endl;
    }
    else{
        cout << menor + 1 << endl;
    }
    return 0;
}