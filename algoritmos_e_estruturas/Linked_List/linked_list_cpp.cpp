#include <iostream>

using namespace std;

struct Node{
    int dado;
    Node *next;
};
struct LinkedList{
    Node *head = NULL;
};

void add(LinkedList *&list, int dado){
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
    Node *current = list->head;

    while(current != NULL){
        cout << current->dado << " -> ";
        current = current->next;
    }
}

void destruct_list(LinkedList *& list){
    Node * current = list->head;
    while(current != NULL){
        Node * aux = current;
        current = current->next;
        delete aux;
    }
}

int main(){
    LinkedList *list = new LinkedList;
    int dado;
    while(true){
        cin >> dado;
        if(dado == -1){
            break;
        }
        add(list, dado);
        show_list(list);
    }
    destruct_list(list);
    cout << "Lista destruida" << endl;  
    return 0;

}