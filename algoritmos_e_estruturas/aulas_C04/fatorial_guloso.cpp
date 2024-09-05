#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int fatorial[11];
	fatorial[0] = 1;
	for (int i=1;i<=10;i++){
		fatorial[i] = fatorial[i-1] *i;
	}
	/// escolher os numeros do maior para o menor
	int ans=0;
	for(int i=10;i>0;i--){
		// quantas vezes tirar o numero da resposta
		// n cabe em fat [i]	jjj
		int at = n/fatorial[i];
		ans += at;
		n -= at*fatorial[i];
	}
	
	
	cout << ans << endl;
	return 0;
}