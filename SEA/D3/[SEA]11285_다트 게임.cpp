#include <iostream>
#include <cmath>
using namespace std;
int T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; long long ans = 0;
		for (int i = 0; i < N; i++) {
			int x, y;
			float r;
			cin >> x >> y;
			if (x == 0 && y == 0) { ans += 10; continue; }
			r = sqrt(x * x + y * y) / 20;
			if (r > 11)continue;
			ans += 11 - r;
		}
		cout << "#" << t << " " << ans << "\n";
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