#include <iostream>
#include <iomanip>

using namespace std;

struct Nota{
	int notas[4];
	float media;
};
int main()
{
	int qtd_alunos;
	cin >> qtd_alunos;
	
	// ponteiro apontando para aluno - dinamico
	Nota* p = new Nota[qtd_alunos];
	
	float media_total = 0;
	float aux_media;
	
	for(int i =0;i < qtd_alunos;i++){
	    aux_media = 0;
		for(int j=0;j<4;j++){
			cin >> p[i].notas[j];	
			aux_media += p[i].notas[j];
		}
		p[i].media = aux_media/4.0;
		media_total += p[i].media;
	}

	
	cout << fixed << setprecision(2);
	cout << media_total/qtd_alunos << endl;
	
	
	delete [] p;
	
	return 0;
}