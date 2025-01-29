#include <iostream>
#include <list>

using namespace std;

struct Node{
    int dado;
    Node * right;
    Node * left;
};

void insert(Node *& curr, int new_info){
    if(curr == NULL){
        curr = new Node;
        curr->dado = new_info;
        curr->left = NULL;
        curr->right = NULL;
    }
    else{
        if (new_info < curr->dado){
            insert(curr->left, new_info);
        }
        else{
            insert(curr->right, new_info);
        }
    }
}
void inLevel(Node * curr){

    if (curr == NULL){
        return;
    }
    list<Node *> visit;
    visit.push_back(curr);

    while(!visit.empty()){
        int level_size = visit.size();
        for(int i=0; i < level_size ;i++){

            Node * aux = visit.front();
            visit.pop_front();
            cout << aux->dado << " ";

            if(aux->left != NULL){
                visit.push_back(aux->left);
            }
            if(aux->right !=  NULL){
                visit.push_back(aux->right);
            }
        }
        cout << endl;
    }
    

}

int main(){
    Node * root = NULL;
    int dado;

    while(true){
        cin >> dado;
        if (dado == -1){
            break;
        }
        insert(root, dado);
    }
    inLevel(root);


    return 0;
}