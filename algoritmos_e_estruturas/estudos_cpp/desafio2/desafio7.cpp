#include <iostream>

using namespace std;

int main(){

    int linha, coluna;

    cout << "Entre com o valor da linha: " << endl;
    cin >> linha;
    cout << "Entre com o valor da coluna: " << endl;
    cin >> coluna;

    int matriz1[linha][coluna], matriz2[linha][coluna],  soma[linha][coluna], valor;
    

    for (int i = 0;i< linha;i++){
        for(int j=0; j<coluna;j++){
            cout << "Entre com o valor (" << i << ", " << j << "): ";
            cin >> valor;
            matriz1[i][j] = valor;
        }
    }

    for (int i=0;i< linha;i++){
        for(int j=0; j<coluna;j++){
            cout << "Entre com o valor (" << i << ", " << j << "): ";
            cin >> matriz2[i][j];
        }
    }
    for (int i=0;i< linha;i++){
        for(int j=0; j<coluna;j++){
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

     for (int i=0;i< linha;i++){
        for(int j=0; j<coluna;j++){
            cout << soma[i][j] << " ";
        }
        cout << endl;
    }



}