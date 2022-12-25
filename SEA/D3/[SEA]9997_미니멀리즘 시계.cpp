#include <iostream>
using namespace std;
int T, A;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A;
		int m = 2 * A;
		int h = m / 60;
		m %= 60;
		h %= 24;
		cout << "#" << t << " " << h << " " << m << "\n";
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