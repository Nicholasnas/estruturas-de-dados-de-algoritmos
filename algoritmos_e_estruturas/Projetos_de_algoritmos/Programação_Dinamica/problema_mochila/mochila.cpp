#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Explicação:

    1. Uso de std::vector para a matriz de memoização: 
        ◦ A matriz é criada como um vetor bidimensional de tamanho (numero_itens + 1) x (cap_peso + 1). 

        ◦ Cada célula é inicializada com 0, representando os casos base (sem itens ou capacidade 0).

    2. Preenchimento da Matriz: 
        ◦ Iteramos sobre os itens e as capacidades da mochila.

        ◦ Se o peso do item atual for menor ou igual à capacidade w, calculamos o máximo entre:

            ▪ O valor obtido ao incluir o item itens[i−1].valor + memoria[i−1][w−itens[i−1].peso].

            ▪ O valor sem incluir o item memoria[i−1][w].
    3. Resultado:
        ◦ O valor ótimo está na última célula da matriz, memoria[numero_itens][cap_peso].

    4. Simplificação com std::vector:
        ◦ O std::vector cuida automaticamente da alocação e liberação de memória.

        ◦ Evita erros de ponteiros e simplifica a inicialização.

*/

struct Item {
    int id;
    int valor;
    int peso;
    string nome;
};

int mochila_com_vector(const vector<Item>& itens, int numero_itens, int cap_peso) {
    // Criar uma matriz de tamanho (numero_itens + 1) x (cap_peso + 1)
    vector<vector<int>> memoria(numero_itens + 1, vector<int>(cap_peso + 1, 0));

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

    // O valor ótimo está na última célula
    return memoria[numero_itens][cap_peso];
}

int main() {
    int numero_itens;
    cout << "Entre com a quantidade de itens: ";
    cin >> numero_itens;

    int cap_peso;
    cout << "Entre com a capacidade de peso da mochila: ";
    cin >> cap_peso;

    vector<Item> itens(numero_itens);

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
    int resultado = mochila_com_vector(itens, numero_itens, cap_peso);
    cout << "O valor máximo que pode ser carregado na mochila é: " << resultado << endl;

    return 0;
}
