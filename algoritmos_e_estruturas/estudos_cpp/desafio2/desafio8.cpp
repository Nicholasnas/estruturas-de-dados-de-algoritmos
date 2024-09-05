#include <iostream>

using namespace std;

int main(){
    int tam;
    bool continua = true;
    float valor;
    string opcao;
    
    while(continua){
        cout << "Entre com tamanho do vetor: ";
        cin >> tam;
        float* vetor = new float[tam];
        
        for (int i =0;i < tam;i++){
            cout << "Entre com o valor (" << i << "): ";
            cin >> vetor[i];
        }
        // mostrando o vetor
        for (int i =0;i < tam;i++){
            cout << vetor[i] << " "; 
        }
        cout << endl;

        cout << "Deseja entrar com outro vetor: (sim ou nao) ";
        cin >> opcao;

        delete [] vetor;

        if (opcao == "sim" || opcao == "SIM"){
            continue;
        }
        else{
            cout << "Fim!" << endl;
            break;
        }
    }
}