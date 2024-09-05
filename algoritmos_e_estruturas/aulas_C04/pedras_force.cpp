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
    if(n < 0 || cap_peso <= 0 || cap_volume <= 0){
        return 0;
    }

    float pegar_pedra=0, nao_pegar=0;
    nao_pegar = minerador(pedras, n-1, cap_peso, cap_volume);
    
    if (cap_peso >= pedras[n].peso && cap_volume >= pedras[n].volume){
        pegar_pedra = pedras[n].valor +
        minerador(pedras, n-1,cap_peso - pedras[n].peso, cap_volume - pedras[n].volume);
    }
    if (pegar_pedra > nao_pegar){
        pedras[n].escolhida = true;
        return pegar_pedra;
    }
    else{
        pedras[n].escolhida = false;
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
        cin >> nome >> volume >> peso >> valor;
        pedras[i].nome = nome;
        pedras[i].volume = volume;
        pedras[i].peso = peso;
        pedras[i].valor = valor;        
        pedras[i].escolhida = false;        

    }
    cout << "Melhor valor obtido: " << minerador(pedras, n-1, 400, 1000) << endl;

    cout << "Pedras escolhidas:" << endl;
    for (int i = 0; i < n; i++) {
        if (pedras[i].escolhida)
            cout << pedras[i].nome << endl;
	}
    return 0;
}
