#include <iostream>
using namespace std;
int T, N, c, a;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; int r = 0, v = 0;
		for (int i = 0; i < N; i++) {
			cin >> c;
			if (c != 0)cin >> a;
			if (c == 0) r += v;
			if (c == 1) r += (v += a);
			if (c == 2) r += (v = (v - a < 0 ? 0 : v - a));
		}
		cout << "#" << t << " " << r << "\n";
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