#include <iostream>
#include <string>
using namespace std;

struct Item {
    int id;
    int valor;
    int peso;
    string nome;
};

int mochila_bottom_up(Item* itens, int numero_itens, int cap_peso) {
    // Alocar dinamicamente a matriz de memoização
    int** memoria = new int*[numero_itens + 1];
    for (int i = 0; i <= numero_itens; i++) {
        memoria[i] = new int[cap_peso + 1];
        for (int j = 0; j <= cap_peso; j++) {
            memoria[i][j] = 0; // Inicializar com 0 (caso base)
        }
    }

    // Preencher a matriz
    for (int i = 1; i <= numero_itens; i++) {
        for (int w = 1; w <= cap_peso; w++) {
            if (itens[i - 1].peso <= w) {
                // Máximo entre incluir ou não incluir o item atual
                memoria[i][w] = max(
                    itens[i - 1].valor + memoria[i - 1][w - itens[i - 1].peso],
                    memoria[i - 1][w]
                );
            } else {
                // Não incluir o item
                memoria[i][w] = memoria[i - 1][w];
            }
        }
    }

    // O resultado final está na última célula
    int resultado = memoria[numero_itens][cap_peso];

    // Liberar memória alocada dinamicamente
    for (int i = 0; i <= numero_itens; i++) {
        delete[] memoria[i];
    }
    delete[] memoria;

    return resultado;
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

    // Resolver o problema da mochila
    int resultado = mochila_bottom_up(itens, numero_itens, cap_peso);
    cout << "O valor máximo que pode ser carregado na mochila é: " << resultado << endl;

    // Liberar memória alocada dinamicamente
    delete[] itens;

    return 0;
}
