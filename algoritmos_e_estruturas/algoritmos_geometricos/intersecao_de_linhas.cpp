#include <iostream>
#include <math.h>
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

double distancia(Ponto p1, Ponto p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

int posicao_ralativa(Ponto a, Ponto b, Ponto p) {
    double area = area_triangulo(a, b, p);
    if (area > 0) {
        return 1;  // p está à esquerda de ab - anti horario
    } else if (area < 0) {
        return -1;  // p está à direita de ab - sentido horario
    } else {
        return 0;  // p está alinhado - colinear
    }
}

// Verificando se um ponto esta sobre um segmento de reta
// e entre as extremidades do segmento, p ponto a ser verificado
bool noSegmento(Ponto a, Ponto b, Ponto p) {
    return (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
            p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y));
}

// Verifica se dois segmentos se cruzam
bool segmentosSeCruzam(Ponto a, Ponto b, Ponto c, Ponto d) {
    int o1 = posicao_ralativa(a, b, c);
    int o2 = posicao_ralativa(a, b, d);
    int o3 = posicao_ralativa(c, d, a);
    int o4 = posicao_ralativa(c, d, b);

    // Caso geral
    if (o1 != o2 && o3 != o4)
        return true;

    // Casos especiais: pontos colineares
    if (o1 == 0 && noSegmento(a, b, c)) 
        return true;
    if (o2 == 0 && noSegmento(a, b, d))
         return true;
    if (o3 == 0 && noSegmento(c, d, a)) 
        return true;
    if (o4 == 0 && noSegmento(c, d, b))
         return true;

    return false;
}

int main() {
    Ponto a, b, c, d;

    // Entrada dos pontos dos segmentos
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    // Determinar se os segmentos se cruzam
    if (segmentosSeCruzam(a, b, c, d)) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}
