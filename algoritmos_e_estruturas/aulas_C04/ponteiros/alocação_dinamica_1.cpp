#include <iostream>
#include <iomanip>

using namespace std;

struct Nota{
	int notas[4];
	float media;
};
int main()
{
	// ponteiro apontando para aluno - dinamico
	Nota* p = new Nota;
	
	float aux_media = 0;
	
	for(int i=0;i<4;i++){
		cin >> p->notas[i];
		aux_media += p->notas[i];
	}
	
	p->media = aux_media/4;
	
	cout << fixed << setprecision(2);
	cout << p->media << endl;
	
	
	delete p;
	
	return 0;
}