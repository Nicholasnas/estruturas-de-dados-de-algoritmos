#include<iostream>
using namespace std;

struct pedra{
	string nome;
	int peso;
	int volume;
	int valor;
};

int potencia(int base, int expoente){
	if(expoente == 0) return 1;
	return base * potencia(base, expoente-1);
}

int calcula_valor(pedra pedras[], int n, int cap_peso, int cap_volume, bool pedras_atuais[]){
	int valor = 0;
	for(int i=0; i<n; i++){
		if(pedras_atuais[i]){
			cap_peso -= pedras[i].peso;
			cap_volume -= pedras[i].volume;
			if(cap_peso >= 0 && cap_volume >= 0){
				valor += pedras[i].valor;
			} else return 0;			
		}
	}
	return valor;
}

void escolhe_pedras_iterativo(pedra pedras[], int n, int cap_peso, int cap_volume){
	bool melhores_pedras[n], pedras_atuais[n];
	for(int i=0; i<n; i++){
		melhores_pedras[i] = false;
		pedras_atuais[i] = false;
	}
	int valor_atual = 0, melhor_valor = 0;
	int limite = potencia(2, n);
	for(int i=1; i <= limite; i++){
		for(int j=0; j<n; j++){
			if(pedras_atuais[j] == false){
				pedras_atuais[j] = true;
				break;
			} else {
				pedras_atuais[j] = false;
			}
		}
		valor_atual = calcula_valor(pedras, n, cap_peso, cap_volume, pedras_atuais);
		if(valor_atual > melhor_valor){
			melhor_valor = valor_atual;
			for(int i=0; i<n; i++)
				melhores_pedras[i] = pedras_atuais[i];
		}
	}
	cout << melhor_valor << endl;
	for(int i=0; i<n; i++){
		if(melhores_pedras[i])
		  cout << pedras[i].nome << endl;
	}
}