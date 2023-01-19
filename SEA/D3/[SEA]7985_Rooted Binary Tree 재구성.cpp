#include <iostream>
using namespace std;
int T, K;
int a[(1 << 10) + 1];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> K;
		for (int i = 1; i < (1 << K); i++)cin >> a[i];
		cout << "#" << t << " ";
		for (int i = K; i > 0; i--) {
			for (int j = (1 << i) / 2; j < (1 << K); j += (1 << i)) {
				cout << a[j] << " ";
			}
			cout << "\n";
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