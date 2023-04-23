#include <iostream>
#include <queue>
using namespace std;
int m[20][20];
int sy, sx, ty, tx;
queue<pair<int, int>> q;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};


void input() {
	for (int y = 0; y < 16; y++)for (int x = 0; x < 16; x++) {
		char c; cin >> c;
		m[y][x] = c - '0';
		if (m[y][x] == 2) { sy = y; sx = x; }
		if (m[y][x] == 3) { ty = y; tx = x; }
	}
}
void solve() {
	for (int T = 0; T < 10; T++) {
		int t, f = false; cin >> t;
		q = queue<pair<int, int>>();
		int u[20][20] = { 0 };
		input();
		q.push({ sy, sx });
		u[sy][sx] = 1;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= 16 || nx < 0 || nx >= 16)continue;
				if (m[ny][nx] == 1)continue;
				if (u[ny][nx] == 1)continue;
				if (m[ny][nx] == 3) { f = true; continue; }
				u[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
		if (f)cout << "#" << t << " 1\n";
		else cout << "#" << t << " 0\n";
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