#include <iostream>
using namespace std;
int T, N, S[10010];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int ts = 0;
		cin >> N; for (int i = 0; i < N; i++) { cin >> S[i]; ts += S[i]; }
		int avg = ts / N, r = 0;
		for (int i = 0; i < N; i++)if (S[i] < avg)r += avg - S[i];
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