#include <iostream>
#define MAX_INT 999

using namespace std;


int fibonacci(int n) {
    int memoria[n+1];
    int i;
    if (n == 0) {
        return 0;
    }else if(n==1){
        return 1;
    }
    else {
        memoria[0] = 0;
        memoria[1] = 1;
        for(i=2;i<=n;i++){
            memoria[i] = memoria[i-1] + memoria[i-2];
        }
    }
    return memoria[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;  
    return 0;
}
