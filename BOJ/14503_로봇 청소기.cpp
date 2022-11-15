#include <iostream>
using namespace std;
int N, M, r, c, d, a, m[55][55], u[55][55];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

pair<int, pair<int, int>> findInfo(int d, int r, int c) {
	int dir = d;
	for (int i = 0; i < 4; i++) {
		dir = (dir - 1 < 0 ? 3 : dir - 1);
		int ny = r + dy[dir];
		int nx = c + dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
		if (u[ny][nx] == 1 || m[ny][nx] == 1)continue;
		return { dir,{ny,nx} };
	}
	dir = (d + 2) % 4;
	int ny = r + dy[dir];
	int nx = c + dx[dir];
	if (ny < 0 || nx < 0 || ny >= N || nx >= M) return { -1,{0,0} };
	if (m[ny][nx] == 1) return { -1,{0,0} };
	return { d,{ny,nx} };
}
void solve() {
	cin >> N >> M >> r >> c >> d;
	for (int y = 0; y < N; y++)for (int x = 0; x < M; x++)cin >> m[y][x];
	u[r][c] = 1; a = 1;
	while (1) {
		pair<int, pair<int, int>> info = findInfo(d, r, c);
		if (info.first == -1)break;
		if (u[info.second.first][info.second.second] != 1) {
			a++;
			u[info.second.first][info.second.second] = 1;
		}
		d = info.first;
		r = info.second.first;
		c = info.second.second;
	}
	cout << a << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}