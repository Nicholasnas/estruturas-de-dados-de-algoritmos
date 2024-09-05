    #include <stdio.h>
    #include <iostream>
    #include <iomanip>

    using namespace std;
    
    int main() {
        
        // Variaves
        float valor;
        int notas[6] = {100, 50, 20, 10, 5, 2};
        int qtd_notas[6] = {0,0,0,0,0,0};
        int moedas[6] = {100, 50, 25, 10, 5, 1}; // Valores das moedas em centavos

        float qtd_moedas[6] = {0, 0, 0,0,0,0};
        int centavos;

        // Entrada de dados - Valor
        cin >> valor;
        
        // Calcular notas
        
        for (int i=0; i < 6; i++){
            qtd_notas[i] = valor / notas[i];
            valor -= qtd_notas[i] * notas[i];
        }
        
        // cout << "resto: " << valor << endl; 
        
        centavos = valor * 100;
        // Calcular moedas
        
        for (int i=0; i < 6; i++){
            qtd_moedas[i] = centavos / moedas[i];
            centavos %=  moedas[i];
        }

        // Saida de dados
        
        cout << "NOTAS:" << endl;

        for (int i=0; i < 6; i++){
            cout << qtd_notas[i] << " nota(s) de R$ " << float(notas[i]) << ".00" << endl;
        }
        
        cout << "MOEDAS:" << endl;

        for (int i=0; i < 6; i++){
            cout << int(qtd_moedas[i]) << " moedas(s) de R$ " << float(moedas[i]) / 100.0 << setprecision(2) <<  endl;
        }

        return 0;
    }