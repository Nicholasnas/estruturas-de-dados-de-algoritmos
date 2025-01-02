#include <iostream>

using namespace std;

int busca_binaria(int lista[], int tam, int target){
    int baixo = 0;
    int alto = tam -1;
    int meio, chute;

    while (baixo <= alto){
        meio = (baixo + alto) / 2;
        chute = lista[meio];
        if (chute == target)
            return chute; // retorna o endereco do item
        if (chute > target)
            alto = meio - 1;
        else
            baixo = meio + 1;
    }
    return -1;
}

int main(){

    int lista[5] = {2,4,6,8,10};
    int tam = 5;


    while (true){

        cout << 
        cout << "Lista: [ ";
        for (int i=0; i<5; i++){
            cout << lista[i] << " " ;
        }
        cout << "]" << endl;

        cout << busca_binaria(lista, tam, 3);
    }

}
