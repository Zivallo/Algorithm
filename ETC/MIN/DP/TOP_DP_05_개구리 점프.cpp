#include <iostream>
using namespace std;

int H, W;
int map[1100][1100], memo[1100][1100];
int drY[3] = { 1,1,1 };
int drX[3] = { -1,0,1 };

int dp(int y, int x) {
	if (memo[y][x] != -21e8) return memo[y][x];
	if (y == H - 1) return map[y][x];

	int maxVal = -21e8;
	for (int i = 0; i < 3; i++) {
		int ny = y + drY[i];
		int nx = x + drX[i];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
		if (map[ny][nx] == 0) continue;
		int Val = dp(ny, nx) + map[y][x];
		maxVal = max(maxVal, Val);
	}
	memo[y][x] = maxVal;
	return maxVal;
}


int main() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
			memo[y][x] = -21e8;
		}
	}
	cout << dp(0, 0);
	return 0;
}