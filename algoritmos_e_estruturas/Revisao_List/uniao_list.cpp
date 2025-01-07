#include <iostream>
#include <list>

using namespace std;


void uniao(list<int> lista1, list<int> lista2)
{

    list<int>::iterator p;
    list<int>::iterator i;
    list<int> lista3;
    int primeiro;
    bool existe;


     for(p = lista1.begin();p!= lista1.end();p++){
        primeiro = *(p);
        lista3.push_back(primeiro);
     }
     
    for(i= lista2.begin();i!= lista2.end();i++){
        primeiro = *(i);
        existe = false;
        for(p = lista3.begin();p!= lista3.end();p++){
            if (*(p)  == primeiro){
                existe = true;
                break;
            }
        }
        if(!existe){
            lista3.push_back(primeiro);
        }
     }
     lista3.sort();
    for(p = lista3.begin();p!= lista3.end();p++){
        cout << *p << " ";
    }
    cout << endl;

}
int main()
{

    list<int> lista1;
    list<int> lista2;
    int valor;


    // cout << "Entre com os valores da lista 1: " << endl;
    while(true){
        cin >> valor;
        if (valor == 0){
            break;
        }
        lista1.push_back(valor);
    }
    // cout << "Entre com os valores da lista 2: " << endl;
     while(true){
        cin >> valor;
        if (valor == 0){
            break;
        }
        lista2.push_back(valor);
    }

    uniao(lista1, lista2);

    return 0;
}