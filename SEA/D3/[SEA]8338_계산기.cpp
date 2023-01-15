#include <iostream>
using namespace std;
int T, N, dp[10];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		cin >> dp[0];
		for (int i = 1; i < N; i++) {
			cin >> dp[i];
			dp[i] = (dp[i] * dp[i - 1] > dp[i] + dp[i - 1] ? dp[i] * dp[i - 1] : dp[i] + dp[i - 1]);
		}
		cout << "#" << t << " " << dp[N - 1] << "\n";
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