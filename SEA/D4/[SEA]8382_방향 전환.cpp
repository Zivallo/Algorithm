#include <iostream>
#include <cmath>
using namespace std;
int T, x1, y11, x2, y2;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> x1 >> y11 >> x2 >> y2;
		int yc = (y11 > y2 ? y11 - y2 : y2 - y11);
		int xc = (x1 > x2 ? x1 - x2 : x2 - x1);
		if (yc == xc) cout << "#" << t << " " << 2 * yc << "\n";
		else {
			int a = (yc > xc ? xc : yc);
			int b = (yc > xc ? yc : xc) - a;
			int r = 2 * a + ((b + 1) / 2 + 3 * (b / 2));
			cout << "#" << t << " " << r << "\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}