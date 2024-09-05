#include <iostream>
#include <cmath>

using namespace std;

int main(){

    float b, resultado;
    int n;
    string continua = "sim";
    do{
        resultado = 1;
        cout << "Entre com valor de B e do N: " << endl;
        cin >> b >> n;

        for (int i = 0 ;i < n; i++)
        {
            resultado *= b;
        }
        cout << resultado << endl;
        cout << "Deseja continuar calculando? sim ou nao ";
        cin >> continua;
    }while (continua == "sim");


    return 0;
}