#include <iostream>

using namespace std;

struct ROCHA{
	char nome[30];
	float peso, volume, valor;
}familia_pedra;




int main()
{
	
	// carrinho 1 m3, peso de 400 kg
	// volumes, pesos e preco de cada pedra
	// entrada n - qtd de pedras informadas
	// n linhas com nome, peso, volume e valor de cada uma
	// saida de nomes de pedras preciosas
	
	int n;
	struct ROCHA pedra[n];
	
	
	// Entrada de dados
	for (int i = 0; i < n; i++){
		char nome[30];
		float peso, volume, valor;
		cin >> nome >> peso >> volume >> valor;
		pedra[i].nome = nome;
		pedra[i].peso = peso;
		pedra[i].volume = volume;
		pedra[i].valor = valor;
	
	}
	
	
	
	
	return 0;
}