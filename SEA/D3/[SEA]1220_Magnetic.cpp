#include<iostream>
using namespace std;
int m[110][110];
int N;

void solve() {
	for (int t = 1; t <= 10; t++) {
		cin >> N; int ret = 0, xv[110] = { 0 };
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> m[y][x];
				if (m[y][x] == 0)continue;
				if (xv[x] == 1 && m[y][x] == 2)ret++;
				xv[x] = m[y][x];
			}
		}
		cout << "#" << t << " " << ret << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}