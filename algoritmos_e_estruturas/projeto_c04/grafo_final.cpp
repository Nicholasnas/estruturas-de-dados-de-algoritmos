#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <iterator>

using namespace std;

struct Palavra {
    string palavra_ficticia;
    list<string> significados; // significados da palavra
    list<int> conexoes;  // ids dos nos conectados
    int x, y, z;  // Coordenadas do nó
};

struct Dicionario{
    int id; // id de cada palavra
    Palavra palavra; 
};

// Calcular a distancia entre duas palavras 
double calcular_distancia(Palavra p1, Palavra p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

// Adicionar uma nova palavra ao grafo
void adicionar_palavra(list<Dicionario>& dicionario, int& contador) {
    
    Palavra nova_palavra;

    cout << "Insercao de nova palavra." << endl;
    cout << "Entre com a palavra ficticia: ";
    cin.ignore();
    getline(cin, nova_palavra.palavra_ficticia);

    cout << "Entre com o significado: ";
    string significado;
    getline(cin, significado);
    nova_palavra.significados.push_back(significado);

    cout << "Entre com as coordenadas (x, y, z): " << endl;
    cout << "Coordenada x: ";
    cin >> nova_palavra.x;
    cout << "Coordenada y: ";
    cin >> nova_palavra.y;
    cout << "Coordenada z: ";
    cin >> nova_palavra.z;
    // Conectar as palavra tendo como distancia minima 10   

    Dicionario nova_entrada;

    nova_entrada.id = contador++;
    nova_entrada.palavra = nova_palavra;

    dicionario.push_back({nova_entrada.id, nova_entrada.palavra});

    // Criando conexões com nós existentes
    list<Dicionario>::iterator it;

    for (it = dicionario.begin(); it != dicionario.end(); it++) {

        if(it->id != nova_entrada.id && calcular_distancia(it->palavra, nova_palavra) < 10){
            it->palavra.conexoes.push_back(nova_entrada.id);
            nova_entrada.palavra.conexoes.push_back(it->id);
        }
    }

    cout << "Palavra adicionada com sucesso!" << endl;
}

// Mostrar todas as palavras no grafo
void mostrar_palavras(list<Dicionario>& dicionario) {
    list<Dicionario>::iterator it; // itarar sobre o dicionario
    list<string>::iterator significado; // iterar sobre os significados da palavra

    cout << "Palavras no grafo:" << endl;
    for (it = dicionario.begin(); it != dicionario.end(); it++) {
        cout << it->id << " - " << it->palavra.palavra_ficticia << ": ";
        for (significado = it->palavra.significados.begin(); significado != it->palavra.significados.end(); significado++) {
            cout << *significado << ", ";
        }
        cout << endl;
    }
}

// Mostrar conexões entre palavras
void mostrar_conexoes(list<Dicionario>& dicionario) {
    list<Dicionario>::iterator it; // percorrer o Dicionario
    list<int>::iterator conexao; // percorrer as conexoes do grafo
    list<Dicionario>::iterator it_conectado;

    cout << "Conexoes no grafo:" << endl;
    // Percorrer o dicionario para mostrar as conexoes entre
    for (it = dicionario.begin(); it != dicionario.end(); it++) {
        cout << "Palavra: " << it->palavra.palavra_ficticia << " conecta com: ";
        // Percorrendo a lista de conexoes de uma certa palavra
        for (conexao = it->palavra.conexoes.begin(); conexao != it->palavra.conexoes.end(); conexao++) {
            // Percorrer o dicionario para palavras conectadas 
            for (it_conectado = dicionario.begin(); it_conectado != dicionario.end(); it_conectado++) {
                if (it_conectado->id == *conexao) {
                    cout << it_conectado->palavra.palavra_ficticia << " ";
                }
            }
        }
        cout << endl;
    }
}

int main() {
    list<Dicionario> dicionario; // Lista de nós
    int opcao;
    int contador = 0;  // ID único para cada nó

    while (true) {
        cout << "======== Sistema de Vocabulario Ficticio - Grafos =========" << endl;
        cout << "1 - Adicionar nova palavra" << endl;
        cout << "2 - Listar todas as palavras" << endl;
        cout << "3 - Listar conexoes entre palavras" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa!" << endl;
                return 0;
            case 1:
                adicionar_palavra(dicionario, contador);
                break;
            case 2:
                mostrar_palavras(dicionario);
                break;
            case 3:
                mostrar_conexoes(dicionario);
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    }
}
