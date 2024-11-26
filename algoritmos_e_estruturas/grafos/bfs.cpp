/// decidir se é ponderado ou não
#include <iostream>
#include <list>
using namespace std;

struct No{
    int origem;  // origem da aresta
    int destino;
    int peso; // caso a grafo seja ponderado

};

// precisa marcar o vertice como visitado
void bfs(list<No>grafo[], int vertices, int origem){
    // controlar os vertices visitados
    bool visitados[vertices];
    list<No>::iterator it;
    list<int> fila_visitados;

    for(int i=0;i<vertices;i++){
        visitados[i] = false;
    }
    visitados[origem] = true;

    // criar um fila de visitação
    fila_visitados.push_back(origem);

    while(!fila_visitados.empty()){
        int atual = fila_visitados.front();
        // varrer os vizinhos dela agora
        fila_visitados.pop_front();
        cout << atual << endl;
        for(it=grafo[atual].begin();it != grafo[atual].end();it++){
            int dest = it->destino;
            
            if(!visitados[dest]){
                cout << atual << " " <<  dest << endl;
				visitados[dest] = true;
				fila_visitados.push_back(dest);

            }
        }
        }
        fila_visitados.pop_front();

    }

  
int main(){
    int vertices, vertice_inicial;
    int origem, destino, peso;

    cin >> vertices >> vertice_inicial;

    list<No> grafo[vertices];
    list<No>::iterator it;

    while(true){
        cin >> origem >> destino >> peso;

        if(origem == -1 && destino == -1 && peso == -1){
            break;
        }
        grafo[origem].push_back({origem, destino, peso});
        grafo[destino].push_back({destino, origem, peso}); 
    }
    // mostrar grafo
    for(int i=0;i<vertice_inicial;i++){
        for (it = grafo[i].begin();it!= grafo[i].end();it++){
            cout << it->origem << it->destino << endl;
        }

    }
    bfs(grafo, vertices, vertice_inicial);


    return 0;
}