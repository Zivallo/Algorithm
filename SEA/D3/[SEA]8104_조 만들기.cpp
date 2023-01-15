#include <iostream>
using namespace std;
int T, N, K;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		cout << "#" << t << " ";
		if (N % 2 == 0) {
			for (int i = 0; i < K; i++) cout << (N * K + 1) * (N / 2) << " ";
		}
		else {
			for (int i = 0; i < K; i++) cout << ((N-1) * K + 1) * (N / 2) + ((N - 1) * K + (i + 1)) << " ";
		}
		cout << "\n";
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