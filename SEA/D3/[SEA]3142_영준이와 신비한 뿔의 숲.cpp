#include <iostream>
using namespace std;
int T, N, M;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		cout << "#" << t << " " << 2 * M - N << " " << N - M << "\n";
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