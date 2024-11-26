#include <iostream>

using namespace std;

struct Implante
{
    string nome;
    string fabricante;
    int tier;
    float taxa_psicose;
};

int main(){
    int qtd_implantes;
    cin >> qtd_implantes;

    Implante * implantes = new Implante[qtd_implantes];

    float aux_soma_verifica = 0;

    for(int i=0;i<qtd_implantes;i++){
        cin >> implantes[i].nome;
        cin >> implantes[i].fabricante;
        cin >> implantes[i].tier;
        cin >> implantes[i].taxa_psicose;
        aux_soma_verifica += implantes[i].taxa_psicose;
    }
    
    if(aux_soma_verifica < 60){
        cout << "Vamos tchum! Temos uma cidade pra conquistar!" << endl;
    }
    else{
        cout << "Alerta! Uma recompensa de 50.000 edinhos foi colocada pela sua cabeça. Você se tornou um Ciberpsicopata." << endl;
    }

    delete [] implantes;


    return 0;
}