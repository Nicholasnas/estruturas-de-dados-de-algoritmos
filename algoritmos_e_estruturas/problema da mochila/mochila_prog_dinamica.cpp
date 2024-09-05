#include <iostream>
using namespace std;

struct pedra{
    string nome;
    float peso;
    float volume;
    float valor;
    bool escolhida;
};




float minerador(pedra pedras[], int n, float cap_peso, float cap_volume){
    if(n == 0 || cap_peso <= 0 || cap_volume <= 0){
        return 0;
    }

    float pegar_pedra=0, nao_pegar=0;
    nao_pegar = minerador(pedras, n-1, cap_peso, cap_volume);
    
    if (pedras[n-1].peso <= cap_peso && pedras[n-1].volume <= cap_volume){
         pedras[n-1].escolhida = true;
        pegar_pedra = pedras[n-1].valor +
         minerador(pedras, n-1,cap_peso - pedras[n-1].peso, cap_volume - pedras[n-1].volume);
    }
    if (pegar_pedra >= nao_pegar){
        pedras[n-1].escolhida = true;
        return pegar_pedra;
    }
    else{
        pedras[n-1].escolhida = false;
        return nao_pegar;
    }

}

int main() {
    int n;
    cin >> n;

    pedra pedras[n];
 
    for (int i = 0; i < n; i++) {
        string nome;
        float volume, peso, valor;
        cin >> nome >> peso >> volume >> valor;
        pedras[i].nome = nome;
        pedras[i].volume = volume;
        pedras[i].peso = peso;
        pedras[i].valor = valor;        
        pedras[i].escolhida = false;        

    }
    cout << "Melhor valor obtido: " << minerador(pedras, n, 400, 1000) << endl;

    cout << "Pedras escolhidas:" << endl;
    for (int i = 0; i < n; i++) {
        if (pedras[i].escolhida)
            cout << pedras[i].nome << endl;
	}
    return 0;
}
