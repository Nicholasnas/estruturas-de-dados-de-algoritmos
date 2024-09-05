// usando estrategia gulosa

#include <iostream>

using namespace std;


struct pedra
{
	char nome[30];
	int peso;
	int volume;
	int valor;
	bool escolhida = false;
};
// força bruta e estrategia gulosa
// pega  a solução mais apetitosa do problema
// nao precisa criar o algoritmo do zero
// fazer o exercicio da estrategia gulosa para pedras preciosas.
// solucao de forca bruta testando todas posibilidades - O(2^n)
// estrategia gulosa para essa exercicio, pedra mais valiosa p/ menos valiosa
// ordenar por valor
// retornar a combinação de pedras, quais pedras foram escolhidas.
// retorna o melhor valor possivel, resolver 

int melhor_combinacao(pedra pedras[],int n, int i, int cap_peso, int cap_volume, bool escolhas[]){ 
	// i: pedra atual
	int solucao1=0, solucao2=0;
	
	if (i >= n || cap_volume <=0 || cap_peso <= 0){
		return 0;
	}
	// solucao é o valor das pedras colocas na mochila
	// nao escolheu a pedra inicial 
	solucao1 = 0 + melhor_combinacao(pedras, n, i+1, cap_peso, cap_volume); 
	
	// pega a primeria pedra
	int valor = pedras[i].valor;
	int nova_cap_peso = cap_peso - pedras[i].peso;
	int nova_cap_volume = cap_volume - pedras[i].volume;
	
	if (nova_cap_peso >= 0 && nova_cap_volume >= 0){
		solucao2 = pedras[i].valor + 
		melhor_combinacao(pedras, n, i+1, nova_cap_peso, nova_cap_volume);
		
	}
	
	if (solucao1 > solucao2)
		return solucao1;
	else
	{
		return solucao2;
	}
}

int main(){
	int n;
	cin >> n;
	bool escolha[n];
	
	// qtd de pedras
	
	// Entrada das pedras
	pedra pedras[n];

	for (int i=0;i<n;i++){
		float volume;
		cin >> pedra;
		cin >> pedras[i].peso;
		cin >> volume;
		
		pedras[i].volume = volume*1000;
		cin >> pedras[i].valor;
		
	}
	
	for(int i)
	
}