#include<iostream>
using namespace std;
int T, N, K;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		if (N % K)cout << "#" << t << " 1\n";
		else cout << "#" << t << " 0\n";
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