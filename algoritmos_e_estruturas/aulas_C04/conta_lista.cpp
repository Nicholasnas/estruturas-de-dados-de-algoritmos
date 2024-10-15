#include <iostream>
#include <list>

using namespace std;


int conta(list<int> lista){
    return lista.size();
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

    cout << conta(lista) << endl;

    return 0;
}