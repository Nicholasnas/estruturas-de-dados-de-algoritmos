#include <iostream>
#include <list>

using namespace std;


int soma(list<int> lista){
    list<int>::iterator p;
    int resultado = 0;

    for(p=lista.begin(); p != lista.end();p++){
        resultado += *(p);
    }
    return resultado;
}
int main(){

    list<int> lista;
    int valor;

    do{
        cin >> valor;
        if(valor != 0){
            lista.push_back(valor);
        }
    }while(valor != 0);

    cout << soma(lista) << endl;

    return 0;
}