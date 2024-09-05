#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double potencia(double x, double estimativa, double tolerancia){

    double nova_estimativa = 0.5 *(estimativa +x/ estimativa);

    if (abs(nova_estimativa - estimativa) < tolerancia)
        return nova_estimativa;
    
    return potencia(x, nova_estimativa, tolerancia);

}

int main(){
    double x, estimativa, limite;

    cin >> x >> estimativa >> limite;
    cout << potencia(x, estimativa, limite) << fixed << setprecision(4);
    /// cout << "A raiz quadrada aproximada de " << x << " eh: " << potencia(x, estimativa, limite) << endl;
    return 0;
}