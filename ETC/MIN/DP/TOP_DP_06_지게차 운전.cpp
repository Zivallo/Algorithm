#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int val;
	int ny, nx;
};
int map[1100][1100], used[1100][1100];
Node memo[1100][1100];
int N;
int dy[4] = { 0,1,-1,0 };
int dx[4] = { 1,0,0,-1 };

int setDam(int y, int x) {
	if (memo[y][x].val != 21e8) return memo[y][x].val;
	if (y == N - 1 && x == N - 1) {
		memo[y][x].val = 0;
		return memo[y][x].val;
	}

	int mini = 21e8, miny = 0, minx = 0;
	for (int i = 0; i < 2; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (used[ny][nx] == 1) continue;
		used[ny][nx] = 1;
		int temp = setDam(ny, nx);
		used[ny][nx] = 0;
		if (mini > temp) {
			mini = temp;
			miny = ny;
			minx = nx;
		}
	}

	memo[y][x].val = mini + map[y][x];
	memo[y][x].ny = miny;
	memo[y][x].nx = minx;

	return memo[y][x].val;
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			memo[y][x].val = 21e8;
		}
	}
	used[0][0] = 1;
	int ans = setDam(0, 0);
	int ya = 0, xa = 0;
	cout << ans << '\n';
	cout << 0 << "," << 0 << '\n';
	while (1) {
		if (ya == N - 1 && xa == N - 1) break;
		int ny = memo[ya][xa].ny;
		int nx = memo[ya][xa].nx;
		cout << ny << "," << nx << '\n';
		ya = ny;
		xa = nx;
	}
	return 0;
}