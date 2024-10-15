#include<iostream>
#include<list>

#define MAX_VERTICES 10
#define INT_MAX 9999

using namespace std;

struct Aresta {
	int origem, destino, peso;
};

void prim(list<Aresta>grafo[], int vertices, int start){
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
            int destino = it->destino;
            int peso = it->peso;
            if(peso < distancia[destino] && !visitados[destino]){
                distancia[destino] = peso;
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

	cout<<"Arvore Geradora Minima:"<<endl;
	for(int i=0; i<vertices; i++){
		if(parente[i] != -1)			
	        cout<<parente[i]<<" "<<i<<endl;
	    custo+=distancia[i];
	}
	cout<<"Custo: "<<custo <<endl;
		
    
}


int main(){
	int vertices, origem, peso, destino, orientado, vertice_inicial;
	cin >> vertices >> orientado >> vertice_inicial;
	
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
    prim(grafo, vertices, vertice_inicial);

    
	return 0;
}