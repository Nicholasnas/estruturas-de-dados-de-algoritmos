#include <list>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

struct Palavra {
    string palavra_ficticia;
    string significado;
    int x,y,z;
};

// Dicionario de palavaras
struct Dicionario {
    string palavra_ficticia;
    list<string> significados;
};

// Calculando a distancia entre duas palavras
double calcular_distancia(Palavra p1, Palavra p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

// Adicionando a palavra ao dicionario - grafo
void adicionar_palavra(list<Palavra>& palavras, list<Dicionario>& dicionario) {
    Palavra nova_palavra;
    
    cout << "Inserção de nova palavra:" << endl;
    cout << "Palavra fictícia: ";
    getline(cin, nova_palavra.palavra_ficticia);
    
    cout << "Significado em português: ";
    getline(cin, nova_palavra.significado);
    cin.ignore();
    
    cout << "Entre com as coordenadas (x, y, z): " << endl;
    cout << "Coordenada x: ";
    cin >> nova_palavra.x;
    cout << "Coordenada y: ";
    cin >> nova_palavra.y;   
    cout << "Coordenada z: ";
    cin >> nova_palavra.z;
    
    bool encontrado = false;
    list<Dicionario>::iterator it;

    //Finalmente adicionando
    for (it = dicionario.begin(); it != dicionario.end(); it++) {
        if (it->palavra_ficticia == nova_palavra.palavra_ficticia) {
            it->significados.push_back(nova_palavra.significado);
            encontrado = true;
            break;
        }
    }

    if (!encontrado){
        Dicionario nova_entrada;
        nova_entrada.palavra_ficticia = nova_palavra.palavra_ficticia;
        nova_entrada.significados.push_back(nova_palavra.significado);
        dicionario.push_back(nova_entrada);
    }

    // Add na lista
    palavras.push_back(nova_palavra);

    cout << "Palavra adicionada com sucesso!" << endl;
}

// Mostrando os significados  de uma palavra em especifico
void listarSignificados(list<Dicionario>& dicionario) {
    string palavra;
    cout << "Digite a palavra fictícia para buscar seus significados: ";
    cin >> palavra;

    bool encontrada = false;
    list<Dicionario>::iterator it;

    for (it = dicionario.begin(); it != dicionario.end(); it++) {
        if (it->palavra_ficticia == palavra) {
            cout << "Significados da " << palavra << ": " << endl;
            int i = 1;
            list<string>::iterator sig;
            for (sig = it->significados.begin(); sig!= it->significados.end(); sig++) {
                cout << i++ << ". " << *sig << endl;
            }
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "Palavra " << palavra << " não encontrada no vocabulário." << endl;
    }
}

// Mostrando as palavras no dicionario
void listar_palavras_dicionario(list<Palavra>& palavras) {
    // Mostrar todos os componentes das palavras
    // palavra ficticia e seu(s) significados
    // e suas coordenadas

    if (palavras.empty()) {
        // Nenhuma palavra no grafo.
        cout << "Nenhuma palavra cadastrada ainda." << endl;
        return;
    }
    
    list<Palavra>::iterator it;

    for (it = palavras.begin(); it != palavras.end(); it++) {
        cout << "Palavra Fictícia: " << it->palavra_ficticia << endl;
        cout << "Significado: " << it->significado << endl;
        cout << "Coordenadas: (" << it->x << ", " << it->y << ", " << it->z << ")" << endl;
    }
}

int main() {

    list<Palavra> palavras;
    list<Dicionario> dicionario;
    int opcao;

    while (true) {
        cout << "======== Sistema de Vocabulário Fictício - Grafos =========" << endl;
        cout << "1 - Adicionar nova palavra"  << endl;
        cout << "2 - Listar significados de uma palavra" << endl;
        cout << "3 - Listar todas as palavras" << endl;
        cout << "4 - " << endl;
        cout << "0 - Sair " << endl;
        cout << "Escolha uma opção: ";
        
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa!" << endl;
                return 0;
            case 1:
                adicionar_palavra(palavras, dicionario);
                break;
            case 2:
                listar_palavras_dicionario(dicionario);
                break;
            case 3:
                listar_palavras(palavras);
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}