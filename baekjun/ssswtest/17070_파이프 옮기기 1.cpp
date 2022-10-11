#include <iostream>
using namespace std;
int N, result;
int map[20][20];
int drY[4][3] = {
	{0,1,10},
	{0,1,1},
	{10,1,1},
	{0,1,2}
};
int drX[3][3] = {
	{1,1,10},
	{1,1,0},
	{10,1,0}
};
void input() {
	cin >> N;
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++)cin >> map[y][x];
	map[0][0] = map[0][1] = 1;
}
bool isInstall(int y,int x) {
	for (int i = 0; i < 3; i++) {
		int ny = y + drY[1][i];
		int nx = x + drX[1][i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) return false;
		if (map[ny][nx] == 1)return false;
	}
	return true;
}
void dfs(int y, int x,int dir) {
	if (y == N - 1 && x == N - 1) {
		result++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (drY[dir][i] == 10)continue;
		if (i == 1) if (!isInstall(y,x)) continue;
		int ny = y + drY[dir][i];
		int nx = x + drX[dir][i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
		if (map[ny][nx] == 1)continue;
		map[ny][nx] = 1;
		dfs(ny, nx, drY[3][i]);
		map[ny][nx] = 0;
	}
}
void solve() {
	input();
	dfs(0, 1,0);
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