#include <iostream>
#include <vector>

using namespace std;

int main(){
    int linhas=4, colunas =3;
    vector<vector<int>> matriz(linhas, vector<int>(colunas, 1));

    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            matriz[i][j] = 1;
        }
    }
     
     cout << "Matriz preenchida:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}