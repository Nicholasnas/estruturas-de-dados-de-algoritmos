#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

// Estrutura para representar um ponto
struct Point {
    int x, y;
};

// Função para calcular a distância entre dois pontos
double distance(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

// Função para calcular o produto vetorial de OA e OB
int crossProduct(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// Função comparadora para ordenar pontos
bool compare(Point a, Point b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

// Função para encontrar o fecho convexo usando Graham Scan
list<Point> convexHull(list<Point>& points) {
    // Converter lista para vetor temporário para ordenar
    list<Point>::iterator it;
    Point tempArray[10000];
    int idx = 0;
    for (it = points.begin(); it != points.end(); ++it) {
        tempArray[idx++] = *it;
    }
    sort(tempArray, tempArray + idx, compare);

    list<Point> lower, upper;

    // Construir o fecho inferior
    for (int i = 0; i < idx; i++) {
        while (lower.size() >= 2) {
            list<Point>::iterator secondLast = lower.end();
            secondLast--;
            list<Point>::iterator last = secondLast;
            secondLast--;
            if (crossProduct(*secondLast, *last, tempArray[i]) <= 0) {
                lower.pop_back();
            } else {
                break;
            }
        }
        lower.push_back(tempArray[i]);
    }

    // Construir o fecho superior
    for (int i = idx - 1; i >= 0; i--) {
        while (upper.size() >= 2) {
            list<Point>::iterator secondLast = upper.end();
            secondLast--;
            list<Point>::iterator last = secondLast;
            secondLast--;
            if (crossProduct(*secondLast, *last, tempArray[i]) <= 0) {
                upper.pop_back();
            } else {
                break;
            }
        }
        upper.push_back(tempArray[i]);
    }

    // Remover o último ponto para evitar duplicatas
    lower.pop_back();
    upper.pop_back();

    // Combinar as partes inferior e superior
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

// Função para calcular o material mínimo necessário
int minimumFencingMaterial(int n, list<Point>& points) {
    list<Point> hull = convexHull(points);

    // Calcular o perímetro
    double perimeter = 0;
    list<Point>::iterator it1 = hull.begin();
    list<Point>::iterator it2 = hull.begin();
    ++it2;
    while (it2 != hull.end()) {
        perimeter += distance(*it1, *it2);
        ++it1;
        ++it2;
    }
    perimeter += distance(*it1, *hull.begin());

    // Arredondar para cima e retornar como inteiro
    return (int)ceil(perimeter);
}

int main() {
    int n;
    cin >> n;

    list<Point> points;
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    cout << minimumFencingMaterial(n, points) << endl;
    return 0;
}