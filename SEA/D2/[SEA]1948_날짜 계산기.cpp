#include <iostream>
using namespace std;
int T, m1, d1, m2, d2;
int last[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> m1 >> d1 >> m2 >> d2; int r = 0;
		if (m1 == m2) {
			r = d2 - d1 + 1;
		}
		else {
			r += (last[m1] - d1 + 1);
			for (int m = m1 + 1; m < m2; m++) r += last[m];
			r += d2;
		}
		cout << "#" << t << " " << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}