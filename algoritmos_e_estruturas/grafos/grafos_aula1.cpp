/// decidir se é ponderado ou não
#include <iostream>

using namespace std;

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



    return 0;
}