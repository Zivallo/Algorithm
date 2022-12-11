#include <iostream>
using namespace std;
int T, N;
char m[22][22];

bool check(int miny, int minx, int maxy, int maxx) {
	if (maxy - miny != maxx - minx)return false;
	for (int y = miny; y <= maxy; y++) {
		for (int x = minx; x <= maxx; x++) {
			if (m[y][x] != '#')return false;
		}
	}
	return true;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int miny = 21e8, minx = 21e8, maxy = 0, maxx = 0;
		cin >> N; for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
			cin >> m[y][x];
			if (m[y][x] != '#') continue;
			miny = (miny > y ? y : miny);
			minx = (minx > x ? x : minx);
			maxy = (maxy < y ? y : maxy);
			maxx = (maxx < x ? x : maxx);
		}
		cout << "#" << t;
		if (check(miny, minx, maxy, maxx))cout << " yes\n";
		else cout << " no\n";
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