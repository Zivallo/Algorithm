#include <iostream>
using namespace std;
int T, N;
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; int r = 0;
		r += (-1 * (N / 2));
		if (N % 2 == 1) r += N;
		cout << "#" << t << " " << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}