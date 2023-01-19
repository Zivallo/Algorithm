#include <iostream>
using namespace std;
int T, S, E, M;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> S >> E >> M;
		int r = S;
		while (1) {
			if ((r - E) % 24 == 0 && (r - M) % 29 == 0) break;
			r += 365;
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