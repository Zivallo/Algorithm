#include <iostream>
using namespace std;
int T, N, M;
int A[30], B[30];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> M; int r = -21e8;
		for (int i = 0; i < N; i++)cin >> A[i];
		for (int i = 0; i < M; i++)cin >> B[i];
		if (N < M) {
			for (int i = 0; i < M - N + 1; i++) {
				int tmp = 0;
				for (int j = 0; j < N; j++) {
					tmp += (B[i + j] * A[j]);
				}
				r = (r < tmp ? tmp : r);
			}
		}
		else {
			for (int i = 0; i < N - M + 1; i++) {
				int tmp = 0;
				for (int j = 0; j < M; j++) {
					tmp += (A[i + j] * B[j]);
				}
				r = (r < tmp ? tmp : r);
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