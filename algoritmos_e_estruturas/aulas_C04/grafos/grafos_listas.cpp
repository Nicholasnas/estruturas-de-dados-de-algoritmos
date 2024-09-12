/// decidir se é ponderado ou não
#include <iostream>
#include <list>
#define MAX_VERTICES 10
using namespace std;

struct Aresta{
    int origem;  // da onda sai a aresta
    int destino;
    int peso; // caso a grafo seja ponderado

};
// precisa marcar o vertice como visitado
void bfs(list<Aresta>grafo[], int vertices, int origem){
    // controlar os vertices visitados
    bool visitados[vertices];
    list<Aresta>::iterator it;
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

        for(it = grafo[atual].begin();it!= grafo[atual].end();it++){
            int dest = (*it).destino;
            
            if(!visitados[dest]){
                cout<<dest<<endl;
				visitados[dest] = true;
				fila_visitados.push_back(dest);

            }
            cout << it->destino << ", ";
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
            break;
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
    // bool grafo[vertices][vertices];
    list<Aresta> grafo[vertices];
    list<Aresta>::iterator it;


    // inserir os dados
    // ler o par de vertices que esta conectado
    for(int i=0;i<arestas;i++){
        // verificar a entrada caso a entrada seja maior que a matriz
        // pode ter peso da conecção
        cin >> origem >> destino;
        // // grafo nao direcionado- poder ir para as duas direcoes
        // grafo[origem][destino] = true;

        // // caso seja direcionado nao faz isso
        // grafo[destino][origem] = true;
        
        grafo[origem].push_back({origem, destino, 0});
        grafo[destino].push_back({destino, origem, 0}); 

    }


      for (int i=0;i<vertices;i++){
        cout << "Vertices atual " << i << ": ";
        for(it = grafo[i].begin();it!= grafo[i].end();it++){

            cout << (*it).destino << ", ";
            // cout << it->destino << " "; /// pondeiro acessar o atributo de um ponteiro

        }
        cout << endl;
        }

    return 0;
}