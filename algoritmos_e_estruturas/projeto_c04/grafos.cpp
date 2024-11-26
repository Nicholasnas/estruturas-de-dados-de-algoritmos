#include <iostream>
#include <list>
#include <cmath>
#include <iomanip>

using namespace std;

struct Palavra {
    string palavraFicticia;
    string significado;
    int x,y,z;
};

// Dicionario de palavaras
struct Dicionario {
    string palavraFicticia;
    list<string> significados;
};

// Calcular a distancia enter duas palavras no espaco
double calcularDistancia(Palavra p1, Palavra p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

// Validar as coordenadas lidas
int lerCoordenada(string nomeCoordenada) {
    int coordenada;
    do {
        cout << "Coordenada " << nomeCoordenada << " (0-100): ";
        cin >> coordenada;
    } while (coordenada < 0 || coordenada > 100);
    return coordenada;
}

// Adicionar uma palavra ao dicionario
void adicionarPalavra(list<Palavra>& palavras, list<Dicionario>& dicionario) {
    Palavra novaPalavra;
    
    cout << "Inserção de nova palavra:" << endl;
    cout << "Palavra fictícia: ";
    cin >> novaPalavra.palavraFicticia;
    
    cout << "Significado em português: ";
    cin.ignore();
    getline(cin, novaPalavra.significado);
    
    novaPalavra.x = lerCoordenada("X");
    novaPalavra.y = lerCoordenada("Y");
    novaPalavra.z = lerCoordenada("Z");

    bool encontrado = false;
    list<Dicionario>::iterator it;

    //Finalmente adicionando
    for (it = dicionario.begin(); it != dicionario.end(); it++) {
        if (it->palavraFicticia == novaPalavra.palavraFicticia) {
            it->significados.push_back(novaPalavra.significado);
            encontrado = true;
            break;
        }
    }


    if (!encontrado){
        Dicionario novaEntrada;
        novaEntrada.palavraFicticia = novaPalavra.palavraFicticia;
        novaEntrada.significados.push_back(novaPalavra.significado);
        dicionario.push_back(novaEntrada);
    }

    // Add na lista
    palavras.push_back(novaPalavra);

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
        if (it->palavraFicticia == palavra) {
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

// Listar as palavra presentes no dicionario
void listarTodasPalavras(list<Palavra>& palavras) {
    if (palavras.empty()) {
        cout << "Nenhuma palavra cadastrada ainda." << endl;
        return;
    }
    
    list<Palavra>::iterator it;
    for (it = palavras.begin(); it != palavras.end(); it++) {
        cout << "Palavra Fictícia: " << it->palavraFicticia << endl;
        cout << "Significado: " << it->significado << endl;
        cout << "Coordenadas: (" << it->x << ", " << it->y << ", " << it->z << ")" << endl;
    }
}

int main() {
    // Declaração das estruturas de dados principais
    list<Palavra> palavras;
    list<Dicionario> dicionario;
    int opcao;

    while (true) {
        cout << "======== Sistema de Vocabulário Fictício =========" << endl;
        cout << "1 - Adicionar nova palavra"  << endl;
        cout << "2 - Listar significados de uma palavra" << endl;
        cout << "3 - Listar todas as palavras" << endl;
        cout << "0 - Sair " << endl;
        cout << "Escolha uma opção: ";
        
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa!" << endl;
                return 0;
            case 1:
                adicionarPalavra(palavras, dicionario);
                break;
            case 2:
                listarSignificados(dicionario);
                break;
            case 3:
                listarTodasPalavras(palavras);
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}