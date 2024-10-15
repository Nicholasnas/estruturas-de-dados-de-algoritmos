#include <iostream>
#include <list>
#define MAX_VERTICES 10
using namespace std;


struct Aresta{
	int origem, destino;
};


void dfs(list<Aresta>grafo[MAX_VERTICES], int vertices, int start, bool visitado[]){
	int destino;
	visitado[start] = true;
	list<Aresta>::iterator it;
	// cout aqui fica mais profundo
	for(it=grafo[start].begin();it!=grafo[start].end();it++){   
		destino = it->destino;
		if(!visitado[destino]){
		   	dfs(grafo,vertices, destino, visitado);
		}
	}

	// menos profundo, ordem de entrada de ajacencia.
	cout << start << endl;
	
	// ordem de inserção importa durante os testes
	// ordenação topologica para descobrir o no mais importante
	// dfs-
	
}
int main(){
	int vertices, origem, destino;
	cin >> vertices;
	
	list<Aresta>grafo[vertices];

	// criando as arestas de um grafo não direcionado
	while(cin >> origem >> destino && origem != -1 && destino != -1){
		grafo[origem].push_back({origem,destino});
		grafo[destino].push_back({destino, origem});
	}
	
	
	bool visitado[vertices];
	for(int i=0;i<vertices;i++){
		visitado[i] = false;
	}
	
	dfs(grafo, vertices,0, visitado);
	return 0;
}