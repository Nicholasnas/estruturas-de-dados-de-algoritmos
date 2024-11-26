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
