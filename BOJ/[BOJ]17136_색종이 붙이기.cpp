#include <iostream>
#include <cstring>
using namespace std;
int m[11][11], u[11][11];
int n[6] = { 5,5,5,5,5 };
int s[6] = { 1,4,9,16,25 };
int r, c;

bool check(int sy, int sx, int t) {
	for (int y = 0; y <= t; y++) {
		for (int x = 0; x <= t; x++) {
			if (m[sy + y][sx + x] == 0)return false;
		}
	}
	return true;
}
void setm(int sy, int sx, int t,int s) {
	for (int y = 0; y <= t; y++) {
		for (int x = 0; x <= t; x++) {
			m[sy + y][sx + x] = s;
		}
	}
}
void dfs(int l, int sy, int sx, int cnt) {
	if (r < l) return;
	if (cnt < 0) return;
	if (cnt == 0) {
		if (r > l) r = l;
		return;
	}
	int ty = sy, tx = sx;
	for (int y = ty; y < 10; y++) {
		for (int x = tx; x < 10; x++) {
			if (m[y][x] == 0)continue;
			for (int i = 4; i >= 0; i--) {
				if (y + i >= 10 || x + i >= 10)continue;
				if (n[i] == 0)continue;
				if (!check(y, x, i))continue;
				n[i]--;
				setm(y, x, i, 0);
				dfs(l + 1, y, x, cnt - s[i]);
				setm(y, x, i, 1);
				n[i]++;
			}
			return;
		}
		tx = 0;
	}
}
void solve() {
	r = 21e8;
	for (int y = 0; y < 10; y++)for (int x = 0; x < 10; x++) {
		cin >> m[y][x];
		if (m[y][x])c++;
	}
	if (c == 0) { cout << "0\n"; return; }
	dfs(0, 0, 0, c);
	if (r == 21e8)r = -1;
	cout << r << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}