#include <iostream>
#include <cmath>


using namespace std;

int somar(int &x, int &y){

    // x = 10;
    // y = 20;
    x*= 10;
    y*= 2;
    return x + y;

}

int main(){
    int a=2, b=5;
    int soma, media;

    cout << pow(8, a) << endl;
    soma = somar(a,b);
    cout << soma << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    media = (a + b) / 2;


    (media >= 15) ? cout << 'A': cout << 'B';
    if (not media != 14){
        cout <<endl<<"passou";
    }
}



