#include <iostream>
using namespace std;
int T, N, M;
int plate[12][12];
int drY[8] = { 0,0,-1,1,-1,1,-1,1 };
int drX[8] = { -1,1,0,0,-1,-1,1,1 };

void init() {
	cin >> N >> M;
	for (int y = 1; y <= N; y++)for (int x = 1; x <= N; x++)plate[y][x] = 0;
	plate[N / 2 + 1][N / 2 + 1] = 2;
	plate[N / 2][N / 2] = 2;
	plate[N / 2][N / 2 + 1] = 1;
	plate[N / 2 + 1][N / 2] = 1;
}
void draw(int y, int x, int c, int d) {
	for (int i = 1; i <= N; i++) {
		int ny = y + drY[d] * i;
		int nx = x + drX[d] * i;
		if (plate[ny][nx] == c)break;
		plate[ny][nx] = c;
	}
}
void check(int y, int x, int c) {
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j <= N; j++) {
			int ny = y + drY[i] * j;
			int nx = x + drX[i] * j;
			if (ny<1 || nx<1 || ny>N || nx>N) break;
			if (plate[ny][nx] == 0)break;
			if (plate[ny][nx] == c) {draw(y, x, c, i); break;}
		}
	}
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		init(); int y, x, c;
		for (int i = 0; i < M; i++) {
			cin >> x >> y >> c;
			plate[y][x] = c;
			check(y, x, c);
		}int bc = 0, wc = 0;
		for (y = 1; y <= N; y++)for (int x = 1; x <= N; x++) {
			if (plate[y][x] == 1)bc++;
			if (plate[y][x] == 2)wc++;
		}
		cout << "#" << t << " " << bc << " " << wc << "\n";
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