#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char map[11][11], map1[11][11][11];
pair<int, int> B;
pair<int, int> R;
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
int result = 21e8, N, M;
queue<pair<int, int>> q;
void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'B') {
				B.first = y;
				B.second = x;
			}
			if (map[y][x] == 'R') {
				R.first = y;
				R.second = x;
			}
		}
	}
}
void setQueue(int dir) {
	while (!q.empty()) q.pop();
	if (dir == 0) {
		if (B.first < R.first) {
			q.push({ B.first, B.second });
			q.push({ R.first, R.second });
		}
		else {
			q.push({ R.first, R.second });
			q.push({ B.first, B.second });
		}
	}
	if (dir == 1) {
		if (B.first > R.first) {
			q.push({ B.first, B.second });
			q.push({ R.first, R.second });
		}
		else {
			q.push({ R.first, R.second });
			q.push({ B.first, B.second });
		}
	}
	if (dir == 2) {
		if (B.second < R.second) {
			q.push({ B.first, B.second });
			q.push({ R.first, R.second });
		}
		else {
			q.push({ R.first, R.second });
			q.push({ B.first, B.second });
		}
	}
	if (dir == 3) {
		if (B.second > R.second) {
			q.push({ B.first, B.second });
			q.push({ R.first, R.second });
		}
		else {
			q.push({ R.first, R.second });
			q.push({ B.first, B.second });
		}
	}
}
int setMap(int dir,int lev) {
	setQueue(dir);
	int flagR = 0, flagB = 0;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		int tar = 0;
		for (int i = 1; i < 10; i++) {
			int ny = nowy + drY[dir] * i;
			int nx = nowx + drX[dir] * i;
			if ((map1[lev][ny][nx] == 'O') && (map1[lev][nowy][nowx] == 'R')) {
				tar = 1;
				flagR = 1;
				map1[lev][nowy][nowx] = '.';
				break;
			}
			if ((map1[lev][ny][nx] == 'O') && (map1[lev][nowy][nowx] == 'B')) {
				tar = 1;
				flagB = 1;
				map1[lev][nowy][nowx] = '.';
				break;
			}
			if (map1[lev][ny][nx] != '.') {
				tar = i;
				break;
			}
		}
		if (tar == 1) continue;
		int ny1 = nowy + drY[dir] * (tar - 1);
		int nx1 = nowx + drX[dir] * (tar - 1);
		map1[lev][ny1][nx1] = map1[lev][nowy][nowx];
		map1[lev][nowy][nowx] = '.';
		if (map1[lev][ny1][nx1] == 'B') {
			B.first = ny1;
			B.second = nx1;
		}
		if (map1[lev][ny1][nx1] == 'R') {
			R.first = ny1;
			R.second = nx1;
		}
	}
	if (flagR == 1 && flagB == 1) return 1;
	if (flagR == 1) {
		result = min(result, lev);
		return 1;
	}
	if (flagB == 1) return 1;
	return 0;
}
void dfs(int lev) {
	if (result <= lev || lev >= 11) return;
	int Ry = R.first;
	int Rx = R.second;
	int By = B.first;
	int Bx = B.second;
	for (int i = 0; i < 4; i++) {
		memcpy(map1[lev], map1[lev - 1], sizeof(map1[lev]));
		R.first = Ry;
		R.second = Rx;
		B.first = By;
		B.second = Bx;
		int flag = setMap(i, lev);
		if (flag) continue;
		if (result <= lev) return;
		dfs(lev + 1);
		if (result <= lev) return;
	}
}
void solve() {
	input();
	memcpy(map1[0], map, sizeof(map));
	dfs(1);
	if (result == 21e8) result = -1;
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