#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	cout << ((1 + n) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0));
}