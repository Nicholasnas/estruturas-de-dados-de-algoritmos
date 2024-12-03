#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include <iterator>


using namespace std;

// Palavra para o Grafo
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

// Palavra fictícia, significado e os componentes geometricos
struct Palavra_Tree{
    string palavraFicticia;
    string significado;
    int x, y, z;
};

// Nó para a Árvore Binária
struct Node {
    Palavra_Tree palavra;
    Node * left;
    Node * right;
};

// Calcular a distancia entre duas palavras 
double calcular_distancia_grafo(Palavra p1, Palavra p2) {
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
        if(it->id != nova_entrada.id && calcular_distancia_grafo(it->palavra, nova_palavra) < 10){
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
        cout << "Palavra " << it->palavra.palavra_ficticia << " conecta com: ";
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

// Função para inserir palavras na árvore binária
void insert(Node *& curr, Palavra_Tree nova_palavra) {
    if (curr == NULL) {
        curr = new Node;
        curr->palavra = nova_palavra;
        curr->right = NULL;
        curr->left = NULL;
    }
    else{
        if(nova_palavra.palavraFicticia < curr->palavra.palavraFicticia){
            insert(curr->left, nova_palavra);
        }
        else{
            insert(curr->right, nova_palavra);
        }
    }
}

// Realizar a busca na arvore pela palavra ficticia
Node * search(Node* curr, string palavraFicticia) {
    // Passando o no da arvore por referencia - pont atual
    if (curr == NULL) {
        // Palavra não encontrada ou arvore vazia
        return NULL;
    }
    else if(palavraFicticia == curr->palavra.palavraFicticia){
        return curr; // palavra encontrada - retornando o NO
    }
    else{
        if(palavraFicticia < curr->palavra.palavraFicticia){
            // procurar na sub-arvore a esquerda
            return search(curr->left, palavraFicticia);
        }
        else{
            // procurar na sub-arvore a direita
            return search(curr->right, palavraFicticia);
        }
    }
}
// Busca em nivel de profundidade na arvore
void in_level(Node * curr)
{
	list<Node *> visit_queue;
	if(curr != NULL)
	{
		visit_queue.push_back(curr);
		while(!visit_queue.empty())
		{
			Node * aux = visit_queue.front();
			visit_queue.pop_front();
			if(aux->left != NULL)
				visit_queue.push_back(aux->left);
			if(aux->right != NULL)
				visit_queue.push_back(aux->right);

			cout << "Palavra Ficticia: " << aux->palavra.palavraFicticia << endl;
			cout << "Significado: " << aux->palavra.significado << endl;
		}
	}
}

// Mostrando as palavras em ordem alfabetica
void arvore_em_ordem(Node* curr) {
    if (curr == NULL) {
        return;
    }
    arvore_em_ordem(curr->left);
    cout << "Palavra Ficticia: " << curr->palavra.palavraFicticia << endl;
    cout << "Significado: " << curr->palavra.significado << endl;
    cout << "Coordenadas: (" << curr->palavra.x << ", ";
    cout << curr->palavra.y << ", " << curr->palavra.z << ")" << endl;
    arvore_em_ordem(curr->right);
}

// Mostrando as palavras em pre ordem
void arvore_em_pre_ordem(Node* curr) {
    if (curr == NULL) {
        return;
    }
    arvore_em_pre_ordem(curr->left);
    arvore_em_pre_ordem(curr->right);
    cout << "Palavra Ficticia: " << curr->palavra.palavraFicticia << endl;
    cout << "Significado: " << curr->palavra.significado << endl;
    cout << "Coordenadas: (" << curr->palavra.x << ", ";
    cout << curr->palavra.y << ", " << curr->palavra.z << ")" << endl;
}

// Mostrando as palavras em pos ordem
void arvore_em_pos_ordem(Node * curr){
	if(curr != NULL){
		cout << "Palavra Ficticia: " << curr->palavra.palavraFicticia << endl;
        cout << "Significado: " << curr->palavra.significado << endl;
        cout << "Coordenadas: (" << curr->palavra.x << ", ";
        cout << curr->palavra.y << ", " << curr->palavra.z << ")" << endl;
		arvore_em_pos_ordem(curr->left);
		arvore_em_pos_ordem(curr->right);
	}
}

// Destruindo a arvore - removendo os nos
void destruct(Node * &curr){
	if(curr != NULL){
		destruct(curr->left);
		destruct(curr->right);
		delete curr;
		curr = NULL;
	}
}

// Encontrar o menor elemento e apontar para direita dele
Node * PointSmall(Node *&curr) {
    if (curr->left == NULL) { // Encontrou o menor palavras
        Node *temp = curr;
        curr = curr->right;
        return temp;
    }
    // continua procurando na subarvire a esquerda
    return PointSmall(curr->left); 
}

bool remove_palavra(Node *& curr, string palavra) {
    if (curr == NULL) { // arvore vazia
        return false;
    }
    if (curr->palavra.palavraFicticia == palavra) {
        Node * aux = curr;
        if (curr->left == NULL) { // sem filhos a esquerda
            curr = curr->right;
        } else if (curr->right == NULL) { // sem filhos a direita
            curr = curr->left;
        } else {
            aux = PointSmall(curr->right);
            curr->palavra = aux->palavra;
        }
        delete aux;
        return true;
    } else if (palavra < curr->palavra.palavraFicticia) {
        return remove_palavra(curr->left, palavra);
    } else {
        return remove_palavra(curr->right, palavra);
    }
}
Palavra_Tree nova_palavra(){
    Palavra_Tree palavra;

    cout << "Entre com a palavra ficticia: ";
    cin.ignore();
    getline(cin, palavra.palavraFicticia);
    cout << "Significado: ";
    getline(cin, palavra.significado);
   
    cout << "Entre com as coordenadas (x, y, z): " << endl;
    cout << "Coordenada x: ";
    cin >> palavra.x;
    cout << "Coordenada y: ";
    cin >> palavra.y;    
    cout << "Coordenada z: ";
    cin >> palavra.z;

    return palavra;

}


int main() {
    list<Dicionario> dicionario; // Lista de nós
    list<Palavra_Tree> palavras;
    Node * root = NULL;
    int opcao;
    int contador = 0;  // ID único para cada nó

    while (true) {
        cout << "======== Sistema de Vocabulario Ficticio =========" << endl;
        cout << "1 - Adicionar nova palavra no grafo: " << endl;
        cout << "2 - Listar todas as palavras do grafo: " << endl;
        cout << "3 - Listar conexoes entre palavras do grafo: " << endl;
        cout << "4 - Adicionar nova palavra na arvore: "  << endl;
        cout << "5 - Listar palavras em pre ordem alfabetica: " << endl;
        cout << "6 - Listar palavras em ordem alfabetica: " << endl;
        cout << "7 - Listar palavras em pos ordem alfabetica: " << endl;
        cout << "8 - Varredura em largura (nivel): " << endl;
        cout << "9 - Busca na arvore: " << endl;
        cout << "10 - Remover palavra da arvore: " << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                destruct(root);
                cout << "Encerrando o programa!" << endl;
                return 0;
            case 1:
                // Adicionar palavra no grafo
                adicionar_palavra(dicionario, contador);
                break;
            case 2:
                // Mostrar as palavras do grafo
                mostrar_palavras(dicionario);
                break;
            case 3:
                // Mostrar as conexoes entre as palavras
                mostrar_conexoes(dicionario);
                break;
            case 4:
                // Inserindo as palavras na arvore
                insert(root, nova_palavra());
                cout << "Palavra adicionada com sucesso!" << endl;
                break;
            case 5:
                // Imprimindo a arvore em pre ordem alfabetica
                cout << "Palavras em pre ordem alfabetica:" << endl;
                arvore_em_pre_ordem(root);
                break;
            case 6:
                 // Imprimindo a arvore em ordem alfabetica
                cout << "Palavras em ordem alfabetica:" << endl;
                arvore_em_ordem(root);
                break;
            case 7:
                // Imprimindo em pos ordem a arvore
                cout << "Palavras em pos ordem alfabetica:" << endl;
                arvore_em_pos_ordem(root);
                break;
            
            case 8: {
                // Realizando a varredura em nivel
                cout << "Palavras em nivel: " << endl;
                in_level(root);
                break;
            }
            case 9: {
                // Buscando palavra na arvore e retornando suas caracteristicas
                string busca;
                cout << "Digite a palavra ficticia para buscar: ";
                cin.ignore();
                getline(cin, busca);
                Node * resultado = search(root, busca);
                if (resultado) {
                    cout << "Palavra: " << resultado->palavra.palavraFicticia << endl;
                    cout << "Significado: " << resultado->palavra.significado << endl;
                } else {
                    cout << "Palavra nao encontrada!" << endl;
                }
                break;
            }
            case 10:{
                // Remover palavra da arvore
                string palavra;
                cout << "Entre com a palavra a ser removida: ";
                cin >> palavra;
                if(remove_palavra(root, palavra)){
                    cout << "Palavra removida com sucesso!" << endl;
                }
                else cout << "Palavra não encontrada!" << endl;
                break;
            }
            default:
                cout << "Opcao invalida!" << endl;
        }
    }
}
