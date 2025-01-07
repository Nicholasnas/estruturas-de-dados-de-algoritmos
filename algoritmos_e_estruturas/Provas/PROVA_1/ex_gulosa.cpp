#include <iostream>
#include <list>
using namespace std;

struct Dado{
    int id;
    float tamanho;
};

bool comparar(Dado d1, Dado d2){
    return d1.tamanho < d2.tamanho;
}
int main(){
    list<Dado>lista;
    list<Dado>::iterator it;
    list<int>::iterator p;
    int numero;
    float tamanho;
    list <int>escolhidos;
    float pendrive_tamanho = 15;


    for(int i=0;i<7;i++){
        cin >> numero >> tamanho;
        lista.push_back({numero, tamanho});
    }

    lista.sort(comparar);
    // lista ordenada
    cout << "lista ordenada: " << endl;
    for(it=lista.begin();it!=lista.end();it++){
        cout << it->id << " " << it->tamanho << endl;
    }


    // tentando pegar os arquivos mais espacos enquanto tiver espaco no pendrive
    for(it=lista.begin();it!=lista.end();it++){
        if(it->tamanho <= pendrive_tamanho){
            pendrive_tamanho -= it->tamanho;
            escolhidos.push_back(it->id);
        }
    }
    cout << "Arquivos escolhidos: ";
    for(p=escolhidos.begin();p!=escolhidos.end();p++){
        cout << *p << " ";  
    }
    cout << endl << "Tamanho disponivel: " << pendrive_tamanho;
    
    




    return 0;
}