#include <iostream>
#include <cstring>
using namespace std;
int N, M, K, result;
int map[10][55][55];
int cmd[10][3], used[10];
int drY[4] = { 1,0,-1,0 };
int drX[4] = { 0,1,0,-1 };

void input() {
	result = 21e8;
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++)for (int x = 1; x <= M; x++)cin >> map[0][y][x];
	for (int i = 0; i < K; i++) cin >> cmd[i][0] >> cmd[i][1] >> cmd[i][2];
}
int findResult(int lev) {
	int sum = 21e8;
	for (int y = 1; y <= N; y++){
		int tempsum = 0;
		for (int x = 1; x <= M; x++) {
			tempsum += map[lev - 1][y][x];
		}
		if (sum > tempsum) sum = tempsum;
	}
	return sum;
}
void rotate(int lev, int idx) {
	int r = cmd[idx][0], c = cmd[idx][1], s = cmd[idx][2];
	int dir = 0;
	for (int i = 0; i < s; i++) {
		int sy = r - s + i, sx = c - s + i;
		int y = r - s + i, x = c - s + i;
		while (1) {
			int ny = y + drY[dir];
			int nx = x + drX[dir];
			if (ny<sy || nx<sx || ny>(r + s - i) || nx>(c + s - i)) {
				dir = (dir + 1) % 4;
				continue;
			}
			if (ny == sy && nx == sx) break;
			swap(map[lev][y][x], map[lev][ny][nx]);
			y = ny; x = nx;
		}
	}
}
void dfs(int lev) {
	if (lev == K+1) {
		result = min(result, findResult(lev));
	}
	for (int i = 0; i < K; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		memcpy(map[lev], map[lev - 1], sizeof(map[lev]));
		rotate(lev, i);
		dfs(lev + 1);
		used[i] = 0;
	}
}
void solve() {
	input();
	dfs(1);
	cout << result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}