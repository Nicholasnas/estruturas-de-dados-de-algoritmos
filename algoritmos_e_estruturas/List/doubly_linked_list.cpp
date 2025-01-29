#include <iostream>

using namespace std;

struct Node{
    int info;
    Node * next; // proximo
    Node * previus; // antecessor
};

struct DoublyLinkedList{
    Node * head = NULL; 
};

void addNode(DoublyLinkedList *& list, int dado){
    Node * new_node = new Node;
    new_node->info = dado;
    new_node->next = NULL;

    if (list->head == NULL){
        list->head = new_node;
        return;
    }
    Node * current_node = list->head;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    new_node->previus = current_node;
    current_node->next = new_node;
    
}

void showList(DoublyLinkedList * list){
    Node * current = list->head;

    while(current->next != NULL){
        cout << current-> info << " -> ";
        current = current->next;
    }
}

void destructList(DoublyLinkedList *& list){
    Node * current = list->head;
    while(current != NULL){
        Node * aux = current;
        current = current->next;
        delete aux;
    }
    cout << "Doubly Linked List Destruct! " << endl;
}

int main(){

    DoublyLinkedList * list = new DoublyLinkedList;
    int dado;
    while(true){
        // cout << "Entre com um valor numerico: ";
        cin >> dado;
        if (dado == -1){
            break;
        }
        addNode(list, dado);
        showList(list);

    }

    destructList(list);
    return 0;
}