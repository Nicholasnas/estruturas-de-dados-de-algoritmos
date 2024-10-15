#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct No{
	int origem, destino, peso;
};


void mostrar_grafo(vector<No>grafo[], int vertices){
	vector<No>::iterator it;
	for(int i=1;i<vertices+1;i++){
    	cout << i << ": ";
		for(it=grafo[i].begin();it!=grafo[i].end();it++){
			cout << it->destino << "; ";
		}
		cout << endl;
	}
}
// Função de comparação para ordenar os nós pelo destino
// retorna true se o destino da primeira for menor do que a segunda
// funcao sort usara isso para ordenar

bool ordenarPorDestino(No aresta1, No aresta2) {
    return aresta1.destino < aresta2.destino;
}

void cidades_conectadas(vector<No>grafo[], int vertices){
	vector<No>::iterator it;
	int cont_vertices[vertices];
	int soma;
	
	for(int i=0;i<vertices+1;i++){
		soma=0;
		for(it=grafo[i].begin();it!=grafo[i].end();it++){
			soma++;
		}
		cont_vertices[i] = soma;
	}
	for(int i=1;i<vertices+1;i++){
		cout << cont_vertices[i] << " ";
		for(it=grafo[i].begin();it!=grafo[i].end();it++){
			cout << it->destino << " ";
		}
		cout << endl;
	}
	}

int main(){
    int vertices, arestas;
    int origem, destino;

    cin >> vertices >> arestas;
    // cout << vertices << arestas<< endl;
    vector<No> grafo[vertices+1];
    // Entradas de cidades
    for(int i=0;i<arestas;i++){
        cin >> origem >> destino;
        grafo[origem].push_back({origem, destino, 0});
        grafo[destino].push_back({destino, origem, 0}); 
    }
    // ordenando o vector do grafo
	for(int i=1;i<=vertices;i++){
		sort(grafo[i].begin(), grafo[i].end(),ordenarPorDestino);
	}
  	// mostrar_grafo(grafo, vertices);
    cidades_conectadas(grafo, vertices);

    return 0;
}