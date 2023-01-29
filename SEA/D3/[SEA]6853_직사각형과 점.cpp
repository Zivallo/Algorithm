#include <iostream>
using namespace std;
int T, N, x1, x2, y3, y2;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> x1 >> y3 >> x2 >> y2 >> N;
		int c1 = 0, c2 = 0, c3 = 0, x, y;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			if (x > x1 && x < x2 && y > y3 && y < y2)c1++;
			else if (x == x1 && y >= y3 && y <= y2)c2++;
			else if (x == x2 && y >= y3 && y <= y2)c2++;
			else if (y == y3 && x >= x1 && x <= x2)c2++;
			else if (y == y2 && x >= x1 && x <= x2)c2++;
			else c3++;			
		}
		cout << "#" << t << " " << c1 << " " << c2 << " " << c3 << "\n";
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