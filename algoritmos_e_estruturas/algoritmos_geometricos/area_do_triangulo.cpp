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
