#include <iostream>
using namespace std;
int T, N;
int a[100100];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int c[100100] = { 0 }, f = 1;
		cin >> N; for (int i = 0; i < N; i++) {
			cin >> a[i];
			if (c[a[i]] == 1) f = 0;
			c[a[i]]++;
		}
		if (f) cout << "#" << t << " Yes\n";
		else cout << "#" << t << " No\n";
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