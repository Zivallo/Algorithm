#include <iostream>
using namespace std;
int N, M, result;
int map[550][550], used[550][550];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

void input() {
	result = 0;
	cin >> N >> M;
	for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) cin >> map[y][x];
}
void dfs(int ty, int tx, int lev, int sum) {
	if (lev == 3) {
		if (sum > result) result = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = ty + drY[i];
		int nx = tx + drX[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (used[ny][nx] == 1)continue;
		used[ny][nx] = 1;
		dfs(ny, nx, lev + 1, sum + map[ny][nx]);
		dfs(ty, tx, lev + 1, sum + map[ny][nx]);
		used[ny][nx] = 0;
	}
}
void solve() {
	input();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			used[y][x] = 1;
			dfs(y, x, 0, map[y][x]);
		}
	}
	cout << result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}