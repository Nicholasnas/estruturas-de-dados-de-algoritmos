// Contexto:
// Um arquiteto precisa calcular a área de um triângulo para determinar o espaço disponível para a construção de um novo prédio.
// Entradas:
// Três pares de inteiros x1, y1, x2, y2, x3, y3 (-100 <= x, y <= 100).
// Saídas:
// Um número decimal representando a área do triângulo.
// Casos de teste:
// Exemplo de entrada 


// 0 0 4 0 2 3
// Exemplo de saída 
// 6.0
// 1 1 1 1 1 1	
// Exemplo de saída 
// 0.0


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

int main() {
    Ponto a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    cout << fixed << setprecision(1);
    cout << area_triangulo(a, b,c) << endl;
    return 0;
}
