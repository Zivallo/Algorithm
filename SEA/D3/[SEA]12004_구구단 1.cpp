#include <iostream>
using namespace std;
int T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; int flag = 0;
		for (int i = 1; i < 10; i++) {
			if (i * i > N) break;
			if (N / i < 10) if(i*(N/i)==N) { flag = 1; break; }
		}
		if (flag)cout << "#" << t << " Yes\n";
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