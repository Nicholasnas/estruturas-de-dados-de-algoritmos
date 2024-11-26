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
bool inside(Ponto a, Ponto b, Ponto c, Ponto d){
    float area = area_triangulo(a,b,c);
    float area1 = area_triangulo(d,b,c);
    float area2 = area_triangulo(d,a,c);
    float area3 = area_triangulo(d,a,b);

    return area == (area1 + area2 + area3);
}

int main() {
    Ponto a, b, c, d;


    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    if (inside(a, b, c, d)) {
        cout << "DENTRO" << endl;
    } else {
        cout << "!(DENTRO)" << endl;
    }

    return 0;
}
