#include<iostream>
#include<list>

#define MAX_VERTICES 10

using namespace std;

struct Aresta {
	int origem, destino, peso;
};

void bfs(list<Aresta> grafo[], int vertices, int origem){
	bool visitado[vertices];
	list<int> fila_visitacao;
	list<Aresta>::iterator it;
	
	for(int i=0; i<vertices; i++)
		visitado[i] = false;

	// cout<<origem<<endl;
	visitado[origem] = true;
	fila_visitacao.push_back(origem);
	
	while(!fila_visitacao.empty()){
		int atual = fila_visitacao.front();

        for(it = grafo[atual].begin(); it != grafo[atual].end(); it++){
            
            int i = it->destino;
            if(!visitado[i]){
                    // cout<<i<<endl;
                    visitado[i] = true;
                    fila_visitacao.push_back(i);
                }
		}
		fila_visitacao.pop_front();
	}
	bool disconexo = false;
	for(int i=0; i<vertices; i++){
		if(!visitado[i]){
			cout<<"Nao conexo"<<endl;
			disconexo = true;
			break;
		}
	}
	if(!disconexo)
		cout<<"Conexo"<<endl;
}


int main(){
	int vertices, inicial, origem, destino;
	cin >> vertices >> inicial;
	
	list<Aresta> grafo[vertices];
	list<Aresta>::iterator it;

	while(true){
		cin >> origem >> destino;
		if(origem == -1 && destino == -1){
			break;
		}
		grafo[origem].push_back({origem, destino, 1});
		grafo[destino].push_back({destino, origem, 1});
	}
       
	bfs(grafo, vertices, inicial);
    
	return 0;
}