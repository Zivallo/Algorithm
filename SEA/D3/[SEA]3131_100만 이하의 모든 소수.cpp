#include <iostream>
using namespace std;
int prime[1000010];

void solve() {
	for (int i = 2; i < 1000000; i++) {
		if (prime[i] == 1)continue;
		cout << i << " ";
		for (int j = 2; j < 1000000; j++) {
			if (i * j > 1000000)break;
			prime[i * j] = 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}