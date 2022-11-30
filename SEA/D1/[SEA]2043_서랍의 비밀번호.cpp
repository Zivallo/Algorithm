#include <iostream>
using namespace std;

int main() {
	int P, K; cin >> P >> K;
	if (P - K > 0) cout << P - K + 1;
	else {
		cout << 1000 + (P - K) + 1;
	}
}