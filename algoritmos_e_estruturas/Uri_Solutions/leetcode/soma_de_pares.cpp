#include <iostream>
#include <list>

using namespace std;
void brute_force(int array[], int size, int target){

    /*Complexidade O(n²)*/

    for(int i=0; i<size-1; i++){
        for (int j=i+1;j<size;j++){
            if ((array[i] + array[j]) == target){
                cout << "Par (" << array[i] << "," << array[j] << ")" << endl;
            
            }
        }
    }
   
}

int main(){
    int tam;
    cout << "Entre com o tamanho do array: ";
    cin >> tam;
    int * array = new int[tam];
    
    cout << "Entre com os valores do array: " << endl;
    for (int i=0;i<tam;i++){
        cin >> array[i];
    }

    int target;

    cout << "Entre com o target: ";
    cin >> target;

    brute_force(array, tam, target);


    return 0;
}