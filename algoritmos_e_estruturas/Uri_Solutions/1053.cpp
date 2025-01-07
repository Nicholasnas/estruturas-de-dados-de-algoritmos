#include <iostream>
#include <list>
#include <cmath>
using namespace std;

struct No{
    char origem[2], destino[2];
    float peso;
};

void mostrar_grafo(list<No>grafo[], int vertices){
	list<No>::iterator it;
	for(int i=1;i<vertices+1;i++){
    	cout << i << ": ";
		for(it=grafo[i].begin();it!=grafo[i].end();it++){
			cout << it->destino << "; ";
		}
		cout << endl;
	}
}

int main(){
    int vertices, arestas;
    char origem[2], destino[2];
    int total_casos;
    
    cin >> total_casos;

    while(total_casos != 0){
        cin >> vertices;
        list<No> grafo[vertices];

        for(int i=0;i<vertices;i++){
            cin >> origem >> destino;
            No coordenada;
        
            coordenada.origem = origem;
            coordenada.destino = destino;

            float peso = sqrt(pow(origem[0] - destino[0], 2) + pow(origem[1] - destino[1], 2));
            coordenada_origem.peso = peso;

            grafo[i].push_back(coordenada_origem);
        }
    }

    return 0;
}