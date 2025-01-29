#include <iostream>

using namespace std;

struct Item{
	string nome;
	float peso;
	float valor;
	bool escolhido;
};

int valorMaximo = 0;
bool* melhorEscolha;
void mochilaForcaBruta(Item* itens, int tam, int capacidade,
 int inicial, int pesoAtual, int valorAtual, bool* escolhidos) {
    // Caso base: todos os itens foram considerados
    if (inicial == tam) {
        if (valorAtual > valorMaximo) {
            valorMaximo = valorAtual;
            // Copiar a solução atual para a melhor solução
            for (int i = 0; i < tam; i++) {
                melhorEscolha[i] = escolhidos[i];
            }
        }
        return;
    }

    // Não incluir o item atual
    mochilaForcaBruta(itens, tam, capacidade, inicial + 1, pesoAtual, valorAtual, escolhidos);

    // Incluir o item atual, se couber na mochila
    if (pesoAtual + itens[inicial].peso <= capacidade) {
        escolhidos[inicial] = true;
        mochilaForcaBruta(itens, tam, capacidade, inicial + 1, pesoAtual + itens[inicial].peso, valorAtual + itens[inicial].valor, escolhidos);
        escolhidos[inicial] = false; // Desmarcar a escolha para a próxima chamada
    }
}

int main() {
    // Exemplo de entrada
    int n = 3;
    int capacidade = 5;
    Item itens[] = {{"livro", 1, 3}, {"lápis", 2, 2}, {"caderno", 3, 4}};

    // Alocar dinamicamente um array booleano para a força bruta
    bool* escolhidos = new bool[n];
    melhorEscolha = new bool[n];

    // Inicializar o array de escolha com false
    for (int i = 0; i < n; ++i) {
        escolhidos[i] = false;
        melhorEscolha[i] = false;
    }

    
    mochilaForcaBruta(itens, n, capacidade, 0, 0,0, escolhidos);

    // Imprimir os itens escolhidos pela força bruta
    std::cout << "Itens escolhidos (força bruta):\n";
    for (int i = 0; i < n; i++) {
        if (melhorEscolha[i]) {
            std::cout << itens[i].nome << " ";
        }
    }
    std::cout << std::endl;

    // Liberar a memória alocada
    delete[] escolhidos;
    delete[] melhorEscolha;

    return 0;
}
