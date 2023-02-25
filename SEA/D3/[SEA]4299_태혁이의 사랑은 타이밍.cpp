#include <iostream>
using namespace std;
int T, D, H, M;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> D >> H >> M; int d, h, m;
		cout << "#" << t << " ";
		d = D - 11;
		h = H - 11;
		m = M - 11;
		if (m < 0) { h--; m = 60 + m; }
		if (h < 0) { d--; h = 24 + h; }
		if (d < 0)cout << "-1\n";
		else cout << d * (24 * 60) + h * 60 + m << "\n";
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