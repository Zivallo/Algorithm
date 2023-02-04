#include <iostream>
using namespace std;
int T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		double p, x, ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> p >> x;
			ans += (p * x);
		}
		cout << "#" << t << " " << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cout << fixed;
	cout.precision(6);
	solve();
	return 0;
}