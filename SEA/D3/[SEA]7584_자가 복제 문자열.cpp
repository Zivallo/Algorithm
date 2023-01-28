#include <iostream>
using namespace std;
long long T, K;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> K; K -= 1;
		cout << "#" << t << " "; 
		while (K >= 0) {
			if (K % 2 == 1) K = (K - 1) / 2;
			if (K % 4 == 0) { cout << "0\n"; break; }
			else if (K % 2 == 0) { cout << "1\n"; break; }
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