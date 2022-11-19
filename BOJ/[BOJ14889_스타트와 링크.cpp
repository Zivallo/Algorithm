#include <iostream>
using namespace std;
int N, S[21][21], u[21], r;

int getGap() {
	int s1 = 0, s2 = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (y == x)continue;
			if (u[x] == 0)if (u[x] == u[y]) s1 += S[y][x];
			if (u[x] == 1)if (u[x] == u[y]) s2 += S[y][x];
		}
	}
	return (s1 > s2 ? s1 - s2 : s2 - s1);
}
void dfs(int l,int s) {
	if (r == 0) return;
	if (l == N / 2) {
		int c = getGap();
		if (c < r) r = c;
		return;
	}
	for (int i = s; i < N; i++) {
		if (N / 2 - l < 0)continue;
		u[i] = 1;
		dfs(l + 1, i + 1);
		u[i] = 0;
		if (r == 0)return;
	}
}
void solve() {
	r = 21e8;
	cin >> N;
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) cin >> S[y][x];
	dfs(0, 0);
	cout << r << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}