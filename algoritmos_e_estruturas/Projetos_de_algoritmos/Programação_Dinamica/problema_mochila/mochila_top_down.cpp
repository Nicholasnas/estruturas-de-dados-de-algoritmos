#include <iostream>
#include <string>
using namespace std;

// Tamanho máximo da mochila
#define TAM 100

struct Item {
    int id;
    int valor;
    int peso;
    string nome;
};

// Função recursiva com memoização
int mochila_recursivo_top_down(int** memoria, Item* itens, int n, int cap_peso) {
    // Caso base: sem itens ou capacidade 0
    if (n == 0 || cap_peso == 0)
        return 0;

    // Se já foi calculado
    if (memoria[n][cap_peso] != -1)
        return memoria[n][cap_peso];

    // Não incluir o item atual
    int nao_incluir = mochila_recursivo_top_down(memoria, itens, n - 1, cap_peso);

    // Incluir o item atual (se o peso permitir)
    int incluir = 0;
    if (itens[n - 1].peso <= cap_peso) {
        incluir = itens[n - 1].valor + mochila_recursivo_top_down(memoria, itens, n - 1, cap_peso - itens[n - 1].peso);
    }

    // Armazenar o resultado e retornar o máximo
    memoria[n][cap_peso] = max(nao_incluir, incluir);
    return memoria[n][cap_peso];
}

int main() {
    int numero_itens;
    cout << "Entre com a quantidade de itens: ";
    cin >> numero_itens;

    int cap_peso;
    cout << "Entre com a capacidade de peso da mochila: ";
    cin >> cap_peso;

    Item* itens = new Item[numero_itens];

    for (int i = 0; i < numero_itens; i++) {
        itens[i].id = i + 1;
        cin.ignore(); // Limpar o buffer
        cout << "Entre com o nome do item: ";
        getline(cin, itens[i].nome);
        cout << "Entre com o valor do item: ";
        cin >> itens[i].valor;
        cout << "Entre com o peso do item: ";
        cin >> itens[i].peso;
    }

    // Alocar dinamicamente a matriz de memoização
    int** memoria = new int*[numero_itens + 1];
    for (int i = 0; i <= numero_itens; i++) {
        memoria[i] = new int[cap_peso + 1];
        for (int j = 0; j <= cap_peso; j++) {
            memoria[i][j] = -1; // Inicializar com -1
        }
    }

    // Resolver o problema da mochila
    int resultado = mochila_recursivo_top_down(memoria, itens, numero_itens, cap_peso);
    cout << "O valor máximo que pode ser carregado na mochila é: " << resultado << endl;

    // Liberar memória alocada
    for (int i = 0; i <= numero_itens; i++) {
        delete[] memoria[i];
    }
    delete[] memoria;
    delete[] itens;

    return 0;
}
