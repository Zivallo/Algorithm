#include <iostream>
using namespace std;
int T, A, B;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		if (A / 10 != 0 || B / 10 != 0)cout << "#" << t << " -1\n";
		else cout << "#" << t << " " << A * B << "\n";
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