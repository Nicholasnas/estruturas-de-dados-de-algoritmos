    #include<iostream>
    #include<list>

    #define MAX_VERTICES 10
    #define INT_MAX 9999

    using namespace std;

    struct Aresta {
        int origem, destino, peso;
    };

    void dijkstra(list<Aresta>grafo[], int vertices, int start){
        list<Aresta>::iterator it;
        bool visitados[vertices]; // controle para verificar se já foi visitado
        int distancia[vertices]; // distancia entre os vertices
        int parente[vertices]; // controle dos pais-parentes(origem)
        int aresta_atual;

        for(int i=0;i<vertices;i++){
            visitados[i] = false;
            distancia[i] = INT_MAX;
            parente[i] = -1;
        }

        distancia[start] = 0;
        aresta_atual = start;

        while(visitados[aresta_atual] == false){
            visitados[aresta_atual]= true; // marcar a primeira aresta da arvore
            for(it=grafo[aresta_atual].begin();it!=grafo[aresta_atual].end();it++){
                // pegando os dados dos vertices vizinhos
                int destino = it->destino;
                int peso = it->peso;
                // verificar se o peso atual no vertice de origem mais o peso
                // para chegar no vizinho é menor que o peso ja marcado no vertice vizinho
                if(peso + distancia[aresta_atual] < distancia[destino] && !visitados[destino]){
                    // adicionado o peso para chegar ao vizinho mais o peso do pai
                    distancia[destino] = peso + distancia[aresta_atual];
                    // marcando o pai
                    parente[destino] = aresta_atual;
                }
            }

            aresta_atual = 0;
            int dist = INT_MAX;
            // pegar o menor caminho entre os vertices nao visitados
            for(int i=0;i<vertices;i++){
                if(visitados[i] == false && dist > distancia[i]){
                    dist = distancia[i];
                    aresta_atual = i;
                }
            }

        }

        // saida de dados
        list<int>menor_caminho;
        for(int i=1;i<vertices;i++){
        cout << distancia[i] << endl;
        }
            
    }



    bool comparar(Aresta a1, Aresta a2){
        return a1.destino < a2.destino;
    }

    void mostrar_grafo(list<Aresta>grafo[MAX_VERTICES], int vertices){
        list<Aresta>::iterator it;
        cout << "################################ " << endl;
        for(int i = 0; i < vertices; i++)
        {
            cout << i << ": ";
            for(it=grafo[i].begin();it!=grafo[i].end();it++){
                cout << it->destino << " (" << it->peso << ") ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int main(){
        int salas, corredores, peso,origem, destino;
        cin >> salas >> corredores;
        
        list<Aresta> grafo[salas];
        list<Aresta>::iterator it;


        for(int i=0;i<corredores;i++){
            cin >> origem >> destino >> peso;
            grafo[origem].push_back({origem, destino, peso});
            grafo[destino].push_back({destino, origem, peso});
            
        }
       // mostrar_grafo(grafo, salas);

        // ordenando o array 
        for(int i = 0; i < salas; i++)
        {
            grafo[i].sort(comparar);
        }
        //mostrar_grafo(grafo, salas);
        
        dijkstra(grafo, salas, 0);

        return 0;
    }