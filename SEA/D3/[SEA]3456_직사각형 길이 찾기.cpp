#include <iostream>
using namespace std;
int T, a, b, c;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> a >> b >> c; cout << "#" << t << " ";
		if (a == b)cout << c << "\n";
		else if (a == c)cout << b << "\n";
		else cout << a << "\n";
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