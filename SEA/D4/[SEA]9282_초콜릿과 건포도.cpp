#include <iostream>
#include <cstring>
using namespace std;
int T, map[55][55], s[55][55], d[55][55][55][55];
int n, m;

void input() {
	memset(s, 0, sizeof(s));
	memset(d, -1, sizeof(d));
	cin >> n >> m;
	for (int y = 1; y <= n; y++)for (int x = 1; x <= m; x++) {
		cin >> map[y][x];
		s[y][x] = map[y][x] + s[y - 1][x] + s[y][x - 1] - s[y - 1][x - 1];
	}
}
int dfs(int y1, int x1, int y2, int x2) {
	if (y1 == y2 && x1 == x2)return 0;
	if (d[y1][x1][y2][x2] != -1)return d[y1][x1][y2][x2];

	d[y1][x1][y2][x2] = 21e8;
	int cnt = s[y2][x2] - s[y2][x1 - 1] - s[y1 - 1][x2] + s[y1 - 1][x1 - 1];

	for (int yc = y1; yc < y2; yc++) {
		int cnt1 = dfs(y1, x1, yc, x2);
		int cnt2 = dfs(yc + 1, x1, y2, x2);
		d[y1][x1][y2][x2] = min(d[y1][x1][y2][x2], cnt1 + cnt2 + cnt);
	}
	for (int xc = x1; xc < x2; xc++) {
		int cnt1 = dfs(y1, x1, y2, xc);
		int cnt2 = dfs(y1, xc + 1, y2, x2);
		d[y1][x1][y2][x2] = min(d[y1][x1][y2][x2], cnt1 + cnt2 + cnt);
	}
	return d[y1][x1][y2][x2];
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		input();
		int result = dfs(1, 1, n, m);
		cout << "#" << t << " " << result << "\n";
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