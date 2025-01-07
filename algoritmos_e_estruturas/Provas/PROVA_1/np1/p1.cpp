#include<iostream>
#include<string>
#include<list>
using namespace std;

#define INT_MAX 99999

struct Estrada{
	int orig;
	int dest;
	int distancia;
};


struct Cidade {
	string nome;
	int codigo;
	float idh;
	list<Estrada> vizinhos;
};

int shortest_path_dijkstra(Cidade cidades[], int vertices, int start, int end, float idh){
	bool intree[vertices];
	int distance[vertices], parent[vertices];
	
	for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
	}
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
		list<Estrada>::iterator p;
		list<Estrada> adj = cidades[v].vizinhos;
    	for(p = adj.begin(); p != adj.end(); p++){
            int dest = p->dest;
            int weight = p->distancia;
            if(distance[dest] > distance[v]+weight && cidades[v].idh > idh){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
			}
		}
        v = 0;
        int dist = INT_MAX;
        for(int u = 0; u < vertices; u++){
            if(intree[u]==false && dist>distance[u]){
                dist = distance[u];
                v = u;
			}
		}
	}
	return distance[end];
}

int main(){
	
	int num_cidades;
	cin >> num_cidades;
	
	Cidade cidades[num_cidades];
	
	for(int i=0; i< num_cidades; i++){
		cidades[i].codigo = i;
		cin >> cidades[i].nome;
		cin >> cidades[i].idh;
	}
	
	int num_estradas, origem, destino, distancia;
	cin >> num_estradas;
	
	for(int j=0; j < num_estradas; j++){
		cin >> origem;
		cin >> destino;
		cin >> distancia;
		cidades[origem].vizinhos.push_back({origem, destino, distancia});
		cidades[destino].vizinhos.push_back({destino, origem, distancia});
	}
	
	float idh;
	
	cin>>origem>>destino>>idh;
	
	cout << shortest_path_dijkstra(cidades, num_cidades,origem, destino, idh) << endl;

}

// Poles está desenvolvendo uma árvore de habilidades para o seu jogo de RPG. 
//Ele quer que os personagens possam escolher, partindo de uma habilidade principal, 
//algumas ramificações possíveis. 
// Para cada upgrade de habilidade, o personagem deve gastar alguns pontos de experiência 
//e pode adquirir alguma pontuação de poder.
// Ele quer saber, dada um determinada árvore de habilidadades, qual é o custo mínimo de 
//experiência para ter um determinado valor de poder.

// Entrada
// A entrada começa com um número inteiro indicando a quantidade H de habilidades. 
//As H linhas seguintes contêm o nome (palavra) e o poder (número real) de cada habilidade
//(cada habilidade tem um código automático de 0 a H de acordo com a entrada de dados).
// Em seguida é informado um valor inteiro indicando a quantidade U de upgrades possíveis. 
//As U linhas seguintes contêm três inteiros indicando o código da habilidade origem, o 
//código da habilidade destino e o custo de cada upgrade.
// Por fim, é informado um número real que é o valor de poder desejado.

// Saída
// A saída é um número inteiro indicando o custo mínimo para se conseguir o nível de poder desejado. 
