#include <iostream>
using namespace std;
int n, memo[40] = { 0,0,1 };

int fibo(int th) {
	if (th == 1) return 0;
	if (th == 2) return 1;
	if (memo[th] > 0) return memo[th];

	int a = fibo(th - 1);
	int b = fibo(th - 2);

	memo[th] = a + b;
	return a + b;
}

int main() {
	cin >> n;
	cout << fibo(n);
	return 0;
}