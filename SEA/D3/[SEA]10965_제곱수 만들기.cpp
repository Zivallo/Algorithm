#include <iostream>
using namespace std;
int T, N, pos, ans, idx, cnt;
int prime[10000001], list[3500];
void mk() {
	pos = 0;
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i < 10001; i++) {
		if (prime[i] == 1)continue;
		else list[pos++] = i;
		for (int j = i + i; j < 10000001; j += i)prime[j] = 1;
	}
}
void solve() {
	mk();
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		if (!prime[N])cout << "#" << t << " " << N << "\n";
		else {
			ans = 1, idx = 0, cnt = 0;
			while (N > 1) {
				if (N % list[idx] == 0) {
					cnt++;
					N /= list[idx];
				}
				if (N % list[idx] != 0) {
					if (cnt % 2 != 0)ans *= list[idx];
					if (!prime[N]) { ans *= N; break; }
					idx++;
					if (idx == pos) { ans *= N; break; }
					cnt = 0;
				}
			}
			cout << "#" << t << " " << ans << "\n";
		}
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