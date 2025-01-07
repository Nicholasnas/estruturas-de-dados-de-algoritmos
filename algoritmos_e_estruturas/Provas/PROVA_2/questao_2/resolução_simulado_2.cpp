#include <iostream>
#include <math.h>
using namespace std;

typedef struct {
	int x;
	int y;	
} Ponto;

double area_triangulo(
	Ponto a, 
	Ponto b, 
	Ponto c
){
	return 
		((a.x*b.y) - (a.y*b.x) + 
		(a.y*c.x) - (a.x*c.y) + 
		(b.x*c.y) - (b.y*c.x))/2.0;  
}

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

int orientacao(Ponto a, Ponto b, Ponto c){
	double area = area_triangulo(a,b,c);
	if(area > 0){
		return 1; 
	} else if(area < 0){
		return -1; 
	} else {
		return 0; 
	}
}

int main(){
    Ponto a,b,c,d;
    int espessura, diamentro, altura;

    cin >>a.x >> a.y;
    cin >>b.x >> b.y;
    cin >>c.x >> c.y;
    cin >>d.x >> d.y;

    espessura = distancia(a,b);
    altura = distancia(a,c);
    diamentro = distancia(c,d);

    cout << espessura << endl;
    cout << diamentro<< endl;
    cout << altura << endl;
    
    return 0;
}