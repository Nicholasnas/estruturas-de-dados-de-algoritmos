#include <iostream>
using namespace std;

struct pedra {
    string nome;
    float peso;
    float volume;
    float valor;
};

float minerador_brute_force(pedra pedras[], int n, int i,
    float cap_peso, float cap_vol,bool escolhidos[], bool melhor_escolha[]) {

    if (i >= n || cap_peso <=0|| cap_vol<=0) {
        return 0;
    }
    
    // Escolhendo não pegar a pedra atual
    float nao_pegar = minerador_brute_force(pedras, n, i + 1, cap_peso,
	 cap_vol, escolhidos, melhor_escolha);

    // Escolhendo pegar a pedra atual
    float pegar_pedra = 0;
    float nova_cap_peso = cap_peso - pedras[i].peso;
    float nova_cap_vol = cap_vol - pedras[i].volume;
    
    if (nova_cap_peso >= 0 && nova_cap_vol >= 0) {
        escolhidos[i] = true;
        pegar_pedra = pedras[i].valor + minerador_brute_force(pedras, n, i + 1, nova_cap_peso,
         nova_cap_vol, escolhidos, melhor_escolha);
         escolhidos[i] = false;
    }

    if (pegar_pedra > nao_pegar) {
        for (int j = 0; j < n; j++) {
            melhor_escolha[j] = escolhidos[j];
           
        }
        melhor_escolha[i] = true;
        return pegar_pedra;
    } else {
    	escolhidos[i] = false;
        return nao_pegar;
    }
}

int main() {
    int n;
    cin >> n;

    pedra pedras[n];
    bool escolhidos[n];
    bool melhor_escolha[n];

    for (int i = 0; i < n; i++) {
        string nome;
        float volume, peso, valor;
        cin >> nome >> peso >> volume >> valor;
        pedras[i].nome = nome;
        pedras[i].volume = volume;
        pedras[i].peso = peso;
        pedras[i].valor = valor;
    }

    // Inicializar o array de escolha com false
    for (int i = 0; i < n; i++) {
        escolhidos[i] = false;
        melhor_escolha[i] = false;
    }

    cout << "Melhor valor obtido: " << minerador_brute_force(pedras, n, 0, 400, 1000, escolhidos, melhor_escolha) << endl;

    cout << "Pedras escolhidas:" << endl;
    for (int i = 0; i < n; i++) {
        if (melhor_escolha[i])
            cout << pedras[i].nome << endl;
	}
    return 0;
}
