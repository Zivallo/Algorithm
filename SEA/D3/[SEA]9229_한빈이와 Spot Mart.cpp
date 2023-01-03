#include <iostream>
using namespace std;
int T, N, M, r;
int w[1010];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> M; r = 0;
		for (int i = 0; i < N; i++)cin >> w[i];
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (w[i] + w[j] > M)continue;
				if (w[i] + w[j] > r)r = w[i] + w[j];
				if (r == M)break;
			}
			if (r == M)break;
		}
		cout << "#" << t << " " << (r == 0 ? -1 : r) << "\n";
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