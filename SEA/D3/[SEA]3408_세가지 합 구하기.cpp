#include <iostream>
using namespace std;
long long T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; long long a = (1 + N) * (N / 2) + (N & 1 ? (N + 1) / 2 : 0);
		cout << "#" << t << " " << a << " " << a + a - N << " " << a + a << "\n";
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