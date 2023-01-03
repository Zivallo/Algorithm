#include <iostream>
using namespace std;
int T;
float p, q;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> p >> q;
		if (((1 - p) * q) < (p * (1 - q) * q))cout << "#" << t << " YES\n";
		else cout << "#" << t << " NO\n";
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