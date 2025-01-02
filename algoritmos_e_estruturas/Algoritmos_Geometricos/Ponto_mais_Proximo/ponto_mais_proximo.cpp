#include <iostream>
#include <math.h>
#include <iomanip>
#include <list>

using namespace std;

struct Ponto {
    int x;
    int y;
};

Ponto distancia(list<Ponto> pontos, Ponto p) {
    Ponto proximo;
    float menor = 99999; 

    while (!pontos.empty()) {
        Ponto aux = pontos.front();
        pontos.pop_front();

        float dist = sqrt(pow(aux.x - p.x, 2) + pow(aux.y - p.y, 2));

        if (dist < menor) {
            menor = dist;
            proximo = aux;
        }
    }
    return proximo;
}

int main() {
    int qtd_pontos;
    list<Ponto> pontos;

    cin >> qtd_pontos;

    Ponto p;
    for (int i = 0; i < qtd_pontos; i++) {
        cin >> p.x >> p.y;
        pontos.push_back(p);
    }

    cin >> p.x >> p.y;

    Ponto proximo = distancia(pontos, p);

    cout << proximo.x << " " << proximo.y << endl;

    return 0;
}
