#include <iostream>
#include <list>
#define MAX_VERTICES 10
using namespace std;

struct No{
    int origem;  // origem da aresta
    int destino;
    int peso; // caso a grafo seja ponderado

};
void cria_aresta(list<No> grafo[], int u, int v, int p, int orientado){

    if (orientado == 0){
        grafo[u].push_back({u, v, p});
        grafo[v].push_back({v, u, p}); 
    }
    else{
        grafo[u].push_back({u,v,p});
    }
    
    }
void mostrar_grafo(list<No> grafo[], int vertices){
    list<No>::iterator it;

    for (int i=0;i<vertices;i++){
        for (it = grafo[i].begin();it!=grafo[i].end();it++){
            cout << it->origem  << " " << it->destino << " " << it->peso << endl;
        }   
    }
    
}
int main(){
    int vertices;
    int origem, destino, peso;
    int orientado;

    cin >> vertices >> orientado;

    list<No> grafo[vertices];
    list<No>::iterator it;


    // inserir os dados
    // ler o par de vertices que esta conectado

    while(true){
        cin >> origem >> destino >> peso;

        if(origem == -1 && destino == -1 && peso == -1){
            break;
        }
        cria_aresta(grafo, origem, destino, peso, orientado);    
    }
    mostrar_grafo(grafo, vertices);
    return 0;
}