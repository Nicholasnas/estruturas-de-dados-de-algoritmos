#include <iostream>

using namespace std;

struct pedra{
    string nome;
    float peso;
    float volume;
    float valor;
    float razao;
    bool escolhida;
};

void escolhe_pedras_gulosa(pedra pedras[], int n, int cap_peso, int cap_volume){
	for(int i=0; i<n; i++){
		if(pedras[i].peso <= cap_peso && pedras[i].volume <= cap_volume){
			cout << pedras[i].nome << endl;
			cap_peso -= pedras[i].peso;
			cap_volume -= pedras[i].volume;
		}
	}
}
int main() {
    int n;
    cin >> n;

    pedra pedras[n];
 
    for (int i = 0; i < n; i++) {
        string nome;
        float volume, peso, valor;
        cin >> nome >> volume >> peso >> valor;
        pedras[i].nome = nome;
        pedras[i].volume = volume;
        pedras[i].peso = peso;
        pedras[i].valor = valor;        
        pedras[i].escolhida = false;        

    }
    escolhe_pedras_gulosa(pedras, n-1, 400, 1000);

    return 0;
}
