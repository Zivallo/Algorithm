#include <iostream>;
#include <cmath>
using namespace std;
int T, K;
int s[11][1 << 10];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> K; for (int i = 0; i < 1 << K; i++)cin >> s[0][i];
		long long r = 0;
		for (int d = 0; d < K; d++) {
			for (int i = 0; i < (1 << K); i += (1 << d+1)) {
				s[d + 1][i] = (s[d][i] > s[d][i + (1 << d)] ? s[d][i] : s[d][i + (1 << d)]);
				r += abs(s[d][i] - s[d][i + (1 << d)]);
			}
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