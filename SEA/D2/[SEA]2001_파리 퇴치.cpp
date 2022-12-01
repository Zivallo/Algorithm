#include <iostream>
using namespace std;
int T, N, M;
int m[20][20];
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> M; int r = 0;
		for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
			cin >> m[y][x];
			if (y >= M - 1 && x >= M - 1) {
				int s = 0;
				for (int i = 0; i < M; i++)for (int j = 0; j < M; j++) {
					s += m[y - i][x - j];
				}
				r = (r > s ? r : s);
			}
		}
		cout << "#" << t << " " << r << "\n";
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