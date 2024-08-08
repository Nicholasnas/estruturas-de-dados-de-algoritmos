#include <iostream>

using namespace std;

int potencia_recursion(int a, int n){
	if (n == 0){
		return 1;
	}
	else if (n == 1) {
		return a;
	}
	else{
		return a * potencia_recursion(a, n-1);
	}
}

int main()
{
	int a, n;
	
	cin >> a >> n;
	cout << potencia_recursion(a, n);
	return 0;
}