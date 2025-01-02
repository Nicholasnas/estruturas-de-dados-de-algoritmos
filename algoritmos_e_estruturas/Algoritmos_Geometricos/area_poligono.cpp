// Contexto: Um designer de jogos precisa saber se um objeto (representado por um ponto) está dentro de uma área segura (um polígono) no mapa do jogo.
// Entradas:
// Primeiro, um inteiro N (3 <= N <= 100) representando o número de vértices do polígono, seguido por N pares de inteiros x, y (-100 <= x, y <= 100) para os vértices. Em seguida, um par px, py para o ponto.
// Saídas:
// "DENTRO" se o ponto estiver dentro do polígono, "!(DENTRO)" se não.
// Casos de teste:


// Exemplo de entrada 
// 4 0 0 0 4 4 4 4 0 2 2
// Exemplo de saída 
// DENTRO

// Exemplo de entrada 
// 4 0 0 0 4 4 4 4 0 5 5	
// Exemplo de saída 
// !(DENTRO)




#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

struct Ponto {
    int x;
    int y;
};

double area_triangulo(Ponto a, Ponto b, Ponto c) {
    return ((a.x * b.y) - (a.y * b.x) +
            (a.y * c.x) - (a.x * c.y) +
            (b.x * c.y) - (b.y * c.x)) / 2.0;
}


bool verifica_ponto_interno_poligono(Ponto a, Ponto b, Ponto c, Ponto d, Ponto p){

    float area_retangulo = area_triangulo(a,b,c) + area_triangulo(b,c,d);    
    float a1 = area_triangulo(p,a,b);    
    float a2= area_triangulo(p,b,c);    
    float a3 = area_triangulo(p,c,d);    
    float a4 = area_triangulo(p,a,d);

    if (area_retangulo == a1+a2+a3+a4){
        return true;
    }    
    else return false;
}

int main() {
    Ponto a, b, c, d, p;
    int arestas;
    cin >> arestas;


    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;    
    cin >> p.x >> p.y;    


    if(verifica_ponto_interno_poligono(a,b,c,d,p)){
        cout << "DENTRO" << endl;
    }
    else cout << "!(DENTRO)" << endl;
    
    return 0;
}
