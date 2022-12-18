#include <iostream>
using namespace std;
int T, A, B, C, D;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A >> B >> C >> D;
		int s = (A > C ? A : C);
		int e = (B > D ? D : B);
		int r = e - s;
		if (r <= 0)cout << "#" << t << " 0\n";
		else cout << "#" << t << " " << r << '\n';
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