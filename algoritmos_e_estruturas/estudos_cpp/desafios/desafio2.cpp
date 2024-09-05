#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float notas[3];
    float media_turma, media_aluno, soma_das_notas = 0;
    

    for (int i = 0; i < 3; i++){
        cout << "Entre com a nota " << i + 1 << " : ";
        cin >> notas[i]; 
        soma_das_notas += notas[i];
    }
    media_aluno = soma_das_notas / 3;

    cout << "Entre com a média da turma: ";
    cin >> media_turma;


    if (media_aluno < media_turma){
        cout << "Aluno está abaixo da média!" << endl;
    }
    else if (media_aluno > media_turma) {
        cout << "Aluno está acima da média!" << endl;
    }
    else{
        cout << "Aluno está na média!" << endl;
    }
    cout << media_aluno;

    return 0;
}