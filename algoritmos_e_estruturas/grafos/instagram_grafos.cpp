/// decidir se é ponderado ou não
#include <iostream>
#include <list>
using namespace std;

struct No{
    int origem;  // origem da aresta
    int destino;
    int peso; // caso a grafo seja ponderado

};

int main(){
    int usuarios;
    int origem, destino;
    int pessoa;
    cin >> usuarios ;
    cin.ignore();
    string nomes[usuarios];

    list<No> grafo[usuarios];
    list<No>::iterator it;

    // Entrada dos nomes dos usuarios
    for(int i=0;i<usuarios;i++){
        getline(cin, nomes[i]);
    }

    for(int i=0;i<usuarios;i++){
        while(true){
            cin >> destino;
            if(destino == -1){
                break;
            }
            grafo[i].push_back({i, destino, 0});
        }


    }
    cout << "grafo: " << endl;
    for(int i=0;i<usuarios;i++){
        cout << i << " ";
        for (it = grafo[i].begin();it!= grafo[i].end();it++){
            cout << it->destino << " ";
            }
        cout << endl;
        }

    cout << endl;
    // saida de dados
    cin >> pessoa;
    for (it = grafo[pessoa-1].begin();it!= grafo[pessoa-1].end();it++){
            cout << nomes[it->destino] << endl;
        }
    
    return 0;
}