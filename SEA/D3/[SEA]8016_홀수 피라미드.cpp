#include <iostream>
using namespace std;
long long T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << "#" << t << " " << 1 + 2 * (N - 1) * (N - 1) << " " << 1 + 2 * (N - 1) * (N - 1) + 2 * 2 * (N - 1) << "\n";
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