#include <iostream>
using namespace std;

struct Node{
    int dado;
    Node *next= NULL;
};
struct LinkedList{
    Node *head = NULL;
};

void insert_at_end(LinkedList *&list, int dado){
    Node * new_node = new Node;
    new_node->dado = dado;
    // Arvore vazia
    if(list->head == NULL){
        list->head = new_node;
        return;
    }
    Node * current = list->head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;

    }
void show_list(LinkedList *&list){
    if (list->head == NULL){
        cout << "List Empty" << endl;
        return;
    }

    Node *current = list->head;

    while(current){
        cout << current->dado << " -> ";
        current = current->next;
    }
    cout << "Fim" <<  endl;
    
}
int lenght(LinkedList *& list){
    if (list->head == NULL){
        return 0;
    }
    Node * current_node = list->head;
    int total = 0;
    while (current_node){
        total++;
        current_node = current_node->next;
    }
    return total;
}
int get_item(LinkedList *& list, int index){
    if(index > lenght(list) || index < 0){
        cout << "Error: Index out of range" << endl;
        return NULL;
    }
    int current_index = 0;
    Node * current_node = list->head;

    while(current_node){
        if(current_index == index){
            return current_node->dado;
        }
        current_node = current_node->next;
        current_index++;
    }
}

int search_item(LinkedList *&list, int dado){
    if (list->head == NULL){
        cout << "List is Empty" << endl;
        return NULL;
    }
    Node * current_node = list->head;
    while(current_node){
        if (current_node->dado == dado){
            cout << "I find the target " << dado << endl;
            return dado;
        }
    }
    cout << "Item not found." << endl;
    return NULL;
}
void insert_at_start(LinkedList *& list, int value){
    Node * new_node = new Node;
    new_node->dado = value;

    if(list->head == NULL){
        list->head = new_node;
    }
    new_node->next = list->head;
    list->head = new_node;
    cout << "Add at start sucess!" << endl;

}
void destruct_list(LinkedList *& list){
    Node * current = list->head;
    while(current != NULL){
        Node * aux = current;
        current = current->next;
        delete aux;
    }
    cout << "Destruct list" << endl;
}
void remove_at_start(LinkedList *& list){
    if (list->head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    list->head = list->head->next;

}
void remove_at_end(LinkedList *& list){
    if(list->head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    Node * current_node = list->head;
    while(current_node){
        current_node = current_node->next;
    }
    current_node->next = NULL;
}

void menu(LinkedList *& list){

    int opcao;
    int dado;
    while (true) {
        cout << "======== Menu de LinkedList =========" << endl;
        cout << "1 - Adicionar um numero no final da lista: " << endl;
        cout << "2 - Adicionar um numero no inicio da lista: " << endl;
        cout << "3 - Mostrar a lista: " << endl;
        cout << "4 - Tamanho do lista: "  << endl;
        cout << "5 - Obter o valor pelo index: " << endl;
        cout << "6 - Procurar valor(dado:int): " << endl;
        cout << "7 - Remover no inicio: " << endl;
        cout << "8 - Remover no final: " << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
    }
    switch (opcao)
    {
    case 1:
        cout << "Entre com o numero a ser adicionado: ";
        cin >> dado;
        insert_at_end(list, dado);
        cout << "Inserido com sucesso!" << endl;
        break;
    case 2:
        cout << "Entre com o numero a ser adicionado: ";
        cin >> dado;
        insert_at_start(list, dado);
        cout << "Inserido com sucesso!" << endl;
        break;
    case 3:
        cout << "===== LinkedList ======" << endl;
        show_list(list);
        break;
    case 4:
        cout << "O tamanho do array: " << lenght(list) << endl;
        break;
    case 5:
        cout << "Entre com o index: " << endl;
        cin >> dado;
        cout << "O valor do item: " << get_item(list,dado) << endl;
        break;
    case 6:
        cout << "Entre com dado a ser procurado: ";
        cin >> dado;
        cout << search_item(list, dado) << endl;
        break;
    case 7:
        remove_at_start(list);
        cout << "Removido com sucesso!" << endl;
        break;
    case 8:
        remove_at_end(list);
        cout << "Removido com sucesso!" << endl;
        break;
    case 0:
        destruct_list(list);
        cout << "Lista destruida com sucesso! " << endl;
    default:
        cout << "Opcao invalida!" << endl;
        break;
    }

}
int main(){
    LinkedList *list = new LinkedList;
    menu(list);

    delete list;
    return 0;

}