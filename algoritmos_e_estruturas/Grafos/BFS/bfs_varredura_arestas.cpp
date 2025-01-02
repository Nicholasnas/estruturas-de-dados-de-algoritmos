/// decidir se é ponderado ou não
#include <iostream>
#include <list>
#define MAX_VERTICES 10
using namespace std;


// precisa marcar o vertice como visitado
void bfs(bool grafo[][MAX_VERTICES], int vertices, int origem){
    // controlar os vertices visitados
    bool visitados[vertices];

    list<int> fila_visitados;
    for(int i=0;i<vertices;i++){
        visitados[i] = false;
    }
    cout << origem << endl;
    visitados[origem] =true;

    // criar um fila de visitação
    fila_visitados.push_back(origem);

    while(!fila_visitados.empty()){
        int atual = fila_visitados.front();
        // varrer os vizinhos dela agora

        for(int i=0;i<vertices;i++){
            if(grafo[atual][i] && !visitados[i]){
                    cout << i << endl;
                    visitados[i] = true;
                    fila_visitados.push_back(i);
                
            }
        }
        fila_visitados.pop_front();

    }
    // entender a topologia
    // verificar se o grafo é conexo pois foi possivel visitar todos os vertices

    bool disconexo = false;

    for(int i =0;i<vertices;i++){
        if(!visitados[i]){
            cout << "grafo disconexo" << endl;
            disconexo = true;
        }
    }

    if(!disconexo)
        cout << "grafo conexo" << endl;


    // fazer os exercicios de grafos
}
int main(){
    int vertices, arestas;
    int origem, destino;

    cin >> vertices >> arestas;
    /// aresta que liga os nos entre eles

    // inicializar o grafo
    bool grafo[vertices][vertices];
    for (int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            grafo[i][j] = false;    
        }
    }

    // ler o par de vertices que esta conectado

    for(int i=0;i<arestas;i++){
        // verificar a entrada caso a entrada seja maior que a matriz
        // pode ter peso da conecção
        cin >> origem >> destino;
        // grafo nao direcionado- poder ir para as duas direcoes
        grafo[origem][destino] = true;

        // caso seja direcionado nao faz isso
        grafo[destino][origem] = true;
    }


    for (int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){

            cout << grafo[i][j] << " ";
        }
        cout << endl;
        }
    
    bfs(grafo,vertices, 5);


    return 0;
}
