#include <iostream>
using namespace std;
int T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		if (t == 5) {
			int b = 1;
		}
		if (N == 1) { cout << "#" << t << " 1\n"; continue; }
		if (N == 2) { cout << "#" << t << " 1\n"; continue; }
		int l = 1, r = 2, s = 3, a = 1;
		while (l < r) {
			if (s == N) a++;
			if (s > N) { s -= l; l++; continue; }
			if (s <= N) { r++; s += r; continue; };
		}
		cout << "#" << t << " " << a << "\n";
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