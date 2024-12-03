// 697	Nícholas Lima do Nascimento	
// 469	Mateus Franco de Oliveira
// 187	Tomé Assis Salgarello		


#include <iostream>
#include <list>
#include <math.h>
#include <iomanip>


using namespace std;

// Palavra fictícia, significado e os componentes geometricos
struct Palavra {
    string palavraFicticia;
    string significado;
    int x, y, z;
};

// Nó para a Árvore Binária
struct Node {
    Palavra palavra;
    Node * left;
    Node * right;
};

// Função para inserir palavras na árvore binária
void insert(Node *& curr, Palavra nova_palavra) {
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
Palavra nova_palavra(){
    Palavra palavra;

    cout << "Entre com a palavra ficticia: ";
    cin.ignore();
    getline(cin, palavra.palavraFicticia);
    cout << "Significado: ";
    getline(cin, palavra.significado);
    cin.ignore();
    
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
    list<Palavra> palavras;
    Node * root = NULL;
    int opcao;

    while (true) {
        cout << "======== Sistema de Vocabulario Ficticio =========" << endl;
        cout << "1 - Adicionar nova palavra na arvore: "  << endl;
        cout << "2 - Listar palavras em pre ordem alfabetica: " << endl;
        cout << "3 - Listar palavras em ordem alfabetica: " << endl;
        cout << "4 - Listar palavras em pos ordem alfabetica: " << endl;
        cout << "5 - Varredura em largura (nivel): " << endl;
        cout << "6 - Busca na arvore: " << endl;
        cout << "7 - Remover palavra da arvore: " << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        
        cin >> opcao;

        switch (opcao) {
            case 0:
                // Realizando a destruicao da arvore antes de para o programa
                destruct(root);
                cout << "Encerrando o programa!" << endl;
                return 0;
            case 1:
                // Inserindo as palavras na arvore
                insert(root, nova_palavra());
                cout << "Palavra adicionada com sucesso!" << endl;
                break;
            case 2:
                // Imprimindo a arvore em pre ordem alfabetica
                cout << "Palavras em pre ordem alfabetica:" << endl;
                arvore_em_pre_ordem(root);
                break;
            case 3:
                // Imprimindo a arvore em ordem alfabetica
                cout << "Palavras em ordem alfabetica:" << endl;
                arvore_em_ordem(root);
                break;
            case 4:
                // Imprimindo em pos ordem a arvore
                cout << "Palavras em pos ordem alfabetica:" << endl;
                arvore_em_pos_ordem(root);
                break;
            
            case 5: {
                // Realizando a varredura em nivel
                cout << "Palavras em nivel: " << endl;
                in_level(root);
                break;
            }
            case 6: {
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
            case 7:{
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

    return 0;
}