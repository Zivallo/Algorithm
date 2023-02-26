#include <iostream>
using namespace std;
int T;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int r = 0, tmp;
		for (int i = 0; i < 5; i++) {
			cin >> tmp;
			r += (tmp < 40 ? 40 : tmp);
		}
		cout << "#" << t << " " << r / 5 << "\n";
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