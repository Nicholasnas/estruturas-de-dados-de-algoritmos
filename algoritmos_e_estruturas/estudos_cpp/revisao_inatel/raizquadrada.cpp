#include <iostream>
#include <cmath>

using namespace std;

float calcula(float x,float ex_inicial){
	
	if (abs(pow(ex_inicial,2)- x)){
		return ex_inicial;
	}
	else {
		 return	sqrt(x);
	}
	
}

int main()
{
	float x, ex_inicial, e;
	
	cin >> x >> ex_inicial >> e;
	cout << calcula(x, ex_inicial);
	return 0;
}