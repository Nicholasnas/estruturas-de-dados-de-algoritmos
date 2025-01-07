#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pedra {
    int id;
    string nome;
    float volume;
    int preco, peso;
};

struct Carrinho {
    int peso;
    float volume;
};

// Função recursiva para força bruta
float minerar(Carrinho carrinho, Pedra pedras[], int index, int num_pedras, vector<int>& escolhidas) {
    // Caso base: limite da árvore de decisão ou capacidade do carrinho
    if (index >= num_pedras || carrinho.peso <= 0 || carrinho.volume <= 0) {
        return 0;
    }

    // Não pegar a pedra atual
    vector<int> nao_pegar_escolhidas = escolhidas; // Clona o estado atual
    float nao_pegar = minerar(carrinho, pedras, index + 1, num_pedras, nao_pegar_escolhidas);

    // Tentar pegar a pedra atual
    float pegar_pedra = 0;
    vector<int> pegar_escolhidas = escolhidas; // Clona o estado atual
    
    if (carrinho.peso >= pedras[index].peso && carrinho.volume >= pedras[index].volume) {
        Carrinho novo_carrinho = { 
            carrinho.peso - pedras[index].peso, 
            carrinho.volume - pedras[index].volume 
        };
        pegar_escolhidas.push_back(pedras[index].id); // Marca a pedra como escolhida
        pegar_pedra = pedras[index].preco + minerar(novo_carrinho, pedras, index + 1, num_pedras, pegar_escolhidas);
    }

    // Atualiza a lista de escolhidas com base na melhor decisão
    if (pegar_pedra > nao_pegar) {
        escolhidas = pegar_escolhidas;
        return pegar_pedra;
    } else {
        escolhidas = nao_pegar_escolhidas;
        return nao_pegar;
    }
}

int main() {
    int tam = 5;
    Carrinho carrinho = {400, 1.0};  // Capacidade do carrinho: 400kg e 1m³
    Pedra* pedras = new Pedra[tam];

    // Entrada de dados
    for (int i = 0; i < tam; i++) {
        pedras[i].id = i;
        cout << "Entre com a pedra " << i << "." << endl;
        cout << "Entre com o nome da pedra: ";
        cin.ignore();
        getline(cin, pedras[i].nome);
        cout << "Entre com o volume da pedra (m³): ";
        cin >> pedras[i].volume;
        cout << "Entre com o peso (kg): ";
        cin >> pedras[i].peso;
        cout << "Entre com o preco (R$): ";
        cin >> pedras[i].preco;
    }

    // Resolver problema
    vector<int> escolhidas;
    float max_valor = minerar(carrinho, pedras, 0, tam, escolhidas);

    // Exibir resultado
    cout << "O maior valor que pode ser minerado é: R$ " << max_valor << endl;
    cout << "Pedras escolhidas: ";
    for (int id : escolhidas) {
        cout << pedras[id].nome << " ";
    }
    cout << endl;

    delete[] pedras;

    return 0;
}
