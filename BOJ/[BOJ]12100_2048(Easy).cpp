#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, map[7][22][22], result;
void input() {
	cin >> N;
	for (int y = 0; y < N; y++) for (int x = 0; x < N; x++)cin >> map[0][y][x];
}
void zero(int lev, int dir) {
	if (dir == 0) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (map[lev][y][x] == 0) continue;
				int ny = y;
				for (int i = 1; i <= N * N; i++) {
					ny -= 1;
					if (ny < 0) break;
					if (map[lev][ny][x] != 0) break;
					swap(map[lev][ny][x], map[lev][ny + 1][x]);
				}
			}
		}
	}
	if (dir == 1) {
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y >= 0; y--) {
				if (map[lev][y][x] == 0) continue;
				int ny = y;
				for (int i = 1; i <= N * N; i++) {
					ny += 1;
					if (ny >= N)break;
					if (map[lev][ny][x] != 0) break;
					swap(map[lev][ny][x], map[lev][ny - 1][x]);
				}
			}
		}
	}
	if (dir == 2) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[lev][y][x] == 0) continue;
				int nx = x;
				for (int i = 1; i <= N * N; i++) {
					nx -= 1;
					if (nx < 0) break;
					if (map[lev][y][nx] != 0) break;
					swap(map[lev][y][nx], map[lev][y][nx + 1]);
				}
			}
		}
	}
	if (dir == 3) {
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x >= 0; x--) {
				if (map[lev][y][x] == 0) continue;
				int nx = x;
				for (int i = 1; i <= N * N; i++) {
					nx += 1;
					if (nx >= N) break;
					if (map[lev][y][nx] != 0) break;
					swap(map[lev][y][nx], map[lev][y][nx - 1]);
				}
			}
		}
	}
}
void setMap(int lev, int dir) {
	if (dir == 0) {
		zero(lev, dir);
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N - 1; y++) {
				if (map[lev][y][x] == 0) continue;
				if (map[lev][y][x] == map[lev][y + 1][x]) {
					map[lev][y][x] += map[lev][y + 1][x];
					map[lev][y + 1][x] = 0;
				}
			}
		}
		zero(lev, dir);
	}
	else if (dir == 1) {
		zero(lev, dir);
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y > 0; y--) {
				if (map[lev][y][x] == 0) continue;
				if (map[lev][y][x] == map[lev][y - 1][x]) {
					map[lev][y][x] += map[lev][y - 1][x];
					map[lev][y - 1][x] = 0;
				}
			}
		}
		zero(lev, dir);
	}
	else if (dir == 2) {
		zero(lev, dir);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N - 1; x++) {
				if (map[lev][y][x] == 0) continue;
				if (map[lev][y][x] == map[lev][y][x + 1]) {
					map[lev][y][x] += map[lev][y][x + 1];
					map[lev][y][x + 1] = 0;
				}
			}
		}
		zero(lev, dir);
	}
	else if (dir == 3) {
		zero(lev, dir);
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x > 0; x--) {
				if (map[lev][y][x] == 0) continue;
				if (map[lev][y][x] == map[lev][y][x - 1]) {
					map[lev][y][x] += map[lev][y][x - 1];
					map[lev][y][x - 1] = 0;
				}
			}
		}
		zero(lev, dir);
	}
}
void setResult(int lev) {
	int mapMax = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			mapMax = max(mapMax, map[lev][y][x]);
		}
	}
	result = max(result, mapMax);
}
void dfs(int lev, int dir) {
	if (lev != 0) {
		memcpy(map[lev], map[lev - 1], sizeof(map[lev]));
		setMap(lev, dir);
	}
	if (lev == 1 && dir == 0) {
		int a = 0;
	}
	if (lev == 5) {
		setResult(lev);
		return;
	}
	for (int i = 0; i < 4; i++) {
		dfs(lev + 1, i);
	}
}
void solve() {
	input();
	dfs(0, 0);
	//if (result > 2048) result = 2048;
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