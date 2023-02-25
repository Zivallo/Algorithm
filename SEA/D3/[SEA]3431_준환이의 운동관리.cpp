#include <iostream>
using namespace std;
int T, L, U, X;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> L >> U >> X;
		cout << "#" << t << " ";
		if (X < L)cout << L - X << "\n";
		else if (X < U)cout << "0\n";
		else cout << "-1\n";
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