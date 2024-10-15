#include<iostream>
#include<list>

#define MAX_VERTICES 10

using namespace std;

struct Aresta {
	int origem, destino, peso;
};


int main(){
	int vertices, origem, peso, destino, orientado;
	cin >> vertices >> orientado;
	
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
       
    for(int i=0;i<vertices;i++){
        for(it=grafo[i].begin();it!=grafo[i].end();it++){
            cout << it->origem << " " <<  it->destino << " " << it->peso << endl;
        }
    }
    
	return 0;
}