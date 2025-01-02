#include<iostream>
#include<list>

#define MAX_VERTICES 10
#define INT_MAX 9999

using namespace std;

struct Aresta {
	int origem, destino, peso;
};

void dijkstra(list<Aresta>grafo[], int vertices, int start, int end){
    list<Aresta>::iterator it;
    bool visitados[vertices]; // controle para verificar se já foi visitado
    int distancia[vertices]; // distancia entre os vertices
    int parente[vertices]; // controle dos pais-parentes(origem)
    int custo = 0;
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

    // saida de dados
    list<int>menor_caminho;

    int aux = end;
    while(aux != start){
        menor_caminho.push_front(aux);
        aux = parente[aux];
    }
    cout << "Menor caminho: "<< start;
    while(!menor_caminho.empty()){
        cout <<  " " << menor_caminho.front();
        menor_caminho.pop_front();
    }
	cout <<"\nCusto: "<< distancia[end];
		
}

int main(){
	int vertices, origem, peso, destino, orientado, vertice_inicial, end;
	cin >> vertices >> orientado >> vertice_inicial >> end;
	
	list<Aresta> grafo[vertices];
	list<Aresta>::iterator it;

	while(true){
		cin >> origem >> destino >> peso;
		if(origem == -1 && destino == -1 && peso == -1){
			break;
		}
        if(orientado == 0){
            grafo[origem].push_back({origem, destino, peso});
            grafo[destino].push_back({destino, origem, peso});

        }
        else{
            grafo[origem].push_back({origem, destino, peso});
            }
	}
    dijkstra(grafo, vertices, vertice_inicial, end);

    
	return 0;
}
