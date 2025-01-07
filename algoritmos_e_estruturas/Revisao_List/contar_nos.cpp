#include <iostream>
#include <list>

using namespace std;


int contar(list<int> lista){
    return lista.size();
}
int main(){

    list<int> lista;

    int valor;

    while(true){
        cin >> valor;
        if (valor == 0){
            break;
        }
        lista.push_back(valor);
    }
    cout << contar(lista) << endl;
    return 0;
}