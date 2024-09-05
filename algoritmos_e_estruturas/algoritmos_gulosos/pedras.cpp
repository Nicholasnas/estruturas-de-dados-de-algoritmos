#include <iostream>

using namespace std;

struct pedra {
	string nome;
	float peso;
	float volume;
	float valor;
};

float minerador_guloso(pedra pedras[], int n, int i, 
	float cap_peso, float cap_vol, string pedras_selecionadas[], int num_selecion){
	if (i >= n || cap_peso <= 0 || cap_vol <= 0){
		return 0;
	}
    
    // escolhendo não pegar a primeira pedra
    float sem_pegar = 0 + minerador_guloso(pedras, n, i+1,
	 cap_peso, cap_vol, pedras_selecionadas, num_selecion);

    float pegar_a_pedra=0;
    float valor = pedras[i].valor;
    float nova_capa_peso = cap_peso - pedras[i].peso;
    float nova_capa_volume = cap_vol - pedras[i].volume;

    // Caso escolhe pegar a primeira pedra
    if (nova_capa_peso >= 0 && nova_capa_volume >=0){
    	pedras_selecionadas[num_selecion] = pedras[i].nome;
    	num_selecion += 1;
        pegar_a_pedra =  valor + minerador_guloso(pedras,n, i+1,
		 nova_capa_peso, nova_capa_volume, pedras_selecionadas, num_selecion);
    }

    return max(sem_pegar, pegar_a_pedra);
}

int main()
{
	int n;
	
	cin >> n;
	pedra pedras[n];
	
    string pedras_selecionadas[n];
    int num_selecionadas = 0;
	
	for(int i=0;i<n;i++){
        string nome;
	   	float volume, peso, valor;
        cin >> nome >> peso >> volume >> valor;
		pedras[i].nome = nome;
		pedras[i].volume = volume * 1000;
        pedras[i].peso = peso;
		pedras[i].valor = valor;
	}
    minerador_guloso(pedras,n,0,400,1000, pedras_selecionadas, num_selecionadas);
    for (int i = 0; i < num_selecionadas; ++i) {
        cout << pedras_selecionadas[i] << endl;
    }
	return 0;
}