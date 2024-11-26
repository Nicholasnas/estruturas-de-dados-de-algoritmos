#include<iostream>
#include<list>

#define MAX_VERTICES 10
#define INT_MAX 9999

using namespace std;

struct Aresta {
	int origem, destino, peso;
};

int dijkstra(list<Aresta>grafo[], int vertices, int start, int end){
    list<Aresta>::iterator it;
    bool visitados[vertices]; // controle para verificar se já foi visitado
    int distancia[vertices]; // distancia entre os vertices
    int parente[vertices]; // controle dos pais-parentes(origem)
    int aresta_atual;

    for(int i=0;i<vertices;i++){
        visitados[i] = false;
        distancia[i] = INT_MAX;
        parente[i] = -1;
    }

    distancia[start] = 0;
    aresta_atual = start;

    while(visitados[aresta_atual] == false){
        visitados[aresta_atual]= true; // marcar a primeira aresta da arvore
        for(it=grafo[aresta_atual].begin();it!=grafo[aresta_atual].end();it++){
            // pegando os dados dos vertices vizinhos
            int destino = it->destino;
            int peso = it->peso;
            // verificar se o peso atual no vertice de origem mais o peso
            // para chegar no vizinho é menor que o peso ja marcado no vertice vizinho
            if(peso + distancia[aresta_atual] < distancia[destino] && !visitados[destino]){
                // adicionado o peso para chegar ao vizinho mais o peso do pai
                distancia[destino] = peso + distancia[aresta_atual];
                // marcando o pai
                parente[destino] = aresta_atual;
            }
        }

        aresta_atual = 0;
        int dist = INT_MAX;
        // pegar o menor caminho entre os vertices nao visitados
        for(int i=0;i<vertices;i++){
            if(visitados[i] == false && dist > distancia[i]){
                dist = distancia[i];
                aresta_atual = i;
            }
        }

    }
    return distancia[end];
		
}

int main(){
	int vertices, origem, peso, destino, arestas;
    int start, end;
	cin >> vertices >> arestas;
	
	list<Aresta> grafo[vertices];
	list<Aresta>::iterator it;

    for(int i=0;i<arestas;i++){
        cin >> origem >> destino >> peso;

        grafo[origem-1].push_back({origem-1, destino-1, peso});
        grafo[destino-1].push_back({destino-1, origem-1, peso}); 

    }
    cin >> start >> end;
    cout << dijkstra(grafo, vertices, start-1, end-1);

    
	return 0;
}
