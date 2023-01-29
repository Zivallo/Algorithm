#include <iostream>
using namespace std;
int T, N, M;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		int c[44] = { 0 }, maxi = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (++c[i + j] > maxi)maxi = c[i + j];
			}
		}
		cout << "#" << t << " ";
		for (int i = 2; i <= N + M; i++) {
			if (c[i] == maxi)cout << i << " ";
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